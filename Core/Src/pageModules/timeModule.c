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
#include "fonts/zekton14.h"
#include "fonts/zekton14b.h"
#include "fonts/zekton24.h"

#include <fonts/zekton45.h>

void startStopwatch(){
	stwStart();
	btn_BB.onSinglePressHandler = &stopStopwatch;
	btn_B2.onSinglePressHandler = &saveStopwatch;
}
void stopStopwatch(){
	stwStop();
	btn_BB.onSinglePressHandler = &startStopwatch;
	btn_B2.onSinglePressHandler = &resetStopwatch;
}
void resetStopwatch(){
	stwClear();
	stwT.clear();
}
void saveStopwatch(){
	stwSave();
}

static void setDefaultClbcks(void){
	btn_B3.onSingleLongPressHandler = &returnToMenu;
	btn_B3.onSinglePressHandler = &resetPos;
	btn_BA.onSinglePressHandler = &nextScreen;
	btn_BC.onSinglePressHandler = &prevScreen;
	// Start/pause stw
	if(stwS.state){
		btn_BB.onSinglePressHandler = &stopStopwatch;
		btn_B2.onSinglePressHandler = &saveStopwatch;
	} else {
		btn_BB.onSinglePressHandler = &startStopwatch;
		btn_B2.onSinglePressHandler = &resetStopwatch;
	}
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

struct stopwatch_t{
	uint8_t hours;
	uint8_t min;
	uint8_t sec;
	uint8_t csec;
};
struct stopwatch_t stw_val = {0, 0, 0, 0};

struct stopwatch_t convBuffer = {0, 0, 0, 0};
struct stopwatch_t convertTicks(uint32_t ticks){
	struct stopwatch_t bff = {
		stwS.cnt/(100*60*60),
		stwS.cnt%(100*60*60)/(60*100),
		stwS.cnt%(60*100)/(100),
		stwS.cnt%100
	};
	return bff;
}
uint8_t* stwString(struct stopwatch_t stw){
	char str[20] = {0};
	sprintf(&str, "%dh%02d'%02d.%02d\"", stw.hours, stw.min, stw.sec, stw.csec);
	return &str;
}
void updateStopwatch(void){
	stw_val.hours = stwS.cnt/(100*60*60);
	stw_val.min = stwS.cnt%(100*60*60)/(60*100);
	stw_val.sec = stwS.cnt%(60*100)/(100);
	stw_val.csec = stwS.cnt%100;
}

void timeSetup(void){
	setDefaultClbcks();
}


// functions to execute when menu item entered
void timeMain(void){
	char tempStr[4] = {0};
	char funcArr[6][4] = {"STW", "TMR", "WRT", "TRK", "LFT", "SLT"};
	for(uint8_t i = 0; i < 6; i++){
		sprintf(&tempStr, funcArr[i]);
		if(i == 0){
			lcdPutStr(10+50*i, 10, tempStr, zecton12bfont);
		} else {
			lcdPutStr(10+50*i, 10, tempStr, zecton12font);
		}
	}

	char guiPos[6] = {0};
	sprintf(&guiPos, "%02d:%02d", RtcTime.Hours, RtcTime.Minutes);
	lcdPutStr(400 - 10 - (*zecton12font.font_Width) * strlen(guiPos), 10, guiPos, zecton12font);

	updateStopwatch();
	char tempStr2[30] = {0};
	sprintf(&tempStr2, "%01dh", stw_val.hours);
	lcdPutStr(0, 50, tempStr2, zektonSmallFont);
	sprintf(&tempStr2, "%02d'%02d.%02d\"", stw_val.min, stw_val.sec, stw_val.csec);
	lcdPutStr(0, 76, tempStr2, zecton45font);
	for(uint8_t i = 0; i < 7; i++){
		sprintf(&tempStr2, "%d. %d\"", i, stwT.stwArray[i]%(60*100)/100);
		lcdPutStr(0, 125+i*16, tempStr2, zecton12font);
	}

//	sprintf(&tempStr2, "%d", stwS.cnt);
//	lcdPutStr(0, 130, tempStr2, zecton45font);
//	sprintf(&tempStr2, "%d", stwS.state);
//	lcdPutStr(0, 184, tempStr2, zecton45font);
}
