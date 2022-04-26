/*
 * timeModule.c
 *
 *  Created on: 25 kwi 2022
 *      Author: wojch
 *
 *      TODO: in time module
 *      1. Showing time and date
 *      2. World time
 *      3. Stopwatch
 *      4. Timer
 *      5. Life count↓
 *      6. Time tracker
 *
 *
 *
 *
 *
 */

#include "timeModule.h"
#include "font13.h"
#include "digits5x9.h"

static void setDefaultClbcks(void){
	btn_B2.onSinglePressHandler = &returnToMenu;
}
// functions to execute while menu item highlighted
void timeDescription(void){
	char tempStr[30] = {0};
	sprintf(&tempStr, "Time will be shown");
	lcdPutStr(0, 9, tempStr, font13);
}

void timeSetup(void){
	setDefaultClbcks();
}

// functions to execute when menu item entered
void timeMain(void){

	char fracStr[30] = {0};
	char timeStr[30] = {0};

	sprintf(&timeStr, "%02d:%02d:%02d", RtcTime.Hours, RtcTime.Minutes, RtcTime.Seconds);
	sprintf(&fracStr, "%02d", 100*(RtcTime.SecondFraction - RtcTime.SubSeconds)/RtcTime.SecondFraction);
	lcdPutStr(130, 2, timeStr, dig5x9);
	lcdPutStr(275, 4, fracStr, font13);
}
