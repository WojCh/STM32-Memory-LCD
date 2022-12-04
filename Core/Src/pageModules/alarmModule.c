/*
 * alarmModule.c
 *
 *  Created on: Nov 27, 2022
 *      Author: wojch
 */
#include "alarmModule.h"
#include "fonts/fonts.h"
#include "../Src/pageModules/guiUtils/valueSelector.h"


//struct alarmType alarmList[5];
void addAlarm(uint8_t hour, uint8_t min){
	if(alarmCount < 5){
		alarmList[alarmCount] = createAlarm(hour, min);
		alarmCount++;
	}
//	else {
////		return ERROR_FAIL;
//	}
}

struct alarmType *createAlarm(uint8_t hour, uint8_t min){
	struct alarmType *alm;
	alm = malloc(sizeof (struct alarmType));
	alm->hour = hour;
	alm->min = min;
	return alm;
}
uint8_t remAlarm(struct alarmType* alm){
	free(alm);
	return 1;
}
uint8_t setAlarm(struct alarmType* alm, uint8_t hour, uint8_t min){
	alm->hour = hour;
	alm->min = min;
	alm->isActive = 1;
}
uint8_t enableAlarm(struct alarmType* alm){
	alm->isActive = 1;
}
uint8_t disableAlarm(struct alarmType* alm){
	alm->isActive = 0;
}
//uint8_t toggleAlarm(struct alarmType* alm);

void selectAlarm(void){
	if(alarmCount == 0){
		//create alarm and add to list
		addAlarm(1, 23);
	} else {
		addAlarm(1, 23);
		setAlarm(alarmList[0], 4, 56);
	}
}

uint8_t alarmPosition;
uint8_t isAlarmEditModeOn = 0;

void nextPosition(void){
	if(alarmPosition < alarmCount){
		alarmPosition++;
	} else {
		alarmPosition = 0;
	}
}
void prevPosition(void){
	if(alarmPosition > 0){
		alarmPosition--;
	} else {
		alarmPosition = alarmCount;
	}
}
void toggleEditAlarmMode(void){
	isAlarmEditModeOn = !isAlarmEditModeOn;
	if(isAlarmEditModeOn){
		setEditModeClbcks();
		if(alarmCount == 0){
			addAlarm(1, 23);
		}
	} else {
		setDefaultClbcks();
	}
}

void setEditModeClbcks(void){
	resetButtonHandlers();
	btn_BA.onSinglePressHandler = &nextPosition;
	btn_BC.onSinglePressHandler = &prevPosition;


	btn_B1.onSinglePressHandler = &toggleEditAlarmMode;
}

static void setDefaultClbcks(void){
	btn_BA.onSinglePressHandler = &nextScreen;
	btn_BC.onSinglePressHandler = &prevScreen;

	btn_BB.onSinglePressHandler = &toggleEditAlarmMode;
}

void alarmSetup(void){
	setDefaultClbcks();
	isAlarmEditModeOn = 0;
}

void alarmMain(void){
	char tempStr[51] = {0};
	sprintf(&tempStr, "Alarms");
	lcdPutStr(10, 10, tempStr, zekton24font);
	lcdHLine2(10, 390, 40, 1, 2);

	if(alarmCount == 0){
		sprintf(&tempStr, "No alarms");
		lcdPutStr(170, 120, tempStr, font_12_zekton);
	} else {
		// could be removed from /else/ cause for alarmCount==0 loop will not execute
		for(uint8_t i = 0; i < alarmCount; i++){
			sprintf(&tempStr, "%d:%d", alarmList[i]->hour, alarmList[i]->min);
			lcdPutStr(250, 45+i*30, tempStr, zekton24font);
			if(alarmList[i]->isActive){
				sprintf(&tempStr, "on");
			} else {
				sprintf(&tempStr, "off");
			}
			lcdPutStr(350, 45+i*30, tempStr, font_12_zekton);

		}
	lcdRect(350, 375, 63+alarmPosition*30, 65+alarmPosition*30, 1);
	}
	if(alarmCount < 5){
		sprintf(&tempStr, "+");
		lcdPutStr(375, 110, tempStr, zekton24font);
	}

	// show option list


	// trying to create alarm instance and display it
//	struct alarmType *singleAlarm = addAlarm(12, 15);
//	sprintf(&tempStr, "%2d:%2d", singleAlarm->hour, singleAlarm->min);
//	lcdPutStr(15, 170, tempStr, zekton24font);
//	sprintf(&tempStr, "%2d:%2d", alarmList[0]->hour, alarmList[0]->min);
//	lcdPutStr(15, 170, tempStr, zekton24font);


//	struct settingMenu menu;
//	menu.itemNum = 2;
//	menu.itemArr = {&item1, &item2}
//	struct settingLine line1
//	numSelector.valPtr = &AdjVar;
//	numSelector.draw();

//	drawNumberSelector(&AdjVar);

}
