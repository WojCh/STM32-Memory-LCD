/*
 * customTimer.h
 *
 *  Created on: Apr 11, 2022
 *      Author: wojch
 */

#ifndef INC_CUSTOMTIMER_H_
#define INC_CUSTOMTIMER_H_

#include "tim.h"
#include "gpio.h"
#include "main.h"

void initTimer(void);

void setTimeout(int count);
void setFunction(void (*handler)(void));

void timerFunction(void);

void startMeasure(void);

void stopMeasure(void);

void doSomeTiming(void);

#endif /* INC_CUSTOMTIMER_H_ */
