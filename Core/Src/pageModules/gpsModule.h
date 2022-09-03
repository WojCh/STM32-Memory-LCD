/*
 * gpsModule.h
 *
 *  Created on: 25 kwi 2022
 *      Author: wojch
 */

#ifndef SRC_PAGEMODULES_GPSMODULE_H_
#define SRC_PAGEMODULES_GPSMODULE_H_

#include "buttons.h"
#include "gui.h"

void readGps(void);
static void setDefaultClbcks(void);

void gpsSetup(void);
void gpsMain(void);


#endif /* SRC_PAGEMODULES_GPSMODULE_H_ */
