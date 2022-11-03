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
extern location_t location;


void nextPg(void){
	pageNum++;
}
void prevPg(void){
	pageNum--;
}
void syncTime(void){
	if(location.isValid){

	RtcTime.Hours = location.utc_hour+GLOBAL_timezone;
		RtcTime.Minutes = location.utc_min;
		RtcTime.Seconds = location.utc_sec;
		RtcTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
		RtcTime.StoreOperation = RTC_STOREOPERATION_RESET;
		if (HAL_RTC_SetTime(&hrtc, &RtcTime, RTC_FORMAT_BIN) != HAL_OK)
		{
		Error_Handler();
		}
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
		uint8_t locUpdated = 0;
		locUpdated = getLocation(&gpsDev, &location);
		if(location.hasFix & location.isValid){
			sprintf(&tempStr, "GPS fix (%d satellites)", location.satNum);
			lcdPutStr(200, 220, tempStr, smallestFont);
			sprintf(&tempStr, "UTC %02d%02d %02d", location.utc_hour, location.utc_min, location.utc_sec);
			lcdPutStr(0, 0, tempStr, ocrFont);
			sprintf(&tempStr, "LOC %02d%02d %02d", RtcTime.Hours, RtcTime.Minutes, RtcTime.Seconds);
			lcdPutStr(220, 0, tempStr, ocrFont);
			sprintf(&tempStr, "GMT%+d", GLOBAL_timezone);
			lcdPutStr(220, 20, tempStr, ocrFont);
			sprintf(&tempStr, "%c%3d`%.3f'", location.n_s, location.latitudeDeg, location.latitudeMin);
			lcdPutStr(0, 50, tempStr, zekton45font);
			sprintf(&tempStr, "%c%3d`%.3f'", location.w_e, location.longitudeDeg, location.longitudeMin);
			lcdPutStr(0, 110, tempStr, zekton45font);
			sprintf(&tempStr, "ALT: %.1fm", location.elevation);
			lcdPutStr(20, 170, tempStr, zekton24font);

		} else {
			sprintf(&tempStr, "No fix - %d satellites", location.satNum);
			lcdPutStr(0, 0, tempStr, ocrFont);
			sprintf(&tempStr, "UTC time: %02d:%02d %02d", location.utc_hour, location.utc_min, location.utc_sec);
			lcdPutStr(0, 30, tempStr, ocrFont);
		}
		if(locUpdated){
			sprintf(&tempStr, "location updated");
			lcdPutStr(0, 220, tempStr, smallestFont);
		}
		break;
	}
	case 1: {
		getLocation(&gpsDev, &location);
		lcdPutStr(0, 25, location.debug, smallestFont);
		lcdPutStr(0, 40, location.words[0], smallestFont);
		lcdPutStr(0, 55, location.words[1], smallestFont);
		lcdPutStr(0, 70, location.words[2], smallestFont);
		lcdPutStr(0, 85, location.words[3], smallestFont);
		lcdPutStr(0, 100, location.words[4], smallestFont);
		lcdPutStr(100, 25, location.words[5], smallestFont);
		lcdPutStr(100, 40, location.words[6], smallestFont);
		lcdPutStr(100, 55, location.words[7], smallestFont);
		lcdPutStr(100, 70, location.words[8], smallestFont);
		lcdPutStr(100, 85, location.words[9], smallestFont);
		lcdPutStr(100, 100, location.words[10], smallestFont);
		lcdPutStr(200, 25, location.words[11], smallestFont);
		lcdPutStr(200, 40, location.words[12], smallestFont);
		break;
	}
	default:{
		// show gpsDev buffer in many lines
//		for(uint8_t i=0; i<6; i++){
//			strncpy(&tempStr, &gpsDev.buffer[50*i], 50);
//			lcdPutStr(0,120+14*i, tempStr, smallestFont);
//		}
		char tempStr2[GPS_BUFFER_SIZE+1] = {0};

		strcpy(&tempStr2, &gpsDev.buffer);
		lcdPutStrML(0,0, tempStr2, smallestFont);
		break;
	}
	}





}
