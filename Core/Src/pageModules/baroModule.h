/*
 * baroModule.h
 *
 *  Created on: 25 kwi 2022
 *      Author: wojch
 */

#ifndef SRC_PAGEMODULES_BAROMODULE_H_
#define SRC_PAGEMODULES_BAROMODULE_H_

#define BARO_MODE_FIXED_ALTITUDE 0
#define BARO_MODE_FIXED_PRESSURE 1

#include "bmp180.h"
#include "buttons.h"
#include "gui.h"

void baroSetup(void);
void baroMain(void);

void changeBaroMode(void);
void addBaro(void);
void remBaro(void);

#endif /* SRC_PAGEMODULES_BAROMODULE_H_ */
