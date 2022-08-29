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
lcdRect(0,399,25,80,1);
lcdRect(0,399,120,180,1);
	lcdRect2(10, 50, 10, 50,     3, 0, 1);
	lcdRect2(60, 100, 10, 50,    3, 1, 1);
	lcdRect2(110, 150, 10, 50,   3, 2, 1);
	lcdRect2(160, 200, 10, 50,   3, 3, 1);
	lcdRect2(210, 250, 10, 50,   3, 4, 1);
	lcdRect2(260, 300, 10, 50,   3, 5, 1);
	lcdRect2(310, 350, 10, 50,   3, 6, 1);
	lcdRect2(10, 50, 60, 100,    3, 7, 1);
	lcdRect2(60, 100, 60, 100,   3, 8, 1);
	lcdRect2(110, 150, 60, 100,  3, 9, 1);
	lcdRect2(160, 200, 60, 100,  3, 10, 1);
	lcdRect2(210, 250, 60, 100,  3, 11, 1);
	lcdRect2(260, 300, 60, 100,  3, 12, 1);
	lcdRect2(310, 350, 60, 100,  3, 13, 1);
	lcdRect2(10, 50, 110, 150,   3, 14, 1);
	lcdRect2(60, 100, 110, 150,  3, 15, 1);
	lcdRect2(110, 150, 110, 150, 3, 16, 1);
	lcdRect2(160, 200, 110, 150, 3, 17, 1);
	lcdRect2(210, 250, 110, 150, 3, 18, 1);
	lcdRect2(260, 300, 110, 150, 3, 19, 1);
	lcdRect2(310, 350, 110, 150, 3, 20, 1);
//	lcdRect2(50, 120, 40, 120, 1, 1);
	lcdRect2(10, 350, 160, 200, 1, 4);

//	for(pix=0; pix<=200; pix++){
//		lcdHLine(pix, 2*pix, pix, 1);
//	}
}
