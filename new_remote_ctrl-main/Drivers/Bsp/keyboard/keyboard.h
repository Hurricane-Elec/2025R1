/**
 * @file    keyboard.h
 * @author  Deadline039
 * @brief   16键矩阵键盘驱动
 * @version 0.2
 * @date    2023-11-05
 * @note    由于键盘的IO较多, 宏定义较麻烦, 所以这里就不定义IO口了
 */

#ifndef __KEYBOARD_H
#define __KEYBOARD_H

#include <CSP_Config.h>

/* Rows, 行定义 */
#define KEYBOARD_ROW_PORT      B
#define KEYBOARD_ROW_PIN       (GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15)
#define KEYBOARD_ROW_START_PIN 12U
#define KEYBOARD_ROW_GPIO_PORT CSP_GPIO_PORT(KEYBOARD_ROW_PORT)

/* Colums, 列定义 */
#define KEYBOARD_COL_PORT      C
#define KEYBOARD_COL_PIN       (GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7)
#define KEYBOARD_COL_START_PIN 4U
#define KEYBOARD_COL_GPIO_PORT CSP_GPIO_PORT(KEYBOARD_COL_PORT)

void keyboard_init(void);
uint32_t keyboard_scan(void);

#endif /* __KEYBOARD_H */