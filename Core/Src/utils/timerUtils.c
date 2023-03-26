/*
 * timerUtils.c
 *
 *  Created on: 2 lut 2023
 *      Author: wojch
 */

#include "timerUtils.h"

timer_T* createTimer(void){
	timer_T* timerPtr = malloc(sizeof(timer_T));
	timerPtr->timerStatus = TIMER_STATUS_UNSET;
	return timerPtr;
}
void deleteTimer(timer_T* timer){
	free(timer);
}
uint8_t setTimerAAA(timer_T* timer, uint16_t targetTime, void* callback){
	timer->currentValue = 0;
	timer->targetValue = targetTime;
	timer->callback = callback;
	timer->timerStatus = TIMER_STATUS_READY;
}

uint8_t runTimerAAA(timer_T* timer){
	if((timer->timerStatus == TIMER_STATUS_READY) || (timer->timerStatus == TIMER_STATUS_PAUSED)){
		timer->timerStatus = TIMER_STATUS_RUNNING;
	}
}
uint8_t pauseTimerAAA(timer_T* timer){
	if(timer->timerStatus == TIMER_STATUS_RUNNING){
		timer->timerStatus = TIMER_STATUS_PAUSED;
	}
}
// stop and clear
uint8_t resetTimerAAA(timer_T* timer){
	timer->currentValue = 0;
	timer->timerStatus = TIMER_STATUS_READY;
}

void tickTimer(timer_T* timer){
	if(timer->timerStatus == TIMER_STATUS_RUNNING) timer->currentValue++;
	if(timer->currentValue == timer->targetValue){
		timer->timerStatus = TIMER_STATUS_ELAPSED;
		// callback will be executed in the TMR interrupt!
		timer->callback(NULL);
	}
}
// check if elapsed and execute callback, TODO: var args in clbk
void timerElapsedClbk(timer_T* timer){
	if(timer->timerStatus == TIMER_STATUS_ELAPSED){
		timer->callback(NULL);
	}
}


