/*
 * settingsModule.c
 *
 *  Created on: 25 kwi 2022
 *      Author: wojch
 */

#include "settingsModule.h"
#include "font13.h"
#include "digits5x9.h"

static void setDefaultClbcks(void){
	btn_B2.onSinglePressHandler = &returnToMenu;
}

void settingsDescription(void){
//	char tempStr[30] = {0};
//	sprintf(&tempStr, "Settings will be shown");
//	lcdPutStr(0, 9, tempStr, font13);
}

void settingsSetup(void){
	setDefaultClbcks();
}

void settingsMain(void){
	char tempStr[30] = {0};
	sprintf(&tempStr, "Settings will be shown");
	lcdPutStr(0, 0, tempStr, font13);
}
