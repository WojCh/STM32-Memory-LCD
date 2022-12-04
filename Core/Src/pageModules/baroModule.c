/*
 * baroModule.c
 *
 *  Created on: 25 kwi 2022
 *      Author: wojch
 */

#include "baroModule.h"
#include "fonts/fonts.h"


// fixed alt = 0/fixed baro = 1 mode
uint8_t baroMode = BARO_MODE_FIXED_ALTITUDE;

static void setDefaultClbcks(void){
//	btn_B2.onSinglePressHandler = &returnToMenu;
	btn_BA.onSinglePressHandler = &nextScreen;
	btn_BC.onSinglePressHandler = &prevScreen;
	btn_BB.onSingleLongPressHandler = &changeBaroMode;
	btn_B3.onContinuousShortPressHandler = &addBaro;
	btn_B1.onContinuousShortPressHandler = &remBaro;
	btn_B2.onSinglePressHandler = NULL;
}

// function executed once on module load
void baroSetup(void){
	setDefaultClbcks();
}

uint16_t minX = 35;
uint16_t maxX = 347;
uint8_t maxHeight = 225;
uint8_t minHeight = 110;

// main function
void baroMain(void){
	// update data
	bmpData = getBmpData(&bmp180module);


	uint16_t minBaro = (*(uint16_t*)(cbuf_readn(&baroRing, 0)));
	uint16_t maxBaro = (*(uint16_t*)(cbuf_readn(&baroRing, 0)));
	uint16_t minTemp = read_nth_ring_buffer(&tempRing, 0);
	uint16_t maxTemp = read_nth_ring_buffer(&tempRing, 0);
	char str1[50] = {0};
	char str3[50] = {0};
	char str4[50] = {0};
	sprintf(&str1, "Temperature: %4.1f`C", bmpData.temperature);
	lcdPutStr(10, 14, str1, font_12_zekton);
	sprintf(&str1, "Ambient pressure: %04.1fhPa", (float)bmpData.pressure/100);
	lcdPutStr(10, 30, str1, font_12_zekton);
	if(baroMode == BARO_MODE_FIXED_ALTITUDE){
		sprintf(&str4, "Fixed altitude mode");
		sprintf(&str1, "Pressure %6.1f hPa at the sea level", bmpData.slpress/100);
		sprintf(&str3, "At const %.0fm above sea level", fixedAltitude);
	} else {
		sprintf(&str4, "Fixed pressure mode");
		sprintf(&str1, "Altitude %5.1fm above sea level", bmpData.altitude);
		sprintf(&str3, "For const pressure %6.1f hPa", (BMP_PRESS_CONST_SEA_LEVEL/100));
	}
	lcdPutStr(10, 50, str4, font_12_zekton);
	lcdPutStr(10, 66, str1, font_12_zekton);
	lcdPutStr(10, 82, str3, font_12_zekton);

	for(uint16_t i=0; i<tempRing.num_entries; i++){
		uint16_t* currB= (uint16_t*)(cbuf_readn(&baroRing, i));
		uint16_t currT= read_nth_ring_buffer(&tempRing, i);
		if(*currB>=maxBaro) maxBaro = *currB;
		if(*currB<=minBaro) minBaro = *currB;
		if(currT>=maxTemp) maxTemp = currT;
		if(currT<=minTemp) minTemp = currT;
	}
	for(uint16_t j=minX; j<maxX; j++){
		uint16_t i = (j-minX)*baroRing.elemNum/(maxX-minX);
		// graph data
		uint16_t* vvaall= (uint16_t*)(cbuf_readn(&baroRing, i));
		lcdRect2(j, j+1, maxHeight-(maxHeight-minHeight)*((*vvaall)-minBaro)/(maxBaro-minBaro), maxHeight, 1, 2, 0);
		lcdRect2(j, j+1, maxHeight-(maxHeight-minHeight)*(read_nth_ring_buffer(&tempRing, i)-minTemp)/(maxTemp-minTemp), maxHeight, 1, 14, 0);
//		lcdRect2(400/baroRing.maxSize*i, 400/baroRing.maxSize*i+1, maxHeight-(maxHeight-minHeight)*((*vvaall)-minBaro)/(maxBaro-minBaro), maxHeight, 1, 2, 0);
//		lcdRect2(400/tempRing.size*i, 400/tempRing.size*i+1, maxHeight-(maxHeight-minHeight)*(read_nth_ring_buffer(&tempRing, i)-minTemp)/(maxTemp-minTemp), maxHeight, 1, 14, 0);
		// horizontal lines
		lcdHLine2(minX, maxX, maxHeight-(maxHeight-minHeight)*(maxTemp-minTemp)/(maxTemp-minTemp), 1, 2);
		lcdHLine2(minX, maxX, maxHeight-(maxHeight-minHeight)*(minTemp-minTemp)/(maxTemp-minTemp), 1, 2);
//		lcdHLine2(0, 399, maxHeight-(maxHeight-minHeight)*(300-minTemp)/(maxTemp-minTemp), 1, 2);
	}
	sprintf(&str4, "%0.1f", ((float)maxTemp)/10);
	lcdPutStr(0, minHeight-6, str4, smallestFont);
	sprintf(&str4, "%0.1f", ((float)minTemp)/10);
	lcdPutStr(0, maxHeight-6, str4, smallestFont);
	sprintf(&str4, "%0.1f", ((float)maxBaro)/10);
	lcdPutStr(350, minHeight-6, str4, smallestFont);
	sprintf(&str4, "%0.1f", ((float)minBaro)/10);
	lcdPutStr(350, maxHeight-6, str4, smallestFont);
//	lcdVLine(baroRing.tail, minHeight, maxHeight, 1);
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
