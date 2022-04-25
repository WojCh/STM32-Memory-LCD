/*
 * baroModule.h
 *
 *  Created on: 25 kwi 2022
 *      Author: wojch
 */

#ifndef SRC_PAGEMODULES_BAROMODULE_H_
#define SRC_PAGEMODULES_BAROMODULE_H_

#include "bmp180.h"
#include "buttons.h"
#include "gui.h"

extern const struct Module baroModule;

void setDefaultClbcks(void);
void baroSetup(void);

void baroMain(void);

void changeBaroMode(void);
void addBaro(void);
void remBaro(void);

void showBaroDesc(void);
void showBaroScreen(void);

#endif /* SRC_PAGEMODULES_BAROMODULE_H_ */
