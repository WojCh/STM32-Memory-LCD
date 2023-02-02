/*
 * guiMenu.c
 *
 *  Created on: 4 gru 2022
 *      Author: wojch
 */

#include "guiMenu.h"
//#include "../Src/utils/linkedList.h"

// create menu
menuList_t *createGuiMenu(menuConfig_t *settings){
	//allocate memory for menu structure
}

//add menu item
//void addMenuItem(menuList_t *menu, char* label, void (*action)(void), enum MENU_ITEM_TYPE type){
void addMenuItem(menuList_t *menu, char* label, void (*action)(void)){

}


void nextMenuItem(guiMenu_t *menu){
	if(menu->selectedItem<(menu->itemCount-1)){
		menu->selectedItem++;
	} else {
		menu->selectedItem=0;
//		if(menu->wrappingEnabled) menu->selectedItem=0;
	}
//	btn_BB.onSinglePressHandler = menuItemArray[settingsMenu.currentPosition]->action;
}
void prevMenuItem(guiMenu_t *menu){
	if(menu->selectedItem>0){
		menu->selectedItem--;
	} else {
		menu->selectedItem=menu->itemCount-1;
//		if(menu->wrappingEnabled) menu->selectedItem=0;
	}
//	btn_BB.onSinglePressHandler = menuItemArray[settingsMenu.currentPosition]->action;
}
void drawGuiMenu(guiMenu_t *menu){

		char tempStr[30] = {0};
		for(uint8_t i = 0; i < menu->itemCount; i++){
//			guiMenuItem_t *list = menu->itemList;
//			char* label = list[i].label;

//			char label[] = "label";
			sprintf(&tempStr, "cnt:%d", i);
			lcdPutStr(0, 40+20*i, ((menu->itemList)[i])->label, font_13_calibri);
			//			drawMenuItem(menuItemArray[i], i==menu->currentPosition, x, y+(menu->listItemHeight+1)*i);
			if(menu->selectedItem == i) lcdRect(0, 200, 40+20*i, 40+20*i+20, 2);
		}
}

// apply settings
//void menuApplySettings(menuList_t *menu, menuConfig_t *settings);

