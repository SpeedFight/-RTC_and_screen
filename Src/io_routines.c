/*
 * io_routines.c
 *
 *  Created on: 26 lis 2017
 *      Author: speedfight
 */

#include "io_routines.h"

extern TIM_HandleTypeDef htim14;
extern uint8_t pointer_pos;

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


				if(++rtc_values.seconds > 59){
					rtc_get_all_time_registers();
				}

		HAL_TIM_Base_Start_IT(&htim14);

		//update_screen();
		set_pointer(pointer_pos);
				break;
	}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4);
	clear_pointer(pointer_pos);
}

void increment_minutes(){
	if(++rtc_values.minutes > 59){
		rtc_values.minutes = 0;
	}
  rtc_set_minutes(rtc_values.minutes);
  update_screen();
}

void increment_hours(){
	if(++rtc_values.hours > 23){
		rtc_values.hours = 0;
	}
  rtc_set_hours(rtc_values.hours);
  update_screen();
}

void increment_days(){
	if(++rtc_values.date > 31){
		rtc_values.date = 1;
	}
 rtc_set_days(rtc_values.date);
 update_screen();
}

void increment_months(){
	if(++rtc_values.months > 12){
		rtc_values.months = 1;
	}
 rtc_set_months(rtc_values.months);
 update_screen();
}

void increment_years(){
	if(++rtc_values.year > 12){
		rtc_values.year = 1;
	}
 rtc_set_years(rtc_values.year);
 update_screen();
}



