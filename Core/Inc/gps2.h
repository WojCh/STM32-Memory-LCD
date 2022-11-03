/*
 * gps2.h
 *
 *  Created on: Sep 4, 2022
 *      Author: wojch
 */

#ifndef INC_GPS2_H_
#define INC_GPS2_H_

#define NMEA_MAX_SENTENCE_LENGTH 82

#define GPS_BUFFER_SIZE 600

typedef struct location_t location_t;
typedef struct gpsDevice gpsDevice_t;

#include "usart.h"

struct gpsDevice{
	UART_HandleTypeDef* uartPort;
	char buffer[GPS_BUFFER_SIZE];
	void (*getData)(struct gpsDevice*);
	uint8_t isReady;
};

extern char gpsBuffer[];


gpsDevice_t initGps(UART_HandleTypeDef* uartPort);

//temporary include - before local, improved implementation of gpsSentence parsing
//#include "gps.h"

//NMEA definitions
//GNGGA - Global Positioning System Fix Data
//GNGLL - Geographic position, latitude and longitude (and time)
//GNGSA - GPS DOP and active satellites
//GPGSV - Satellites in view
//BDGSV - Satellites in view
//GNRMC - Recommended minimum specific GPS/Transit data
//GNVTG - Track made good and ground speed
//GNZDA - Time and Date
//GPTXT - Device message
#define NMEA_MSG_TYPE_NUM 9
static const char gpsCmd[NMEA_MSG_TYPE_NUM][6] = {"GNGGA", "GNGLL", "GNGSA", "GPGSV", "BDGSV", "GNRMC", "GNVTG", "GNZDA", "GPTXT"};
typedef enum nmeaSentenceType{
	NMEA_GNGGA,
	NMEA_GNGLL,
	NMEA_GNGSA,
	NMEA_GPGSV,
	NMEA_BDGSV,
	NMEA_GNRMC,
	NMEA_GNVTG,
	NMEA_GNZDA,
	NMEA_GPTXT,
}nmeaSentence_t;


typedef struct location_t{
	char debug[86];
	char words[15][15];
	uint8_t isValid;
	uint8_t utc_hour, utc_min, utc_sec;
	uint8_t hasFix;
	uint8_t satNum;
	double latitude, longitude, elevation;
	uint8_t latitudeDeg, longitudeDeg;
	double latitudeMin, longitudeMin;
	char n_s, w_e;
} location_t;

typedef struct course_t{
	double heading, vSpeed;
};

// update gpsinfo from device
uint8_t updateGpsData(void);
// get location from device
uint8_t getLocation(struct gpsDevice* dev, location_t* position);
// get course from device

//initialize device
//get NMEA sentence
//update information
//parse time
//parse position

#endif /* INC_GPS2_H_ */
