/**
 * @file    devices.c
 * @author  Deadline039
 * @brief   各种芯片的实例
 * @version 0.1
 * @date    2025-01-26
 */

#include "includes.h"

at24cxx_handle_t at24c02_handle;
w25qxx_handle_t w25q256_handle = {.handle.hqspi = &qspi_handle};

/**
 * @brief 初始化 AT24C02
 *
 */
void at24c02_dev_init(void) {
    at24cxx_init(&at24c02_handle, &i2c2_handle, AT24C02, AT24CXX_ADDRESS_A000);
}

void w25q256_dev_init(void) {
    w25q256_handle.handle.hqspi = &qspi_handle;
    
}