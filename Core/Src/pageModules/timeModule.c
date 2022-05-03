/*
 * timeModule.c
 *
 *  Created on: 25 kwi 2022
 *      Author: wojch
 *
 *      TODO: in time module
 *      1. Showing time and date
 *      2. World time
 *      3. Stopwatch
 *      4. Timer
 *      5. Life count↓
 *      6. Time tracker
 *
 *
 *
 *
 *
 */

#include "timeModule.h"

#include "font13.h"
#include "digits5x9.h"
#include "digits_larabie.h"
#include "font_larabie.h"
#include "font_larabie36.h"
#include "icons/icons_small.h"
#include "fonts/minimalFont.h"
#include "fonts/smallestFont.h"
#include "fonts/ocrFont.h"

uint8_t currentPage = 0;
uint8_t PAGES_NUM = 6;

void prevPage(void){
	if(currentPage>0){
		currentPage--;
	} else {
		currentPage=PAGES_NUM-1;
	}
}
void nextPage(void){
	if(currentPage<(PAGES_NUM-1)){
		currentPage++;
	} else {
		currentPage=0;
	}
}

void showPage1(void){
	char fracStr[30] = {0};
		char timeStr[30] = {0};

	//	sprintf(&timeStr, "a%02d:%02d.%02d", RtcTime.Hours, RtcTime.Minutes, RtcTime.Seconds);
		sprintf(&timeStr, "%02d%02d", RtcTime.Hours, RtcTime.Minutes);
	//	sprintf(&fracStr, "%02d", 100*(RtcTime.SecondFraction - RtcTime.SubSeconds)/RtcTime.SecondFraction);
		sprintf(&fracStr, "%02d", RtcTime.Seconds);
		lcdPutStr(0, 0, timeStr, bigDigitsLarabie);
		lcdPutStr(300, 0, fracStr, fontLarabieMedium);
}
void showPage2(void){
	char fracStr[30] = {0};
		sprintf(&fracStr, "Page 2: STW");
		lcdPutStr(0, 0, fracStr, fontLarabieMedium);
}
void showPage3(void){
	char fracStr[30] = {0};
		sprintf(&fracStr, "Page 3: TMR");
		lcdPutStr(0, 0, fracStr, fontLarabieMedium);
}
void showPage4(void){
	char fracStr[30] = {0};
		sprintf(&fracStr, "Page 4: CAL");
		lcdPutStr(0, 0, fracStr, fontLarabieMedium);
}
void showPage5(void){
	char fracStr[30] = {0};
		sprintf(&fracStr, "Page 5: WRLD");
		lcdPutStr(0, 0, fracStr, fontLarabieMedium);
}
void showPage6(void){
	char fracStr[30] = {0};
		sprintf(&fracStr, "Page 6: DLT");
		lcdPutStr(0, 0, fracStr, fontLarabieMedium);
}

void showPage(uint8_t pageNum){
	switch(pageNum){
	case 0:
		showPage1();
		break;
	case 1:
		showPage2();
		break;
	case 2:
		showPage3();
		break;
	case 3:
		showPage4();
		break;
	case 4:
		showPage5();
		break;
	case 5:
		showPage6();
		break;
	}
}

static void setDefaultClbcks(void){
	btn_B2.onSinglePressHandler = &returnToMenu;
	btn_B1.onSinglePressHandler = &prevPage;
	btn_BA.onSinglePressHandler = &nextPage;
//	btn_BB.onSinglePressHandler = &showOptions;

}
// functions to execute while menu item highlighted
void timeDescription(void){
//	char tempStr[30] = {0};
//	sprintf(&tempStr, "Time will be 24h45.2min");
//	lcdPutStr(0,132, tempStr, smallestFont);
//	lcdPutStr(4,140, tempStr, smallestFont);
//	lcdPutStr(7,180, tempStr, ocrFont);
//	lcdPutStr(4,5, tempStr, font13);
}

void timeSetup(void){
	setDefaultClbcks();
}

// functions to execute when menu item entered
void timeMain(void){
	showPage(currentPage);
}
