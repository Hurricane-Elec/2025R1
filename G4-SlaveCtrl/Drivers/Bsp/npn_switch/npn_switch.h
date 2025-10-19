/**
 * @file npn_switch.h
 * @author CV-Engineer-Chen
 * @brief npn型接近开关
 * @version 0.1
 * @date 2025-03-09
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef __NPN_SWITCH_H
#define __NPN_SWITCH_H

#include <CSP_Config.h>

#define PROXIMITY_SWITCH_OUT_PORT E
#define PROXIMITY_SWITCH_OUT_PIN  GPIO_PIN_5
#define PROXIMITY_SWITCH_OUT_PULL GPIO_NOPULL

#define PROXIMITY_OUT_SWITCH()                                                 \
    HAL_GPIO_ReadPin(CSP_GPIO_PORT(PROXIMITY_SWITCH_OUT_PORT),                 \
                     PROXIMITY_SWITCH_OUT_PIN)

/* 触发光电IO的电平 */
#define PROXIMITY_OUT_SWITCH_TOUCHED GPIO_PIN_SET

void npn_switch_init(void);

#endif // !__NPN_SWITCH_H
