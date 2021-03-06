/*
 * rtc.h
 *
 *  Created on: 14 lis 2017
 *      Author: speedfight
 */

#ifndef RTC_H_
#define RTC_H_

#include "stm32f0xx_hal.h"
#include "main.h"
#include "stdint.h"

typedef enum
{
	RTC_CONTROL_REGISTER		,
	RTC_HUNDR_SECONDS_REGISTER	,
	RTC_SECONDS_REGISTER		,
	RTC_MINUTES_REGISTER		,
	RTC_HOURS_REGISTER			,
	RTC_YEAR_DATE_REGISTER		,
	RTC_WEEKS_MONTHS_REGISTER	,
	RTC_TIMER_REGISTER			,
	RTC_ALARM_CONTROL_REGISTER
}rtc_register;

typedef struct
{
	uint8_t control_status	;
	uint8_t	hundr_seconds	;
	uint8_t	seconds			;
	uint8_t	minutes			;
	uint8_t	hours			;
	uint8_t	date			;
	uint8_t	months	;
	uint8_t	year		;
	uint8_t	weekdays	;
	uint8_t	timer			;
	uint8_t	alarm_control	;
}rtc_data_t;

rtc_data_t rtc_values;

void rtc_set(uint8_t *data,rtc_register reg);
uint8_t rtc_get_seconds();
void rtc_get_all_time_registers();
uint8_t* rtc_get_all_data();


void rtc_set_minutes(uint8_t newMinutes);
void rtc_set_hours(uint8_t newHours);
void rtc_set_days(uint8_t newDays);
void rtc_set_months(uint8_t newMonths);
void rtc_set_years(uint8_t newYears);

void rtc_inc_hour();
void rtc_inc_min();
void rtc_inc_day();
void rtc_inc_month();
void rtc_inc_year();

void rtc_dec_hour();
void rtc_dec_min();
void rtc_dec_day();
void rtc_dec_month();
void rtc_dec_year();



#endif /* RTC_H_ */
