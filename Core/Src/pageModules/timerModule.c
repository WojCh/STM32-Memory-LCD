/*
 * timerModule.c
 *
 *  Created on: Nov 27, 2022
 *      Author: wojch
 */


#include "timerModule.h"
#include "fonts/fonts.h"

extern 	countdown_t countDown1;


void startPauseTimer(void){
	if(countDown1.isRunning){
		pauseTimer(&countDown1);
	} else {
		startTimer(&countDown1);
	}
}
void resetTim(void){
	resetTimer(&countDown1);
}
void setTim(void){
	setTimer(&countDown1, 5*60);
}

static void setDefaultClbcks(void){
	btn_BA.onSinglePressHandler = &nextScreen;
	btn_BC.onSinglePressHandler = &prevScreen;
	btn_BB.onSinglePressHandler = &startPauseTimer;
	btn_B1.onSinglePressHandler = &setTim;
	btn_B2.onSinglePressHandler = &resetTim;
}

void timerSetup(void){
	setDefaultClbcks();
}

void timerMain(void){
	char tempStr[51] = {0};
	sprintf(&tempStr, "Timer");
	lcdPutStr(10, 10, tempStr, zekton24font);

	char guiPos[6] = {0};
	sprintf(&guiPos, "%02d:%02d", RtcTime.Hours, RtcTime.Minutes);
	lcdPutStr(400 - 10 - (*zekton24font.font_Width) * strlen(guiPos), 10, guiPos, zekton24font);

	sprintf(&tempStr, "%02dh %02d'%02d\"", countDown1.remainingSec/3600, (countDown1.remainingSec%3600)/60, countDown1.remainingSec%60);
	lcdPutStr(380-(*(zekton45font.font_Width)*strlen(tempStr)), 76, tempStr, zekton45font);
	sprintf(&tempStr, "%02dh %02d'%02d\"", countDown1.setpoint/3600, (countDown1.setpoint%3600)/60, countDown1.setpoint%60);
	lcdPutStr(20, 165, tempStr, font_12_zekton);
	if(countDown1.isRunning){
		sprintf(&tempStr, "running");
		lcdPutStr(380-(*(font_12_zekton.font_Width)*strlen(tempStr)), 165, tempStr, font_12_zekton);
	} else {
		sprintf(&tempStr, "paused");
		lcdPutStr(380-(*(font_12_zekton.font_Width)*strlen(tempStr)), 165, tempStr, font_12_zekton);
	}

	lcdRect2(20, 400-20, 140, 160, 1, 0, 1);
	// 22 - 400-22
	uint16_t barx = 22+((countDown1.setpoint-countDown1.remainingSec)*(400-22-22))/countDown1.setpoint;
	lcdRect2(barx, 400-22, 142, 158, 1, 6, 0);
}
