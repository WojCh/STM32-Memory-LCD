/*
 * numberInputScreen.h
 *
 *  Created on: 19 lip 2022
 *      Author: wojch
 */

#ifndef SRC_PAGEMODULES_SUBMODULES_TIMEINPUTSCREEN_H_
#define SRC_PAGEMODULES_SUBMODULES_TIMEINPUTSCREEN_H_

#include "buttons.h"
#include "gui.h"


static void setDefaultClbcks(void);
void timeInputConfigure(void);
void timeInputSetup(void);
void timeInputMain(void);

static void cursorNext(void);
static void cursorPrev(void);
static void increment(void);
static void decrement(void);
static void exit(void);
static void accept(void);

extern struct Module timeInputModule;

#endif /* SRC_PAGEMODULES_SUBMODULES_TIMEINPUTSCREEN_H_ */
