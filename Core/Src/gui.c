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
#include "gui.h"

const struct Module homeModule = {"Home", &homeDescription, &homeSetup, &homeMain};
const struct Module timeModule = {"Time and Date", &timeDescription, &timeSetup, &timeMain};
const struct Module baroModule = {"Atmospherical data", &baroDescription, &baroSetup, &baroMain};
const struct Module gpsModule = {"Global Positioning System", &gpsDescription, &gpsSetup, &gpsMain};
const struct Module settingsModule = {"Settings", &settingsDescription, &settingsSetup, &settingsMain};

struct Module menuItems[MENU_ITEM_NUM] = {homeModule, timeModule, baroModule, gpsModule, settingsModule};

// default screens and displays/values
char pointerChar = '>';
static uint8_t position = 0;
void (*moduleDescPtr)(void) = homeModule.description;
void (*moduleMainPtr)(void) = homeModule.main;
void (*moduleSetupPtr)(void) = timeSetup;
void (*currentModulePtr)(void) = timeMain;
//void (*moduleSetupPtr)(void) = mainMenuSetup;
//void (*currentModulePtr)(void) = &showMainMenu;
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
		lcdPutStr(0, 0+i, tempStr, font13);
	}
	// debug stuff
	if(1){
		sprintf(&tempStr, "%d", position);
		lcdPutStr(380, 0, tempStr, font13);
	}
	  char guiPos[50] ={0};
	  sprintf(&guiPos, "%02d:%02d:%02d   %4.1f*C   %02d-%02d-20%02d", RtcTime.Hours, RtcTime.Minutes, RtcTime.Seconds, bmpData.temperature, RtcDate.Date, RtcDate.Month, RtcDate.Year);
	  lcdPutStr(0, 10, guiPos, font13);
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
	currentModulePtr = &showMainMenu;
}

void setMenuClbs(void){
	btn_B1.onSinglePressHandler = &nextPos;
	btn_B1.onContinuousLongPressHandler = &nextPos;

	btn_B2.onSinglePressHandler = &select;

	btn_B3.onContinuousLongPressHandler = &prevPos;
	btn_B3.onSinglePressHandler = &prevPos;
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

