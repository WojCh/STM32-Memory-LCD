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

#include "gui.h"

const struct Module menuModule = {"Menu", &menuSetup, &menuMain, NULL};
const struct Module faceModule = {"Watchface", &faceSetup, &faceMain, homeIcon};
const struct Module stwModule = {"Stopwatch", &stwSetup, &stwMain, timeIcon};
const struct Module baroModule = {"Atmo", &baroSetup, &baroMain, atmoIcon};
const struct Module gpsModule = {"GPS", &gpsSetup, &gpsMain, gpsIcon};
const struct Module settingsModule = {"Settings", &settingsSetup, &settingsMain, settingsIcon};

struct Module menuItems[MENU_ITEM_NUM] = {faceModule, stwModule, baroModule, gpsModule, settingsModule};

// default screens and displays/values
uint8_t position = 0;
void (*moduleMainPtr)(void) = faceModule.main;
void (*moduleSetupPtr)(void) = faceSetup;
void (*currentModulePtr)(void) = faceMain;

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
	moduleSetupPtr = menuModule.setup;
	currentModulePtr =menuModule.main;
}

// function to display alert message over current gui
void showAlert(){

}

void showGui(void){
	if(isModuleSet == 0){
		moduleSetupPtr();
		isModuleSet = 1;
	}
	if(currentModulePtr != NULL) currentModulePtr();
	lcdRefresh();
}

