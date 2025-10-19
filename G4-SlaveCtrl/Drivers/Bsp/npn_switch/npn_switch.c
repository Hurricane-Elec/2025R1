/**
 * @file npn_switch.c
 * @author CV-Engineer-Chen
 * @brief npn接近开关
 * @version 0.1
 * @date 2025-03-09
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "npn_switch.h"

/**
 * @brief 接近开关GPIO初始化
 * 
 * @return * void 
 */
void npn_switch_init(void) {
    GPIO_InitTypeDef gpio_initure = {0};
    CSP_GPIO_CLK_ENABLE(PROXIMITY_SWITCH_OUT_PORT);

    gpio_initure.Pin = PROXIMITY_SWITCH_OUT_PIN;
    gpio_initure.Mode = GPIO_MODE_INPUT;
    gpio_initure.Pull = PROXIMITY_SWITCH_OUT_PULL;
    gpio_initure.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(CSP_GPIO_PORT(PROXIMITY_SWITCH_OUT_PORT), &gpio_initure);
}