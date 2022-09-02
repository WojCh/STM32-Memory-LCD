/*
 * dateInputScreen.c
 *
 *  Created on: 19 lip 2022
 *      Author: wojch
 */

#ifndef SRC_PAGEMODULES_SUBMODULES_DATEPUTSCREEN_C_
#define SRC_PAGEMODULES_SUBMODULES_DATEINPUTSCREEN_C_

#include "dateInputScreen.h"

//#include "fonts/zekton84.h"
//#include <fonts/zekton45.h>
//#include "fonts/zekton24.h"
#include "fonts/fonts.h"

static uint8_t curPosition = 0;
static uint8_t valDatePos[3] = {0, 0, 0};
static uint16_t cursorXarr[3] = {10, 210, 50};
static uint16_t cursorYarr[3] = {197, 197, 229};
static uint16_t cursorL[3] = {190, 85, 250};

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
	valDatePos[0] = RtcDate.Date;
	valDatePos[1] = RtcDate.Month;
	valDatePos[2] = RtcDate.Year;
}

void dateInputMain(void){
	char buffString[30] = {0};
	sprintf(&buffString, "September 2022");
	sprintf(&buffString, "%s %d", months[valDatePos[1]], 2000+valDatePos[2]);
	lcdPutStr(35+(*(zekton24font.font_Width)*(13-strlen(buffString))), 174, buffString, zekton24font);
	// here change weekday to dynamic zeller's congruence calculation
	sprintf(&buffString, "%s %d", weekDays[zellerCongruence(valDatePos[0], valDatePos[1], 2000+valDatePos[2])], valDatePos[0]);
	lcdPutStr(35+(*(zekton24font.font_Width)*(13-strlen(buffString))), 202, buffString, zekton24font);
	lcdHLine(cursorXarr[curPosition], cursorXarr[curPosition]+cursorL[curPosition], cursorYarr[curPosition], 1);
	lcdHLine(cursorXarr[curPosition], cursorXarr[curPosition]+cursorL[curPosition], cursorYarr[curPosition]+1, 1);
}

static void cursorNext(void){
	if(curPosition < 2)	curPosition++;
	else curPosition = 0;
}
static void cursorPrev(void){
	if(curPosition > 0)	curPosition--;
	else curPosition = 2;
}
static void increment(void){
	switch(curPosition){
		case 0:
			if(valDatePos[1] < 12 ) valDatePos[1]+=1;
			else valDatePos[1] = 1;
			break;
		case 1:
			if(valDatePos[2] <= 99 ) valDatePos[2]++;
			else valDatePos[2] = 0;
			break;
		case 2:
			if(valDatePos[0] < 31 ) valDatePos[0]+=1;
			else valDatePos[0] = 1;
			break;
	}
}
static void decrement(void){
	switch(curPosition){
			case 0:
				if(valDatePos[1] >= 1 ) valDatePos[1]-=1;
				else valDatePos[1] = 12;
				break;
			case 1:
				if(valDatePos[2] > 0 ) valDatePos[2]--;
				else valDatePos[2] = 100;
				break;
			case 2:
				if(valDatePos[0] > 1 ) valDatePos[0]-=1;
				else valDatePos[0] = 31;
				break;
		}
}
static void exit(void){
	applySelectedScreen();
}
static void accept(void){

	RtcDate.Month = valDatePos[1];
	RtcDate.Date = valDatePos[0];
	RtcDate.Year = valDatePos[2];
	RtcDate.WeekDay = zellerCongruence(valDatePos[0], valDatePos[1], 2000+valDatePos[2]);

	if (HAL_RTC_SetDate(&hrtc, &RtcDate, RTC_FORMAT_BIN) != HAL_OK)
	{
	Error_Handler();
	}
	exit();
}

struct Module dateInputModule = {"Date input", &dateInputSetup, &dateInputMain, NULL};


#endif /* SRC_PAGEMODULES_SUBMODULES_DATEINPUTSCREEN_C_ */
