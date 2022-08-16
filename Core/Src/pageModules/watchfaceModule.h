/*
 * homeModule.h
 *
 *  Created on: 25 kwi 2022
 *      Author: wojch
 */

#ifndef SRC_PAGEMODULES_WATCHFACEMODULE_H_
#define SRC_PAGEMODULES_WATCHFACEMODULE_H_

#include "buttons.h"
#include "gui.h"

#include "submodules/timeInputScreen.h"
#include "submodules/dateInputScreen.h"

static void setDefaultClbcks(void);
void faceSetup(void);
void faceMain(void);

#endif /* SRC_PAGEMODULES_WATCHFACEMODULE_H_ */
