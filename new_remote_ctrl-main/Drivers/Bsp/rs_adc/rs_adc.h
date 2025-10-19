/**
 * @file    rs_adc.h
 * @author  ash
 * @brief   adc 摇杆采样
 * @version 0.1
 * @date    2025-04-12
 */

#ifndef __RS_ADC_H
#define __RS_ADC_H

#include <CSP_Config.h>

#define RS_ADC                ADC1
#define RS_ADC_ENABLE()       __HAL_RCC_ADC12_CLK_ENABLE()

#define RS_DMA                DMA2_Stream7
#define RS_DMA_ENABLE()       __HAL_RCC_DMA2_CLK_ENABLE()
#define RS_DMA_IRQn           DMA2_Stream7_IRQn
#define RS_DMA_IRQHandler     DMA2_Stream7_IRQHandler
#define RS_DMA_IT_PRIORITY    7

#define RS_ADC_BUF_SIZE       400

/*******************************************************************************
 * @defgroup 左摇杆
 * @{
 */

#define LEFT_X_GPIO_PORT      GPIOA
#define LEFT_X_GPIO_ENABLE()  __HAL_RCC_GPIOA_CLK_ENABLE()
#define LEFT_X_GPIO_PIN       GPIO_PIN_3
#define LEFT_X_ADC_CHANNEL    ADC_CHANNEL_15

#define LEFT_Y_GPIO_PORT      GPIOA
#define LEFT_Y_GPIO_ENABLE()  __HAL_RCC_GPIOA_CLK_ENABLE()
#define LEFT_Y_GPIO_PIN       GPIO_PIN_2
#define LEFT_Y_ADC_CHANNEL    ADC_CHANNEL_14

#define LEFT_Z_GPIO_PORT      GPIOB
#define LEFT_Z_GPIO_ENABLE()  __HAL_RCC_GPIOB_CLK_ENABLE()
#define LEFT_Z_GPIO_PIN       GPIO_PIN_3

/**
 * @}
 */

/*******************************************************************************
 * @defgroup 右摇杆
 * @{
 */

#define RIGHT_X_GPIO_PORT     GPIOA
#define RIGHT_X_GPIO_ENABLE() __HAL_RCC_GPIOA_CLK_ENABLE()
#define RIGHT_X_GPIO_PIN      GPIO_PIN_5
#define RIGHT_X_ADC_CHANNEL   ADC_CHANNEL_19

#define RIGHT_Y_GPIO_PORT     GPIOA
#define RIGHT_Y_GPIO_ENABLE() __HAL_RCC_GPIOA_CLK_ENABLE()
#define RIGHT_Y_GPIO_PIN      GPIO_PIN_4
#define RIGHT_Y_ADC_CHANNEL   ADC_CHANNEL_18

#define RIGHT_Z_GPIO_PORT     GPIOB
#define RIGHT_Z_GPIO_ENABLE() __HAL_RCC_GPIOB_CLK_ENABLE()
#define RIGHT_Z_GPIO_PIN      GPIO_PIN_4

/**
 * @}
 */

extern uint16_t g_rs_adc_buf[RS_ADC_BUF_SIZE];

void rs_init(void);
void rs_get_value(uint32_t *data, uint8_t dead_zone, uint8_t data_level);
uint32_t rs_get_z(void);

#endif /* __RS_ADC_H */
