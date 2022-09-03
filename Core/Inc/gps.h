#ifndef INC_GPS_H_
#define INC_GPS_H_

#define GPS_BUFFER_SIZE 600

typedef struct gpsDevice gpsDevice_t;

#include "usart.h"

struct gpsDevice{
	UART_HandleTypeDef* uartPort;
	char buffer[GPS_BUFFER_SIZE];
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

//NMEA definitions
//char* gpsCmds[9] = {"GNGSA", "GNGLL", "GNGGA", "GPTXT", "GNZDA", "GNVTG", "GNRMC", "GPGSV", "BDGSV"};

//GNGGA - Global Positioning System Fix Data
//GNGLL - Geographic position, latitude and longitude (and time)
//GNGSA - GPS DOP and active satellites
//GPGSV - Satellites in view
//BDGSV - Satellites in view
//GNRMC - Recommended minimum specific GPS/Transit data
//GNVTG - Track made good and ground speed
//GNZDA - Time and Date
//GPTXT -

//initialize device
//get NMEA sentence


#endif /* INC_LCD_H_ */
