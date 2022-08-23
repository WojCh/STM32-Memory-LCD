/*
 * gpsModule.c
 *
 *  Created on: 25 kwi 2022
 *      Author: wojch
 */

#include "gpsModule.h"
#include "font13.h"
#include "digits5x9.h"

static void setDefaultClbcks(void){
//	btn_B2.onSinglePressHandler = &returnToMenu;
	btn_BA.onSinglePressHandler = &nextScreen;
	btn_BC.onSinglePressHandler = &prevScreen;
}

void gpsSetup(void){
	setDefaultClbcks();

}

void gpsMain(void){
//	char tempStr[30] = {0};
//	sprintf(&tempStr, "GPS will be shown");
//	lcdPutStr(0, 0, tempStr, font13);
	uint16_t i = 0;
	uint16_t j = 0;
	for(i=0; i<15; i++){
		for(j=0; j<16; j++){
			lcdHLine(i, i+j, i*16+j, 1);
		}
	}
	for(i=0; i<=150; i++){
		lcdHLine(5, 5, i, 2);
	}
	lcdVLine(200,0,239,1);
	lcdVLine(10,1,238,0);
	lcdVLine(7,1,238,2);

//	for(pix=0; pix<=200; pix++){
//		lcdHLine(pix, 2*pix, pix, 1);
//	}
}
