/*
 * io_routines.c
 *
 *  Created on: 26 lis 2017
 *      Author: speedfight
 */

#include "io_routines.h"


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){

	switch(GPIO_Pin){
		case(GPIO_PIN_0):
				btn_1++;
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4);
				break;

		case(GPIO_PIN_1):
				btn_2++;
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4);
				break;

		case(GPIO_PIN_2):
				btn_3++;
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4);
				break;

		case(GPIO_PIN_3):
				rtc_get_all_time_registers();
			 	show_time_num(rtc_values.hours, rtc_values.minutes, rtc_values.seconds, rtc_values.date, rtc_values.months, rtc_values.year +2017);
				break;
	}
}

