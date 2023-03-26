/*
 * stw.h
 *
 *  Created on: Jul 10, 2022
 *      Author: wojch
 */

#ifndef INC_STW_H_
#define INC_STW_H_

//#include "main.h"
#include <stdint.h>

typedef struct stw_counter_t{
	uint32_t sec;
	uint16_t csec;
}stw_counter_t;

typedef struct stw_t{
	stw_counter_t* cnt;
	uint8_t state;
}stw_t;

extern stw_counter_t currentStw;
extern stw_t stwS;

#define STW_SPLIT_MAX_NUM	30
extern stw_counter_t stw_splits[STW_SPLIT_MAX_NUM];

struct stopwatch_t{
	uint8_t hours;
	uint8_t min;
	uint8_t sec;
	uint8_t csec;
};

void stwStart(void);
void stwStop(void);
void stwClear(void);
void stwSave(void);


#endif /* INC_STW_H_ */
