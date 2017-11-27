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
#include "lcd.h"
#include "rtc.h"
#include "text.h"

volatile uint8_t btn_1, btn_2, btn_3, second_pass;

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);

void increment_minutes();
void increment_hours();
void increment_days();
void increment_months();
void increment_years();

typedef struct{
	positions pointer_position; //blinking cursor under value to change
	void (*inc_value)(void);
	void (*dec_value)(void);
}mode_routines_t;

extern const mode_routines_t callback_mode[];

#endif /* IO_ROUTINES_H_ */
