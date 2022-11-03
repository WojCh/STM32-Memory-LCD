/*
 * numberInputScreen.h
 *
 *  Created on: 19 lip 2022
 *      Author: wojch
 */

#ifndef SRC_PAGEMODULES_SUBMODULES_DATEINPUTSCREEN_H_
#define SRC_PAGEMODULES_SUBMODULES_DATEINPUTSCREEN_H_

#include "buttons.h"
#include "gui.h"

static void setDefaultClbcks(void);
void dateInputConfigure(void);
void dateInputSetup(void);
void dateInputMain(void);

static void cursorNext(void);
static void cursorPrev(void);
static void increment(void);
static void decrement(void);
static void exitScr(void);
static void accept(void);

extern struct Module dateInputModule;

#endif /* SRC_PAGEMODULES_SUBMODULES_DATEINPUTSCREEN_H_ */
