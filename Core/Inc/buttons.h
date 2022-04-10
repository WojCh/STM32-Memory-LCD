/*
 * buttons.h
 *
 *  Created on: Apr 10, 2022
 *      Author: wojch
 */

#ifndef INC_BUTTONS_H_
#define INC_BUTTONS_H_

typedef struct buttons{
	uint8_t BA: 1;
	uint8_t BB: 1;
	uint8_t BC: 1;
	uint8_t B1: 1;
	uint8_t B2: 1;
	uint8_t B3: 1;
}buttons;

buttons btns;


#endif /* INC_BUTTONS_H_ */
