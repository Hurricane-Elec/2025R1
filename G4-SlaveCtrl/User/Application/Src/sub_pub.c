/**
 * @file sub_pub.c
 * @author CV-Engineer-Chen
 * @brief sub-订阅变量值;pub-发布参数.
 *        - 订阅遥控器的值并发布给main-ctrl
 *        - 订阅底盘参数:speedx\speedy\speedz\halt\world_yaw
 *        - 订阅摩擦带参数:5065-speed\云台angle\俯仰angle\shoot-flag
 *        - 订阅运球参数:dribblling_flag
 * @version 0.1
 * @date 2025-04-20
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "includes.h"
#include "message-protocol/msg_protocol.h"

#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Waddress-of-packed-member"
#endif /* __GNUC__ */
float world_angle;

static struct __packed {
    float chassis_speedx;    /* 底盘speedx */
    float chassis_speedy;    /* 底盘speedy */
    float chassis_speedyaw;  /* 底盘speedyaw */
    float chassis_world_yaw; /* 世界坐标yaw */
    bool chassis_halt;       /* 底盘停止标志 */

    float friction_speed_5065; /* 摩擦带速度 */
    uint8_t shoot_flag;        /* 射击标志 */
} sub_main_ctrl_data;

TaskHandle_t sub_pub_task_handle;

/**
 * @brief 公开底参数
 * 
 * @param speedx 底盘订阅x方向速度
 * @param speedy 底盘订阅y方向速度
 * @param speedw 底盘订阅yaw角速度
 * @return * void 
 */
void pub_to_chassis(float *speedx, float *speedy, float *speedw) {
    *speedx = sub_main_ctrl_data.chassis_speedx;
    *speedy = sub_main_ctrl_data.chassis_speedy;
    *speedw = sub_main_ctrl_data.chassis_speedyaw;
}
void pub_to_chassis_halt(bool *chassis_halt) {
    *chassis_halt = sub_main_ctrl_data.chassis_halt ? true : false;
}

void pub_to_friction(float *speed5065) {
    *speed5065 = sub_main_ctrl_data.friction_speed_5065;
}

void pub_to_friction_flag(uint8_t *flag) {
    *flag = sub_main_ctrl_data.shoot_flag;
}


void pub_to_chassis_world_angle(float **angle) {
    (*angle) = &world_angle;
}

void sub_master_call_back(uint32_t msg_length, uint8_t msg_id_type,
                          uint8_t *msg_data) {
    UNUSED(msg_length);

    if ((msg_id_type >> 4) != MSG_TO_SLAVE) {
        return;
    }
    memcpy(&sub_main_ctrl_data, msg_data, sizeof(sub_main_ctrl_data));
}

void sub_pub_task(void *pvParameters) {
    UNUSED(pvParameters);

    memset(&sub_main_ctrl_data, 0, sizeof(sub_main_ctrl_data));
    message_register_polling_uart(MSG_TO_SLAVE, &usart2_handle, 512);
    message_register_recv_callback(MSG_TO_SLAVE, sub_master_call_back);
    while (1) {
        message_polling_data();
        world_angle = sub_main_ctrl_data.chassis_world_yaw;
        vTaskDelay(2);
    }
}