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

static uint8_t dec_to_BCD(uint8_t dec)
{
	return ((dec / 10) << 4) | (dec % 10);
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

void rtc_set(uint8_t *data, rtc_register reg){
	HAL_I2C_Mem_Write(&hi2c1, RTC_ADDRESS, reg, 1, data, 1, 0xFFF);
}

uint8_t rtc_get(rtc_register reg)
{
	static uint8_t tmp_data;
	HAL_I2C_Mem_Read(&hi2c1, RTC_ADDRESS, reg, 1, &tmp_data, 1, 0xFFF);
	return tmp_data;
}


void rtc_set_minutes(uint8_t newMinutes)
{
	if(newMinutes > 59){
		newMinutes = rtc_values.minutes = 0;
	}

	uint8_t tmp = dec_to_BCD(newMinutes);
	rtc_set(&tmp, RTC_MINUTES_REGISTER);
}

void rtc_set_hours(uint8_t newHours)
{
	if(newHours > 23){
		newHours = rtc_values.hours = 0;
	}

	uint8_t tmp = dec_to_BCD(newHours);
	tmp |= rtc_get(RTC_HOURS_REGISTER) & ~(0x3F);
	rtc_set(&tmp, RTC_HOURS_REGISTER);
}

void rtc_set_days(uint8_t newDays)
{
	if(newDays > 31 || newDays == 0){
		newDays = rtc_values.date =1;
	}
	uint8_t tmp = dec_to_BCD(newDays);
	tmp |= rtc_get(RTC_YEAR_DATE_REGISTER) & ~(0x3F);
	rtc_set(&tmp, RTC_YEAR_DATE_REGISTER);
}

void rtc_set_months(uint8_t newMonths)
{
	if(newMonths > 12 || newMonths == 0){
		newMonths = rtc_values.months = 1;
	}
	uint8_t tmp = dec_to_BCD(newMonths);
	tmp |= rtc_get(RTC_WEEKS_MONTHS_REGISTER) & ~(0x1F);
	rtc_set(&tmp, RTC_WEEKS_MONTHS_REGISTER);
}

void rtc_set_years(uint8_t newYears)
{
	rtc_values.year = newYears;
	uint8_t tmp = dec_to_BCD(newYears);
	tmp |= rtc_get(RTC_YEAR_DATE_REGISTER) & ~(0x3F);
	tmp = tmp << 5;
	rtc_set(&tmp, RTC_YEAR_DATE_REGISTER);
}

void rtc_inc_hour(){
	rtc_set_hours(++(rtc_values.hours));
}
void rtc_inc_min(){
	rtc_set_minutes(++(rtc_values.minutes));
}
void rtc_inc_day(){
	rtc_set_days(++(rtc_values.date));
}
void rtc_inc_month(){
	rtc_set_months(++(rtc_values.months));
}
void rtc_inc_year(){
	rtc_set_years(++(rtc_values.year));
}

void rtc_dec_hour(){
	rtc_set_hours(--(rtc_values.hours));
}
void rtc_dec_min(){
	rtc_set_minutes(--(rtc_values.minutes));
}
void rtc_dec_day(){
	rtc_set_days(--(rtc_values.date));
}
void rtc_dec_month(){
	rtc_set_months(--(rtc_values.months));
}
void rtc_dec_year(){
	rtc_set_years(--(rtc_values.year));
}
