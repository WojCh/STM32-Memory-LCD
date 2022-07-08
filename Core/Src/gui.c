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
#include "fonts/zekton14.h"
#include "icons/icons_small.h"

const struct Module menuModule = {"Menu", &menuDescription, &menuSetup, &menuMain, NULL};
const struct Module homeModule = {"Home", &homeDescription, &homeSetup, &homeMain, homeIcon};
const struct Module timeModule = {"Time", &timeDescription, &timeSetup, &timeMain, timeIcon};
const struct Module baroModule = {"Atmo", &baroDescription, &baroSetup, &baroMain, atmoIcon};
const struct Module gpsModule = {"GPS", &gpsDescription, &gpsSetup, &gpsMain, gpsIcon};
const struct Module settingsModule = {"Settings", &settingsDescription, &settingsSetup, &settingsMain, settingsIcon};

struct Module menuItems[MENU_ITEM_NUM] = {homeModule, timeModule, baroModule, gpsModule, settingsModule};

// default screens and displays/values
uint8_t position = 0;
void (*moduleDescPtr)(void) = homeModule.description;
void (*moduleMainPtr)(void) = homeModule.main;
void (*moduleSetupPtr)(void) = homeSetup;
void (*currentModulePtr)(void) = homeMain;

uint8_t* isModuleSet = 0;

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

void applySelectedScreen(void){
	moduleDescPtr = menuItems[position].description;
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

void returnToMenu(void){
	resetButtonHandlers();
	isModuleSet = 0;
	moduleSetupPtr = menuModule.setup;
	currentModulePtr =menuModule.main;
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

