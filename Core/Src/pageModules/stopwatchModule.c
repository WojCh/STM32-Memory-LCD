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

uint8_t stwSubView = 0;
void switchStwView(void){
//	if(stwSubView<3){
//		stwSubView++;
//	} else {
//		stwSubView = 0;
//	}
		stwSubView++;
}

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
//	stwT.clear();
}
void saveStopwatch(){
	stwSave();
}

static void setDefaultClbcks(void){
	btn_B3.onSinglePressHandler = &resetPos;
	btn_BA.onSinglePressHandler = &nextScreen;
	btn_BC.onSinglePressHandler = &prevScreen;

	btn_B1.onSinglePressHandler = &switchStwView;
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
struct stopwatch_t stw_lap_val = {0, 0, 0, 0};

void stwSetup(void){
	setDefaultClbcks();
}
// position of the top of the stopwatch total value
uint8_t stw_time_y_pos = 40;

// functions to execute when menu item entered
void stwMain(void){

//	lcdPutIcon(2, 200, accept_icon);
//	lcdPutIcon(370, 106, play_pause_icon);
//	lcdPutIcon(2, 106, cancel_icon);

	// statusbar
	lcdPutIcon(320, 5, full_battery_icon);
	char timeString[6] = {0};
	sprintf(&timeString, "%02d:%02d", RtcTime.Hours, RtcTime.Minutes);
	lcdPutStr(400 - 5 - (*font_12_zekton.font_Width) * strlen(timeString), 5, timeString, font_12_zekton);
	char tempStr2[30] = {0};
	sprintf(&tempStr2, "Stopwatch");
	lcdPutStr(5, 5, tempStr2, font_12_zekton);

	// update stopwatch value
	getStw(&stw_val, &stwS);

	// main STW view
	//show hours if exist
	if(stw_val.hours != 0){
//	if(1){
		sprintf(&tempStr2, "%02dh %02d'%02d\"", stw_val.hours, stw_val.min, stw_val.sec);
		lcdPutStr(380-(*(zekton45font.font_Width)*strlen(tempStr2)), stw_time_y_pos, tempStr2, zekton45font);
//	} else if(stw_val.min != 0){
	} else {
		sprintf(&tempStr2, "%02d'%02d.%02d\"", stw_val.min, stw_val.sec, stw_val.csec);
		lcdPutStr(365-(*(zekton45font.font_Width)*strlen(tempStr2)), stw_time_y_pos, tempStr2, zekton45font);
	}
//	} else {
//		sprintf(&tempStr2, "%02d.%02d\"", stw_val.sec, stw_val.csec);
//		lcdPutStr(365-(*(zekton45font.font_Width)*strlen(tempStr2)), stw_time_y_pos, tempStr2, zekton45font);
//	}

	stw_counter_t lapTimeCnt;
	switch(stwSubView){
//		case 0:
//			sprintf(&tempStr2, "Stopwatch ready", getLapNum());
//			lcdPutStr(55, 100, tempStr2, zekton24font);
//			break;
		case 0:
			if(getLapNum()>0){
				sprintf(&tempStr2, "LAP %d", getLapNum());
				lcdPutStr(250, 112, tempStr2, font_12_zekton);
				counterDiff(&lapTimeCnt, stwS.cnt, &stw_splits[getLapNum()-1]);
				counterToStopwatch(&stw_lap_val, &lapTimeCnt);
				stwprintf(&tempStr2, &stw_lap_val);
				lcdPutStr(60, 100, tempStr2, zekton24font);
				lcdRoundedRect2(240, 305, 110, 124, 2, LCD_RECT_PATTERN_FILL, 0, 2);
			}
			for(uint8_t i = 1; i<=4; i++){
				if(getLapNum()>i){
					sprintf(&tempStr2, "LAP %d", getLapNum()-i);
					lcdPutStr(250, 112+i*28, tempStr2, font_12_zekton);
					counterDiff(&lapTimeCnt, &stw_splits[getLapNum()-i], &stw_splits[getLapNum()-1-i]);
					counterToStopwatch(&stw_lap_val, &lapTimeCnt);
					stwprintf(&tempStr2, &stw_lap_val);
					lcdPutStr(60, 100+28*i, tempStr2, zekton24font);
				}
			}
			break;
		case 1:
			// split/lap table
			for(uint8_t i = 1; i<=5; i++){
				if(getLapNum()>i){
					counterToStopwatch(&stw_lap_val, &stw_splits[getLapNum()-i]);
					stwprintf(&tempStr2, &stw_lap_val);
					lcdPutStr(60, 100+28*(i-1), tempStr2, zekton24font);

					sprintf(&tempStr2, "SPLIT %d", getLapNum()-i);
					lcdPutStr(250, 112+(i-1)*28, tempStr2, font_12_zekton);

				}
			}
			break;
		default:
			stwSubView = 0;
	}







}
