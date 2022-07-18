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


// fixed alt = 0/fixed baro = 1 mode
uint8_t baroMode = 0;

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
	sprintf(&str1, "%4.1f`C", bmpData.temperature);
	lcdPutStr(10, 14, str1, zektonSmallFont);
	sprintf(&str1, "%04.1fhPa", (float)bmpData.pressure/100);
	lcdPutStr(215, 14, str1, zektonSmallFont);
	if(baroMode == 0){
		sprintf(&str1, "%6.1f hPa@sl", bmpData.slpress/100);
		sprintf(&str3, "At const %.0fm asl", fixedAltitude);
	} else {
		sprintf(&str1, "Altitude %5.1fm asl", bmpData.altitude);
		sprintf(&str3, "For const %6.1fhPa", (BMP_PRESS_CONST_SEA_LEVEL/100));
	}
	lcdPutStr(0, 100, str1, zektonSmallFont);
	lcdPutStr(0, 150, str3, zektonSmallFont);
}

void changeBaroMode(void){
	if(baroMode == 0){
		BMP_PRESS_CONST_SEA_LEVEL = bmpData.slpress;
		baroMode = 1;
	} else {
		fixedAltitude = bmpData.altitude;
		baroMode = 0;
	}
}
void addBaro(void){
	if(baroMode == 0){
			fixedAltitude += 1;
		} else {
			BMP_PRESS_CONST_SEA_LEVEL += 10;
		}
}
void remBaro(void){
	if(baroMode == 0){
			fixedAltitude -= 1;
		} else {
			BMP_PRESS_CONST_SEA_LEVEL -= 10;
		}
}
