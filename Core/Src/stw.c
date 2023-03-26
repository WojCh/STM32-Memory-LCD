/*
 * stw.c
 *
 *  Created on: Jul 10, 2022
 *      Author: wojch
 */

#include "stw.h"
#include "tim.h"

#define STW_STATE_ENABLED	1
#define STW_STATE_DISABLED	0

stw_counter_t currentStw = {0,0};
stw_t stwS = {&currentStw, STW_STATE_DISABLED};

stw_counter_t stw_splits[STW_SPLIT_MAX_NUM];
uint8_t snap_number = 1;

uint8_t getLapNum(void){
	return snap_number;
}
//uint32_t getSec(void){
//	return stwS.cnt->sec;
//}
//uint16_t getCsec(void){
//	return (uint16_t)__HAL_TIM_GET_COUNTER(&htim10)/100;
//}
//uint32_t getLapSec(void){
//	return (getSec()*100+getCsec()-stw_sec_table[snap_number-1]*100-stw_csec_table[snap_number-1])/100;
//}
//uint16_t getLapCsec(void){
//	uint16_t diff = getCsec()-stw_csec_table[snap_number-1];
//	if(diff > 100){
//		return diff+100;
//	} else {
//		return diff;
//	}
//}

// activate stopwatch and it's timer
void stwStart(void){
	stwS.state = STW_STATE_ENABLED;
	  HAL_TIM_Base_Start_IT(&htim10);
}
void stwTick(void){
	if(stwS.state){
		(stwS.cnt->sec)++;
	}
}
void stwStop(void){
	stwS.state = STW_STATE_DISABLED;
	  HAL_TIM_Base_Stop_IT(&htim10);

}
void stwClear(void){
	__HAL_TIM_SET_COUNTER(&htim10, 0);
	stwS.cnt->sec = 0;
	memset(stw_splits, 0, sizeof stw_splits);
	snap_number = 1;
}

void getStw(struct stopwatch_t* stw_ptr, stw_t* stwS){
		stw_ptr->hours = stwS->cnt->sec/(60*60);
		stw_ptr->min = stwS->cnt->sec%(60*60)/(60);
		stw_ptr->sec = stwS->cnt->sec%60;
		stw_ptr->csec = (uint16_t)__HAL_TIM_GET_COUNTER(&htim10)/100;
		// update .00 second counter in stw struct
		stwS->cnt->csec = (uint16_t)__HAL_TIM_GET_COUNTER(&htim10)/100;

}



// stopwatch snapshot
void stwSave(void){
	if(snap_number < STW_SPLIT_MAX_NUM){
		stw_splits[snap_number].sec = stwS.cnt->sec;
		stwS.cnt->csec = (uint16_t)__HAL_TIM_GET_COUNTER(&htim10)/100;
		stw_splits[snap_number].csec = (uint16_t)__HAL_TIM_GET_COUNTER(&htim10)/100;
		snap_number++;
	}
}

void counterDiff(stw_counter_t* result, stw_counter_t* cnt1, stw_counter_t* cnt2){
//	result->sec = (cnt1->sec-cnt2->sec);
//	uint16_t diff = cnt1->csec-cnt2->csec;
////	result->csec = diff;
//		if(diff > 100){
//		result->csec = diff+100;
//	} else {
//		result->csec = diff;
//	}
		result->sec = (cnt1->sec*100+cnt1->csec-cnt2->sec*100-cnt2->csec)/100;
		uint16_t diff = cnt1->csec-cnt2->csec;
		if(diff > 100){
			result->csec = diff+100;
		} else {
			result->csec = diff;
		}
}

// transform counter info into hh/mm/ss/cs struct
void counterToStopwatch(struct stopwatch_t* output, stw_counter_t* counter){
	output->hours = counter->sec/(60*60);
	output->min = counter->sec%(60*60)/(60);
	output->sec = counter->sec%60;
	output->csec = counter->csec;
}


void stwInit(TIM_HandleTypeDef* htim){
	// initialize timer
	// start/stop/reset routine to fix bug:
	//BUG: first stopwatch start after reset causes timer to jump 1 second forward
	  HAL_TIM_Base_Init(htim);
	  HAL_TIM_Base_Start_IT(htim);
	  HAL_TIM_Base_Stop_IT(htim);
	  __HAL_TIM_SET_COUNTER(htim, 0);
}

void stwprintf(char* outputString, struct stopwatch_t* stw_time){
	if(stw_time->hours > 0){
		sprintf(outputString, "%02dh %02d'%02d\"", stw_time->hours, stw_time->min, stw_time->sec);
	} else {
		sprintf(outputString, "%02d'%02d.%02d\"", stw_time->min, stw_time->sec, stw_time->csec);
	}
}


