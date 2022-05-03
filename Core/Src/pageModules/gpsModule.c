/*
 * gpsModule.c
 *
 *  Created on: 25 kwi 2022
 *      Author: wojch
 */

#include "gpsModule.h"
#include "font13.h"
#include "digits5x9.h"

static void setDefaultClbcks(void){
	btn_B2.onSinglePressHandler = &returnToMenu;
}

void gpsDescription(void){
//	char tempStr[30] = {0};
//	sprintf(&tempStr, "GPS will be shown");
//	lcdPutStr(0, 9, tempStr, font13);
}

void gpsSetup(void){
	setDefaultClbcks();

}

void gpsMain(void){
	char tempStr[30] = {0};
	sprintf(&tempStr, "GPS will be shown");
	lcdPutStr(0, 0, tempStr, font13);
}
