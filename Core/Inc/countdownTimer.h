/*
 * countdownTimer.h
 *
 *  Created on: Nov 27, 2022
 *      Author: wojch
 */

#ifndef INC_COUNTDOWNTIMER_H_
#define INC_COUNTDOWNTIMER_H_

#include "main.h"

typedef struct countdown_t {
	uint16_t setpoint;
	uint16_t remainingSec;
	uint8_t isRunning;
} countdown_t;

uint8_t isTimerRunning(countdown_t *cnt);
void setTimer(countdown_t *cnt, uint16_t seconds);
void startTimer(countdown_t *cnt);
void pauseTimer(countdown_t *cnt);
void resetTimer(countdown_t *cnt);

#endif /* INC_COUNTDOWNTIMER_H_ */
