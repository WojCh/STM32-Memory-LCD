#ifndef INC_GPS_H_
#define INC_GPS_H_

typedef struct gpsDevice gpsDevice_t;

#include "usart.h"

struct gpsDevice{
	UART_HandleTypeDef* uartPort;
	char buffer[600];
	void (*getData)(struct gpsDevice*);
};

extern char gpsBuffer[];


gpsDevice_t initGps(UART_HandleTypeDef* uartPort);


typedef struct gpsTime{
	uint8_t hour[3];
	uint8_t minute[3];
	uint8_t second[3];
	uint8_t timestr[9];
	uint8_t day[3];
	uint8_t month[3];
	uint8_t year[5];
	uint8_t datestr[11];
	uint8_t chks[3];
} gpsTime;

typedef struct gpsSentence{
	char msgId[6];
	char words[25][20];
	uint8_t wordNum;
	char valid;
} gpsSentence;

#endif /* INC_LCD_H_ */
