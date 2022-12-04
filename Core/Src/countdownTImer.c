/*
 * countdownTImer.c
 *
 *  Created on: Nov 27, 2022
 *      Author: wojch
 */

#include "countdownTimer.h"

uint8_t isTimerRunning(countdown_t *cnt){
	return cnt->isRunning;
}

void setTimer(countdown_t *cnt, uint16_t seconds){
	cnt->setpoint = seconds;
	cnt->isRunning = 0;
	cnt->remainingSec = seconds;
}
void startTimer(countdown_t *cnt){
	cnt->isRunning = 1;
}
void pauseTimer(countdown_t *cnt){
	cnt->isRunning = 0;
}
void resetTimer(countdown_t *cnt){
	cnt->isRunning = 0;
	cnt->remainingSec = cnt->setpoint;
}
