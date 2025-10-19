/**
 * @file    memmap.c
 * @author  Deadline039
 * @brief   Memory pool.
 * @version 1.0
 * @date    2025-04-17
 */

#include "includes.h"

/* DTCM SRAM */
__attribute__((section(".RAM_DTCM"))) uint8_t DTCM_MEM[64 * 1024];
/* AXI SRAM */
__attribute__((section(".RAM_AXI"))) uint8_t AXI_MEM[256 * 1024];
/* SRAM1,2,3*/
__attribute__((section(".RAM_SRAM123"))) uint8_t SRAM123_MEM[256 * 1024];
/* SRAM4, 64KB */
__attribute__((section(".RAM_SRAM4"))) uint8_t SRAM4_MEM[64 * 1024];

/**
 * @brief 初始化内存池
 * 
 */
void mempool_init(void) {
    /* Enable D2SRAM clock. */
    __HAL_RCC_D2SRAM1_CLK_ENABLE();
    __HAL_RCC_D2SRAM2_CLK_ENABLE();
    __HAL_RCC_D2SRAM3_CLK_ENABLE();

    tlsf_create_with_pool(DTCM_MEM, sizeof(DTCM_MEM));
    tlsf_create_with_pool(AXI_MEM, sizeof(AXI_MEM));
    tlsf_create_with_pool(SRAM123_MEM, sizeof(SRAM123_MEM));
    tlsf_create_with_pool(SRAM4_MEM, sizeof(SRAM4_MEM));
}