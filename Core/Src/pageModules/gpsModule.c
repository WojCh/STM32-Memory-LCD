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
	lcdPutStr(0, 40, getLocation(&gpsDev).words[0], smallestFont);
	lcdPutStr(0, 55, getLocation(&gpsDev).words[1], smallestFont);
	lcdPutStr(0, 70, getLocation(&gpsDev).words[2], smallestFont);
	lcdPutStr(0, 85, getLocation(&gpsDev).words[3], smallestFont);
	lcdPutStr(0, 100, getLocation(&gpsDev).words[4], smallestFont);
	lcdPutStr(100, 25, getLocation(&gpsDev).words[5], smallestFont);
	lcdPutStr(100, 40, getLocation(&gpsDev).words[6], smallestFont);
	lcdPutStr(100, 55, getLocation(&gpsDev).words[7], smallestFont);
	lcdPutStr(100, 70, getLocation(&gpsDev).words[8], smallestFont);
	lcdPutStr(100, 85, getLocation(&gpsDev).words[9], smallestFont);
	lcdPutStr(100, 100, getLocation(&gpsDev).words[10], smallestFont);
	lcdPutStr(200, 25, getLocation(&gpsDev).words[11], smallestFont);
	lcdPutStr(200, 40, getLocation(&gpsDev).words[12], smallestFont);




	// show gpsDev buffer in many lines
	for(uint8_t i=0; i<6; i++){
		strncpy(&tempStr, &gpsDev.buffer[50*i], 50);
		lcdPutStr(0,120+14*i, tempStr, smallestFont);
	}
}
