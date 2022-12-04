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
// initializes device with GPS module as the initial screen
#define LCD_DEBUGGING 1

#include "gui.h"

const struct Module faceModule = {"Watchface", &faceSetup, &faceMain};
const struct Module stwModule = {"Stopwatch", &stwSetup, &stwMain};
const struct Module altiModule = {"Alti", &altiSetup, &altiMain};
const struct Module baroModule = {"Atmo", &baroSetup, &baroMain};
const struct Module localModule = {"Local", &localSetup, &localMain};
const struct Module gpsModule = {"GPS", &gpsSetup, &gpsMain};
const struct Module settingsModule = {"Settings", &settingsSetup, &settingsMain};
const struct Module sdcardModule = {"SD card", &sdcardSetup, &sdcardMain};
const struct Module alarmModule = {"Alarms", &alarmSetup, &alarmMain};
const struct Module worldtimeModule = {"World time", &worldtimeSetup, &worldtimeMain};
const struct Module timerModule = {"Timer", &timerSetup, &timerMain};
const struct Module screentestModule = {"Screen test", &screentestSetup, &screentestMain};

const struct Module menuItems[MENU_ITEM_NUM] = {faceModule, alarmModule, worldtimeModule, stwModule, timerModule, altiModule, baroModule, localModule, gpsModule, screentestModule, settingsModule, sdcardModule};

// default screens and displays/values
#define START_MENU_POSITION 10
uint8_t position = START_MENU_POSITION;
#if LCD_DEBUGGING
	void (*moduleMainPtr)(void) = menuItems[START_MENU_POSITION].main;
//	void (*moduleMainPtr)(void) = localModule.main;
	void (*moduleSetupPtr)(void) = menuItems[START_MENU_POSITION].setup;
	void (*currentModulePtr)(void) = menuItems[START_MENU_POSITION].main;
#else
	void (*moduleMainPtr)(void) = faceModule.main;
	void (*moduleSetupPtr)(void) = faceSetup;
	void (*currentModulePtr)(void) = faceMain;
#endif

uint8_t isModuleSet = 0;

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

void nextScreen(void){
	nextPos();
	applySelectedScreen();
}
void prevScreen(void){
	prevPos();
	applySelectedScreen();
}
void resetPos(void){
	position=0;
	applySelectedScreen();
}

void guiApplyView(struct Module *module){
	moduleSetupPtr = module->setup;
	moduleMainPtr = module->main;
	selectScreen();
}

void applySelectedScreen(void){
//	moduleDescPtr = menuItems[position].description;
	moduleSetupPtr = menuItems[position].setup;
	moduleMainPtr = menuItems[position].main;
	selectScreen();
}

void selectScreen(void){
//	lcdClearBuffer();
	resetButtonHandlers();
	isModuleSet = 0;
	currentModulePtr = moduleMainPtr;
}

// function showing menu with module selector
void returnToMenu(void){
	resetButtonHandlers();
	isModuleSet = 0;
//	moduleSetupPtr = menuModule.setup;
//	currentModulePtr =menuModule.main;
}

// function to display alert message over current gui
//void showAlert(){
//
//}

void showGui(void){
	if(isModuleSet == 0){
		moduleSetupPtr();
		isModuleSet = 1;
	}
	if(currentModulePtr != NULL) currentModulePtr();
//	lcdRefresh();
}

