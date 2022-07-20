/*
 * menuModule.c
 *
 *  Created on: 25 kwi 2022
 *      Author: wojch
 */

#include "menuModule.h"

#include "font13.h"
#include "digits5x9.h"
#include "fonts/zekton24.h"
#include "fonts/zekton84.h"
#include "fonts/zekton45.h"
#include "fonts/zekton14.h"

void resetMenuPos(void){
		position=0;
}

static void setDefaultClbcks(void){
	btn_BA.onSinglePressHandler = &nextPos;
	btn_BA.onContinuousLongPressHandler = &nextPos;

	btn_BB.onSinglePressHandler = &applySelectedScreen;
	btn_B2.onSinglePressHandler = &resetMenuPos;

	btn_B1.onContinuousLongPressHandler = &prevPos;
	btn_B1.onSinglePressHandler = &prevPos;
}


void menuSetup(void){
	setDefaultClbcks();
}

void menuMain(void){
//	if(moduleDescPtr != NULL) moduleDescPtr();
		uint8_t fontWidth = *zekton12font.font_Width;
		char leftStr[30] = {0};
		char rightStr[30] = {0};
		char centStr[30] = {0};
		sprintf(&centStr, "%s", menuItems[position].name);
		if(position > 0){
			sprintf(&leftStr, "%s", menuItems[position-1].name);
//			if(menuItems[position-1].icon != NULL) lcdPutIcon(70 - menuItems[position-1].icon->icon_Width/2, 90, menuItems[position-1].icon);
		} else {
			sprintf(&leftStr, "%s", menuItems[MENU_ITEM_NUM-1].name);
//			if(menuItems[MENU_ITEM_NUM-1].icon != NULL) lcdPutIcon(70 - menuItems[MENU_ITEM_NUM-1].icon->icon_Width/2, 90, menuItems[MENU_ITEM_NUM-1].icon);
		}
		if(position >= MENU_ITEM_NUM - 1){
			sprintf(&rightStr, "%s", menuItems[0].name);
//			if(menuItems[0].icon != NULL) lcdPutIcon(330 - menuItems[0].icon->icon_Width/2, 90, menuItems[0].icon);
		} else {
			sprintf(&rightStr, "%s", menuItems[position+1].name);
//			if(menuItems[position+1].icon != NULL) lcdPutIcon(330 - menuItems[position+1].icon->icon_Width/2, 90, menuItems[position+1].icon);
		}
		sprintf(&centStr, "%s", menuItems[position].name);
//		moduleDescPtr = menuItems[position].description;
		moduleSetupPtr = menuItems[position].setup;
		moduleMainPtr = menuItems[position].main;
		lcdPutStr(200 - (fontWidth * strlen(menuItems[position].name)/2), 180, centStr, zekton12font);
//		if(menuItems[position].icon != NULL) lcdPutIcon(200 - menuItems[position].icon->icon_Width/2, 65, menuItems[position].icon);
		lcdPutStr(70 - (fontWidth * strlen(leftStr)/2), 190, leftStr, zekton12font);
		lcdPutStr(330 - (fontWidth * strlen(rightStr)/2), 190, rightStr, zekton12font);

			// debug stuff
			if(1){
				sprintf(&centStr, "%d", position);
				lcdPutStr(380, 0, centStr, zekton12font);
			}
	//		  char guiPos[50] ={0};
	//		  sprintf(&guiPos, "%02d:%02d:%02d %4.1f*C %02d-%02d-20%02d", RtcTime.Hours, RtcTime.Minutes, RtcTime.Seconds, bmpData.temperature, RtcDate.Date, RtcDate.Month, RtcDate.Year);
	//		  lcdPutStr(0, SCR_H-currentFont->font_Height-1, guiPos, currentFont);
			  char guiPos[50] = {0};
			  sprintf(&guiPos, "%02d:%02d", RtcTime.Hours, RtcTime.Minutes);
	//		  lcdPutStr(200 - fontWidth * strlen(guiPos[0])/2, SCR_H-ocrFont->font_Height-1, guiPos, ocrFont);
			  lcdPutStr(200 - fontWidth * strlen(guiPos)/2, 1, guiPos, zekton12font);
}
