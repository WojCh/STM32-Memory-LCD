/*
 * gpsModule.c
 *
 *  Created on: 25 kwi 2022
 *      Author: wojch
 */

#include "gpsModule.h"
#include "fonts/fonts.h"

//#include <fonts/font_calibri13.h>

extern gpsDevice_t gpsDev;


void readGps(void){
	gpsDev.getData(&gpsDev);
}

static void setDefaultClbcks(void){
//	btn_B2.onSinglePressHandler = &returnToMenu;
	btn_BA.onSinglePressHandler = &nextScreen;
	btn_BC.onSinglePressHandler = &prevScreen;
	btn_BB.onSinglePressHandler = &readGps;
}

void gpsSetup(void){
	setDefaultClbcks();

}

void gpsMain(void){
	char tempStr[30] = {0};
	sprintf(&tempStr, "GPS will be shown");
	lcdPutStr(0, 0, tempStr, font_13_calibri);

//	lcdPutStr(0,30, &gpsDev.buffer, smallestFont);
//	gpsSentence gpsData;
//	readSentence(&gpsDev.buffer, &gpsData);
//	sprintf(&tempStr, "%s", gpsData.words[0]);
//	lcdPutStr(0,30, tempStr, font_13_calibri);
//	sprintf(&tempStr, "%s", gpsData.words[1]);
//	lcdPutStr(0,50, tempStr, font_13_calibri);
//	sprintf(&tempStr, "%s", gpsData.words[2]);
//	lcdPutStr(0,70, tempStr, font_13_calibri);
//	sprintf(&tempStr, "%s", gpsData.words[3]);
//	lcdPutStr(0,90, tempStr, font_13_calibri);
//	sprintf(&tempStr, "%s", gpsData.words[4]);
//	lcdPutStr(0,110, tempStr, font_13_calibri);
//	sprintf(&tempStr, "%s", gpsData.words[5]);
//	lcdPutStr(0,130, tempStr, font_13_calibri);
//	sprintf(&tempStr, "%s", gpsData.words[6]);
//	lcdPutStr(0,150, tempStr, font_13_calibri);
//	sprintf(&tempStr, "%s", gpsData.words[7]);
//	lcdPutStr(0,170, tempStr, font_13_calibri);
//	sprintf(&tempStr, "%s", gpsData.words[8]);
//	lcdPutStr(0,190, tempStr, font_13_calibri);
//	sprintf(&tempStr, "%s", gpsData.words[9]);
//	lcdPutStr(0,210, tempStr, font_13_calibri);
//	sprintf(&tempStr, "%s", gpsDev.buffer);



}
