/*
 * gui.h
 *
 *  Created on: 24 kwi 2022
 *      Author: wojch
 */

#ifndef INC_GUI_H_
#define INC_GUI_H_

#define MENU_ITEM_NUM 6

//#include "main.h"
//#include "font13.h"
#include "buttons.h"
#include "bmp180.h"
#include "../Src/pageModules/watchfaceModule.h"
#include "../Src/pageModules/baroModule.h"
#include "../Src/pageModules/stopwatchModule.h"
#include "../Src/pageModules/gpsModule.h"
#include "../Src/pageModules/localInfo.h"
#include "../Src/pageModules/settingsModule.h"
#include "icons/icons_small.h"


const struct Module{
	// name of the module
	const char name[30];
	// setup function
	const void (*setup)(void);
	// main
	const void (*main)(void);
};

extern struct Module menuItems[MENU_ITEM_NUM];

extern uint8_t position;
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
