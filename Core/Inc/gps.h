#ifndef INC_GPS_H_
#define INC_GPS_H_

#define GPS_BUFFER_SIZE 600

typedef struct gpsDevice gpsDevice_t;

#include "usart.h"

//struct gpsDevice{
//	UART_HandleTypeDef* uartPort;
//	char buffer[GPS_BUFFER_SIZE];
//	void (*getData)(struct gpsDevice*);
//	uint8_t isReady;
//};

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
	uint8_t isValid;
} gpsSentence;


#endif /* INC_LCD_H_ */
