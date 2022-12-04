/*
 * vibrationMotor.h
 *
 *  Created on: Nov 27, 2022
 *      Author: wojch
 */

#ifndef INC_VIBRATIONMOTOR_H_
#define INC_VIBRATIONMOTOR_H_

#include "main.h"
//static uint8_t vibPower = 99;

void setVibrationPower(uint8_t power);
void enableVib(void);
void disableVib(void);
void toggleVib(void);
void pulseVib(uint16_t duration, uint8_t power);
void patternVib(void);

#endif /* INC_VIBRATIONMOTOR_H_ */
