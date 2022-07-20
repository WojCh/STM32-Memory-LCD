/*
 * numberInputScreen.h
 *
 *  Created on: 19 lip 2022
 *      Author: wojch
 */

#ifndef SRC_PAGEMODULES_SUBMODULES_NUMBERINPUTSCREEN_H_
#define SRC_PAGEMODULES_SUBMODULES_NUMBERINPUTSCREEN_H_

#include "buttons.h"
#include "gui.h"


static void setDefaultClbcks(void);
void numberInputConfigure(void);
void numberInputSetup(void);
void numberInputMain(void);

void cursorNext(void);
void cursorPrev(void);
void increment(void);
void decrement(void);
void exit(void);
void accept(void);

extern struct Module numberInputModule;

#endif /* SRC_PAGEMODULES_SUBMODULES_NUMBERINPUTSCREEN_H_ */
