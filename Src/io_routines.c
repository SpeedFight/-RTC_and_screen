/*
 * io_routines.c
 *
 *  Created on: 26 lis 2017
 *      Author: speedfight
 */

#include "io_routines.h"

extern TIM_HandleTypeDef htim14;
extern uint8_t pointer_pos;

void do_nothing(){
	return;
}

const mode_routines_t callback_mode[] = {
		{OFF_POS, do_nothing, do_nothing},
		{HOUR_POS, rtc_inc_hour, rtc_dec_hour},
		{MINUTE_POS, rtc_inc_min, rtc_dec_min},
		{DATE_POS, rtc_inc_day, rtc_dec_day},
		{MONTH_POS, rtc_inc_month, rtc_dec_month},
		{YEAR_POS, rtc_inc_year, rtc_dec_year},
};

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

		update_screen();
		set_pointer(pointer_pos);
				break;
	}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4);
	clear_pointer(pointer_pos);
}



