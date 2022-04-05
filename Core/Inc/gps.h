#ifndef INC_GPS_H_
#define INC_GPS_H_

#include "main.h"
#include "usart.h"

#define GPS_BUFFER_SIZE 600

extern char gpsBuffer[];

typedef struct gpsDevice{
	UART_HandleTypeDef* uartPort;
	char buffer[GPS_BUFFER_SIZE];
	void (*getData)(struct gpsDevice*);
//	uint8_t onOff;
} gpsDevice;

gpsDevice initGps(UART_HandleTypeDef* uartPort);

typedef struct gpsTime{
	uint8_t hour[3];
	uint8_t minute[3];
	uint8_t second[3];
	uint8_t day[3];
	uint8_t month[3];
	uint8_t year[5];
} gpsTime;

const enum gpsFields {GPS_TIME, GPS_POSITION, GPS_SATELLITE};

typedef struct gpsStatus{
	gpsTime time;
} gpsStatus;

//gpsStatus gpsState

void gpsUpdateField(enum gpsFields);

typedef struct gpsSentence{
	char msgId[6];
	char words[25][20];
	uint8_t wordNum;
	char valid;
} gpsSentence;

#endif /* INC_LCD_H_ */
