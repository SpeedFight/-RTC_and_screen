/*
 * text.c
 *
 *  Created on: 12 lis 2017
 *      Author: speedfight
 */

#include "text.h"

char row1[9];
char  row2[11];

void show_time(char* hour, char* minute, char* second, char* day, char* month, char* year)
{

	memset(row1, '\0', sizeof(row1));
	memset(row2, '\0', sizeof(row2));

    strcat(row1, hour);
    strcat(row1, ":");
    strcat(row1, minute);
    strcat(row1, ":");
    strcat(row1, second);

    strcat(row2, day);
    strcat(row2, ".");
    strcat(row2, month);
    strcat(row2, ".");
    strcat(row2, year);

	lcd_clear();

	lcd_draw_text(1, 4*3, row1);
	lcd_draw_text(3, 4*2, row2);

	lcd_copy();
}

void show_time_num(uint8_t hour, uint8_t minute, uint8_t second, uint8_t day, uint8_t month, uint16_t year)
{
	memset(row1, '\0', sizeof(row1));
	memset(row2, '\0', sizeof(row2));

	char tmp[5];

	memset(tmp, '\0', sizeof(tmp));
	if(hour<10){
		strcat(row1, "0");
	}
	strcat(row1, itoa(hour, tmp, 10));
    strcat(row1, ":");

	memset(tmp, '\0', sizeof(tmp));
	if(minute<10){
		strcat(row1, "0");
	}
	strcat(row1, itoa(minute, tmp, 10));
    strcat(row1, ":");

	memset(tmp, '\0', sizeof(tmp));
	if(second<10){
		strcat(row1, "0");
	}
	strcat(row1, itoa(second, tmp, 10));

	memset(tmp, '\0', sizeof(tmp));
	if(day<10){
		strcat(row2, "0");
	}
	strcat(row2, itoa(day, tmp, 10));
    strcat(row2, ":");

	memset(tmp, '\0', sizeof(tmp));
	if(month<10){
		strcat(row2, "0");
	}
	strcat(row2, itoa(month, tmp, 10));
    strcat(row2, ":");

	memset(tmp, '\0', sizeof(tmp));
	strcat(row2, itoa(year, tmp, 10));

	lcd_clear();

	lcd_draw_text(1, 4*3, row1);
	lcd_draw_text(3, 4*2, row2);

	lcd_copy();

}

void update_screen(){
	show_time_num(rtc_values.hours, rtc_values.minutes, rtc_values.seconds, rtc_values.date, rtc_values.months, rtc_values.year +2017);
}
