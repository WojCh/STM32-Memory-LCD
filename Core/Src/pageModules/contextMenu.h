/*
 * contextMenu.h
 *
 *  Created on: Jul 14, 2022
 *      Author: wojch
 */

#ifndef SRC_PAGEMODULES_CONTEXTMENU_H_
#define SRC_PAGEMODULES_CONTEXTMENU_H_

#include "gui.h"

static uint8_t isCntxOpen = 0;

const struct ContextAction{
	// name of the menu
	const char name[30];
	// action pointer
	const void (*main)(void);
};
extern struct ContextAction* ContextActions[3];


void showCntxMenu(void);
void hideCntxMenu(void);
void enableCntxMenu(void);


#endif /* SRC_PAGEMODULES_CONTEXTMENU_H_ */
