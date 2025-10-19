/**
 * @file    rs_adc.c
 * @author  ash
 * @brief   adc 摇杆采样
 * @version 0.1
 * @date    2025-04-12
 */

#include "rs_adc.h"

#include "FreeRTOS.h"
#include "semphr.h"

#include "../core/core_delay.h"

static ADC_HandleTypeDef rs_adc_handle;
static DMA_HandleTypeDef rs_dma_handle;
static SemaphoreHandle_t rs_conv_cplt_semp;

/* DMA 缓存区不能加在 DTCM 区 */
__attribute__((section(".RAM_AXI"))) uint16_t g_rs_adc_buf[RS_ADC_BUF_SIZE];

/**
 * @brief ADC 采样通道设定
 *
 * @param hadc ADC 句柄
 * @param ch 通道号，ADC_CHANNEL_0 ~ ADC_CHANNEL_17
 * @param rank 多通道采集时需要设置的采集编号
 *  @arg    假设定义 channel1 的 rank=1,channel2 的 rank=2,
 *          那么对应你在 DMA 缓存空间的变量数组，
 *          AdcDMA [0] 就 i 是 channel1 的转换结果，AdcDMA [1] 就是通道 2 的转换结果，
 *          单通道 DMA 设置为 ADC_REGULAR_RANK_1
 *  @arg ADC_REGULAR_RANK_1 ~ ADC_REGULAR_RANK_16
 * @param stime 采样时间
 *   @arg ADC_SAMPLETIME_xCYCLES_y, x.y 个 ADC 时钟周期
 */
static void adc_channel_set(ADC_HandleTypeDef *hadc, uint32_t ch,
                            uint32_t rank) {
    ADC_ChannelConfTypeDef adc_ch_conf;

    adc_ch_conf.Channel = ch;                              /* 通道 */
    adc_ch_conf.Rank = rank;                               /* 序列 */
    adc_ch_conf.SamplingTime = ADC_SAMPLETIME_810CYCLES_5; /* 采样周期 */
    adc_ch_conf.SingleDiff = ADC_SINGLE_ENDED;
    adc_ch_conf.OffsetNumber = ADC_OFFSET_NONE;
    adc_ch_conf.Offset = 0;
    adc_ch_conf.OffsetRightShift = DISABLE;
    adc_ch_conf.OffsetSignedSaturation = DISABLE;
    HAL_ADC_ConfigChannel(hadc, &adc_ch_conf); /* 通道配置 */
}

/**
 * @brief 摇杆 ADC 初始化
 * 
 */
void rs_init(void) {
    /* ADC1 初始化 */
    rs_conv_cplt_semp = xSemaphoreCreateBinary(); /* 创建一个二值信号量 */

    rs_adc_handle.Instance = RS_ADC;

    rs_adc_handle.Init.ClockPrescaler = ADC_CLOCK_ASYNC_DIV4;
    /* 这里开启了多个通道 开启扫描 */
    rs_adc_handle.Init.ScanConvMode = ADC_SCAN_ENABLE;
    rs_adc_handle.Init.EOCSelection = ADC_EOC_SINGLE_CONV; /* 关闭 EOC 中断 */
    rs_adc_handle.Init.LowPowerAutoWait = DISABLE; /* 自动低功耗模式关闭 */
    rs_adc_handle.Init.OversamplingMode = DISABLE; /* 过采样模式关闭 */
    rs_adc_handle.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
    rs_adc_handle.Init.ContinuousConvMode = ENABLE; /* 开启连续转换模式 */
    /* DMA 循环接收 */
    rs_adc_handle.Init.ConversionDataManagement =
        ADC_CONVERSIONDATA_DMA_CIRCULAR;
    rs_adc_handle.Init.NbrOfConversion = 4; /* 设置扫描模式下的扫描个数 */
    rs_adc_handle.Init.NbrOfDiscConversion = 1;
    rs_adc_handle.Init.ExternalTrigConv =
        ADC_SOFTWARE_START; /* 软件触发 ADC 转换，但是是连续采样也就是会一直采样 */
    rs_adc_handle.Init.Resolution = ADC_RESOLUTION_16B; /* 16 位分辨率 */
    rs_adc_handle.Init.Overrun =
        ADC_OVR_DATA_OVERWRITTEN; /* 转换溢出后就将寄存器的值覆盖掉 */
    rs_adc_handle.Init.LeftBitShift = 0;

    if (HAL_ADC_Init(&rs_adc_handle) != HAL_OK) {
        return;
    }

    HAL_ADCEx_Calibration_Start(&rs_adc_handle, ADC_CALIB_OFFSET,
                                ADC_SINGLE_ENDED); /* 校准 ADC */
    /* DMA 转运通道配置 */
    adc_channel_set(&rs_adc_handle, LEFT_X_ADC_CHANNEL, ADC_REGULAR_RANK_1);
    adc_channel_set(&rs_adc_handle, LEFT_Y_ADC_CHANNEL, ADC_REGULAR_RANK_2);
    adc_channel_set(&rs_adc_handle, RIGHT_X_ADC_CHANNEL, ADC_REGULAR_RANK_3);
    adc_channel_set(&rs_adc_handle, RIGHT_Y_ADC_CHANNEL, ADC_REGULAR_RANK_4);

    /* 初始化 z 轴, 普通 GPIO 输入 */
    GPIO_InitTypeDef gpio_init_struct = {.Mode = GPIO_MODE_INPUT,
                                         .Pull = GPIO_PULLUP,
                                         .Speed = GPIO_SPEED_FREQ_HIGH};

    LEFT_Z_GPIO_ENABLE();
    gpio_init_struct.Pin = LEFT_Z_GPIO_PIN;
    HAL_GPIO_Init(LEFT_Z_GPIO_PORT, &gpio_init_struct);

    RIGHT_Z_GPIO_ENABLE();
    gpio_init_struct.Pin = RIGHT_Z_GPIO_PIN;
    HAL_GPIO_Init(RIGHT_Z_GPIO_PORT, &gpio_init_struct);

    HAL_ADC_Start_DMA(&rs_adc_handle, (uint32_t *)g_rs_adc_buf,
                      RS_ADC_BUF_SIZE);
}

/**
 * @brief ADC 底层驱动
 * 
 * @param hadc ADC 句柄
 */
void HAL_ADC_MspInit(ADC_HandleTypeDef *hadc) {
    GPIO_InitTypeDef gpio_initure = {0};

    if (hadc->Instance == RS_ADC) {
        RS_ADC_ENABLE();
        RS_DMA_ENABLE();

        /* 设置 ADC 采样通道以及 IO 工作模式 */
        gpio_initure.Mode = GPIO_MODE_ANALOG;
        gpio_initure.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        gpio_initure.Pull = GPIO_NOPULL;

        LEFT_X_GPIO_ENABLE();
        gpio_initure.Pin = LEFT_X_GPIO_PIN;
        HAL_GPIO_Init(LEFT_X_GPIO_PORT, &gpio_initure);

        LEFT_Y_GPIO_ENABLE();
        gpio_initure.Pin = LEFT_Y_GPIO_PIN;
        HAL_GPIO_Init(LEFT_Y_GPIO_PORT, &gpio_initure);

        RIGHT_X_GPIO_ENABLE();
        gpio_initure.Pin = RIGHT_X_GPIO_PIN;
        HAL_GPIO_Init(RIGHT_X_GPIO_PORT, &gpio_initure);

        RIGHT_Y_GPIO_ENABLE();
        gpio_initure.Pin = RIGHT_Y_GPIO_PIN;
        HAL_GPIO_Init(RIGHT_Y_GPIO_PORT, &gpio_initure);

        rs_dma_handle.Instance = RS_DMA;
        /* DMA 转运方向，外设到存储器 */
        rs_dma_handle.Init.Direction = DMA_PERIPH_TO_MEMORY;
        rs_dma_handle.Init.Request = DMA_REQUEST_ADC1; /* 请求类型 */
        rs_dma_handle.Init.PeriphInc = DMA_PINC_DISABLE; /* 外设地址自增禁止 */
        rs_dma_handle.Init.MemInc = DMA_MINC_ENABLE; /* 存储器地址自增使能 */
        rs_dma_handle.Init.PeriphDataAlignment =
            DMA_PDATAALIGN_HALFWORD; /* 外设数据位长度 */
        rs_dma_handle.Init.MemDataAlignment =
            DMA_MDATAALIGN_HALFWORD;            /* 存储器数据位地址 */
        rs_dma_handle.Init.Mode = DMA_CIRCULAR; /* 循环模式 */
        rs_dma_handle.Init.FIFOMode =
            DMA_FIFOMODE_DISABLE; /* 禁止使用 FIFO 模式，也就是每个数据都会被传送 */
        rs_dma_handle.Init.Priority = DMA_PRIORITY_MEDIUM; /* DMA 中等优先级 */
        if (HAL_DMA_Init(&rs_dma_handle) != HAL_OK) {
            return;
        }

        __HAL_LINKDMA(&rs_adc_handle, DMA_Handle, rs_dma_handle);

        HAL_NVIC_SetPriority(RS_DMA_IRQn, RS_DMA_IT_PRIORITY, 0);
        HAL_NVIC_EnableIRQ(RS_DMA_IRQn);
    }
}

/**
 * @brief ADC DMA 中断服务函数
 * 
 */
void RS_DMA_IRQHandler(void) {
    HAL_DMA_IRQHandler(&rs_dma_handle);
}

/**
 * @brief ADC 转换完成中断回调函数
 * 
 * @param hadc ADC 句柄
 * @note 这里中断函数中释放信号量，对应的读取 ADC 的任务中应该使用 xSemaphoreTake
 *       来读取信号量，同时后面等待时间应该给 portMAX_DELAY. 等不到信号量会阻塞任务，不影响其他任务运行. 
 */
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc) {
    if (hadc->Instance == RS_ADC) {
        xSemaphoreGive(rs_conv_cplt_semp); /* 释放信号量 */
    }
}
/**
 * @brief ADC 死区限制
 * 
 * @param data 当前值
 * @param dead_zone 死区限制
 * @param data_level 采样级
 * @return 限制结果 
 */
static uint16_t rs_data_limit(uint16_t data, uint8_t dead_zone,
                              uint8_t data_level) {
    uint16_t data_piece = (uint16_t)((65535 - 655.3 * dead_zone * 2) /
                                     data_level); /* 计算每一份的值 */
    uint8_t data_res = 0;
    /* 死区限位 */
    if (data <= (32767 + 655.3 * dead_zone) &&
        data >= (32767 - 655.3 * dead_zone)) {
        data = 32767;
    }
    if (data > 32767) {
        data -= (uint16_t)(32767 + 655.3 * dead_zone);
        data_res = data / data_piece + data_level / 2;
        if (data_res > 48) {
            data_res = 49;
        }
        return data_res;
    } else if (data < 32676) {
        data = (uint16_t)((32767 - 655.3 * dead_zone) - data +
                          1000); /* 这里加 1000 来补偿 ADC 采样无法到底的问题 */
        data_res = data_level / 2 - data / data_piece;
        if (data_res <= 0) {
            data_res = 0;
        }
        return data_res;
    } else {
        return data_level / 2;
    }
}

/**
 * @brief 计算 100 次采样的平均值
 * 
 * @param data 
 * @param dead_zone 死区限制 如 8 就是上下 8% 总共 16 的死区
 * @param data_level 采样级
 * @note 推荐采样级为 40, 死区为 10. 采样级不能大于 45, 否则会导致采样值无法为零，可以增加 ADC 补偿来进一步提高采样级
 */
void rs_get_value(uint32_t *data, uint8_t dead_zone, uint8_t data_level) {
    xSemaphoreTake(rs_conv_cplt_semp, portMAX_DELAY);
    data[0] = 0;
    data[1] = 0;
    data[2] = 0;
    data[3] = 0;

    for (int i = 0; i < 100; i++) {
        data[0] +=
            rs_data_limit(g_rs_adc_buf[0 + i * 4], dead_zone, data_level);
        data[1] +=
            rs_data_limit(g_rs_adc_buf[1 + i * 4], dead_zone, data_level);
        data[2] +=
            rs_data_limit(g_rs_adc_buf[2 + i * 4], dead_zone, data_level);
        data[3] +=
            rs_data_limit(g_rs_adc_buf[3 + i * 4], dead_zone, data_level);
    }

    data[0] /= 100;
    data[1] /= 100;
    data[2] /= 100;
    data[3] /= 100;
}

/**
 * @brief 获取摇杆 z 轴
 * 
 * @return 摇杆是否按下 z 轴
 *  @retval - 0: 未按下
 *  @retval - 1: 左摇杆按下
 *  @retval - 2: 右摇杆按下
 * @note 两个摇杆同时按下只会响应左边的摇杆
 */
uint32_t rs_get_z(void) {
    if ((HAL_GPIO_ReadPin(LEFT_Z_GPIO_PORT, LEFT_Z_GPIO_PIN) == GPIO_PIN_SET) &&
        (HAL_GPIO_ReadPin(RIGHT_Z_GPIO_PORT, RIGHT_Z_GPIO_PIN) ==
         GPIO_PIN_SET)) {
        return 0;
    }

    delay_ms(10);

    if (HAL_GPIO_ReadPin(LEFT_Z_GPIO_PORT, LEFT_Z_GPIO_PIN) == GPIO_PIN_RESET) {
        return 1;
    }

    if (HAL_GPIO_ReadPin(RIGHT_Z_GPIO_PORT, RIGHT_Z_GPIO_PIN) ==
        GPIO_PIN_RESET) {
        return 2;
    }

    return 0;
}