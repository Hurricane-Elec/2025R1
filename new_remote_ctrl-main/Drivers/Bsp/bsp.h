/**
 * @file    bsp.h
 * @author  Deadline039
 * @brief   Bsp layer export interface.
 * @version 1.0
 * @date    2024-09-18
 */

#ifndef __BSP_H
#define __BSP_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <CSP_Config.h>

#include "./core/bsp_core.h"
#include "./core/core_delay.h"
#include "./core/core_mpu.h"
#include "./key/key.h"
#include "./led/led.h"
#include "./sdram/sdram.h"
#include "./lcd/lcd.h"
#include "./sd_card/sdmmc_sdcard.h"
#include "./at24cxx/at24cxx.h"
#include "./touch/touch.h"
#include "./keyboard/keyboard.h"
#include "./rs_adc/rs_adc.h"
#include "./w25qxx/w25qxx.h"
#include "./battery_monitor/battery_monitor.h"

void bsp_init(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __BSP_H */