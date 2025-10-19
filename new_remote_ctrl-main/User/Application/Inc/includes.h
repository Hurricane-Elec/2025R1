/**
 * @file    includes.h
 * @author  Deadline039
 * @brief   Include files
 * @version 1.0
 * @date    2024-04-03
 */

#ifndef __INCLUDES_H
#define __INCLUDES_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*****************************************************************************
 * @defgroup Include files.
 * @{
 */

#include "bsp.h"

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"

#include "lv_port_disp.h"
#include "lv_port_indev.h"
#include "lvgl.h"
#include "mygui.h"

#include "ff.h"
#include "usbd_cdc.h"
#include "usbd_cdc_if.h"
#include "usbd_conf.h"
#include "usbd_core.h"
#include "usbd_desc.h"
#include "usbd_msc.h"
#include "usbd_storage_if.h"

#include "tlsf.h"

#include "message-protocol/msg_protocol.h"
#include <math.h>

/**
 * @}
 */

/*****************************************************************************
 * @defgroup Public definitions.
 * @{
 */

/**
 * @}
 */

/*****************************************************************************
 * @defgroup Public types.
 * @{
 */

/**
 * @brief 遥控器键盘事件
 * @note 大部分回调注册使用按键按下普通事件
 */
typedef enum {
    REMOTE_KEY_PRESS_DOWN, /*!< 按键按下 */
    REMOTE_KEY_PRESSING,   /*!< 按键长按 */
    REMOTE_KEY_PRESS_UP,   /*!< 按键抬起 */
    REMOTE_KEY_EVENT_NUM   /*!< 保留长度 */
} remote_key_event_t;

typedef enum {
    ORIGIN_SET_INT = 1, /*!< 进入原点设置 */
    ORIGIN_SET_LAST,
    ORIGIN_SET_NEXT, /*!< 下一个原点 */
    ORIGIN_SET_DIRECTION,
    ORIGIN_SET_OUT   /*!< 退出原点设置  */
} origin_key_t;

/**
 * @brief 遥控器键盘回调函数
 * 
 * @param key 按键
 * @param event 事件
 */
typedef void (*remote_key_callback_t)(uint8_t key, remote_key_event_t event);

/**
 * @brief 底盘队列数据
 * 
 */
typedef struct __packed {
    int16_t x;     /*!< x 坐标 */
    int16_t y;     /*!< y 坐标 */
    int16_t angle; /*!< yaw 坐标 */

    /*!< 底盘状态 
     * bit[7:2] 保留
     * bit[1]   是否在自瞄状态
     * bit[0]   是否世界坐标系
     */
    uint8_t chassis_status;
} position_data_t;

/**
 * @}
 */

/*****************************************************************************
 * @defgroup Public variables.
 * @{
 */

/*接收底盘数据数据的消息队列*/
extern QueueHandle_t position_data_queue;

extern at24cxx_handle_t at24c02_handle;

extern TaskHandle_t usb_app_handle;
extern TaskHandle_t gui_task_handle;

/**
 * @}
 */

/*****************************************************************************
 * @defgroup Public functions.
 * @{
 */

void freertos_start(void);
void at24c02_dev_init(void);

void usb_enable_cdc(void);
uint8_t usb_detect_msc(void);
void usb_app(void *pvParameters);

void gui_screen_switch(uint8_t key, remote_key_event_t event);

/* 遥控器数据发送任务API */
void remote_send_init(UART_HandleTypeDef *send_uart);
void remote_report_msg_callback(uint32_t msg_length, uint8_t msg_id_type,
                                uint8_t *msg_data);
void remote_register_key_callback(uint8_t key, remote_key_event_t event,
                                  remote_key_callback_t callback);
void remote_unregister_key_callback(uint8_t key, remote_key_event_t event);

/* 画点任务API */
void show_coordinates_task(void *pvParameters);
void point_draw_clean(int16_t x, int16_t y, uint32_t color);
void triangle_draw_clean(int16_t x, int16_t y, int16_t angle, uint16_t color);
void origin_point_draw(int16_t x, int16_t y, int16_t angle, uint16_t color);
void lcd_draw_triangle(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1,
                       uint16_t x2, uint16_t y2, uint16_t color);

/**
 * @}
 */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __INCLUDES_H */
