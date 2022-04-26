/*
 * gui.h
 *
 *  Created on: 24 kwi 2022
 *      Author: wojch
 */

#ifndef INC_GUI_H_
#define INC_GUI_H_

//#include "main.h"
//#include "font13.h"
#include "buttons.h"
#include "bmp180.h"
#include "../Src/pageModules/baroModule.h"
#include "../Src/pageModules/timeModule.h"
#include "../Src/pageModules/gpsModule.h"
#include "../Src/pageModules/homeModule.h"
#include "../Src/pageModules/settingsModule.h"

const struct Module{
	// name of the module
	const char name[30];
	// setup function
	const void (*description)(void);
	// setup function
	const void (*setup)(void);
	// main
	const void (*main)(void);
};

extern char menuStr[][30];

void mainMenuSetup(void);
void showMainMenu(void);
void returnToMenu(void);

#endif /* INC_GUI_H_ */
