/*
 * buttons.h
 *
 *  Created on: Apr 10, 2022
 *      Author: wojch
 */

#ifndef INC_BUTTONS_H_
#define INC_BUTTONS_H_

//#include "main.h"
#include "gpio.h"

#define BTN_FREQ 	100	// Frequency of polling [Hz]
#define BTN_NUMBER 	6

#define BTN_BA_PORT BA_GPIO_Port
#define BTN_BB_PORT BB_GPIO_Port
#define BTN_BC_PORT BC_GPIO_Port
#define BTN_B1_PORT B1_GPIO_Port
#define BTN_B2_PORT B2_GPIO_Port
#define BTN_B3_PORT B3_GPIO_Port

#define BTN_BA_PIN 	BA_Pin
#define BTN_BB_PIN 	BB_Pin
#define BTN_BC_PIN 	BC_Pin
#define BTN_B1_PIN 	B1_Pin
#define BTN_B2_PIN 	B2_Pin
#define BTN_B3_PIN 	B3_Pin

#define BTN_PRESSED 	1;
#define BTN_RELEASED 	0;

// handler types
// onPress - triggered on the first falling edge, immediate reaction, always executed (independent from other handlers)
// onRelease - triggered on the first rising edge after debouncing period, immediate reaction
// onShortPress - triggered when pressed time: pt > debounce period and pt < longPressed period, exclusive with longPress handler
// onLongPress - triggered when pressed time: pt > longPressed threshold, exclusive with short pressed handler, returns pressed time
// onContinuousPress - triggered repeatedly with custom interval period, for fast functions, executed independently, returns number of execution
// onRepeatedPress - triggered after set number of short presses with custom interval in between, exclusive with shortPress (? not necessarily)

// settings:
// debouncingTime - time required for bounce to stop
// longPressThreshold - minimal time to recognize press as long, maximal time for short press
// continuousPressInterval - interval between consecutive triggers of handler
// repeatedPressCount (?) - number of repeated presses to be recognized (? to rethink)
// repeatedBreakInterval - interval in between presses to recognize as repeatedPress
typedef struct btn_t{
	// configuration
	GPIO_TypeDef* port;
	uint16_t pin;
	// settings
	uint8_t debouncingTime;
	uint8_t longPressThreshold;
	uint8_t continuousPressInterval;
	uint8_t repeatedPressCount;
	uint8_t repeatedBreakInterval;
	// new handlers
	void* (*onPress)(void*);
	void* (*onRelease)(void*);
	void* (*onShortPress)(void*);
	void* (*onLongPress)(void*);
	void* (*onContinuousPress)(void*);
	void* (*onRepeatedPress)(void*);
	// result parameters
	uint16_t pressedFor;
	uint8_t pressedX;
}btn_t;



struct PressSetting {
	uint16_t shortTreshold;		// max number of timer cycles for short press event
	uint16_t longPulseTreshold;	// max number of timer cycles per hold cycle (for continuous pulse on long press)
};

typedef struct Button{
	// settings
	GPIO_TypeDef* port;
	uint16_t pin;
	// status
	uint8_t prevStatus:1;
	uint8_t currStatus:1;
	// flags
	uint8_t shortSingleOn;
	uint8_t shortSingleOff;
	uint8_t longSingleOn;
	uint8_t shortContinuous;
	uint8_t longContinuous;
	uint8_t shortSingleHandled;
	uint8_t longSingleHandled;
	uint8_t releaseHandled;
	// handlers
	void* (*onSinglePressHandler)(void*);
	void* (*onSingleLongPressHandler)(void*);
	void* (*onContinuousShortPressHandler)(void*);
	void* (*onContinuousLongPressHandler)(void*);
	void* (*onReleaseHandler)(void*);
	// NEW //
	// settings
	uint8_t debouncingTime;
	uint8_t longPressThreshold;
	uint8_t continuousPressInterval;
	uint8_t repeatedPressCount;
	uint8_t repeatedBreakInterval;
	// new handlers
	void* (*onPress)(void*);
	void* (*onRelease)(void*);
	void* (*onShortPress)(void*);
	void* (*onLongPress)(void*);
	void* (*onContinuousPress)(void*);
	void* (*onRepeatedPress)(void*);
	// result parameters
	uint16_t pressedFor;
	uint8_t pressedX;
} Button;

extern Button btn_BA, btn_BB, btn_BC, btn_B1, btn_B2, btn_B3;
extern Button* btnsPtrs[];

//typedef struct buttons{
//	uint8_t BA: 1;
//	uint8_t BB: 1;
//	uint8_t BC: 1;
//	uint8_t B1: 1;
//	uint8_t B2: 1;
//	uint8_t B3: 1;
//	uint8_t buttonsState;
//}buttons;
void initButtons(Button* btns[6]);
void resetButtonHandlers(void);
void scanButtons(Button* btns[6]);

//extern buttons btns;


#endif /* INC_BUTTONS_H_ */
