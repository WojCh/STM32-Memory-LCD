/*
 * numberInputScreen.c
 *
 *  Created on: 19 lip 2022
 *      Author: wojch
 */

#ifndef SRC_PAGEMODULES_SUBMODULES_TIMEINPUTSCREEN_C_
#define SRC_PAGEMODULES_SUBMODULES_TIMEINPUTSCREEN_C_

#include "timeInputScreen.h"



#include "fonts/fonts.h"
//#include "fonts/zekton84.h"
//#include <fonts/zekton45.h>
static uint8_t curPosition = 0;
static uint8_t valTimePos[3] = {0, 0, 0};
static uint16_t cursorXarr[5] = {20, 85, 170, 235, 315};

static void setDefaultClbcks(void){
// exit edit mode
	btn_B3.onSinglePressHandler = &exitScr;
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

void timeInputConfigure(void);
void timeInputSetup(void){
	setDefaultClbcks();
	valTimePos[0] = RtcTime.Hours;
	valTimePos[1] = RtcTime.Minutes;
	valTimePos[2] = RtcTime.Seconds;
}

void timeInputMain(void){
		char bufStr[30] = {0};
		sprintf(&bufStr, "%02d", valTimePos[0]);
		lcdPutStr(20, 76, bufStr, zekton84font);
		sprintf(&bufStr, "%02d", valTimePos[1]);
		lcdPutStr(170, 76, bufStr, zekton84font);
		sprintf(&bufStr, "%02d", RtcTime.Seconds);
		lcdPutStr(315, 76, bufStr, zekton45font);
		lcdHLine(cursorXarr[curPosition], cursorXarr[curPosition]+60, 175, 1);
		lcdHLine(cursorXarr[curPosition], cursorXarr[curPosition]+60, 176, 1);
		lcdHLine(cursorXarr[curPosition], cursorXarr[curPosition]+60, 177, 1);
}

static void cursorNext(void){
	if(curPosition < 4)	curPosition++;
	else curPosition = 0;
}
static void cursorPrev(void){
	if(curPosition > 0)	curPosition--;
	else curPosition = 4;
}
static void increment(void){
	switch(curPosition){
		case 0:
			if(valTimePos[0] < 13 ) valTimePos[0]+=10;
			else valTimePos[0] = 20;
			break;
		case 1:
			if(valTimePos[0] <= 23 ) valTimePos[0]++;
			else valTimePos[0] = 0;
			break;
		case 2:
			if(valTimePos[1] < 49 ) valTimePos[1]+=10;
			else valTimePos[1] = 0;
			break;
		case 3:
			if(valTimePos[1] < 59 ) valTimePos[1]++;
			else valTimePos[1] = 0;
			break;
		case 4:
			valTimePos[2] = 0;
			break;
	}
}
static void decrement(void){
	switch(curPosition){
			case 0:
				if(valTimePos[0] > 9 ) valTimePos[0]-=10;
				else valTimePos[0] = 0;
				break;
			case 1:
				if(valTimePos[0] > 0 ) valTimePos[0]--;
				else valTimePos[0] = 23;
				break;
			case 2:
				if(valTimePos[1] > 9 ) valTimePos[1]-=10;
				else valTimePos[1] = 0;
				break;
			case 3:
				if(valTimePos[1] > 0 ) valTimePos[1]--;
				else valTimePos[1] = 59;
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
static void exitScr(void){
	applySelectedScreen();
}
static void accept(void){
	RtcTime.Hours = valTimePos[0];
	RtcTime.Minutes = valTimePos[1];
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
	exitScr();
}

struct Module timeInputModule = {"Time input", &timeInputSetup, &timeInputMain, NULL};


#endif /* SRC_PAGEMODULES_SUBMODULES_TIMEINPUTSCREEN_C_ */
