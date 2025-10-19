/**
 * @file battery_monitor.h
 * @author ash
 * @brief 电池监测
 * @version 0.1
 * @date 2025-05-09
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef __BATTERY_MONITOR_H
#define __BATTERY_MONITOR_H

#include "CSP_Config.h"


/* 电池分压IO */
#define BAT_ADC                 ADC2
#define BAT_ADC_ENABLE()        __HAL_RCC_ADC12_CLK_ENABLE()
#define BAT_GPIO_PORT           GPIOC
#define BAT_GPIO_PIN            GPIO_PIN_1
#define BAT_ADC_CHANNEL         ADC_CHANNEL_11

void battery_monitor_init(void);
uint8_t battey_get_value(void);


#endif /* __BATTERY_MONITOR_H */
