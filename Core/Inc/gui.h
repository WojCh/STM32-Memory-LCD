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

struct Module{
	// name of the module
	char name[30];
	// setup function
	void (*moduleSetup)(void*);
	// main
	void (*moduleMain)(void*);
};

extern char menuStr[][30];

void showMainMenu(void);
void returnToMenu(void);

#endif /* INC_GUI_H_ */
