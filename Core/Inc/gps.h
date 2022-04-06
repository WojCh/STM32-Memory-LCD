#ifndef INC_GPS_H_
#define INC_GPS_H_

#include "main.h"
#include "usart.h"

#define GPS_BUFFER_SIZE 600

extern char gpsBuffer[];

const enum gpsField {GPS_TIME, GPS_POSITION, GPS_SATELLITE};

typedef struct gpsTime{
	uint8_t hour[3];
	uint8_t minute[3];
	uint8_t second[3];
	uint8_t day[3];
	uint8_t month[3];
	uint8_t year[5];
	uint8_t int_hour;
	uint8_t int_minute;
	uint8_t int_second;
	uint8_t int_day;
	uint8_t int_month;
	uint16_t int_year;
	uint8_t isValid;
} gpsTime;


typedef struct gpsStatus{
	gpsTime time;
//	gpsPosition position;
//	gpsSatInfo satInfo;
} gpsStatus;

typedef struct gpsSentence{
	char msgId[6];
	char words[25][20];
	uint8_t wordNum;
	uint8_t valid;
} gpsSentence;


typedef struct gpsDevice{
	UART_HandleTypeDef* uartPort;
	char buffer[GPS_BUFFER_SIZE];
	void (*getData)(struct gpsDevice*);
	void (*updateStatus)(struct gpsDevice*);
	gpsStatus status;
//	uint8_t onOff;
} gpsDevice;

gpsDevice initGps(UART_HandleTypeDef* uartPort);

void gpsUpdateStatus(gpsDevice* gpsModule);

void gpsParseTime(gpsStatus* status, char* buffer);


#endif /* INC_LCD_H_ */
