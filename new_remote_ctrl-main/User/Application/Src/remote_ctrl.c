/**
 * @file    remote_ctrl.c
 * @author  Deadline039
 * @brief   遥控器数据处理并发送
 * @version 0.1
 * @date    2025-04-22
 */

#include "includes.h"

/* 发送的数据 */
static struct __packed {
    uint8_t key;  /*!< 按键值 */
    int8_t rs[4]; /*!< 摇杆, 左 x, 左 y, 右 x, 右 y */
} remote_send_data;

/* 发送任务句柄 */
static TaskHandle_t remote_send_task_handle;

/* 发送时间间隔, 单位: ms */
#define REMOTE_SEND_PERIOD 10

/* 18 个按键, 3 个事件 */
static remote_key_callback_t key_callback[18][REMOTE_KEY_EVENT_NUM];

#define KEY_EVENT_CB(key, event)                                               \
    do {                                                                       \
        if ((key <= 18) && key_callback[key - 1][event]) {                      \
            key_callback[key - 1][event](key, event);                          \
        }                                                                      \
    } while (0)

/**
 * @brief 遥控器发送任务同时调用相应按键回调
 * 
 * @param pvParameters 
 */
static void remote_send_task(void *pvParameters) {
    UNUSED(pvParameters);
    uint32_t rs_adc_buf[4];
    uint32_t keyboard_value;
    uint32_t rs_z_value;
    uint8_t last_key = 0;

    uint8_t key_times = 0;
    TickType_t last_wake_time = xTaskGetTickCount();
    while (1) {
        keyboard_value = keyboard_scan();
        rs_z_value = rs_get_z();
        rs_get_value(rs_adc_buf, 10, 40);

        if (rs_z_value) {
            keyboard_value = 16 + rs_z_value;
        }

        /* 摇杆的按键优先级高于普通按键, 左边为 17, 右边为 18. 没有任何按键按下是 0 */
        remote_send_data.key = (uint8_t)keyboard_value;
        /* 左 x */
        remote_send_data.rs[0] = (uint8_t)rs_adc_buf[0] - 20;
        /* 左 y */
        remote_send_data.rs[1] = (uint8_t)rs_adc_buf[1] - 20;
        /* 右 x */
        remote_send_data.rs[2] = (uint8_t)rs_adc_buf[2] - 20;
        /* 右 y */
        remote_send_data.rs[3] = (uint8_t)rs_adc_buf[3] - 20;

        /* 发送数据 */
        message_send_data(MSG_ID_REMOTE, MSG_DATA_UINT8,
                          (uint8_t *)&remote_send_data,
                          sizeof(remote_send_data));

        if (last_key != 0) {
            if (remote_send_data.key == 0) {
                /* 按键抬起 */
                KEY_EVENT_CB(last_key, REMOTE_KEY_PRESS_UP);
            } else if (remote_send_data.key == last_key) {
                /* 长按 */
                KEY_EVENT_CB(remote_send_data.key, REMOTE_KEY_PRESSING);
            } else {
                /* 抬起一个按键, 按下另一个按键 */
                KEY_EVENT_CB(last_key, REMOTE_KEY_PRESS_UP);
                KEY_EVENT_CB(remote_send_data.key, REMOTE_KEY_PRESS_DOWN);
            }
        } else {
            if (remote_send_data.key != 0) {
                /* 按键按下 */
                KEY_EVENT_CB(remote_send_data.key, REMOTE_KEY_PRESS_DOWN);
            }
        }
        /* 显示按键，按键非零变化后才会显示 */
        if(remote_send_data.key != 0){
            if(remote_send_data.key != key_times){
                lv_label_set_text_fmt(objects.lvble_key_number, "%d",
                                  remote_send_data.key);
                key_times = remote_send_data.key;
            }
        }
        last_key = remote_send_data.key;
        if (objects.lvbar_rs_r_y != NULL) { 
            lv_label_set_text_fmt(objects.lvble_rs_l_x, "%d",
                                  remote_send_data.rs[0]);
            lv_label_set_text_fmt(objects.lvble_rs_l_y, "%d",
                                  remote_send_data.rs[1]);
            lv_label_set_text_fmt(objects.lvble_rs_r_x, "%d",
                                  remote_send_data.rs[2]);
            lv_label_set_text_fmt(objects.lvble_rs_r_y, "%d",
                                  remote_send_data.rs[3]);
            lv_bar_set_value(objects.lvbar_rs_l_x, remote_send_data.rs[0],
                             LV_ANIM_OFF);
            lv_bar_set_value(objects.lvbar_rs_l_y, remote_send_data.rs[1],
                             LV_ANIM_OFF);
            lv_bar_set_value(objects.lvbar_rs_r_x, remote_send_data.rs[2],
                             LV_ANIM_OFF);
            lv_bar_set_value(objects.lvbar_rs_r_y, remote_send_data.rs[3],
                             LV_ANIM_OFF);
        }
        vTaskDelayUntil(&last_wake_time, REMOTE_SEND_PERIOD);
    }
}

/**
 * @brief 遥控器发送初始化
 * 
 * @param send_uart 发送数据的串口
 */
void remote_send_init(UART_HandleTypeDef *send_uart) {
    rs_init();
    keyboard_init();
    if (send_uart == NULL) {
        return;
    }

    message_register_send_uart(MSG_ID_REMOTE, send_uart, 20);
    xTaskCreate(remote_send_task, "send task", 512, NULL, 3,
                &remote_send_task_handle);
}

/**
 * @brief 遥控器键盘注册回调函数
 * 
 * @param key 按键
 * @param event 事件
 * @param callback 事件回调函数
 */
void remote_register_key_callback(uint8_t key, remote_key_event_t event,
                                  remote_key_callback_t callback) {
    if (key > 18) {
        return;
    }

    if (event >= REMOTE_KEY_EVENT_NUM) {
        return;
    }

    key_callback[key - 1][event] = callback;
}

/**
 * @brief 遥控器键盘取消注册回调函数
 * 
 * @param key 按键
 * @param event 事件
 * @param callback 事件回调函数
 */
void remote_unregister_key_callback(uint8_t key, remote_key_event_t event) {
    if (key > 18) {
        return;
    }

    if (event >= REMOTE_KEY_EVENT_NUM) {
        return;
    }

    key_callback[key - 1][event] = NULL;
}
