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


#include "icons/icons_small.h"
#include "fonts/fonts.h"

#include <fonts/zekton45.h>
#include <fonts/font_zekton12.h>
#include "stopwatchModule.h"

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

// initialize stopwatch values
struct stopwatch_t stw_val = {0, 0, 0, 0};

struct stopwatch_t convertTicks(uint32_t ticks){
	struct stopwatch_t bff = {
		ticks/(100*60*60),
		ticks%(100*60*60)/(60*100),
		ticks%(60*100)/(100),
		ticks%100
	};
	return bff;
}

uint8_t* stwString(struct stopwatch_t stw, char* str){
	sprintf(str, "%dh%02d'%02d.%02d\"", stw.hours, stw.min, stw.sec, stw.csec);
	return str;
}
void updateStopwatch(void){
//	stw_val.hours = stwS.cnt/(100*60*60);
//	stw_val.min = stwS.cnt%(100*60*60)/(60*100);
//	stw_val.sec = stwS.cnt%(60*100)/(100);
//	stw_val.csec = stwS.cnt%100;
	stw_val.hours = stwS.cnt/(60*60);
	stw_val.min = stwS.cnt%(60*60)/(60);
	stw_val.sec = stwS.cnt%60;
	stw_val.csec = (uint8_t)getStw();
}

void stwSetup(void){
	setDefaultClbcks();
}


// functions to execute when menu item entered
void stwMain(void){
	char guiPos[6] = {0};
	sprintf(&guiPos, "%02d:%02d", RtcTime.Hours, RtcTime.Minutes);
	lcdPutStr(400 - 10 - (*zekton24font.font_Width) * strlen(guiPos), 10, guiPos, zekton24font);

	char tempStr2[30] = {0};
	sprintf(&guiPos, "Stopwatch");
	lcdPutStr(10, 10, guiPos, zekton24font);

	updateStopwatch();

	if(stw_val.hours != 0){
		sprintf(&tempStr2, "%01dh", stw_val.hours);
	}
	lcdPutStr(20, 95, tempStr2, zekton24font);
	sprintf(&tempStr2, "%02d'%02d.%02d\"", stw_val.min, stw_val.sec, stw_val.csec);
	lcdPutStr(380-(*(zekton45font.font_Width)*strlen(tempStr2)), 76, tempStr2, zekton45font);
	for(uint8_t i = 0; i < 7; i++){
		if(stwT.stwArray[i] != 0){
			sprintf(&tempStr2, "Lap %d:", i+1);
			lcdPutStr(0, 130+i*16, tempStr2, font_12_zekton);
			if(i>0){
				lcdPutStr(55, 130+i*16, stwString(convertTicks(stwT.stwArray[i]-stwT.stwArray[i-1]), &tempStr2), font_12_zekton);
			} else {
				lcdPutStr(55, 130+i*16, stwString(convertTicks(stwT.stwArray[i]), &tempStr2), font_12_zekton);
			}
			sprintf(&tempStr2, "Split:");
			lcdPutStr(165, 130+i*16, tempStr2, font_12_zekton);
			lcdPutStr(225, 130+i*16, stwString(convertTicks(stwT.stwArray[i]), &tempStr2), font_12_zekton);
		}
	}
}
