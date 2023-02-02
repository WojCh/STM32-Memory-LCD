/*
 * screenTest.c
 *
 *  Created on: Nov 27, 2022
 *      Author: wojch
 */
#include "screenTest.h"

uint8_t currentPage = 0;
uint8_t PAGES_NUM = 6;
char btnStr[30] = {0};

void quickPressH(void){
	sprintf(&btnStr, "Button p. for %.2f s", ((float)btn_B2.pressedFor)/100);
}
void quickReleaseH(void){
	sprintf(&btnStr, "Button rel. %.2f s", ((float)btn_B2.pressedFor)/100);
}
void shortPressH(void){
	sprintf(&btnStr, "Short press");
}
void longPressH(void){
	sprintf(&btnStr, "Long press");
}
void doublePressH(void){
	sprintf(&btnStr, "Double press");
}
void triplePressH(void){
	sprintf(&btnStr, "Triple press");
}

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

static void setDefaultClbcks(void){
//	btn_B2.onSinglePressHandler = &quickPressH;
//	btn_B2.onReleaseHandler = &quickReleaseH;
//	btn_B2.onPress = &quickPressH;
//	btn_B2.onRelease = &quickReleaseH;
//	btn_BB.onSinglePressHandler = &showOptions;

	btn_BA.onSinglePressHandler = &nextScreen;
	btn_BC.onSinglePressHandler = &prevScreen;
	btn_B3.onSinglePressHandler = &prevPage;
	btn_B1.onSinglePressHandler = &nextPage;
}

void showPage1(void){
	char fracStr[30] = {0};
		char timeStr[30] = {0};

	//	sprintf(&timeStr, "a%02d:%02d.%02d", RtcTime.Hours, RtcTime.Minutes, RtcTime.Seconds);
		sprintf(&timeStr, "%02d:%02d %02d", RtcTime.Hours, RtcTime.Minutes, RtcTime.Seconds);
	//	sprintf(&fracStr, "%02d", 100*(RtcTime.SecondFraction - RtcTime.SubSeconds)/RtcTime.SecondFraction);
		lcdPutStr(14, 11, timeStr, zekton24font);
		lcdVLine(1, 1*6, 1*6+33, 1);
		lcdVLine(2, 1*6-1, 1*6-1+35, 1);
		lcdVLine(3, 1*6-1, 1*6-1+35, 1);
		lcdVLine(4, 1*6, 1*6+33, 1);


		lcdPutStr(14, 60, btnStr, zekton24font);
}
void showPage2(void){
	char fracStr[30] = {0};
		sprintf(&fracStr, "STW");
		lcdPutStr(14, 50, fracStr, zekton24font);
		lcdVLine(1, 2*6+(2-1)*33, 2*6+33+(2-1)*33, 1);
		lcdVLine(2, 2*6-1+(2-1)*33, 2*6-1+35+(2-1)*33, 1);
		lcdVLine(3, 2*6-1+(2-1)*33, 2*6-1+35+(2-1)*33, 1);
		lcdVLine(4, 2*6+(2-1)*33, 2*6+33+(2-1)*33, 1);
}
void showPage3(void){
	char fracStr[30] = {0};
		sprintf(&fracStr, "Page 3: TMR");
		lcdPutStr(0, 0, fracStr, zekton24font);
		lcdVLine(1, 3*6+(3-1)*33, 3*6+33+(3-1)*33, 1);
		lcdVLine(2, 3*6-1+(3-1)*33, 3*6-1+35+(3-1)*33, 1);
		lcdVLine(3, 3*6-1+(3-1)*33, 3*6-1+35+(3-1)*33, 1);
		lcdVLine(4, 3*6+(3-1)*33, 3*6+33+(3-1)*33, 1);
}
void showPage4(void){
	char fracStr[30] = {0};
		sprintf(&fracStr, "Page 4: CAL");
		lcdPutStr(0, 0, fracStr, zekton24font);
		lcdVLine(1, 4*6+(4-1)*33, 4*6+33+(4-1)*33, 1);
		lcdVLine(2, 4*6-1+(4-1)*33, 4*6-1+35+(4-1)*33, 1);
		lcdVLine(3, 4*6-1+(4-1)*33, 4*6-1+35+(4-1)*33, 1);
		lcdVLine(4, 4*6+(4-1)*33, 4*6+33+(4-1)*33, 1);
}
void showPage5(void){
	char fracStr[30] = {0};
		sprintf(&fracStr, "ABCabc123!@#");
		lcdPutStr(10, 0, fracStr, smallFont);
		lcdPutStr(10, 15, fracStr, ocrFont);
		lcdPutStr(10, 50, fracStr, smallestFont);
		lcdPutStr(10, 60, fracStr, font_13_calibri);
		lcdPutStr(10, 90, fracStr, font_12_zekton);
		lcdPutStr(10, 120, fracStr, font_12_zekton_bold);
		lcdPutStr(10, 150, fracStr, zekton24font);
//		lcdPutStr(10, 180, fracStr, zekton45font);
		lcdVLine(1, 5*6+(5-1)*33, 5*6+33+(5-1)*33, 1);
		lcdVLine(2, 5*6-1+(5-1)*33, 5*6-1+35+(5-1)*33, 1);
		lcdVLine(3, 5*6-1+(5-1)*33, 5*6-1+35+(5-1)*33, 1);
		lcdVLine(4, 5*6+(5-1)*33, 5*6+33+(5-1)*33, 1);
}
void showPage6(void){
		lcdVLine(1, 6*6+(6-1)*33, 6*6+33+(6-1)*33, 1);
		lcdVLine(2, 6*6-1+(6-1)*33, 6*6-1+35+(6-1)*33, 1);
		lcdVLine(3, 6*6-1+(6-1)*33, 6*6-1+35+(6-1)*33, 1);
		lcdVLine(4, 6*6+(6-1)*33, 6*6+33+(6-1)*33, 1);
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
		lcdRect2(10, 350, 160, 200, 1, 4);
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

void screentestSetup(void){
	setDefaultClbcks();
}

void screentestMain(void){
	char tempStr[30] = {0};
//	sprintf(&tempStr, "Settings will be shown");
//	lcdPutStr(0, 0, tempStr, font_13_calibri);
	showPage(currentPage);

}
