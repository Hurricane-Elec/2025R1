/**
 * @file    shoot_machine.c
 * @author  meiwenhuaqingnian
 * @brief   摩擦带，推球电机命令.
 * @version 3.0
 * @date    2025-05-15
 */

#include <math.h>
#include "includes.h"

TaskHandle_t function_ctrl_task_handle;
void function_ctrl_task(void *pvParameters);
TaskHandle_t fribelt_motor_ctrl_handle;
void fribelt_motor_ctrl_Task(void *pvParameters);
TaskHandle_t push_ball_motor_task_handle;
void push_ball_motor_ctrl_task(void *pvParameters);

/* 定义摩擦带5065电机
   从发射架正面看 三个5065发射电机
              | 3 |
        | 2 |       | 1 | */
vesc_motor_handle_t n5065_handle[3] = {0};
#define POLES_PIARS 7 /* 5065 电机极对数：7 */

/* 定义推球2006电机 */
dji_motor_handle_t push_ball_motor_handle;
pid_t push_motor_speed_pid = {0};
pid_t push_motor_angle_pid = {0};

/* 订阅所需参数 */
struct {
    float shoot_speed; /* 摩擦带发射速度 */
    uint8_t shoot_flag;
} shoot_sub = {0};

/**
* @brief 摩擦带射速设定
* @param speed电机转速，单位epm
*/
void fribelt_motor_ctrl(float speed) {
    vesc_motor_set_erpm(&n5065_handle[0], speed);
    vesc_motor_set_erpm(&n5065_handle[1], speed);
    vesc_motor_set_erpm(&n5065_handle[2], -speed);
    log_message(LOG_INFO, "shoot! speed = %d\n", speed);
}

float KP = 15.0f;
float KI = 0.051f;
float KD = 7.0f;

/**
 * @brief 发射结构电机初始化
 */
void shoot_machine_init(void) {
    /* 摩擦带电机初始化 */
    vesc_motor_init(&n5065_handle[0], 1, can3_selected);
    vesc_motor_init(&n5065_handle[1], 2, can3_selected);
    vesc_motor_init(&n5065_handle[2], 3, can3_selected);
    log_message(LOG_INFO, "vesc motor init\n");

    /* 推球电机初始化 */
    dji_motor_init(&push_ball_motor_handle, DJI_M3508, CAN_Motor4_ID,
                   can3_selected);
    pid_init(&push_motor_speed_pid, 16384, 500, 10, 16384, POSITION_PID, 9.0f,
             0.01f * 2, 1.0f);
    pid_init(&push_motor_angle_pid, 8192, 8192 / 7.5f, 0, 16384, POSITION_PID,
             15.0f, 0.051 * 2.0, 7.5f);
    log_message(LOG_INFO, "3508 motor init\n");

    /* 任务创建 */
    xTaskCreate(function_ctrl_task, "function_ctrl_task", 256, NULL, 4,
                &function_ctrl_task_handle);

    xTaskCreate(fribelt_motor_ctrl_Task, "fribelt_motor_ctrl_Task", 256, NULL,
                4, &fribelt_motor_ctrl_handle);
    xTaskCreate(push_ball_motor_ctrl_task, "push_ball", 128, NULL, 4,
                &push_ball_motor_task_handle);
}

/**
 * @brief 订阅发布任务
 */
void function_ctrl_task(void *pvParameters) {
    UNUSED(pvParameters);
    while (1) {
        pub_to_friction_flag(&shoot_sub.shoot_flag);
        switch (shoot_sub.shoot_flag) /* 根据订阅的标志进行任务控制 */
        {
            case 0:
                vTaskSuspend(fribelt_motor_ctrl_handle);
                break;
            case 1:
                pub_to_friction(&shoot_sub.shoot_speed);
                break;
            case 2:
                pub_to_friction(&shoot_sub.shoot_speed);
                vTaskResume(fribelt_motor_ctrl_handle);
                break;
            case 3:
                pub_to_friction(&shoot_sub.shoot_speed);
                vTaskResume(fribelt_motor_ctrl_handle);
                break;
            default:
                break;
        }

        vTaskDelay(10);
    }
}

/**
 * @brief 摩擦带n5065电机控制任务
 */
void fribelt_motor_ctrl_Task(void *pvParameters) {
    UNUSED(pvParameters);
    while (1) {
        fribelt_motor_ctrl(shoot_sub.shoot_speed);
        vTaskDelay(10);
    }
}

/**
 * @brief 推球2006电机控制任务
 */
void push_ball_motor_ctrl_task(void *pvParameters) {
    UNUSED(pvParameters);
    static float target_rpm = 0;
    static float set_rpm = 0;

    static float target_angle = 0.0f; /* 单位° */

    while (1) {
        switch (shoot_sub.shoot_flag) {
            case 0:
            case 3:
                if (push_ball_motor_handle.rotor_degree > -70.0f) {
                    /* 当夹子还没有放平的时候，一个小速度放平 */
                    target_rpm = -400;
                } else {
                    /* 夹子放平后，不控制3508 */
                    target_rpm = 0;
                    goto out_break;
                }
                break;
            case 2:
                target_angle = -60.5;
                target_rpm = pid_calc(&push_motor_angle_pid, target_angle,
                                      push_ball_motor_handle.rotor_degree);

                if (PROXIMITY_OUT_SWITCH() != PROXIMITY_OUT_SWITCH_TOUCHED) {
                    /* 抽屉没有收回积分项清零 */
                    push_motor_angle_pid.iout = 0.0f;
                    push_motor_speed_pid.iout = 0.0f;
                    if (push_ball_motor_handle.rotor_degree > -70.0f) {
                        /* 当夹子还没有放平的时候，一个小速度放平 */
                        target_rpm = -250;
                    } else {
                        /* 如果光电没有触发，夹子放平后，3508电机不工作 */
                        target_rpm = 0;
                        goto out_break;
                    }
                }
                break;
            case 1: {
                target_angle = -19.5;
                // target_angle = -5.0f;
                target_rpm = pid_calc(&push_motor_angle_pid, target_angle,
                                      push_ball_motor_handle.rotor_degree);
            } break;
            default:
                continue;
        }
        set_rpm = pid_calc(&push_motor_speed_pid, target_rpm,
                           push_ball_motor_handle.speed_rpm);

        dji_motor_set_current(can3_selected, DJI_MOTOR_GROUP1, 0, 0, 0,
                              (int16_t)set_rpm);
    out_break:
        vTaskDelay(10);
    }
}
