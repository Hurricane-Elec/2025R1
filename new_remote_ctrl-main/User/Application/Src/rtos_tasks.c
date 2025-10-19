/**
 * @file    rtos_tasks.c
 * @author  Deadline039
 * @brief   RTOS tasks.
 * @version 1.0
 * @date    2024-01-31
 */

#include "includes.h"

static TaskHandle_t task_start_handle;
void task_start(void *pvParameters);

TaskHandle_t gui_task_handle;
void gui_task(void *pvParameters);

static TaskHandle_t message_polling_task_handle;
void message_polling_task(void *pvParameters);

static TaskHandle_t battery_monitor_task_handle;
void battery_monitor_task(void *pvParameters);

TaskHandle_t show_coordinates_task_handle;

/*****************************************************************************/

/**
 * @brief FreeRTOS start up.
 *
 */
void freertos_start(void) {
    xTaskCreate(task_start, "task_start", 1024, NULL, 2, &task_start_handle);
    vTaskStartScheduler();
}

/**
 * @brief Start up task.
 *
 * @param pvParameters Start parameters.
 */
void task_start(void *pvParameters) {
    UNUSED(pvParameters);
    at24c02_dev_init();
    remote_send_init(&usart3_handle); /* 创建 */
    message_register_polling_uart(MSG_ID_REMOTE, &usart3_handle, 100, 512);
    message_register_recv_callback(MSG_ID_REMOTE, remote_report_msg_callback);

    taskENTER_CRITICAL();

    xTaskCreate(gui_task, "gui_task", 3072, NULL, 4, &gui_task_handle);
    xTaskCreate(battery_monitor_task, "battery_monitor_task", 512, NULL, 1,
                &battery_monitor_task_handle);
    xTaskCreate(message_polling_task, "message_polling_task", 512, NULL, 2,
                &message_polling_task_handle);
    taskEXIT_CRITICAL();

    vTaskDelete(task_start_handle);
}

/**
 * @brief gui_task gui运行函数
 * @note 创建gui部件,并指示当前程序是否正常运行。
 *
 * @param pvParameters Start parameters.
 */
void gui_task(void *pvParameters) {
    UNUSED(pvParameters);

    uint8_t times = 0;
    lv_init();
    lv_port_disp_init();
    create_tabview();
    xTaskCreate(show_coordinates_task, "show_coordinates_task", 3072, NULL, 2,
                &show_coordinates_task_handle);
    remote_register_key_callback(17, REMOTE_KEY_PRESS_DOWN, gui_screen_switch);
    while (1) {
        if (times >= 100) {
            LED0_TOGGLE();
            times = 0;
        }
        ++times;
        lv_timer_handler();
        vTaskDelay(5);
    }
}

/**
 * @brief message_polling_task 指定串口轮询数据函数
 *
 * @param pvParameters
 */
void message_polling_task(void *pvParameters) {
    UNUSED(pvParameters);
    while (1) {

        message_polling_data();
        vTaskDelay(5);
    }
}

/**
 * @brief 电池电量监测任务
 * 
 * @param pvParameters 
 */
void battery_monitor_task(void *pvParameters) {
    UNUSED(pvParameters);
    battery_monitor_init();
    uint8_t battery_number = 0;
    uint8_t battery_number_last = 0;
    /* 重复三次计数将标志位置与合适的位置不然后面10s一次来不及更新 */
    battey_get_value();
    battey_get_value();
    battey_get_value();
    while (1) {
        battery_number = battey_get_value();
        if (battery_number != battery_number_last) {
            /* 等待部件创建成功 */
            if (objects.lvble_battery == NULL) {
                continue;
            }
            switch (battery_number) {
                case 100:
                    lv_label_set_text(objects.lvble_battery,
                                      LV_SYMBOL_BATTERY_FULL);
                    break;
                case 75:
                    lv_label_set_text(objects.lvble_battery,
                                      LV_SYMBOL_BATTERY_3);
                    break;
                case 50:
                    lv_label_set_text(objects.lvble_battery,
                                      LV_SYMBOL_BATTERY_2);
                    break;
                case 25:
                    lv_label_set_text(objects.lvble_battery,
                                      LV_SYMBOL_BATTERY_1);
                    break;
                case 0:
                    lv_label_set_text(objects.lvble_battery,
                                      LV_SYMBOL_BATTERY_EMPTY);
                    lv_obj_set_style_text_color(objects.lvble_battery,
                                                lv_color_hex(0xFF0000),
                                                LV_STATE_DEFAULT);
                    break;
                default:
                    break;
            }
        }
        battery_number_last = battery_number;
        vTaskDelay(10000); /* 延时10秒 */
    }
}

#ifdef configASSERT

/**
 * @brief FreeRTOS assert failed function. 
 * 
 * @param pcFile File name
 * @param ulLine File line
 */
void vAssertCalled(const char *pcFile, unsigned int ulLine) {
    fprintf(stderr, "FreeRTOS assert failed. File: %s, line: %u. \n", pcFile,
            ulLine);
}

#endif /* configASSERT */

#if configCHECK_FOR_STACK_OVERFLOW

/**
 * @brief The application stack overflow hook is called when a stack overflow is detected for a task.
 *
 * @param xTask the task that just exceeded its stack boundaries.
 * @param pcTaskName A character string containing the name of the offending task.
 */
void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName) {
    UNUSED(xTask);
    fprintf(stderr, "Stack overflow! Taskname: %s. \n", pcTaskName);
}

#endif /* configCHECK_FOR_STACK_OVERFLOW */

#if configUSE_MALLOC_FAILED_HOOK

/**
 * @brief This hook function is called when allocation failed.
 * 
 */
void vApplicationMallocFailedHook(void) {
    fprintf(stderr, "FreeRTOS malloc failed! \n");
}

#endif /* configUSE_MALLOC_FAILED_HOOK */