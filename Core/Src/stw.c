/*
 * stw.c
 *
 *  Created on: Jul 10, 2022
 *      Author: wojch
 */

#include "stw.h"

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
	stwS.state = 1;
}
void stwTick(void){
	stwS.cnt++;
}
void stwStop(void){
	stwS.state = 0;
}
void stwClear(void){
	stwS.cnt = 0;
}
void stwSave(void){
	// timesnapshot
	stwT.add(stwS.cnt);
}

