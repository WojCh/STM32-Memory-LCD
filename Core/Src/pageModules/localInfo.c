/*
 * localInfo.c
 *
 *  Created on: 25 kwi 2022
 *      Author: wojch
 *
 *      module displaying watchfaces
 */
#include "localInfo.h"

// fonts
#include "fonts/zekton24.h"
#include "fonts/zekton84.h"
#include <fonts/zekton45.h>

void prevMonth(void){
	RtcDate.Month--;
	if (HAL_RTC_SetDate(&hrtc, &RtcDate, RTC_FORMAT_BIN) != HAL_OK)
	{
	Error_Handler();
	}
}

static void setDefaultClbcks(void){
	// module callbacks
	btn_BA.onSinglePressHandler = &nextScreen;
	btn_BB.onSinglePressHandler = &prevMonth;
	btn_BC.onSinglePressHandler = &prevScreen;
}
void localSetup(void){
	setDefaultClbcks();
}

void localMain(void){
	char textBuffer[30] = {0};

	sprintf(&textBuffer, "%d week of the year", RtcDate.WeekDay);
	lcdPutStr(10, 10, textBuffer, zekton24font);
	sprintf(&textBuffer, "%d day of the year", RtcDate.WeekDay);
	lcdPutStr(10, 40, textBuffer, zekton24font);
//	lcdPutStr(35+(*(zekton24font.font_Width)*(13-strlen(textBuffer))), 14, textBuffer, zekton24font);
	sprintf(&textBuffer, "Sunrise ->  Sunset");
	lcdPutStr(10, 100, textBuffer, zekton24font);
	sprintf(&textBuffer, "12:34        21:43");
	lcdPutStr(10, 130, textBuffer, zekton24font);
}


