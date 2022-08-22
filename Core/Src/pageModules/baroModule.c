/*
 * baroModule.c
 *
 *  Created on: 25 kwi 2022
 *      Author: wojch
 */

#include "baroModule.h"
#include "font13.h"
#include "digits5x9.h"
#include <fonts/zekton45.h>
#include "fonts/zekton24.h"
#include "fonts/zekton14.h"
#include "fonts/zekton14b.h"

// fixed alt = 0/fixed baro = 1 mode
uint8_t baroMode = BARO_MODE_FIXED_ALTITUDE;

static void setDefaultClbcks(void){
//	btn_B2.onSinglePressHandler = &returnToMenu;
	btn_BA.onSinglePressHandler = &nextScreen;
	btn_BC.onSinglePressHandler = &prevScreen;
	btn_BB.onSingleLongPressHandler = &changeBaroMode;
	btn_B3.onContinuousShortPressHandler = &addBaro;
	btn_B1.onContinuousShortPressHandler = &remBaro;
}

// function executed once on module load
void baroSetup(void){
	setDefaultClbcks();
}

// main function
void baroMain(void){
	char str1[50] = {0};
	char str3[50] = {0};
	char str4[50] = {0};
	sprintf(&str1, "Temperature: %4.1f`C", bmpData.temperature);
	lcdPutStr(10, 14, str1, zekton12font);
	sprintf(&str1, "Ambient pressure: %04.1fhPa", (float)bmpData.pressure/100);
	lcdPutStr(10, 30, str1, zekton12font);
	if(baroMode == BARO_MODE_FIXED_ALTITUDE){
		sprintf(&str4, "Fixed altitude mode");
		sprintf(&str1, "Pressure %6.1f hPa at the sea level", bmpData.slpress/100);
		sprintf(&str3, "At const %.0fm above sea level", fixedAltitude);
	} else {
		sprintf(&str4, "Fixed pressure mode");
		sprintf(&str1, "Altitude %5.1fm above sea level", bmpData.altitude);
		sprintf(&str3, "For const pressure %6.1f hPa", (BMP_PRESS_CONST_SEA_LEVEL/100));
	}
	lcdPutStr(10, 50, str4, zekton12font);
	lcdPutStr(10, 66, str1, zekton12font);
	lcdPutStr(10, 82, str3, zekton12font);
}

void changeBaroMode(void){
	if(baroMode == BARO_MODE_FIXED_ALTITUDE){
		BMP_PRESS_CONST_SEA_LEVEL = bmpData.slpress;
		baroMode = BARO_MODE_FIXED_PRESSURE;
	} else {
		fixedAltitude = bmpData.altitude;
		baroMode = BARO_MODE_FIXED_ALTITUDE;
	}
}
void addBaro(void){
	if(baroMode == BARO_MODE_FIXED_ALTITUDE){
			fixedAltitude += 1;
		} else {
			BMP_PRESS_CONST_SEA_LEVEL += 10;
		}
}
void remBaro(void){
	if(baroMode == BARO_MODE_FIXED_ALTITUDE){
			fixedAltitude -= 1;
		} else {
			BMP_PRESS_CONST_SEA_LEVEL -= 10;
		}
}
