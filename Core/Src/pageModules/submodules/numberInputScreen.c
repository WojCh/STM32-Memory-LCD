/*
 * numberInputScreen.c
 *
 *  Created on: 19 lip 2022
 *      Author: wojch
 */

#ifndef SRC_PAGEMODULES_SUBMODULES_NUMBERINPUTSCREEN_C_
#define SRC_PAGEMODULES_SUBMODULES_NUMBERINPUTSCREEN_C_

#include "numberInputScreen.h"

#include "fonts/zekton84.h"
#include <fonts/zekton45.h>
uint8_t curPosition = 0;
uint8_t val[3] = {0, 0, 0};
uint16_t cursorXarr[5] = {20, 85, 170, 235, 315};

static void setDefaultClbcks(void){
// exit edit mode
	btn_B3.onSinglePressHandler = &exit;
//	cursor left
	btn_B2.onSinglePressHandler = &cursorPrev;
//	btn_B2.onContinuousShortPressHandler = &cursorPrev;
//	accept
	btn_B1.onSinglePressHandler = &accept;
//	reduce
	btn_BA.onSinglePressHandler = &decrement;
//	cursor right
	btn_BB.onSinglePressHandler = &cursorNext;
//	btn_BB.onContinuousShortPressHandler = &cursorNext;
//	increase
	btn_BC.onSinglePressHandler = &increment;
}

void numberInputConfigure(void);
void numberInputSetup(void){
	setDefaultClbcks();
	val[0] = RtcTime.Hours;
	val[1] = RtcTime.Minutes;
	val[2] = RtcTime.Seconds;
}

void numberInputMain(void){
		char bufStr[30] = {0};
		sprintf(&bufStr, "%02d", val[0]);
		lcdPutStr(20, 76, bufStr, zekton84font);
		sprintf(&bufStr, "%02d", val[1]);
		lcdPutStr(170, 76, bufStr, zekton84font);
		sprintf(&bufStr, "%02d", RtcTime.Seconds);
		lcdPutStr(315, 76, bufStr, zekton45font);
		lcdHLine(cursorXarr[curPosition], cursorXarr[curPosition]+60, 175, 1);
		lcdHLine(cursorXarr[curPosition], cursorXarr[curPosition]+60, 176, 1);
		lcdHLine(cursorXarr[curPosition], cursorXarr[curPosition]+60, 177, 1);
}

void cursorNext(void){
	if(curPosition < 4)	curPosition++;
	else curPosition = 0;
}
void cursorPrev(void){
	if(curPosition > 0)	curPosition--;
	else curPosition = 4;
}
void increment(void){
	switch(curPosition){
		case 0:
			if(val[0] < 13 ) val[0]+=10;
			else val[0] = 20;
			break;
		case 1:
			if(val[0] <= 23 ) val[0]++;
			else val[0] = 0;
			break;
		case 2:
			if(val[1] < 49 ) val[1]+=10;
			else val[1] = 0;
			break;
		case 3:
			if(val[1] < 59 ) val[1]++;
			else val[1] = 0;
			break;
		case 4:
			val[2] = 0;
			break;
	}
}
void decrement(void){
	switch(curPosition){
			case 0:
				if(val[0] > 9 ) val[0]-=10;
				else val[0] = 0;
				break;
			case 1:
				if(val[0] > 0 ) val[0]--;
				else val[0] = 23;
				break;
			case 2:
				if(val[1] > 9 ) val[1]-=10;
				else val[1] = 0;
				break;
			case 3:
				if(val[1] > 0 ) val[1]--;
				else val[1] = 59;
				break;
			case 4:
//				val[2] = 0;
				RtcTime.Seconds = 0;
				if (HAL_RTC_SetTime(&hrtc, &RtcTime, RTC_FORMAT_BIN) != HAL_OK)
					{
						Error_Handler();
					}
				break;
		}
}
void exit(void){
	applySelectedScreen();
}
void accept(void){
	RtcTime.Hours = val[0];
	RtcTime.Minutes = val[1];
//	RtcTime.Seconds = val[2];
	RtcTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
	RtcTime.StoreOperation = RTC_STOREOPERATION_RESET;
	if (HAL_RTC_SetTime(&hrtc, &RtcTime, RTC_FORMAT_BIN) != HAL_OK)
	{
	Error_Handler();
	}
//	sDate.WeekDay = RTC_WEEKDAY_MONDAY;
//	sDate.Month = RTC_MONTH_JANUARY;
//	sDate.Date = 1;
//	sDate.Year = 22;
//
//	if (HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BIN) != HAL_OK)
//	{
//	Error_Handler();
//	}
	exit();
}

struct Module numberInputModule = {"Number input", &numberInputSetup, &numberInputMain, NULL};


#endif /* SRC_PAGEMODULES_SUBMODULES_NUMBERINPUTSCREEN_C_ */
