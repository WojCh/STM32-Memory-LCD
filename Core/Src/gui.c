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
#include "utils/timerUtils.h"

const struct Module faceModule = {"Watchface", &faceSetup, &faceMain};
const struct Module stwModule = {"Stopwatch", &stwSetup, &stwMain};
//const struct Module altiModule = {"Alti", &altiSetup, &altiMain};
//const struct Module baroModule = {"Atmo", &baroSetup, &baroMain};
//const struct Module localModule = {"Local", &localSetup, &localMain};
//const struct Module gpsModule = {"GPS", &gpsSetup, &gpsMain};
//const struct Module settingsModule = {"Settings", &settingsSetup, &settingsMain};
//const struct Module sdcardModule = {"SD card", &sdcardSetup, &sdcardMain};
//const struct Module alarmModule = {"Alarms", &alarmSetup, &alarmMain};
//const struct Module worldtimeModule = {"World time", &worldtimeSetup, &worldtimeMain};
//const struct Module timerModule = {"Timer", &timerSetup, &timerMain};
const struct Module screentestModule = {"Screen test", &screentestSetup, &screentestMain};

const struct Module menuItems[MENU_ITEM_NUM] = {faceModule, stwModule, screentestModule};
//const struct Module menuItems[MENU_ITEM_NUM] = {faceModule, alarmModule, worldtimeModule, stwModule, timerModule, altiModule, baroModule, localModule, gpsModule, screentestModule, settingsModule, sdcardModule};

// default screens and displays/values
#define START_MENU_POSITION 0
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

uint8_t isScrollbarEnabled = 0;
timer_T* scrollerTimer = NULL;
void tickTimAAB(void){
	tickTimer(scrollerTimer);
}
void showScrollbar(void){
	uint16_t x = 390;
	uint8_t y = 20;
	uint8_t h_margin = 2;
	uint8_t v_margin = 2;
	uint8_t b_margin = 4;
	uint8_t width = 9;
	uint8_t height = 200;
	uint8_t b_height = (height-2*v_margin-(MENU_ITEM_NUM-1)*b_margin)/MENU_ITEM_NUM;

	lcdRoundedRect2(x, x+width-1, y, y+height, 0, LCD_RECT_PATTERN_FILL, 0,3);
	lcdRoundedRect2(x, x+width-1, y, y+height, 1, LCD_RECT_PATTERN_CLEAR, 1, 3);
	lcdRoundedRect2(x+h_margin, x+width-1-h_margin, y+1+v_margin+(b_height+b_margin)*position, y+1+v_margin+b_height+(b_height+b_margin)*position, 1, LCD_RECT_PATTERN_FILL, 1, 1);
//	lcdRoundedRect2(x+h_margin, x+width-h_margin, y+1+v_margin+(b_height+b_margin)*0, y+1+v_margin+b_height+(b_height+b_margin)*0, 1, LCD_RECT_PATTERN_FILL, 0, 1);
//	lcdRoundedRect2(x+h_margin, x+width-h_margin, y+1+v_margin+(b_height+b_margin)*1, y+1+v_margin+b_height+(b_height+b_margin)*1, 1, LCD_RECT_PATTERN_FILL, 0, 1);
//	lcdRoundedRect2(x+h_margin, x+width-h_margin, y+1+v_margin+(b_height+b_margin)*2, y+1+v_margin+b_height+(b_height+b_margin)*2, 1, LCD_RECT_PATTERN_FILL, 0, 1);
}
void disableScrollbar(void){
	isScrollbarEnabled = 0;
}
void enableScrollbar(void){
	scrollerTimer = createTimer();
	setTimerAAA(scrollerTimer, 2, &disableScrollbar);
	runTimerAAA(scrollerTimer);
	isScrollbarEnabled = 1;
}

void prevPos(void){
	enableScrollbar();
	if(position>0){
		position--;
	} else {
		position=MENU_ITEM_NUM-1;
	}
}

void nextPos(void){
	enableScrollbar();
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
	if(isScrollbarEnabled) showScrollbar();
//	lcdRefresh();
}

