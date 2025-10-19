#include "includes.h"
#include "steering_wheel/steering_wheel.h"
#include "my_math/my_math.h"

/* 从sub—pub订阅的数据，用于控制底盘状态 */
static struct {
    float speed_x;   /* x方向速度 */
    float speed_y;   /* y方向速度 */
    float speed_yaw; /* yaw方向速度 */
    bool halt;       /* 是否自锁 */

    float *world_angle; /* 世界坐标angle,指向订阅的角度值 */
} chassis_sub;

/* 航向电机 */
dm_handle_t direction_motor[WHEEL_NUM];
float direction_current_angle[WHEEL_NUM] = {0};

/* 舵向电机 */
dji_motor_handle_t speed_motor[WHEEL_NUM];
float speed_motor_target[WHEEL_NUM] = {0};
pid_t speed_motor_pid[WHEEL_NUM];

/* 声明 */
TaskHandle_t chassis_motor_ctrl_task_handle;
void chassis_motor_ctrl_task(void *pvParameters);
TaskHandle_t chassis_ctrl_task_handle;
void chassis_ctrl_task(void *pvParameters);

/**
 * @brief 最小角度选择（rad制） 
 * 
 * @param self_angle 
 * @param target_angle 
 * @return 
 */
float choose_min_rad(float self_angle, float target_angle) {
    float tmp, res1, res2;
    tmp = target_angle - self_angle;
    res1 = tmp > 0 ? tmp - 2 * PI : tmp + 2 * PI;
    res2 = tmp;
    tmp = my_fabs(res1) < my_fabs(res2) ? res1 : res2;
    return tmp;
}

/* dm电机过零处理标志位,用于处理速度电机转向 */
bool dm_zero_flag[WHEEL_NUM] = {false};

/**
 * @brief 舵轮舵向电机控制
 * 
 * @param angle 舵向角度
 */
static void direction_motor_ctrl(float *angle) {
    static float total_angle[WHEEL_NUM] = {0.0f};
    for (uint32_t i = 0; i < WHEEL_NUM; i++) {
        float target_angle;
        target_angle = angle[i];
        /* 由于6220电机使用最小角度选择算法时, 转动角度超过PI时会走优弧回到-PI, 这里选择如果要跨过临界区就取消最小角选择*/

        total_angle[i] += choose_min_rad(direction_current_angle[i], angle[i]);

        if (fabsf(total_angle[i]) >= 12.5f) {
            if (total_angle[i] < 0.0f) {
                target_angle += PI;
                total_angle[i] += PI;
            } else {
                target_angle -= PI;
                total_angle[i] -= PI;
            }
            dm_zero_flag[i] = true; /* dm电机过零处理 */
        }
        direction_current_angle[i] = target_angle;

        dm_mit_ctrl(&direction_motor[i], total_angle[i], 0.0f, 8.8f, 0.1f,
                    0.0f);
    }
}
/**
 * @brief 航向电机目标速度
 * 
 * @param speed 航向电机速度设定
 * @return * void 
 */
static void speed_motor_ctrl(float *speed) {
    for (uint32_t i = 0; i < WHEEL_NUM; i++) {
        if (dm_zero_flag[i]) {
            /* 处理dm电机过零点 */
            dm_zero_flag[i] = false;
            speed[i] *= -1;
        }
        speed_motor_target[i] = speed[i];
    }
}

/**
 * @brief 初始化底盘
 * 
 * @note 包括电机初始化，控制类型初始化，创建相关控制任务
 * 
 */
void chassis_init(void) {
    /* 初始化达妙电机 */
    for (uint32_t i = 0; i < WHEEL_NUM; i++) {
        dm_motor_init(&direction_motor[i], 0x11 + i, i + 1, DM_MODE_MIT,
                      DM_G6220, 12.5, 45, 10, can1_selected);
        dm_motor_enable(&direction_motor[i]);
    }

    /* 初始化dji电机pid */
    for (uint32_t i = 0; i < WHEEL_NUM; i++) {
        pid_init(&speed_motor_pid[i], 16384, 0, 0, 16384, POSITION_PID, 3.9f,
                 0.0f, 1.2f);
    }

    /* 初始化dji电机 */
    for (uint32_t i = 0; i < WHEEL_NUM; i++) {
        dji_motor_init(&speed_motor[i], DJI_M3508, CAN_Motor1_ID + i,
                       can2_selected);
    }

    /* 订阅世界坐标参数 */
    // chassis_sub.world_angle = pub_to_chassis_world_angle();
    pub_to_chassis_world_angle(&chassis_sub.world_angle);

    /* 初始化舵轮底盘 */
    float *steering_motor_real_angle[WHEEL_NUM] = {0};
    for (uint32_t i = 0; i < WHEEL_NUM; i++) {
        steering_motor_real_angle[i] = &direction_current_angle[i];
    }
    steering_wheel_init(0.28, chassis_sub.world_angle, direction_motor_ctrl,
                        speed_motor_ctrl, steering_motor_real_angle);

    /* 创建电机控制任务 */
    xTaskCreate(chassis_motor_ctrl_task, "chassis_motor_ctrl_task", 256, NULL,
                4, &chassis_motor_ctrl_task_handle);
    /* 创建底盘控制任务 */
    xTaskCreate(chassis_ctrl_task, "chassis_ctrl_task", 256, NULL, 4,
                &chassis_ctrl_task_handle);
}

/**
 * @brief 底盘主要控制逻辑
 * 
 * @param pvParameters 
 */
void chassis_ctrl_task(void *pvParameters) {
    UNUSED(pvParameters);

    while (1) {
        pub_to_chassis(&chassis_sub.speed_x, &chassis_sub.speed_y,
                       &chassis_sub.speed_yaw);
        pub_to_chassis_halt(&chassis_sub.halt);
        if (chassis_sub.halt) {
            steering_set_halt(1);
        } else {
            steering_set_halt(0);
        }
        steering_wheel_ctrl(chassis_sub.speed_x, chassis_sub.speed_y,
                            chassis_sub.speed_yaw);
        vTaskDelay(3);
    }
}

/**
 * @brief 底盘电机控制任务(主要服务于dji电机控制)
 * 
 * @param pvParameters 
 */
void chassis_motor_ctrl_task(void *pvParameters) {
    UNUSED(pvParameters);

    /* 控制电机 */
    while (1) {
        for (uint8_t i = 0; i < WHEEL_NUM; i++) {
            speed_motor[i].set_value =
                (int16_t)pid_calc(&speed_motor_pid[i], speed_motor_target[i],
                                  speed_motor[i].speed_rpm);
        }
#if WHEEL_NUM == 4
        dji_motor_set_current(
            can2_selected, DJI_MOTOR_GROUP1, speed_motor[0].set_value,
            speed_motor[1].set_value, speed_motor[2].set_value,
            speed_motor[3].set_value);
#elif WHEEL_NUM == 3
        dji_motor_set_current(
            can2_selected, DJI_MOTOR_GROUP1, speed_motor[0].set_value,
            speed_motor[1].set_value, speed_motor[2].set_value, 0);
#endif /* WHEEL_NUM */
        vTaskDelay(5);
    }
}
