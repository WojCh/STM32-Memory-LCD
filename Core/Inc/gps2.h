/*
 * gps2.h
 *
 *  Created on: Sep 4, 2022
 *      Author: wojch
 */

#ifndef INC_GPS2_H_
#define INC_GPS2_H_

//temporary include - before local, improved implementation of gpsSentence parsing
#include "gps.h"

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
static const char gpsCmds[][6] = {"GNGSA", "GNGLL", "GNGGA", "GPTXT", "GNZDA", "GNVTG", "GNRMC", "GPGSV", "BDGSV"};
typedef enum nmeaSentenceType{
	GNGGA,
	GNGLL,
	GNGSA,
	GPGSV,
	BDGSV,
	GNRMC,
	GNVTG,
	GNZDA,
	GPTXT,
}nmea_t;


typedef struct location_t{
	double latitude, longitude, elevation;
	char debug[86];
	uint8_t chk;
} location_t;

typedef struct course_t{
	double heading, vSpeed;
};

// update gpsinfo from device
uint8_t updateGpsData(void);
// get location from device
location_t getLocation(struct gpsDevice* dev);
// get course from device

//initialize device
//get NMEA sentence
//update information
//parse time
//parse position

#endif /* INC_GPS2_H_ */
