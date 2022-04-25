/*
 * timeModule.c
 *
 *  Created on: 25 kwi 2022
 *      Author: wojch
 */

#include "timeModule.h"
#include "font13.h"
#include "digits5x9.h"



// functions to execute while menu item highlighted
void showTimeDesc(void){
	char tempStr[30] = {0};
	sprintf(&tempStr, "Time will be shown");
	lcdPutStr(0, 4, tempStr, font13);
}

// functions to execute when menu item entered
void showTimeScreen(void){
	btn_B2.onSinglePressHandler = &returnToMenu;
	char tempStr[30] = {0};
	char timeStr[30] = {0};
	uint8_t hh = 12;
	uint8_t mm = 34;
	uint8_t ss = 56;
	sprintf(&tempStr, "Time is shown here");
	sprintf(&timeStr, "%2d:%02d:%02d", hh, mm, ss);
//	lcdPutStr(0, 0, tempStr, font13);
	lcdPutStr(130, 2, timeStr, dig5x9);
}
