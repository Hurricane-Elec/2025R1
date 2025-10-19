/**
 * @file    report_data.c
 * @author  Deadline039
 * @brief   主板数据上报
 * @version 0.1
 * @date    2025-04-22
 */

#include "includes.h"

static position_data_t recv_position_data;

/**
 * @brief 上报数据内容
 */
typedef enum __packed {
    REMOTE_REPORT_POSITION, /*!< 上报位置信息 */
} remote_report_data_t;

/**
 * @brief 主板上报数据回调函数
 * 
 * @param msg_length 消息帧长度
 * @param msg_id_type 消息 ID 和数据类型 (高四位为 ID, 低四位为数据类型)
 * @param[in] msg_data 消息数据接收区
 */
void remote_report_msg_callback(uint32_t msg_length, uint8_t msg_id_type,
                                uint8_t *msg_data) {
    UNUSED(msg_length);
    if ((msg_id_type >> 4) != MSG_ID_REMOTE) {
        return;
    }

    switch (msg_data[0]) {
        case REMOTE_REPORT_POSITION: {
            memcpy(&recv_position_data, &msg_data[1],
                   sizeof(recv_position_data));
            LED1_TOGGLE();
            /* 这里将数据入队列 */
            xQueueOverwrite(position_data_queue, &recv_position_data);
        } break;

        default:
            return;
    }
}