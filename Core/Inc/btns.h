/*
 * btns.h
 *
 *  Created on: 26 mar 2023
 *      Author: wojch
 */

#ifndef SRC_BTNS_H_
#define SRC_BTNS_H_

#include "gpio.h"

// To implement
//    BUTTON_EVENT_HOLD set cycle period

// Button events
typedef enum {
    BUTTON_EVENT_DOWN,
    BUTTON_EVENT_SHORT_PRESS,
    BUTTON_EVENT_RELEASE,
    BUTTON_EVENT_LONG_PRESS,
    BUTTON_EVENT_DOUBLE_PRESS
} Button_Event;

#endif /* SRC_BTNS_H_ */
