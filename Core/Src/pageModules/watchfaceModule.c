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
#include "fonts/zekton24.h"
#include "fonts/zekton84.h"
#include <fonts/zekton45.h>

static void setDefaultClbcks(void){
	// module callbacks
	btn_B2.onSinglePressHandler = &showCntxMenu;
	btn_BA.onSinglePressHandler = &nextScreen;
	btn_BC.onSinglePressHandler = &prevScreen;
}

//void setTimeScreenSetup(void){
//
////	exit edit mode
//	btn_B3.onSinglePressHandler = &applySelectedScreen;
////	cursor left
//	btn_B2.onSinglePressHandler = &applySelectedScreen;
////	accept
//	btn_B1.onSinglePressHandler = &applySelectedScreen;
////	reduce
//	btn_BA.onSinglePressHandler = &applySelectedScreen;
////	cursor right
//	btn_BB.onSinglePressHandler = &applySelectedScreen;
////	increase
//	btn_BC.onSinglePressHandler = &applySelectedScreen;
//}
//void setTimeScreen(void){
//	char fracStr[30] = {0};
//	char timeStr[30] = {0};
//	char timeStr2[30] = {0};
//	sprintf(&timeStr, "%02d", RtcTime.Hours);
//	sprintf(&timeStr2, "%02d", RtcTime.Minutes);
//	sprintf(&fracStr, "%02d", RtcTime.Seconds);
//	lcdPutStr(20, 76, timeStr, zecton84font);
//	lcdPutStr(170, 76, timeStr2, zecton84font);
//	lcdPutStr(315, 76, fracStr, zecton45font);
//}
//const struct Module setTimeModule = {"Set time", &setTimeScreenSetup, &setTimeScreen, NULL};


static void setTimeAction(void){
	guiApplyView(&numberInputModule);
//	lcdRect(150, 300, 10, 230, 2);
//	RtcTime.Hours = 12;
//	RtcTime.Minutes = 34;
//	RtcTime.Seconds = 56;
//	RtcTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
//	RtcTime.StoreOperation = RTC_STOREOPERATION_RESET;
//	if (HAL_RTC_SetTime(&hrtc, &RtcTime, RTC_FORMAT_BIN) != HAL_OK)
//	{
//	Error_Handler();
//	}
//	sDate.WeekDay = RTC_WEEKDAY_MONDAY;
//	sDate.Month = RTC_MONTH_JANUARY;
//	sDate.Date = 1;
//	sDate.Year = 22;
//
//	if (HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BIN) != HAL_OK)
//	{
//	Error_Handler();
//	}
}

const struct ContextAction action1 = {"Set time", &setTimeAction};
const struct ContextAction action2 = {"Customize", &setTimeAction};
const struct ContextAction action3 = {"Lock", &setTimeAction};
struct ContextAction* ContextActions[] = {&action1, &action2, &action3};

void faceSetup(void){
	setDefaultClbcks();
	setupCntxMenu(&setDefaultClbcks);
//	setupCntxMenu(&setDefaultClbcks, cntxActions, 3);
}

void faceMain(void){
	char temperature[30] = {0};
	sprintf(&temperature, "%4.1f`C", bmpData.temperature);
	lcdPutStr(35+(*(zektonSmallFont.font_Width)*(13-strlen(temperature))), 14, temperature, zektonSmallFont);
	char baroStr[30] = {0};
	sprintf(&baroStr, "%04.1f hPa", ((float)bmpData.pressure/100));
	lcdPutStr(35+(*(zektonSmallFont.font_Width)*(13-strlen(baroStr))), 42, baroStr, zektonSmallFont);

	char fracStr[30] = {0};
	char timeStr[30] = {0};
	char timeStr2[30] = {0};
	sprintf(&timeStr, "%02d", RtcTime.Hours);
	sprintf(&timeStr2, "%02d", RtcTime.Minutes);
	sprintf(&fracStr, "%02d", RtcTime.Seconds);
	lcdPutStr(20, 76, timeStr, zecton84font);
	lcdPutStr(170, 76, timeStr2, zecton84font);
	lcdPutStr(315, 76, fracStr, zecton45font);

	char dateStr[30] = {0};
	sprintf(&dateStr, "20 september");
	lcdPutStr(35+(*(zektonSmallFont.font_Width)*(13-strlen(dateStr))), 174, dateStr, zektonSmallFont);
	char weekStr[30] = {0};
	sprintf(&weekStr, "wednesday");
	lcdPutStr(35+(*(zektonSmallFont.font_Width)*(13-strlen(weekStr))), 200, weekStr, zektonSmallFont);

	enableCntxMenu();
}
