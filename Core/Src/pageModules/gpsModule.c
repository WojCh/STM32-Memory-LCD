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
uint8_t pageNum = 0;
extern gpsDevice_t gpsDev;
extern char dmaBuffer[];

location_t location;

void nextPg(void){
	pageNum++;
}
void prevPg(void){
	pageNum--;
}
void syncTime(void){
	RtcTime.Hours = location.utc_hour;
		RtcTime.Minutes = location.utc_min;
		RtcTime.Seconds = location.utc_sec;
		RtcTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
		RtcTime.StoreOperation = RTC_STOREOPERATION_RESET;
		if (HAL_RTC_SetTime(&hrtc, &RtcTime, RTC_FORMAT_BIN) != HAL_OK)
		{
		Error_Handler();
		}
}

static void setDefaultClbcks(void){
//	btn_B2.onSinglePressHandler = &returnToMenu;
	btn_BA.onSinglePressHandler = &nextScreen;
	btn_BC.onSinglePressHandler = &prevScreen;
	btn_B1.onSinglePressHandler = &nextPg;
	btn_B3.onSinglePressHandler = &prevPg;
	btn_B2.onSinglePressHandler = &syncTime;
}

void gpsSetup(void){
	setDefaultClbcks();

}

void gpsMain(void){
	char tempStr[51] = {0};

	switch(pageNum){
	case 0: {
		location = getLocation(&gpsDev);
		if(location.hasFix){
			sprintf(&tempStr, "GPS fix (%d satellites)", location.satNum);
			lcdPutStr(0, 0, tempStr, ocrFont);
			sprintf(&tempStr, "Latitude: %2.3f%c", location.latitude, location.n_s);
			lcdPutStr(0, 60, tempStr, ocrFont);
			sprintf(&tempStr, "Longitude: %.3f%c", location.longitude, location.w_e);
			lcdPutStr(0, 90, tempStr, ocrFont);
			sprintf(&tempStr, "Altitude: %f", location.elevation);
			lcdPutStr(0, 120, tempStr, ocrFont);
		} else {
			sprintf(&tempStr, "No fix - %d satellites", location.satNum);
			lcdPutStr(0, 0, tempStr, ocrFont);
		}
			sprintf(&tempStr, "UTC time: %02d:%02d %02d", location.utc_hour, location.utc_min, location.utc_sec);
			lcdPutStr(0, 30, tempStr, ocrFont);
		break;
	}
	case 1: {
		lcdPutStr(0, 0, tempStr, font_13_calibri);
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
		break;
	}
	default:{
		// show gpsDev buffer in many lines
		for(uint8_t i=0; i<6; i++){
			strncpy(&tempStr, &gpsDev.buffer[50*i], 50);
			lcdPutStr(0,120+14*i, tempStr, smallestFont);
		}
		break;
	}
	}





}
