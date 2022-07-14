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

// internal functions setting changing visible module in main menu
void nextScreenInt(void){
	nextScreen();
}
void prevScreenInt(void){
	prevScreen();
}

static void setDefaultClbcks(void){
	btn_B3.onSinglePressHandler = &hideCntxMenu;
	btn_B2.onSinglePressHandler = &showCntxMenu;
	btn_BA.onSinglePressHandler = &nextScreen;
//	btn_B1.onSinglePressHandler = &prevScreenInt;
}

void faceDescription(void){
//	char tempStr[30] = {0};
//	sprintf(&tempStr, "HOME will be shown");
//	lcdPutStr(0, 9, tempStr, font13);
}

void faceSetup(void){
	setDefaultClbcks();

}

void faceMain(void){
//	char tempStr[30] = {0};
//	sprintf(&tempStr, "HOME will be shown");
//	lcdPutStr(0, 0, tempStr, font13);

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
