/*
 * contextMenu.c
 *
 *  Created on: Jul 14, 2022
 *      Author: wojch
 */

#include "contextMenu.h"
// fonts
#include "fonts/zekton24.h"



void showCntxMenu(void){
	isCntxOpen = 1;
}
void hideCntxMenu(void){
	isCntxOpen = 0;
}
void enableCntxMenu(void){
	if(isCntxOpen){
		char item[30] = {0};
		sprintf(&item, "Hello?");
		lcdPutStr(0, 0, item, zektonSmallFont);
	}
}
