/*
 * watchfaceModule.c
 *
 *  Created on: 25 kwi 2022
 *      Author: wojch
 *
 *      module displaying watchfaces
 */
#include "watchfaceModule.h"
#include "../utils/timerUtils.h"
#include "btns.h"

// fonts
#include "fonts/fonts.h"

uint8_t singlePressCount = 0;
uint8_t shortPressCount = 0;
uint8_t longPressCount = 0;
uint8_t doublePressCount = 0;
uint8_t releaseCount = 0;
uint8_t holdCyclicCount = 0;

void add_counter(Button_Event event){
	switch (event) {
	        case BUTTON_EVENT_DOWN:
	        	singlePressCount++;
	            break;
	        case BUTTON_EVENT_SHORT_PRESS:
	        	shortPressCount++;
	            break;
	        case BUTTON_EVENT_DOUBLE_PRESS:
	        	doublePressCount++;
	            break;
	        case BUTTON_EVENT_LONG_PRESS:
	        	longPressCount++;
	            break;
	        case BUTTON_EVENT_RELEASE:
	        	releaseCount++;
	            break;
	        case BUTTON_EVENT_HOLD_CYCLIC:
	        	holdCyclicCount++;
	            break;
	        default:
	            break;
	    }
}

static void setDefaultClbcks(void){
	// module callbacks
	btn_BA.onSinglePressHandler = &nextScreen;
	btn_BC.onSinglePressHandler = &prevScreen;

	//new button handlers
	button_set_hold_cycle_time(1, 1000);
	button_set_long_press_time(1, 500);
	button_set_handler(1, add_counter, NULL);
}

static void setTimeAction(void){
	guiApplyView(&timeInputModule);
}
static void setDateAction(void){
	guiApplyView(&dateInputModule);
}

void faceSetup(void){
	setDefaultClbcks();
}


void faceMain(void){

	char tempStr2[30] = {0};
	sprintf(&tempStr2, "short: %d, long: %d", shortPressCount, longPressCount);
	lcdPutStr(5, 5, tempStr2, font_12_zekton);
	sprintf(&tempStr2, "double: %d, release: %d", doublePressCount, releaseCount);
	lcdPutStr(5, 20, tempStr2, font_12_zekton);
	sprintf(&tempStr2, "single: %d", singlePressCount);
	lcdPutStr(5, 35, tempStr2, font_12_zekton);
	sprintf(&tempStr2, "total: %d, cyclic: %d", shortPressCount+longPressCount+2*doublePressCount, holdCyclicCount);
	lcdPutStr(5, 50, tempStr2, font_12_zekton);

	char temperature[30] = {0};
	sprintf(&temperature, "%4.1f`C", bmpData.temperature);
	lcdPutStr(35+(*(zekton24font.font_Width)*(13-strlen(temperature))), 14, temperature, zekton24font);
	char baroStr[30] = {0};
	sprintf(&baroStr, "%4.0f hPa", ((float)bmpData.pressure/100));
	lcdPutStr(35+(*(zekton24font.font_Width)*(13-strlen(baroStr))), 42, baroStr, zekton24font);

	char fracStr[30] = {0};
	char timeStr[30] = {0};
	char timeStr2[30] = {0};
	sprintf(&timeStr, "%02d", RtcTime.Hours);
	sprintf(&timeStr2, "%02d", RtcTime.Minutes);
	sprintf(&fracStr, "%02d", RtcTime.Seconds);
	lcdPutStr(20, 76, timeStr, zekton84font);
	lcdPutStr(170, 76, timeStr2, zekton84font);
	lcdPutStr(315, 76, fracStr, zekton45font);

	char buffString[30] = {0};
	sprintf(&buffString, "September 2022");
	sprintf(&buffString, "%s %d", months[RtcDate.Month], 2000+RtcDate.Year);
	lcdPutStr(35+(*(zekton24font.font_Width)*(13-strlen(buffString))), 174, buffString, zekton24font);
	sprintf(&buffString, "%s %d", weekDays[RtcDate.WeekDay], RtcDate.Date);
	lcdPutStr(35+(*(zekton24font.font_Width)*(13-strlen(buffString))), 202, buffString, zekton24font);
}


