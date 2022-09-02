/*
 * global.h
 *
 *  Created on: 1 wrz 2022
 *      Author: wojch
 */

#ifndef SRC_GLOBAL_H_
#define SRC_GLOBAL_H_

	extern RTC_TimeTypeDef RtcTime;
	extern RTC_DateTypeDef RtcDate;
	extern RingBuffer_t tempRing;
	extern RingBuffer_t baroRing;
	extern gpsDevice_t gpsDev;

#endif /* SRC_GLOBAL_H_ */
