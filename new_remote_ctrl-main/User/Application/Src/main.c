/**
 * @file    main.c
 * @author  Deadline039
 * @brief   Main function files.
 * @version 1.0
 * @date    2024-07-29
 */

#include "includes.h"

void mempool_init(void);

/**
 * @brief The program entrance.
 *
 * @return Exit code.
 */
int main(void) {
    HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);
    mempool_init();

    bsp_init();
    usb_enable_cdc();
    if (usb_detect_msc()) {
        usb_app(NULL);
    }

    freertos_start();
    return 0;
}
