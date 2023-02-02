/*
 * guiMenu.h
 *
 *  Created on: 4 gru 2022
 *      Author: wojch
 */

#ifndef SRC_UTILS_GUIMENU_H_
#define SRC_UTILS_GUIMENU_H_

#include <stdint.h>
#include "gui.h"

const enum MENU_ITEM_TYPE {
	MENU_ITEM_TYPE_GENERIC = 0,
	MENU_ITEM_TYPE_SUBMENU,
	MENU_ITEM_TYPE_LIST_SELECTOR,
	MENU_ITEM_TYPE_VAR_SELECTOR,
	MENU_ITEM_TYPE_TOGGLE,
//	DROPDOWN
};
typedef struct guiMenuItem_t{
	const char label[30];						// name
	enum MENU_ITEM_TYPE type;			// type of item
	void (*actionCallback)(void);
//	void (*genericAction)(void);		// action callback when clicked on
//	struct guiMenu_t *submenuPtr;	// submenu pointer
//	uint8_t toggleState;				// state
}guiMenuItem_t;

typedef struct guiMenu_t{
	uint16_t x;					// x position of the menu
	uint16_t y;					// y position of the menu
//	uint16_t height;			// max height of the menu
//	uint16_t width;				// max width of the menu
//	uint8_t showScroll;			// showing scrollbar
//	uint8_t wrappingEnabled;	// when reached end of the list, wrap to start
//	Font_TypeDef *font;			// font used for labels
//	uint8_t listItemHeight;		// height of single list item

	uint8_t selectedItem;
	uint8_t itemCount;
	guiMenuItem_t **itemList;
}guiMenu_t;


#define MENU_SHOW_SCROLL 		1
#define MENU_HIDE_SCROLL 		0
#define MENU_WRAPPING_ENABLED 	1
#define MENU_WRAPPING_DISABLED 	0

// menu settings
typedef struct menuConfig_t{
	uint16_t x;					// x position of the menu
	uint16_t y;					// y position of the menu
	uint16_t height;			// max height of the menu
	uint16_t width;				// max width of the menu
	uint8_t showScroll;			// showing scrollbar
	uint8_t itemNum;			// number of items in the menu
	uint8_t wrappingEnabled;	// when reached end of the list, wrap to start
	Font_TypeDef *font;			// font used for labels
	uint8_t listItemHeight;		// height of single list item
}menuConfig_t;

typedef struct menuItem_t{
	const char *label;
	void (*action)(void);
}menuItem_t;

typedef struct menuList_t{
	uint8_t currentPosition;	// position of highlighted item
	void (*actionClbk)(void);	// action callback
	menuItem_t *items[8];		// list of items
} menuList_t;

#endif /* SRC_UTILS_GUIMENU_H_ */
