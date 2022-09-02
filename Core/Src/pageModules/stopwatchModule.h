/*
 * stopwatchModule.h
 *
 *  Created on: 25 kwi 2022
 *      Author: wojch
 */

#ifndef SRC_PAGEMODULES_STOPWATCHMODULE_H_
#define SRC_PAGEMODULES_STOPWATCHMODULE_H_

#include "buttons.h"
#include "gui.h"
#include "rtc.h"
//#include "main.h"

#include "bmp180.h"
#include "stw.h"

void startStopwatch();
void stopStopwatch();
void resetStopwatch();
void saveStopwatch();

void stwSetup(void);
void stwMain(void);


#endif /* SRC_PAGEMODULES_STOPWATCHMODULE_H_ */
