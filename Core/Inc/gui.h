/*
 * gui.h
 *
 *  Created on: 24 kwi 2022
 *      Author: wojch
 */

#ifndef INC_GUI_H_
#define INC_GUI_H_

#define MENU_ITEM_NUM 5

//#include "main.h"
//#include "font13.h"
#include "buttons.h"
#include "bmp180.h"
#include "../Src/pageModules/menuModule.h"
#include "../Src/pageModules/baroModule.h"
#include "../Src/pageModules/timeModule.h"
#include "../Src/pageModules/gpsModule.h"
#include "../Src/pageModules/homeModule.h"
#include "../Src/pageModules/settingsModule.h"
#include "icons/icons_small.h"


const struct Module{
	// name of the module
	const char name[30];
	// setup function
	const void (*description)(void);
	// setup function
	const void (*setup)(void);
	// main
	const void (*main)(void);
	const Icon_TypeDef* icon;
};

extern struct Module menuItems[MENU_ITEM_NUM];
extern char menuStr[][30];

extern uint8_t position;
extern void (*moduleDescPtr)(void);
extern void (*moduleMainPtr)(void);
extern void (*moduleSetupPtr)(void);
extern void (*currentModulePtr)(void);

void prevPos(void);
void nextPos(void);
void nextScreen(void);
void prevScreen(void);
void resetPos(void);
void applySelectedScreen(void);
void selectScreen(void);
void returnToMenu(void);
void showGui(void);


#endif /* INC_GUI_H_ */
