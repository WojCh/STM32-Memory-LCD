/*
 * contextMenu.c
 *
 *  Created on: Jul 14, 2022
 *      Author: wojch
 */
#include "contextMenu.h"

#include <fonts/font_zekton12.h>
// fonts
#include "fonts/zekton24.h"

static uint8_t cntxPosition = 0;
static void (*prevClbcks)(void) = NULL;

//static struct ContextActions (*cntxActions2)[10];

uint8_t actionsNum = 3;

// method for initialization the context menu from the module
//void setupCntxMenu(void (*defClbckPtr)(void), struct ContextActions act[], uint8_t num){
void setupCntxMenu(void (*defClbckPtr)(void)){
	prevClbcks = defClbckPtr;
}

uint8_t actionIndex = 0;
void cntxSelect(void){
	hideCntxMenu();
	// execute selected action
//	(*cntxActions2[cntxPosition]).main();
	ContextActions[cntxPosition]->main();
}

void nextItem(void){
	if(cntxPosition < actionsNum-1){
		cntxPosition++;
	} else {
		cntxPosition = 0;
	}
}
void prevItem(void){
	if(cntxPosition > 0){
		cntxPosition--;
	} else {
		cntxPosition = actionsNum-1;
	}
}

static void setDefaultClbcks(void){
	btn_B3.onSinglePressHandler = &hideCntxMenu;

	btn_BC.onSinglePressHandler = &prevItem;
	btn_BC.onContinuousLongPressHandler = &prevItem;
	btn_BB.onSinglePressHandler = &cntxSelect;
	btn_BA.onSinglePressHandler = &nextItem;
	btn_BA.onContinuousLongPressHandler = &nextItem;
}

void showCntxMenu(void){
	//set up context callbacks
//	resetButtonHandlers();
	setDefaultClbcks();
	isCntxOpen = 1;
}
void hideCntxMenu(void){
	//bring back module callbacks
	resetButtonHandlers();
	(*prevClbcks)();
	isCntxOpen = 0;
}

// drawing routine
void enableCntxMenu(void){
	if(isCntxOpen){
//		clear rect
		lcdRect(0, 200, 5, 8+(*font_12_zekton.font_Height)*(actionsNum)+2, 0);
//		draw frame
		lcdHLine(0, 200, 6, 1);
		lcdHLine(0, 200, 8+(*font_12_zekton.font_Height)*(actionsNum)+2, 1);
//		create list
		char item[30] = {0};
		for(uint8_t i = 0; i < actionsNum; i++){
			sprintf(&item, ContextActions[i]->name);
			lcdPutStr(5, 10+(*font_12_zekton.font_Height)*i, item, font_12_zekton);
		}
//		indicate selection
		lcdRect(0, 200, 8+(*font_12_zekton.font_Height)*cntxPosition, 8+(*font_12_zekton.font_Height)*(cntxPosition+1), 2);

	}
}
