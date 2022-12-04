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

const enum MENU_ITEM_TYPE {
	GENERIC = 0,
	SUBMENU,
	LIST_SELECTOR,
	VAR_SELECTOR,
	TOGGLE
};
//add menu item
//void addMenuItem(menuList_t *menu, char* label, void (*action)(void), enum MENU_ITEM_TYPE type){
void addMenuItem(menuList_t *menu, char* label, void (*action)(void)){

}

// apply settings
//void menuApplySettings(menuList_t *menu, menuConfig_t *settings);

