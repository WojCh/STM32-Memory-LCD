/*
 * valueSelector.c
 *
 *  Created on: Nov 30, 2022
 *      Author: wojch
 */

#include "valueSelector.h"
#include "fonts/fonts.h"

// Routine for drawing interactive selector
// <[4s]>

//enum SELECTOR_VALUE_TYPE{
//		INT = 0,
//		UINT
//};

void numberSelectorInc(uint8_t *val){
	(*val)++;
}
void numberSelectorDec(uint8_t *val){
	(*val)--;
}

void drawNumberSelector(uint8_t *val){

	char tempStr[51] = {0};
	sprintf(&tempStr, "%d", *val);
	lcdPutStr(10, 50, tempStr, zekton24font);

	lcdRect(5, 35, 45, 75, 2);
}

