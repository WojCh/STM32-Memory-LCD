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

//	uint16_t i = 0;
//	uint16_t j = 0;
//	for(i=0; i<12; i++){
//		for(j=0; j<20; j++){
//			lcdHLine2(i, i+j, i*20+j, 1, 3);
//		}
//	}

	lcdRect2(10, 50, 10, 50, 1, 0);
	lcdRect2(60, 100, 10, 50, 1, 1);
	lcdRect2(110, 150, 10, 50, 1, 2);
	lcdRect2(160, 200, 10, 50, 1, 3);
	lcdRect2(210, 250, 10, 50, 1, 4);
	lcdRect2(260, 300, 10, 50, 1, 5);
	lcdRect2(310, 350, 10, 50, 1, 6);
	lcdRect2(10, 50, 60, 100, 1, 7);
	lcdRect2(60, 100, 60, 100, 1, 8);
	lcdRect2(110, 150, 60, 100, 1, 9);
	lcdRect2(160, 200, 60, 100, 1, 10);
	lcdRect2(210, 250, 60, 100, 1, 11);
	lcdRect2(260, 300, 60, 100, 1, 12);
	lcdRect2(310, 350, 60, 100, 1, 13);
//	lcdRect2(50, 120, 40, 120, 1, 1);
	lcdRect2(10, 390, 110, 230, 1, 4);

//	for(pix=0; pix<=200; pix++){
//		lcdHLine(pix, 2*pix, pix, 1);
//	}
}
