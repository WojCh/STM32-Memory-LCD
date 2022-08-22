/*
 * watchfaceModule.c
 *
 *  Created on: 25 kwi 2022
 *      Author: wojch
 *
 *      module displaying watchfaces
 */
#include "watchfaceModule.h"
#include "contextMenu.h"

// fonts
#include "font13.h"
#include "digits5x9.h"
#include "fonts/zekton14.h"
#include "fonts/zekton24.h"
#include "fonts/zekton84.h"
#include <fonts/zekton45.h>



static void setDefaultClbcks(void){
	// module callbacks
	btn_B2.onSinglePressHandler = &showCntxMenu;
	btn_BA.onSinglePressHandler = &nextScreen;
	btn_BC.onSinglePressHandler = &prevScreen;
}

static void setTimeAction(void){
	guiApplyView(&timeInputModule);
}
static void setDateAction(void){
	guiApplyView(&dateInputModule);
}

const struct ContextAction action1 = {"Set time", &setTimeAction};
const struct ContextAction action2 = {"Set date", &setDateAction};
const struct ContextAction action3 = {"Customize", &setTimeAction};
const struct ContextAction action4 = {"Lock", &setTimeAction};
struct ContextAction* ContextActions[] = {&action1, &action2, &action3, &action4};

void faceSetup(void){
	setDefaultClbcks();
	setupCntxMenu(&setDefaultClbcks);
//	setupCntxMenu(&setDefaultClbcks, cntxActions, 3);
}

void faceMain(void){
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

	enableCntxMenu();
}


