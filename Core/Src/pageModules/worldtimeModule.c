/*
 * worldtimeModule.c
 *
 *  Created on: Nov 27, 2022
 *      Author: wojch
 */

#include "worldtimeModule.h"
#include "fonts/fonts.h"
#include "icons/icons_small.h"

static void setDefaultClbcks(void){
	btn_BA.onSinglePressHandler = &nextScreen;
	btn_BC.onSinglePressHandler = &prevScreen;
}

void worldtimeSetup(void){
	setDefaultClbcks();
}

void worldtimeMain(void){
	char tempStr[51] = {0};
	sprintf(&tempStr, "World time");
	lcdPutStr(10, 10, tempStr, zekton24font);
	lcdPutIcon(10, 40, wrldMap);

	lcdVLine(100, 40, 40+99, 2);
	lcdHLine(10, 210, 60, 2);

	char guiPos[6] = {0};
	sprintf(&guiPos, "%02d:%02d", RtcTime.Hours, RtcTime.Minutes);
	lcdPutStr(400 - 10 - (*zekton24font.font_Width) * strlen(guiPos), 10, guiPos, zekton24font);

	lcdPutStr(10, 150, "UTC+00", zekton45font);
	lcdPutStr(220, 90, "UTC", zekton45font);

	sprintf(&tempStr, "%02d:%02d", RtcTime.Hours-GLOBAL_timezone, RtcTime.Minutes);
	lcdPutStr(220, 40, tempStr, zekton45font);
}

