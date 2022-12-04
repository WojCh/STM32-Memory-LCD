/*
 * vibrationMotor.c
 *
 *  Created on: Nov 27, 2022
 *      Author: wojch
 */
#define VIB_MOTOR_PWM_TIMER 	TIM14
#define VIB_MOTOR_PWM_CHANNEL 	CCR1

#include "vibrationMotor.h"

static uint8_t vibPower = 99;

void setVibrationPower(uint8_t power){
	vibPower = power;
}

void enableVib(void){
	TIM14->CCR1 = vibPower;
}
void disableVib(void){
	TIM14->CCR1 = 0;
}
void toggleVib(void){
	if(TIM14->CCR1 == 0){
		TIM14->CCR1 = vibPower;
	} else {
		TIM14->CCR1 = 0;
	}
}
void pulseVib(uint16_t duration, uint8_t power){
	vibPower = power;
	enableVib();
	setTimeout(duration, &disableVib);
}
uint8_t patternStep = 0;
uint8_t patternState = 0;
void patternVib(void){
	if(patternState){
		switch(patternStep){
		case 0:
			patternState = 0;
			enableVib();
			setTimeout(10, &disableVib);
			break;
		case 1:
			patternState = 0;
			setTimeout(10, &enableVib);
			break;
		case 2:
			patternState = 0;
			setTimeout(10, &toggleVib);
			break;
		case 3:
			patternState = 0;
			setTimeout(10, &toggleVib);
			break;
		case 4:
			patternState = 0;
			setTimeout(10, &toggleVib);
			break;
		default:
			patternState = 0;
			patternStep = 0;
		}

	}

}
