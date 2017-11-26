/*
 * rtc.c
 *
 *  Created on: 14 lis 2017
 *      Author: speedfight
 */

#include "rtc.h"

#define RTC_ADDRESS	0xA0


extern I2C_HandleTypeDef hi2c1;


static uint8_t BCD_to_dec(uint8_t bcd)
{
	return (bcd>>4)*10 + (bcd & 0xF);
}

void rtc_get_all_time_registers()
{
	uint8_t tmp_data[9];
	HAL_I2C_Mem_Read(&hi2c1, RTC_ADDRESS, RTC_CONTROL_REGISTER, 1, tmp_data, 8, 0xFFF);

	rtc_values.control_status = tmp_data[RTC_CONTROL_REGISTER];
	rtc_values.hundr_seconds 	= BCD_to_dec(tmp_data[RTC_HUNDR_SECONDS_REGISTER]);
	rtc_values.seconds			= BCD_to_dec(tmp_data[RTC_SECONDS_REGISTER		]);
	rtc_values.minutes			= BCD_to_dec(tmp_data[RTC_MINUTES_REGISTER		]);
	rtc_values.hours			= BCD_to_dec(0x3F & tmp_data[RTC_HOURS_REGISTER			]);
	rtc_values.date				= BCD_to_dec(0x3F & tmp_data[RTC_YEAR_DATE_REGISTER		]);
	rtc_values.year				= BCD_to_dec(tmp_data[RTC_YEAR_DATE_REGISTER		] >> 6);
	rtc_values.months	 		= BCD_to_dec(0x1F & tmp_data[RTC_WEEKS_MONTHS_REGISTER	]);
	rtc_values.weekdays	 		= BCD_to_dec(tmp_data[RTC_WEEKS_MONTHS_REGISTER	] >> 5);
	rtc_values.timer			= tmp_data[RTC_TIMER_REGISTER			];
	rtc_values.alarm_control 	= tmp_data[RTC_ALARM_CONTROL_REGISTER];

}

void rtc_set(uint8_t *data,rtc_register reg)
{
	HAL_I2C_Mem_Write(&hi2c1, RTC_ADDRESS, reg, 1, data, 1, 0xFFF);
}

