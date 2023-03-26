/*
 * btns.h
 *
 *  Created on: 26 mar 2023
 *      Author: wojch
 */

#ifndef SRC_BTNS_H_
#define SRC_BTNS_H_

#include "gpio.h"


// Button names
typedef enum {
	BTN_BA,
	BTN_BB,
	BTN_BC,
	BTN_B1,
	BTN_B2,
	BTN_B3
} Button_Id;
// Number of button event types
#define BUTTON_EVENT_TYPE_COUNT 6
// Button events
typedef enum {
    BUTTON_EVENT_DOWN,
    BUTTON_EVENT_SHORT_PRESS,
    BUTTON_EVENT_RELEASE,
    BUTTON_EVENT_LONG_PRESS,
    BUTTON_EVENT_DOUBLE_PRESS,
    BUTTON_EVENT_HOLD_CYCLIC,
} Button_Event;

#endif /* SRC_BTNS_H_ */
