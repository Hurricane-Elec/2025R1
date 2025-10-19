/**
 * @file    keyboard.c
 * @author  Deadline039
 * @brief   16 键矩阵键盘驱动
 * @version 1.0
 * @date    2023-11-05
 * @note    +-------+-------+-------+-------+-------+
 *          | IO    |  PC4  |  PC5  |  PC6  |  PC7  |
 *          +-------+-------+-------+-------+-------+
 *          | PB12  |   1   |   2   |   3   |   4   |
 *          +-------+-------+-------+-------+-------+
 *          | PB13  |   5   |   6   |   7   |   8   |
 *          +-------+-------+-------+-------+-------+
 *          | PB14  |   9   |  10   |  11   |  12   |
 *          +-------+-------+-------+-------+-------+
 *          | PB15  |  13   |  14   |  15   |  16   |
 *          +-------+-------+-------+-------+-------+
 *
 */

#include "keyboard.h"

#include "../core/core_delay.h"

/**
 * @brief 矩阵键盘初始化
 *
 */
void keyboard_init(void) {
    GPIO_InitTypeDef gpio_init_struct = {
        .Pull = GPIO_PULLUP,
        .Speed = GPIO_SPEED_FREQ_HIGH,
        .Mode = GPIO_MODE_OUTPUT_OD,
    };

    CSP_GPIO_CLK_ENABLE(KEYBOARD_ROW_PORT);
    gpio_init_struct.Pin = KEYBOARD_ROW_PIN;
    HAL_GPIO_Init(KEYBOARD_ROW_GPIO_PORT, &gpio_init_struct);

    CSP_GPIO_CLK_ENABLE(KEYBOARD_COL_PORT);
    gpio_init_struct.Pin = KEYBOARD_COL_PIN;
    HAL_GPIO_Init(KEYBOARD_COL_GPIO_PORT, &gpio_init_struct);
}

/**
 * @brief 矩阵键盘扫描
 *
 * @return 按下的按键, 1-16
 */
uint32_t keyboard_scan(void) {
    uint32_t col_bits, row_bits;
    /* 列置低, 行置高 */
    HAL_GPIO_WritePin(KEYBOARD_COL_GPIO_PORT, KEYBOARD_COL_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(KEYBOARD_ROW_GPIO_PORT, KEYBOARD_ROW_PIN, GPIO_PIN_SET);
    /* 等待 GPIO 状态更新 */
    delay_ms(1);

    /* 读行 */
    row_bits = ((~KEYBOARD_ROW_GPIO_PORT->IDR) & KEYBOARD_ROW_PIN) >>
               KEYBOARD_ROW_START_PIN;

    if (row_bits == 0) {
        /* 无按键按下, 返回 */
        return 0;
    }

    /* 消抖 */
    delay_ms(15);
    /* 再次读行 */
    row_bits = ((~KEYBOARD_ROW_GPIO_PORT->IDR) & KEYBOARD_ROW_PIN) >>
               KEYBOARD_ROW_START_PIN;
    if (row_bits == 0) {
        /* 说明上次电平变化是抖动, 返回 */
        return 0;
    }

    if (row_bits & (row_bits - 1)) {
        /* 按下两个及以上按键, 避免鬼影读到其他按键按下, 直接返回
         * 原理是检测是否有两个以上的位为 1.  
         * 如果只有 1 位是 1, 减掉之后最高位的 1 会变成 0 (例如 100 - 1 = 99),
         * 此时在与自身按位与的结果是 0. 如果其他位有 1, 按位与的结果不是 0,
         * 就会进入此判断分支 */
        return 0;
    }

    /* 列置高, 行置低 */
    HAL_GPIO_WritePin(KEYBOARD_COL_GPIO_PORT, KEYBOARD_COL_PIN, GPIO_PIN_SET);
    HAL_GPIO_WritePin(KEYBOARD_ROW_GPIO_PORT, KEYBOARD_ROW_PIN, GPIO_PIN_RESET);
    /* 等待 GPIO 状态更新 */
    delay_ms(1);

    /* 读取列 */
    col_bits = ((~KEYBOARD_COL_GPIO_PORT->IDR) & KEYBOARD_COL_PIN) >>
               KEYBOARD_COL_START_PIN;
    if (col_bits == 0) {
        /* 错误状态, 返回 */
        return 0;
    }
    if (col_bits & (col_bits - 1)) {
        /* 多个按键按下, 原理见上 */
        return 0;
    }

    /* 获取按键位置. POSITION_VAL 用于获取高位 1 的位置 */
    uint32_t row_num = POSITION_VAL(row_bits);
    uint32_t col_num = POSITION_VAL(col_bits) + 1;

    return 4 * row_num + col_num;
}