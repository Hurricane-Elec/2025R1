/**
 * @file    bsp.c
 * @author  Deadline039
 * @brief   Bsp layer initialize.
 * @version 1.0
 * @date    2024-09-18
 */

#include <bsp.h>

/**
 * @brief Bsp layer initiallize.
 *
 */
void bsp_init(void) {
    HAL_Init();
    system_clock_config();
    system_enable_cache();
    mpu_memory_protection();
    delay_init(480);
    usart1_init(115200);
    usart3_init(38400);
    led_init();
    key_init();
    sdram_init();
    i2c2_init(100, 0x00, I2C_ADDRESSINGMODE_7BIT);
    keyboard_init();
    qspi_init(QSPI_CLOCK_MODE_3, 32 * 1024 * 1024);
}

#ifdef USE_FULL_ASSERT

#include <stdio.h>

/**
 * @brief HAL assert failed.
 *
 * @param file File name.
 * @param line Line.
 */
void assert_failed(uint8_t *file, uint32_t line) {
    fprintf(stderr, "HAL assert failed. In file: %s, line: %u. \n", file, line);
}

#endif /* USE_FULL_ASSERT */