/*
 * timeModule.h
 *
 *  Created on: 25 kwi 2022
 *      Author: wojch
 */

#ifndef SRC_PAGEMODULES_TIMEMODULE_H_
#define SRC_PAGEMODULES_TIMEMODULE_H_

#include "buttons.h"
#include "gui.h"
#include "rtc.h"
#include "main.h"

#include "bmp180.h"
#include "stw.h"

void startStopwatch();
void stopStopwatch();
void resetStopwatch();
void saveStopwatch();

void timeDescription(void);
void timeSetup(void);
void timeMain(void);


#endif /* SRC_PAGEMODULES_TIMEMODULE_H_ */
