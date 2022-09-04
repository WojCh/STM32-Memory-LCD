/*
 * gpsModule.c
 *
 *  Created on: 25 kwi 2022
 *      Author: wojch
 */

#include "gpsModule.h"
#include "fonts/fonts.h"
#include "gps2.h"
//#include <fonts/font_calibri13.h>

extern gpsDevice_t gpsDev;
extern char dmaBuffer[];
void readGps(void){
//	gpsDev.getData(&gpsDev);

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
	char tempStr[51] = {0};
	sprintf(&tempStr, "GPS will be shown");

	lcdPutStr(0, 0, tempStr, font_13_calibri);
//	location_t loc = getLocation(&gpsDev);
//	double lat = 17.8;
//	sprintf(&tempStr, "lat: %f", getLocation(&gpsDev).latitude);
//	sprintf(&tempStr, "lat: %f", lat);
//	lcdPutStr(0, 220, tempStr, font_13_calibri);
	lcdPutStr(0, 25, getLocation(&gpsDev).debug, smallestFont);

	sprintf(&tempStr, "%x", getLocation(&gpsDev).chk);
	lcdPutStr(0, 50, tempStr, smallestFont);

//	for(uint8_t i=0; i<6; i++){
//		strncpy(&tempStr, &dmaBuffer[50*i], 50);
////		strncpy(&tempStr, &(gpsDev.buffer[50*i]), 50);
//		lcdPutStr(0,25+14*i, tempStr, smallestFont);
//	}
	for(uint8_t i=0; i<6; i++){
//		strncpy(&tempStr, &dmaBuffer[50*i], 50);
		strncpy(&tempStr, &gpsDev.buffer[50*i], 50);
		lcdPutStr(0,120+14*i, tempStr, smallestFont);
	}

//	gpsSentence gpsData;
//	readSentence(&dmaBuffer, &gpsData);
//	sprintf(&tempStr, "%d", gpsData.isValid);
//	lcdPutStr(300,0, tempStr, font_13_calibri);
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
