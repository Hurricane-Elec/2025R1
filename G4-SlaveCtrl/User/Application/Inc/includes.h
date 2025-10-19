/**
 * @file    includes.h
 * @author  Deadline039
 * @brief   Include files
 * @version 1.0
 * @date    2024-04-03
 */

#ifndef __INCLUDES_H
#define __INCLUDES_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <bsp.h>

#include "FreeRTOS.h"
#include "SEGGER_SYSVIEW.h"
#include "task.h"
#include "logger/logger.h"

#include <stdio.h>
#include <stdbool.h>

void freertos_start(void);

/**
 * @defgroup sub-pub
 * @{
 */
extern TaskHandle_t sub_pub_task_handle;
void sub_pub_task(void *pvParameters);

void pub_to_chassis(float *speedx, float *speedy, float *speedw);
void pub_to_chassis_halt(bool *chassis_halt);
void pub_to_chassis_world_angle(float **angle);
void pub_to_friction(float *speed5065);
void pub_to_friction_flag(uint8_t *flag);
/**
 * @}sub-pub 
 * 
 */

/**
 * @defgroup chassis
 * @{
 */
void chassis_init(void); /* 在rtos—task后调用 */
/**
 * @} chassis
 * 
 */

/**
 * @brief shoot_ball
 * 
 */
void shoot_machine_init(void);
/**
 * @} shoot_ball 
 * 
 */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __INCLUDES_H */
