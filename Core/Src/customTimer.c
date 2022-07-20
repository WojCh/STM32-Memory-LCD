/*
 * customTimer.c
 *
 *  Created on: Apr 11, 2022
 *      Author: wojch
 */
#include "customTimer.h"

void initTimer(void){
	HAL_TIM_Base_Init(&htim11);
}

void setTimeout(int count){
	htim11.Init.Period = 65000;
}

void setFunction(void (*handler)(void)){

}

void timerFunction(void){
	HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin);
//	stopMeasure();
}

void startClock(void){
	HAL_TIM_Base_Start_IT(&htim11);
}


void stopMeasure(void){
	HAL_TIM_Base_Stop_IT(&htim11);
}

void doSomeTiming(void){
//	HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin);
	initTimer();
	setTimeout(1);
	startClock();

}

