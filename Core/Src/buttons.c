#include "buttons.h"

buttons btns;

// initialization of all buttons
Button btn_BA, btn_BB, btn_BC, btn_B1, btn_B2, btn_B3;
GPIO_TypeDef* ports[6] = {BA_GPIO_Port, BB_GPIO_Port, BC_GPIO_Port, B1_GPIO_Port, B2_GPIO_Port, B3_GPIO_Port};
uint16_t pins[6] = {BA_Pin, BB_Pin, BC_Pin, B1_Pin, B2_Pin, B3_Pin};
Button* btnsPtrs[6] = {&btn_BA, &btn_BB, &btn_BC, &btn_B1, &btn_B2, &btn_B3};
void initButtons(Button* btns[6]){
	uint8_t i = 0;
	while(i < 6){
		btns[i]->pin = pins[i];
		btns[i]->port = ports[i];
		btns[i]->prevStatus = 0;
		btns[i]->currStatus = 0;
		// flags & counters
		btns[i]->shortSingleOn = 0;
		btns[i]->shortSingleOff = 0;
		btns[i]->longSingleOn = 0;
		btns[i]->shortContinuous = 0;
		btns[i]->longContinuous = 0;
		btns[i]->shortSingleHandled = 0;
		btns[i]->longSingleHandled = 0;
		btns[i]->releaseHandled = 0;
		// handlers
		btns[i]->singlePressHandler = NULL;
		btns[i]->singleLongPressHandler = NULL;
		btns[i]->continuousShortPressHandler = NULL;
		btns[i]->continuousLongPressHandler = NULL;
		btns[i]->releaseHandler = NULL;
//		btns[i]-> = NULL;
		i++;
	}
}

char buttonHandlers[50] = {0};
char buttonHandler2[50] = {0};

// settings for timer cycles needed for a long threshold and freq of pulse on long press
struct PressSetting pressSetting = {10, 1};
void setPressSetting(uint16_t shortPress, uint16_t longPressPulse){
	pressSetting.shortTreshold = shortPress;
	pressSetting.longPulseTreshold = longPressPulse;
}

uint8_t readButton(Button* btn){
	return ((HAL_GPIO_ReadPin(btn->port, btn->pin) == 0));
}

void scanButton(Button* btn){
	uint8_t prevStatus = btn->currStatus;
	btn->prevStatus = prevStatus;
	uint8_t currStatus = readButton(btn);
	btn->currStatus = currStatus;
	if(currStatus == prevStatus){
		// stable state pressed or released
		if(currStatus == 1){
			// stable pressed state
			btn->shortContinuous++;
			if(btn->shortContinuous >= 10000) btn->shortContinuous = pressSetting.shortTreshold;
			// short continuous press handler
			// ... 																<------ continuous press handler
			if(btn->continuousShortPressHandler != NULL){
				btn->continuousShortPressHandler(NULL);
			}
			// press longer then threshold
			if(btn->shortContinuous >= pressSetting.shortTreshold){
				// single long press handler
				if(btn->longSingleHandled == 0){
					// stuff to do once when long pressed						<------ single hold handler
					if(btn->singleLongPressHandler != NULL){
						btn->singleLongPressHandler(NULL);
					}
					btn->longSingleOn++;
					// set handled flag up
					btn->longSingleHandled = 1;
				}
				if(btn->shortContinuous%pressSetting.longPulseTreshold == 0){
					//continuous long action handler							<------ continuous hold handler
					if(btn->continuousLongPressHandler != NULL){
						btn->continuousLongPressHandler(NULL);
					}
					btn->longContinuous++;
					if(btn->longContinuous >= 1000) btn->longContinuous = 1;
				}
			}
			// clear release handled flag: new release action will be possible
			btn->releaseHandled = 0;
		} else {
			// stable released state
			// clear single press handled flag: ready for another click
			btn->shortSingleHandled = 0;
			btn->longSingleHandled = 0;
		}
	} else {
		// changed state - just pressed or just released
		// check if pressed or released
		if(currStatus == 1){
			// pressed
			// clear old pressed values
			btn->shortContinuous = 0;
			btn->longContinuous = 0;
			// handle single press
			if(btn->shortSingleHandled == 0){
				// to do after press											<------ single press handler
				if(btn->singlePressHandler != NULL){
					btn->singlePressHandler(NULL);
				}
				btn->shortSingleOn++;
				// set single press handled flag
				btn->shortSingleHandled = 1;
			}
		} else {
			// released
			if(btn->releaseHandled == 0){
				// handle button release										<------ single release handler
				if(btn->releaseHandler != NULL){
					btn->releaseHandler(NULL);
				}
				btn->shortSingleOff++;
				// set handled flag
				btn->releaseHandled = 1;
			}
		}
	}
}

void scanButtons(Button* btns[6]){
	uint8_t i = 0;
	while(i < 6){
		scanButton(btns[i]);
		i++;
	}
}
