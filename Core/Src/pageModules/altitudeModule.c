/*
 * altitudeModule.c
 *
 *  Created on: 25 kwi 2022
 *      Author: wojch
 */

#include "altitudeModule.h"
#include "fonts/fonts.h"

// fixed alt = 0/fixed baro = 1 mode
uint8_t altitudeMode = 1;

static void setDefaultClbcks(void){
//	btn_B2.onSinglePressHandler = &returnToMenu;
	btn_BA.onSinglePressHandler = &nextScreen;
	btn_BC.onSinglePressHandler = &prevScreen;
	btn_BB.onSinglePressHandler = &changeAltiMode;
	btn_B3.onContinuousShortPressHandler = &increaseAltitude;
	btn_B1.onContinuousShortPressHandler = &decreaseAltitude;
	btn_B2.onSinglePressHandler = &setRefAltitude;
	btn_B2.onSingleLongPressHandler = &clearRefAltitude;
}

// function executed once on module load
void altiSetup(void){
	setDefaultClbcks();
	minAltitude = bmpData.altitude;
}

// main function
void altiMain(void){
	// header bar temperature - time
	char guiPos[6] = {0};
	sprintf(&guiPos, "%02d:%02d", RtcTime.Hours, RtcTime.Minutes);
	lcdPutStr(400 - 10 - (*zekton24font.font_Width) * strlen(guiPos), 10, guiPos, zekton24font);
	sprintf(&guiPos, "%02.1f`C", bmpData.temperature);
	lcdPutStr(10, 10, guiPos, zekton24font);

	if(altitudeMode){
		// altitude - pressure at the sea level
		char tmpStr[50] = {0};
		sprintf(&tmpStr, "%d", (int16_t)bmpData.altitude);
		lcdPutStr(350-(*(zekton84font.font_Width)*(strlen(tmpStr)+1)), 66, tmpStr, zekton84font);
		sprintf(&tmpStr, ".%1um", ((uint16_t)(fabs(bmpData.altitude)*10))%10);
		lcdPutStr(420-(*(zekton45font.font_Width)*(strlen(tmpStr)+1)), 66, tmpStr, zekton45font);
//		sprintf(&tmpStr, "m ", bmpData.pressure%100/10);
//		lcdPutStr(420-(*(zekton45font.font_Width)*(strlen(tmpStr)+1)), 112, tmpStr, zekton45font);
		sprintf(&tmpStr, "ASL %4.1f hPa", (BMP_PRESS_CONST_SEA_LEVEL/100));
		lcdPutStr(395-(*(font_12_zekton.font_Width)*(strlen(tmpStr)+1)), 165, tmpStr, font_12_zekton);

		// update minimum/maximum/diff
		if(bmpData.altitude < minAltitude) minAltitude = bmpData.altitude;
		if(bmpData.altitude > maxAltitude) maxAltitude = bmpData.altitude;

//		sprintf(&tmpStr, "ref(diff) %.1fm(%+.1fm)", refAltitude, bmpData.altitude-refAltitude);
		if(refAltitude != 0){
			sprintf(&tmpStr, "%+.1fm", bmpData.altitude-refAltitude);
			lcdPutStr(410-(*(zekton24font.font_Width)*(strlen(tmpStr)+1)), 184, tmpStr, zekton24font);
		}
		sprintf(&tmpStr, "%.1fm/%.1fm", minAltitude, maxAltitude);
		lcdPutStr(410-(*(zekton24font.font_Width)*(strlen(tmpStr)+1)), 210, tmpStr, zekton24font);
	} else {
		// altitude - pressure at the sea level
		char tmpStr[50] = {0};
		sprintf(&tmpStr, "%d", bmpData.pressure/100);
		lcdPutStr(350-(*(zekton84font.font_Width)*(strlen(tmpStr)+1)), 66, tmpStr, zekton84font);
		sprintf(&tmpStr, ".%d ", bmpData.pressure%100/10);
		lcdPutStr(420-(*(zekton45font.font_Width)*(strlen(tmpStr)+1)), 66, tmpStr, zekton45font);
		sprintf(&tmpStr, "hpa", bmpData.pressure%100/10);
		lcdPutStr(432-(*(zekton45font.font_Width)*(strlen(tmpStr)+1)), 112, tmpStr, zekton45font);
		sprintf(&tmpStr, "ASL: %6.1f hPa", (BMP_PRESS_CONST_SEA_LEVEL/100));
		lcdPutStr(395-(*(font_12_zekton.font_Width)*(strlen(tmpStr)+1)), 165, tmpStr, font_12_zekton);

	}
}

void setRefAltitude(void){
	refAltitude = bmpData.altitude;
}
void clearRefAltitude(void){
	refAltitude = 0;
}
void changeAltiMode(void){
	if(altitudeMode == 1){
//		BMP_PRESS_CONST_SEA_LEVEL = bmpData.slpress;
		altitudeMode = 0;
	} else {
//		fixedAltitude = bmpData.altitude;
		altitudeMode = 1;
	}
}
void increaseAltitude(void){
	BMP_PRESS_CONST_SEA_LEVEL += 1;
}
void decreaseAltitude(void){
	BMP_PRESS_CONST_SEA_LEVEL -= 1;
}
