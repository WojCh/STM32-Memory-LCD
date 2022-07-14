/*
 * contextMenu.c
 *
 *  Created on: Jul 14, 2022
 *      Author: wojch
 */
#include "contextMenu.h"

// fonts
#include "fonts/zekton24.h"

static uint8_t cntxPosition = 0;
void (*prevClbcks)(void) = NULL;

struct ContextActions* cntxActions2[];
uint8_t actionsNum;



// method for initialization the context menu from the module
void setupCntxMenu(void (*defClbckPtr)(void), struct ContextActions** act, uint8_t num){
//void setupCntxMenu(void (*defClbckPtr)(void)){
	prevClbcks = defClbckPtr;
	//define item structure based on passed parameters
}

void nextItem(void){
	cntxPosition++;
}
void prevItem(void){
	cntxPosition--;
}

void setDefaultClbcks(void){
	btn_B3.onSinglePressHandler = &hideCntxMenu;

	btn_BC.onSinglePressHandler = &prevItem;
	btn_BC.onContinuousLongPressHandler = &prevItem;
//	btn_BB.onSinglePressHandler = &cntxSelect;
	btn_BA.onSinglePressHandler = &nextItem;
	btn_BA.onContinuousLongPressHandler = &nextItem;
}

void showCntxMenu(void){
	//set up context callbacks
	setDefaultClbcks();
	isCntxOpen = 1;
}
void hideCntxMenu(void){
	//bring back module callbacks
	(*prevClbcks)();
	isCntxOpen = 0;
}

// drawing routine
void enableCntxMenu(void){
	if(isCntxOpen){
//		clear rect
		lcdRect(0, 150, 10, 230, 0);
//		draw frame
		lcdHLine(0, 150, 9, 1);
		lcdHLine(0, 150, 231, 1);
//		create list
		char item[30] = {0};
		for(uint8_t i = 0; i <= 5; i++){
			sprintf(&item, "menu %d", i+1);
			lcdPutStr(5, 10+(*zektonSmallFont.font_Height)*i, item, zektonSmallFont);
		}
//		indicate selection
		lcdRect(0, 150, 10+(*zektonSmallFont.font_Height)*cntxPosition, 35+(*zektonSmallFont.font_Height)*cntxPosition, 2);

	}
}
