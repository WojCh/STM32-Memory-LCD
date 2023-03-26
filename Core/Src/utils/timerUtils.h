/*
 * timerUtils.h
 *
 *  Created on: 2 lut 2023
 *      Author: wojch
 */

#ifndef SRC_UTILS_TIMERUTILS_H_
#define SRC_UTILS_TIMERUTILS_H_

#include <stdint.h>
#include <stdlib.h>

#define TIMER_RESET 0
#define TIMER_START 1
#define TIMER_PAUSE 2
#define TIMER_STATUS_UNSET 0
#define TIMER_STATUS_READY 1
#define TIMER_STATUS_RUNNING 2
#define TIMER_STATUS_PAUSED 3
#define TIMER_STATUS_ELAPSED 4

typedef struct timer_T{
	uint16_t currentValue;
	uint16_t targetValue;
	void* (*callback)(void*);
	uint8_t timerStatus;
}timer_T;

timer_T* createTimer(void);
void deleteTimer(timer_T* timer);

// rename after removing old timer library
uint8_t setTimerAAA(timer_T* timer, uint16_t targetTime, void* callback);
uint8_t runTimerAAA(timer_T* timer);
uint8_t pauseTimerAAA(timer_T* timer);
uint8_t resetTimerAAA(timer_T* timer);

//uint16_t getTimerValue(timer_T* timer);
//uint16_t getTimerTarget(timer_T* timer);

void tickTimer(timer_T* timer);
void timerElapsedClbk(timer_T* timer);

#endif /* SRC_UTILS_TIMERUTILS_H_ */
