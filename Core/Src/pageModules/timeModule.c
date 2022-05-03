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
#include "digits_larabie.h"
#include "font_larabie.h"
#include "font_larabie36.h"
#include "icons/icons_small.h"
#include "fonts/minimalFont.h"
#include "fonts/smallestFont.h"
#include "fonts/ocrFont.h"



static void setDefaultClbcks(void){
	btn_B2.onSinglePressHandler = &returnToMenu;

}
// functions to execute while menu item highlighted
void timeDescription(void){
//	char tempStr[30] = {0};
//	sprintf(&tempStr, "Time will be 24h45.2min");
//	lcdPutStr(0,132, tempStr, smallestFont);
//	lcdPutStr(4,140, tempStr, smallestFont);
//	lcdPutStr(7,180, tempStr, ocrFont);
//	lcdPutStr(4,5, tempStr, font13);
}

void timeSetup(void){
	setDefaultClbcks();
}

// functions to execute when menu item entered
void timeMain(void){

	char fracStr[30] = {0};
	char timeStr[30] = {0};

//	sprintf(&timeStr, "a%02d:%02d.%02d", RtcTime.Hours, RtcTime.Minutes, RtcTime.Seconds);
	sprintf(&timeStr, "%02d%02d", RtcTime.Hours, RtcTime.Minutes);
//	sprintf(&fracStr, "%02d", 100*(RtcTime.SecondFraction - RtcTime.SubSeconds)/RtcTime.SecondFraction);
	sprintf(&fracStr, "%02d", RtcTime.Seconds);
	lcdPutStr(0, 0, timeStr, bigDigitsLarabie);
	lcdPutStr(300, 0, fracStr, fontLarabieMedium);

	lcdPutIcon(20, 120, timeIcon);
//	lcdPutIcon(4, 211, lockIcon);
//	lcdPutIcon(8, 222, lockIcon);
}
