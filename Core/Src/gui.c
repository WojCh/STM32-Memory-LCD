/*
 * gui.c
 *
 *  Created on: 24 kwi 2022
 *      Author: wojch
 *
 *      Add modules:
 *      1. Astro module
 *      2. Surfing module
 *      3. Gyro module
 *      4. BT module
 *      5. WIFI module
 *
 *
 */

#define MENU_ITEM_NUM 5
#include "font13.h"
#include "digits5x9.h"
#include "font_larabie.h"
#include "font_paradroid_18.h"
#include "gui.h"
#include "fonts/ocrFont.h"
#include "icons/icons_small.h"


Font_TypeDef* currentFont = font13;


const struct Module homeModule = {"Home", &homeDescription, &homeSetup, &homeMain, homeIcon};
const struct Module timeModule = {"Time", &timeDescription, &timeSetup, &timeMain, timeIcon};
const struct Module baroModule = {"Atmo", &baroDescription, &baroSetup, &baroMain, atmoIcon};
const struct Module gpsModule = {"GPS", &gpsDescription, &gpsSetup, &gpsMain, gpsIcon};
const struct Module settingsModule = {"Settings", &settingsDescription, &settingsSetup, &settingsMain, settingsIcon};
//const struct Module homeModule = {"Home", &homeDescription, &homeSetup, &homeMain};
//const struct Module timeModule = {"Time and Date", &timeDescription, &timeSetup, &timeMain};
//const struct Module baroModule = {"Atmospherical data", &baroDescription, &baroSetup, &baroMain};
//const struct Module gpsModule = {"Global Positioning System", &gpsDescription, &gpsSetup, &gpsMain};
//const struct Module settingsModule = {"Settings", &settingsDescription, &settingsSetup, &settingsMain};

struct Module menuItems[MENU_ITEM_NUM] = {homeModule, timeModule, baroModule, gpsModule, settingsModule};

void showGraphicalMainMenu(void);

// default screens and displays/values
char pointerChar = '>';
static uint8_t position = 1;
void (*moduleDescPtr)(void) = homeModule.description;
void (*moduleMainPtr)(void) = homeModule.main;
void (*moduleSetupPtr)(void) = timeSetup;
void (*currentModulePtr)(void) = timeMain;
// default main menu
//void (*moduleSetupPtr)(void) = mainMenuSetup;
//void (*currentModulePtr)(void) = showMainMenu2;
uint8_t* isModuleSet = 0;

void mainMenuSetup(void){
	setMenuClbs();
}
void showMainMenu(void){
	if(moduleDescPtr != NULL) moduleDescPtr();
	char tempStr[30] = {0};
	for(uint8_t i = 0; i < MENU_ITEM_NUM; i++){
		if(position == i){
			sprintf(&tempStr, "%c%s", pointerChar, menuItems[i].name);
			moduleDescPtr = menuItems[i].description;
			moduleSetupPtr = menuItems[i].setup;
			moduleMainPtr = menuItems[i].main;
		} else {
			sprintf(&tempStr, " %s", menuItems[i].name);
		}
		lcdPutStr(0, 0+i*currentFont->font_Height, tempStr, currentFont);
	}
	// debug stuff
	if(1){
		sprintf(&tempStr, "%d", position);
		lcdPutStr(380, 0, tempStr, currentFont);
	}
	  char guiPos[50] ={0};
	  sprintf(&guiPos, "%02d:%02d:%02d %4.1f*C %02d-%02d-20%02d", RtcTime.Hours, RtcTime.Minutes, RtcTime.Seconds, bmpData.temperature, RtcDate.Date, RtcDate.Month, RtcDate.Year);
	  lcdPutStr(0, SCR_H-currentFont->font_Height-1, guiPos, currentFont);
}

void showGraphicalMainMenu(void){
	if(moduleDescPtr != NULL) moduleDescPtr();
	uint8_t fontWidth = *ocrFont.font_Width;
	char leftStr[10] = {0};
	char rightStr[10] = {0};
	char centStr[10] = {0};
	sprintf(&centStr, "%s", menuItems[position].name);
	if(position > 0){
		sprintf(&leftStr, "%s", menuItems[position-1].name);
		if(menuItems[position-1].icon != NULL) lcdPutIcon(70 - menuItems[position-1].icon->icon_Width/2, 90, menuItems[position-1].icon);
	} else {
		sprintf(&leftStr, "%s", menuItems[MENU_ITEM_NUM-1].name);
		if(menuItems[MENU_ITEM_NUM-1].icon != NULL) lcdPutIcon(70 - menuItems[MENU_ITEM_NUM-1].icon->icon_Width/2, 90, menuItems[MENU_ITEM_NUM-1].icon);
	}
	if(position >= MENU_ITEM_NUM - 1){
		sprintf(&rightStr, "%s", menuItems[0].name);
		if(menuItems[0].icon != NULL) lcdPutIcon(330 - menuItems[0].icon->icon_Width/2, 90, menuItems[0].icon);
	} else {
		sprintf(&rightStr, "%s", menuItems[position+1].name);
		if(menuItems[position+1].icon != NULL) lcdPutIcon(330 - menuItems[position+1].icon->icon_Width/2, 90, menuItems[position+1].icon);
	}
	sprintf(&centStr, "%s", menuItems[position].name);
	moduleDescPtr = menuItems[position].description;
	moduleSetupPtr = menuItems[position].setup;
	moduleMainPtr = menuItems[position].main;
	lcdPutStr(200 - (fontWidth * strlen(menuItems[position].name)/2), 180, centStr, ocrFont);
	if(menuItems[position].icon != NULL) lcdPutIcon(200 - menuItems[position].icon->icon_Width/2, 65, menuItems[position].icon);
	lcdPutStr(70 - (fontWidth * strlen(leftStr)/2), 190, leftStr, ocrFont);
	lcdPutStr(330 - (fontWidth * strlen(rightStr)/2), 190, rightStr, ocrFont);

		// debug stuff
		if(1){
			sprintf(&centStr, "%d", position);
			lcdPutStr(380, 0, centStr, currentFont);
		}
//		  char guiPos[50] ={0};
//		  sprintf(&guiPos, "%02d:%02d:%02d %4.1f*C %02d-%02d-20%02d", RtcTime.Hours, RtcTime.Minutes, RtcTime.Seconds, bmpData.temperature, RtcDate.Date, RtcDate.Month, RtcDate.Year);
//		  lcdPutStr(0, SCR_H-currentFont->font_Height-1, guiPos, currentFont);
		  char guiPos[50] = {0};
		  sprintf(&guiPos, "%02d:%02d", RtcTime.Hours, RtcTime.Minutes);
//		  lcdPutStr(200 - fontWidth * strlen(guiPos[0])/2, SCR_H-ocrFont->font_Height-1, guiPos, ocrFont);
		  lcdPutStr(200 - fontWidth * strlen(guiPos)/2, 1, guiPos, ocrFont);
}

void prevPos(void){
	if(position>0){
		position--;
	} else {
		position=MENU_ITEM_NUM-1;
	}
}
void nextPos(void){
	if(position<(MENU_ITEM_NUM-1)){
		position++;
	} else {
		position=0;
	}
}
void resetPos(void){
		position=0;
}

void select(void){
//	lcdClearBuffer();
	resetButtonHandlers();
	isModuleSet = 0;
	currentModulePtr = moduleMainPtr;
}

void returnToMenu(void){
	resetButtonHandlers();
	isModuleSet = 0;
	moduleSetupPtr = mainMenuSetup;
	currentModulePtr = &showGraphicalMainMenu;
//	currentModulePtr = &showMainMenu;
}

//Font_TypeDef* fontArray[3] = {font13, fontLarabieSmall, fontParadroidSmall};
Font_TypeDef* fontArray[2] = {font13, fontLarabieSmall};
static uint8_t fontIndex = 0;
void nextFont(void){
	if(fontIndex < 1){
		fontIndex++;
	} else {
		fontIndex = 0;
	}
		currentFont = fontArray[fontIndex];
}

void setMenuClbs(void){
	btn_BA.onSinglePressHandler = &nextPos;
	btn_BA.onContinuousLongPressHandler = &nextPos;

	btn_BB.onSinglePressHandler = &select;
	btn_B2.onSinglePressHandler = &resetPos;

	btn_B1.onContinuousLongPressHandler = &prevPos;
	btn_B1.onSinglePressHandler = &prevPos;
}

void showMenu(void){
	if(isModuleSet == 0){
		moduleSetupPtr();
		isModuleSet = 1;
	}
	if(currentModulePtr != NULL) currentModulePtr();
	lcdRefresh();
//	while(1){
//	}
}

