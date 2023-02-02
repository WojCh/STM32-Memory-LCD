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

// fonts
#include "fonts/fonts.h"

void timerElap(void){
	lcdRect(10, 20, 10, 20, 1);
}

timer_T* testTimerPtr = NULL;
static void testTimerAction(void){
	if(testTimerPtr == NULL){
		testTimerPtr = createTimer();
		setTimerAAA(testTimerPtr, 10, &timerElap);
	}
}
static void testTimerStartAction(void){
	runTimerAAA(testTimerPtr);
}
static void testTimerPauseAction(void){
	pauseTimerAAA(testTimerPtr);
}
static void testTimerResetAction(void){
	resetTimerAAA(testTimerPtr);
}
static void testTimerDeleteAction(void){
	deleteTimer(testTimerPtr);
	testTimerPtr = NULL;
}
void tickTimAAA(void){
	tickTimer(testTimerPtr);
}

static void setDefaultClbcks(void){
	// module callbacks
	btn_BB.onSinglePressHandler = &testTimerAction;
//	btn_BA.onSinglePressHandler = &nextScreen;
//	btn_BC.onSinglePressHandler = &prevScreen;
	btn_BC.onSinglePressHandler = &testTimerDeleteAction;

	btn_B1.onSinglePressHandler = &testTimerStartAction;
	btn_B2.onSinglePressHandler = &testTimerPauseAction;
	btn_B3.onSinglePressHandler = &testTimerResetAction;
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
	// callback execution when timer elapsed
	timerElapsedClbk(testTimerPtr);

	char testTimStr[30] = {0};
	sprintf(&testTimStr, "%3d", testTimerPtr->targetValue);
	lcdPutStr(310, 0, testTimStr, zekton24font);
	sprintf(&testTimStr, "%3d", testTimerPtr->currentValue);
	lcdPutStr(310, 24, testTimStr, zekton24font);
	sprintf(&testTimStr, "%3d", testTimerPtr->timerStatus);
	lcdPutStr(310, 48, testTimStr, zekton24font);

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


