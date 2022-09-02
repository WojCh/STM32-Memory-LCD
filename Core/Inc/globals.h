/*
 * global.h
 *
 *  Created on: 1 wrz 2022
 *      Author: wojch
 */

#ifndef SRC_GLOBALS_H_
#define SRC_GLOBALS_H_

#include "../Src/utils/ringBuffer.h"
#include "../Src/utils/cbuffer.h"
#include "gps.h"

extern RTC_TimeTypeDef RtcTime;
extern RTC_DateTypeDef RtcDate;
extern RingBuffer_t tempRing;
//extern RingBuffer_t baroRing;
extern cbuf_t baroRing;
extern gpsDevice_t gpsDev;

#endif /* SRC_GLOBALS_H_ */
