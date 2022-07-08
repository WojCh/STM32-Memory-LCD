/*
 * buttons.h
 *
 *  Created on: Apr 10, 2022
 *      Author: wojch
 */

#ifndef INC_BUTTONS_H_
#define INC_BUTTONS_H_

#include "main.h"
#include "gpio.h"

#define BTN_NUMBER 6

#define BTN_BA_PORT BA_GPIO_Port
#define BTN_BB_PORT BB_GPIO_Port
#define BTN_BC_PORT BC_GPIO_Port
#define BTN_B1_PORT B1_GPIO_Port
#define BTN_B2_PORT B2_GPIO_Port
#define BTN_B3_PORT B3_GPIO_Port

#define BTN_BA_PIN BA_Pin
#define BTN_BB_PIN BB_Pin
#define BTN_BC_PIN BC_Pin
#define BTN_B1_PIN B1_Pin
#define BTN_B2_PIN B2_Pin
#define BTN_B3_PIN B3_Pin

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
} Button;

extern Button btn_BA, btn_BB, btn_BC, btn_B1, btn_B2, btn_B3;
extern Button* btnsPtrs[];

typedef struct buttons{
	uint8_t BA: 1;
	uint8_t BB: 1;
	uint8_t BC: 1;
	uint8_t B1: 1;
	uint8_t B2: 1;
	uint8_t B3: 1;
	uint8_t buttonsState;
	void (*BA_handler)(void);
	void (*BB_handler)(void);
	void (*BC_handler)(void);
	void (*B1_handler)(void);
	void (*B2_handler)(void);
	void (*B3_handler)(void);
}buttons;
void initButtons(Button* btns[6]);
void resetButtonHandlers(void);
void scanButtons(Button* btns[6]);

extern buttons btns;

extern char buttonHandlers[50];
extern char buttonHandler2[50];

#endif /* INC_BUTTONS_H_ */
