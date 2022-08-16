/*
 * dateInputScreen.c
 *
 *  Created on: 19 lip 2022
 *      Author: wojch
 */

#ifndef SRC_PAGEMODULES_SUBMODULES_DATEPUTSCREEN_C_
#define SRC_PAGEMODULES_SUBMODULES_DATEINPUTSCREEN_C_

#include "dateInputScreen.h"

#include "fonts/zekton84.h"
#include <fonts/zekton45.h>
#include "fonts/zekton24.h"

static uint8_t curPosition = 0;
static uint8_t valDatePos[3] = {0, 0, 0};
static uint16_t cursorXarr[5] = {20, 85, 170, 235, 315};

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

void dateInputConfigure(void);
void dateInputSetup(void){
	setDefaultClbcks();
	valDatePos[0] = RtcTime.Hours;
	valDatePos[1] = RtcTime.Minutes;
	valDatePos[2] = RtcTime.Seconds;
}

void dateInputMain(void){
	char buffString[30] = {0};
	sprintf(&buffString, "September 2022");
	sprintf(&buffString, "%s %d", months[RtcDate.Month], 2000+RtcDate.Year);
	lcdPutStr(35+(*(zekton24font.font_Width)*(13-strlen(buffString))), 174, buffString, zekton24font);
	sprintf(&buffString, "%s %d", weekDays[RtcDate.WeekDay], RtcDate.Date);
	lcdPutStr(35+(*(zekton24font.font_Width)*(13-strlen(buffString))), 200, buffString, zekton24font);
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
			if(valDatePos[0] < 13 ) valDatePos[0]+=10;
			else valDatePos[0] = 20;
			break;
		case 1:
			if(valDatePos[0] <= 23 ) valDatePos[0]++;
			else valDatePos[0] = 0;
			break;
		case 2:
			if(valDatePos[1] < 49 ) valDatePos[1]+=10;
			else valDatePos[1] = 0;
			break;
		case 3:
			if(valDatePos[1] < 59 ) valDatePos[1]++;
			else valDatePos[1] = 0;
			break;
		case 4:
			valDatePos[2] = 0;
			break;
	}
}
static void decrement(void){
	switch(curPosition){
			case 0:
				if(valDatePos[0] > 9 ) valDatePos[0]-=10;
				else valDatePos[0] = 0;
				break;
			case 1:
				if(valDatePos[0] > 0 ) valDatePos[0]--;
				else valDatePos[0] = 23;
				break;
			case 2:
				if(valDatePos[1] > 9 ) valDatePos[1]-=10;
				else valDatePos[1] = 0;
				break;
			case 3:
				if(valDatePos[1] > 0 ) valDatePos[1]--;
				else valDatePos[1] = 59;
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
static void exit(void){
	applySelectedScreen();
}
static void accept(void){
//	RtcTime.Hours = val[0];
//	RtcTime.Minutes = val[1];
////	RtcTime.Seconds = val[2];
//	RtcTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
//	RtcTime.StoreOperation = RTC_STOREOPERATION_RESET;
//	if (HAL_RTC_SetTime(&hrtc, &RtcTime, RTC_FORMAT_BIN) != HAL_OK)
//	{
//	Error_Handler();
//	}
	RtcDate.Month = 7;
	RtcDate.Date = 25;
	RtcDate.Year = 22;
	RtcDate.WeekDay = zellerCongruence(RtcDate.Date, RtcDate.Month, 2000+RtcDate.Year);

	if (HAL_RTC_SetDate(&hrtc, &RtcDate, RTC_FORMAT_BIN) != HAL_OK)
	{
	Error_Handler();
	}
	exit();
}

struct Module dateInputModule = {"Date input", &dateInputSetup, &dateInputMain, NULL};


#endif /* SRC_PAGEMODULES_SUBMODULES_DATEINPUTSCREEN_C_ */
