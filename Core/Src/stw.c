/*
 * stw.c
 *
 *  Created on: Jul 10, 2022
 *      Author: wojch
 */

#include "stw.h"
#define STW_STATE_ENABLED	1
#define STW_STATE_DISABLED	0

stw_struct stwS = {0, 0};

stwTable stwT = {{0}, 0, &clearTable, &addItem};

void clearTable(void){
	memset(stwT.stwArray, 0, sizeof stwT.stwArray);
	stwT.position = 0;
}
void addItem(stw_struct stwS){
	stwT.stwArray[stwT.position] = stwS.cnt;
	stwT.position++;
}

void stwStart(void){
	stwS.state = STW_STATE_ENABLED;
}
void stwTick(void){
	stwS.cnt++;
}
void stwStop(void){
	stwS.state = STW_STATE_DISABLED;
}
void stwClear(void){
	stwS.cnt = 0;
}
void stwSave(void){
	// timesnapshot
	stwT.add(stwS.cnt);
}

