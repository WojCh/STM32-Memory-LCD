/*
 * stw.h
 *
 *  Created on: Jul 10, 2022
 *      Author: wojch
 */

#ifndef INC_STW_H_
#define INC_STW_H_

#include "main.h"

typedef struct stw_t{
	uint32_t cnt : 24;
	uint8_t state : 1;
}stw_struct;

extern stw_struct stwS;

// split/laptime array
typedef struct stwTable{
	uint32_t stwArray[10];
	uint8_t position;
	void (*clear)(void);
	void (*add)(uint32_t);
} stwTable;
extern stwTable stwT;

void clearTable(void);
void addItem(stw_struct stwS);

void stwStart(void);
void stwStop(void);
void stwClear(void);
void stwSave(void);


#endif /* INC_STW_H_ */
