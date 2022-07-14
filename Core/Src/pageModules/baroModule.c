/*
 * baroModule.c
 *
 *  Created on: 25 kwi 2022
 *      Author: wojch
 */

#include "baroModule.h"
#include "font13.h"
#include "digits5x9.h"

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
	char str2[50] = {0};
	char str3[50] = {0};
	char str4[50] = {0};
	char temp[50] = {0};
	char pres[50] = {0};
	char alti[50] = {0};
	sprintf(&str1, "%4.2f degC %04.2f hPa", bmpData.temperature, ((float)bmpData.pressure/100));
	if(baroMode == 0){
		sprintf(&str2, "%6.2f hPa@asl.", bmpData.slpress/100);
		sprintf(&str3, "Fix. Alt: %.0f m.asl", fixedAltitude);
	} else {
		sprintf(&str2, "%6.2f m.asl.", bmpData.altitude);
		sprintf(&str3, "Fix. Baro: %6.2f hPa", (BMP_PRESS_CONST_SEA_LEVEL/100));
	}
	lcdPutStr(0, 0, str1, dig5x9);
	lcdPutStr(0, 2*25, str2, dig5x9);
	lcdPutStr(0, 3*25, str3, dig5x9);
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
			BMP_PRESS_CONST_SEA_LEVEL += 1;
		}
}
void remBaro(void){
	if(baroMode == 0){
			fixedAltitude -= 1;
		} else {
			BMP_PRESS_CONST_SEA_LEVEL -= 1;
		}
}

//void showBaroDesc(void){
//	char tempStr[30] = {0};
//	sprintf(&tempStr, "Baro will be shown");
//	lcdPutStr(0, 9, tempStr, font13);
//}
//void showBaroScreen(void){
//	btn_B2.onSinglePressHandler = &returnToMenu;
//	btn_BB.onSingleLongPressHandler = &changeBaroMode;
//	btn_BC.onContinuousShortPressHandler = &addBaro;
//	btn_BA.onContinuousShortPressHandler = &remBaro;
//
//	char str1[50] = {0};
//	char str2[50] = {0};
//	char str3[50] = {0};
//	char str4[50] = {0};
//	char temp[50] = {0};
//	char pres[50] = {0};
//	char alti[50] = {0};
//	sprintf(&str1, "%4.2f degC %04.2f hPa", bmpData.temperature, ((float)bmpData.pressure/100));
//	if(baroMode == 0){
//		sprintf(&str2, "%6.2f hPa@asl.", bmpData.slpress/100);
//		sprintf(&str3, "Fix. Alt: %.0f m.asl", fixedAltitude);
//	} else {
//		sprintf(&str2, "%6.2f m.asl.", bmpData.altitude);
//		sprintf(&str3, "Fix. Baro: %6.2f hPa", (BMP_PRESS_CONST_SEA_LEVEL/100));
//	}
//	lcdPutStr(0, 0, str1, dig5x9);
//	lcdPutStr(0, 2, str2, dig5x9);
//	lcdPutStr(0, 3, str3, dig5x9);
//}
