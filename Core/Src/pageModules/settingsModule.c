/*
 * settingsModule.c
 *
 *  Created on: 25 kwi 2022
 *      Author: wojch
 */
#include "settingsModule.h"
#include "fonts/fonts.h"
#include "../Src/utils/guiMenu.h"

//void (*actionClbk)(void) = NULL;
static uint8_t counter;


static const menuConfig_t menuConfig = {10, 30, 200, 380, MENU_SHOW_SCROLL, 4, MENU_WRAPPING_ENABLED, zekton21font, 24};

void enterMenu(menuList_t *selectedMenu);

void addOne(void){
	counter++;
}

menuItem_t item1 = {"Time & Date >", NULL};
menuItem_t item2 = {"Setting 2", NULL};
menuItem_t item3 = {"Setting 3", NULL};
menuItem_t item4 = {"Set position", NULL};

menuItem_t item5 = {"Set time", NULL};
menuItem_t item6 = {"Set date", NULL};
menuItem_t item7 = {"Set timezone", NULL};



const menuItem_t* menuItemArray[4] = {&item1, &item2, &item3, &item4};
const menuItem_t* subMenuItemArray[3] = {&item5, &item6, &item7};
static menuList_t settingsMenu = {0, &addOne, menuItemArray};

menuList_t *activeMenu = &settingsMenu;
void enterMenu(menuList_t *selectedMenu){
	activeMenu = selectedMenu;
}

void incMenuPosition(void){
	if(settingsMenu.currentPosition<(menuConfig.itemNum-1)){
		settingsMenu.currentPosition++;
	} else {
		if(menuConfig.wrappingEnabled) settingsMenu.currentPosition=0;
	}
	btn_BB.onSinglePressHandler = menuItemArray[settingsMenu.currentPosition]->action;
}
void decMenuPosition(void){
	if(settingsMenu.currentPosition>0){
		settingsMenu.currentPosition--;
	} else {
		if(menuConfig.wrappingEnabled) settingsMenu.currentPosition=menuConfig.itemNum-1;
	}
	btn_BB.onSinglePressHandler = menuItemArray[settingsMenu.currentPosition]->action;
}

static void setDefaultClbcks(void){
	btn_BA.onSinglePressHandler = &nextScreen;
	btn_BC.onSinglePressHandler = &prevScreen;
	btn_B3.onSinglePressHandler = &decMenuPosition;
	btn_B1.onSinglePressHandler = &incMenuPosition;
	btn_BB.onSinglePressHandler = settingsMenu.actionClbk;
}

void drawMenuItem(menuItem_t *item, uint8_t isActive, uint16_t x, uint16_t y){
	char tempStr[30] = {0};
	sprintf(&tempStr, item->label);
	lcdPutStr(x+2, y+2, tempStr, menuConfig.font);
	if(isActive){
		lcdRect(x, x+menuConfig.width-8, y, y+menuConfig.listItemHeight, 2);
	}
}
void drawMenu(menuList_t *menu, uint16_t x, uint16_t y){
	uint8_t fittingItemCount = menuConfig.height/menuConfig.listItemHeight;
	if(menuConfig.showScroll & (menuConfig.itemNum > fittingItemCount)){
		uint16_t barXstart = menuConfig.x+menuConfig.width-2;
		uint16_t barXend = menuConfig.x+menuConfig.width;
		uint16_t scrollBarHeight = (fittingItemCount)*menuConfig.height/menuConfig.itemNum;
		lcdRect(barXstart, barXend, menuConfig.y, scrollBarHeight+menuConfig.y, 1);
	}
	for(uint8_t i = 0; i < menuConfig.itemNum; i++){
		menuItem_t *item = menu->items[0];
		drawMenuItem(menuItemArray[i], i==menu->currentPosition, x, y+(menuConfig.listItemHeight+1)*i);
	}
}



void settingsSetup(void){
	setDefaultClbcks();

}

void settingsMain(void){
	drawMenu(activeMenu, 10, 30);
	char tempStr[30] = {0};
	sprintf(&tempStr, "Settings will be shown");
	lcdPutStr(0, 0, tempStr, font_13_calibri);
	sprintf(&tempStr, "cnt:%d", counter);
	lcdPutStr(310, 0, tempStr, font_13_calibri);

}
