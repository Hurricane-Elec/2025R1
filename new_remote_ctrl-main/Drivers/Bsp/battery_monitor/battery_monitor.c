/**
 * @file battery_monitor.c
 * @author ash
 * @brief 电池监测
 * @version 0.1
 * @date 2025-05-09
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "battery_monitor.h"

static ADC_HandleTypeDef bat_adc_handle;

/**
 * @brief 电池监测初始化
 * 
 */
void battery_monitor_init(void) {

    /* 设置 ADC 采样通道以及 IO 工作模式 */
    BAT_ADC_ENABLE();
    GPIO_InitTypeDef gpio_initure = {0};
    ADC_ChannelConfTypeDef bat_ch_conf = {0};

    gpio_initure.Mode = GPIO_MODE_ANALOG;
    gpio_initure.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    gpio_initure.Pull = GPIO_NOPULL;
    gpio_initure.Pin = BAT_GPIO_PIN;
    HAL_GPIO_Init(BAT_GPIO_PORT, &gpio_initure);

    bat_adc_handle.Instance = BAT_ADC;
    bat_adc_handle.Init.ClockPrescaler = ADC_CLOCK_ASYNC_DIV4;
    bat_adc_handle.Init.ScanConvMode = ADC_SCAN_DISABLE;
    bat_adc_handle.Init.LowPowerAutoWait = DISABLE;
    bat_adc_handle.Init.OversamplingMode = DISABLE;
    bat_adc_handle.Init.NbrOfConversion = 1;
    bat_adc_handle.Init.ContinuousConvMode = DISABLE; /* 不开启连续转换模式 */
    bat_adc_handle.Init.ExternalTrigConv = ADC_SOFTWARE_START;
    bat_adc_handle.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
    bat_adc_handle.Init.Resolution = ADC_RESOLUTION_12B;

    if (HAL_ADC_Init(&bat_adc_handle) != HAL_OK) {
        return;
    }

    bat_ch_conf.Channel = BAT_ADC_CHANNEL;
    bat_ch_conf.SamplingTime = ADC_SAMPLETIME_810CYCLES_5; /* 采样周期 */
    bat_ch_conf.SingleDiff = ADC_SINGLE_ENDED;
    bat_ch_conf.OffsetNumber = ADC_OFFSET_NONE;
    bat_ch_conf.Rank = ADC_REGULAR_RANK_1;
    bat_ch_conf.Offset = 0;

    HAL_ADC_ConfigChannel(&bat_adc_handle, &bat_ch_conf); /* 通道配置 */

    HAL_ADCEx_Calibration_Start(&bat_adc_handle, ADC_CALIB_OFFSET,
                                ADC_SINGLE_ENDED); /* 校准 ADC */
}

/**
 * @brief 获取ADC转换后电池的值
 * 
 * @return uint8_t 电池当前的电量 每25个点为一个分度。
 */
uint8_t battey_get_value(void) {
    float battey_number = 0;
    uint8_t bat_collect = 0;
    static uint8_t bat_precent = 107;
    HAL_ADC_Start(&bat_adc_handle);
    HAL_Delay(1);
    for (bat_collect = 0; bat_collect < 10; bat_collect++) {
        HAL_ADC_PollForConversion(&bat_adc_handle, 10);
        battey_number += HAL_ADC_GetValue(&bat_adc_handle);
    }
    battey_number = battey_number / 10 / 4095 * 3.3 * 2.781;
    if (battey_number < 8.40 && bat_precent > 100) {
        bat_precent = 100;
    } else if (battey_number < 7.80 && bat_precent > 75) {
        bat_precent = 75;
    } else if (battey_number < 7.20 && bat_precent > 50) {
        bat_precent = 50;
    } else if (battey_number < 6.60 && bat_precent > 25) {
        bat_precent = 25;
    } else if(battey_number <6.00){
        bat_precent = 0;
    }
    return bat_precent;
}