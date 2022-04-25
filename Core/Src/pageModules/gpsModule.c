/*
 * gpsModule.c
 *
 *  Created on: 25 kwi 2022
 *      Author: wojch
 */

#include "gpsModule.h"
#include "font13.h"
#include "digits5x9.h"

void showGpsDesc(void){
	char tempStr[30] = {0};
	sprintf(&tempStr, "GPS will be shown");
	lcdPutStr(0, 4, tempStr, font13);
}


void showGpsScreen(void){
	btn_B2.onSinglePressHandler = &returnToMenu;
}
