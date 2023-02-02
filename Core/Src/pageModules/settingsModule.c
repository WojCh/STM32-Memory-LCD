/*
 * settingsModule.c
 *
 *  Created on: 25 kwi 2022
 *      Author: wojch
 */
#include "settingsModule.h"
#include "fonts/fonts.h"
#include "icons/circleLoader.h"
#include "../Src/utils/guiMenu.h"

//void (*actionClbk)(void) = NULL;
static uint8_t counter;
guiMenu_t myMenu;
guiMenu_t timeSubMenu;
guiMenu_t *currentMenu = &myMenu;

static const menuConfig_t menuConfig = {10, 30, 200, 380, MENU_SHOW_SCROLL, 4, MENU_WRAPPING_ENABLED, zekton21font, 24};

void enterMenu(menuList_t *selectedMenu);
void openTimeDateSettings(void);

void addOne(void){
	counter++;
}

menuItem_t item1 = {"Time & Date >", &openTimeDateSettings};
menuItem_t item2 = {"Setting 2", NULL};
menuItem_t item3 = {"Setting 3", NULL};
menuItem_t item4 = {"Set position", NULL};

menuItem_t item5 = {"Set time", NULL};
menuItem_t item6 = {"Set date", NULL};
menuItem_t item7 = {"Set timezone", NULL};
menuItem_t item8 = {"Set timezone2", NULL};


const menuItem_t* menuItemArray[4] = {&item1, &item2, &item3, &item4};
const menuItem_t* subMenuItemArray[4] = {&item5, &item6, &item7, &item8};
static menuList_t settingsMenu = {0, &addOne, menuItemArray};

void openTimeDateSettings(void){
	enterMenu(&subMenuItemArray);
}

menuList_t *activeMenu = &settingsMenu;
void enterMenu(menuList_t *selectedMenu){
	activeMenu = selectedMenu;
}

void incMenuPosition(void){
	nextMenuItem(currentMenu);
	btn_BB.onSinglePressHandler = currentMenu->itemList[currentMenu->selectedItem]->actionCallback;
}
void decMenuPosition(void){
	prevMenuItem(currentMenu);
	btn_BB.onSinglePressHandler = currentMenu->itemList[currentMenu->selectedItem]->actionCallback;
}

static void setDefaultClbcks(void){
	btn_BA.onSinglePressHandler = &nextScreen;
	btn_BC.onSinglePressHandler = &prevScreen;
	btn_B3.onSinglePressHandler = &decMenuPosition;
	btn_B1.onSinglePressHandler = &incMenuPosition;
	btn_BB.onSinglePressHandler = currentMenu->itemList[0]->actionCallback;

//	btn_BB.onSinglePressHandler = activeMenu->actionClbk;
}

//void drawMenuItem(menuItem_t *item, uint8_t isActive, uint16_t x, uint16_t y){
//	char tempStr[30] = {0};
//	sprintf(&tempStr, item->label);
//	lcdPutStr(x+2, y+2, tempStr, menuConfig.font);
//	if(isActive){
//		lcdRect(x, x+menuConfig.width-8, y, y+menuConfig.listItemHeight, 2);
//	}
//}
//void drawMenu(menuList_t *menu, uint16_t x, uint16_t y){
//	uint8_t fittingItemCount = menuConfig.height/menuConfig.listItemHeight;
//	if(menuConfig.showScroll & (menuConfig.itemNum > fittingItemCount)){
//		uint16_t barXstart = menuConfig.x+menuConfig.width-2;
//		uint16_t barXend = menuConfig.x+menuConfig.width;
//		uint16_t scrollBarHeight = (fittingItemCount)*menuConfig.height/menuConfig.itemNum;
//		lcdRect(barXstart, barXend, menuConfig.y, scrollBarHeight+menuConfig.y, 1);
//	}
//	for(uint8_t i = 0; i < menuConfig.itemNum; i++){
//		menuItem_t *item = menu->items[0];
//		drawMenuItem(menuItemArray[i], i==menu->currentPosition, x, y+(menuConfig.listItemHeight+1)*i);
//	}
//}

//void openSubmenu(guiMenu_t *submenu){
void openSubmenu(void){
	currentMenu = &timeSubMenu;
	btn_BB.onSinglePressHandler = currentMenu->itemList[0]->actionCallback;
}
void openSetTimeView(void){
	guiApplyView(&timeInputModule);
}
void openSetDateView(void){
	guiApplyView(&dateInputModule);
}

void settingsSetup(void){
	setDefaultClbcks();
}

uint8_t animationFrameNum = 0;
void animate(void){
	lcdPutChar(10, 200, 32+animationFrameNum%8, circularLoader);
//	lcdHLine(10+(animationFrameNum%8)*2, 20+(animationFrameNum%8)*2, 200, 1);
}

	const guiMenuItem_t timedateSubmenu = {"Time & Date",
			MENU_ITEM_TYPE_GENERIC, &openSubmenu};
	const guiMenuItem_t actionItem = {"Exec. action",
			MENU_ITEM_TYPE_GENERIC, &addOne};
	const guiMenuItem_t valueItem = {"Vibration length",
			MENU_ITEM_TYPE_GENERIC, NULL};
	const guiMenuItem_t *list[3] = {&timedateSubmenu, &actionItem, &valueItem};
	guiMenu_t myMenu = {10, 30, 0, 3, list};

	const guiMenuItem_t setTimeSub = {"Set time",
			MENU_ITEM_TYPE_GENERIC, &openSetTimeView};
	const guiMenuItem_t setDateSub = {"Set date",
			MENU_ITEM_TYPE_GENERIC, &openSetDateView};
	const guiMenuItem_t setZoneSub = {"Set timezone",
			MENU_ITEM_TYPE_GENERIC, NULL};
	const guiMenuItem_t setLocationSub = {"Set location",
			MENU_ITEM_TYPE_GENERIC, NULL};
	const guiMenuItem_t *list2[4] = {&setTimeSub, &setDateSub, &setZoneSub, &setLocationSub};
	guiMenu_t timeSubMenu = {10, 30, 0, 3, list2};

void settingsMain(void){
//	drawMenu(activeMenu, 10, 30);
	drawGuiMenu(currentMenu);
	char tempStr[30] = {0};
	sprintf(&tempStr, "Settings");
	lcdPutStr(0, 0, tempStr, font_13_calibri);
	sprintf(&tempStr, "cnt:%d", counter);
	lcdPutStr(310, 0, tempStr, font_13_calibri);

//	lcdPutStr(10, 200, " !\"#$%&'()", circularLoader);
//	lcdPutChar(10, 200, 32, circularLoader);
	animate();
}
