/*
 * alarmModule.h
 *
 *  Created on: Nov 27, 2022
 *      Author: wojch
 */
#ifndef SRC_PAGEMODULES_ALARMMODULE_H_
#define SRC_PAGEMODULES_ALARMMODULE_H_

#include "buttons.h"
#include "gui.h"

static uint8_t alarmCount = 0;

struct alarmType{
	uint8_t hour;
	uint8_t min;
	uint8_t isActive;
};

static struct alarmType *(alarmList[5]);
//extern struct alarmType *singleAlarm;

struct alarmType *createAlarm(uint8_t hour, uint8_t min);
uint8_t remAlarm(struct alarmType* alm);
uint8_t setAlarm(struct alarmType* alm, uint8_t hour, uint8_t min);
uint8_t enableAlarm(struct alarmType* alm);
uint8_t disableAlarm(struct alarmType* alm);
uint8_t toggleAlarm(struct alarmType* alm);



void alarmSetup(void);
void alarmMain(void);

#endif /* SRC_PAGEMODULES_ALARMMODULE_H_ */
