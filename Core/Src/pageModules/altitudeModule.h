/*
 * altiModule.h
 *
 *  Created on: 25 kwi 2022
 *      Author: wojch
 */

#ifndef SRC_PAGEMODULES_ALTIMODULE_H_
#define SRC_PAGEMODULES_ALTIMODULE_H_

#include "bmp180.h"
#include "buttons.h"
#include "gui.h"
#include "../../Src/utils/ringBuffer.h"

static float refAltitude = 0;
static float minAltitude;
static float maxAltitude;
static float startPressure;
static float minPressure;
static float maxPressure;

void altiSetup(void);
void altiMain(void);
void changeAltiMode(void);
void increaseAltitude(void);
void decreaseAltitude(void);
void setRefAltitude(void);
void clearRefAltitude(void);

#endif /* SRC_PAGEMODULES_BAROMODULE_H_ */
