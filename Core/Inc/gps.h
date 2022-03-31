#include "main.h"


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
