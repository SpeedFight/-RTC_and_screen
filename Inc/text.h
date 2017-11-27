/*
 * text.h
 *
 *  Created on: 12 lis 2017
 *      Author: speedfight
 */

#ifndef TEXT_H_
#define TEXT_H_

#include "lcd.h"
#include "stdint.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum{
	HOUR_POS = 4,
	MINUTE_POS = 7,

	DATE_POS = 3,
	MONTH_POS = 6,
	YEAR_POS = 11,
	OFF_POS = 100
}positions;


void show_time_num(uint8_t hour, uint8_t minute, uint8_t second, uint8_t day, uint8_t month, uint16_t year);
void show_time(char* hour, char* minute, char* second, char* day, char* month, char* year);
void update_screen();

void set_pointer(positions pos);
void clear_pointer(positions pos);
#endif /* TEXT_H_ */
