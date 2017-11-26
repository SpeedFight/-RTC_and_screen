/*
 * io_routines.h
 *
 *  Created on: 26 lis 2017
 *      Author: speedfight
 */

#ifndef IO_ROUTINES_H_
#define IO_ROUTINES_H_

#include "stm32f0xx_hal.h"
#include "main.h"
#include "stdint.h"

volatile uint8_t btn_1, btn_2, btn_3, second_pass;

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);

#endif /* IO_ROUTINES_H_ */
