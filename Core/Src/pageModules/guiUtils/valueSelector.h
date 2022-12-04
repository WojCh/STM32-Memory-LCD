/*
 * valueSelector.h
 *
 *  Created on: Nov 30, 2022
 *      Author: wojch
 */

#ifndef SRC_PAGEMODULES_GUIUTILS_VALUESELECTOR_H_
#define SRC_PAGEMODULES_GUIUTILS_VALUESELECTOR_H_

#include "main.h"

struct guiSelector{
	uint8_t isActive;
	uint8_t *valPtr;
	void (*draw)(void);
};


void numberSelectorInc(uint8_t *val);
void numberSelectorDec(uint8_t *val);
void drawNumberSelector(uint8_t *val);

static const struct guiSelector numSelector = {1, &drawNumberSelector};

#endif /* SRC_PAGEMODULES_GUIUTILS_VALUESELECTOR_H_ */
