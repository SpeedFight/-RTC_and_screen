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


void show_time_num(uint8_t hour, uint8_t minute, uint8_t second, uint8_t day, uint8_t month, uint16_t year);
void show_time(char* hour, char* minute, char* second, char* day, char* month, char* year);
void update_screen();
#endif /* TEXT_H_ */
