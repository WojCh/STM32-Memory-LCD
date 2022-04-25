/*
 * gui.c
 *
 *  Created on: 24 kwi 2022
 *      Author: wojch
 */

#define MENU_ITEM_NUM 4
#include "font13.h"
#include "digits5x9.h"
#include "gui.h"

struct MenuOption{
	// label for menu item
	char title[30];
	// function executed when option highlighted
	void (*tempAction)(void);
	// function executed after option selected
	void (*func)(void);
};

//const struct MenuOption menu1 = {"Time and Date", &showTimeDesc, &showTimeScreen};
//const struct MenuOption menu2 = {"Barometer", &showBaroDesc, &showBaroScreen};
//const struct MenuOption menu3 = {"Global Positioning System", &showGpsDesc, &showGpsScreen};
//const struct MenuOption menu4 = {"BBB", &showBaroDesc, baroModule.moduleMain};
const struct Module menu1 = {"Time and Date", &showTimeDesc, &showTimeScreen};
const struct Module menu2 = {"Barometer", &showBaroDesc, &showBaroScreen};
const struct Module menu3 = {"Global Positioning System", &showGpsDesc, &showGpsScreen};
struct Module menuItems[MENU_ITEM_NUM] = {menu1, menu2, menu3};

// default screens and displays/values
char pointerChar = '>';
static uint8_t position = 0;
void (*showMenuDescPtr)(void) = menu1.moduleSetup;
void (*screenToShowPtr)(void) = menu1.moduleMain;
void (*showScreenPtr)(void) = &showMainMenu;
//void (*showScreenPtr)(void) = &showBaroScreen;

void showMainMenu(void){
	setMenuClbs();
	if(showMenuDescPtr != NULL) showMenuDescPtr();
	char tempStr[30] = {0};
	for(uint8_t i = 0; i < MENU_ITEM_NUM; i++){
		if(position == i){
			sprintf(&tempStr, "%c%s", pointerChar, menuItems[i].name);
			showMenuDescPtr = menuItems[i].moduleSetup;
//			showScreenPtr = menuItems[i].func;
			screenToShowPtr = menuItems[i].moduleMain;
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
//	lcdRefresh();
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
	showScreenPtr = screenToShowPtr;
}

void returnToMenu(void){
	resetButtonHandlers();
	showScreenPtr = &showMainMenu;
}

void setMenuClbs(void){
	btn_B1.onSinglePressHandler = &nextPos;
	btn_B1.onContinuousLongPressHandler = &nextPos;

	btn_B2.onSinglePressHandler = &select;

	btn_B3.onContinuousLongPressHandler = &prevPos;
	btn_B3.onSinglePressHandler = &prevPos;
}

void showMenu(void){
	if(showScreenPtr != NULL) showScreenPtr();
	lcdRefresh();
//	while(1){
//	}
}

