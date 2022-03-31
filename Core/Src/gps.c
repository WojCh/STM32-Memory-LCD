#include "gps.h"

//const uint8_t gpsCmds[] = {"GNGSA", "GNGLL", "GNGGA", "GPTXT", "GNZDA", "GNVTG", "GNRMC", "GPGSV", "BDGSV"};

void test(char* buffer, gpsTime* time){

	char code[] = "GNZDA";
	char term[] = ",";

	//	int diff = strncmp(loc+1, "GNZDA", sizeof(uint8_t)*5);
		char* pos = strstr(buffer, code);
		char* end = strchr(pos, 13); // carriage return
		uint8_t strl = end - pos;

		char myStr[84] = {0};
		strncpy(myStr, pos, 83);

//		Add checking of checksum
//		Add checking if data provided
//		$GNZDA,204235.000,31,03,2022,00,00*49 - every char xor

		char* timestr = strtok(myStr+6, ",");
		char* day = strtok(NULL, term);
		char* mon = strtok(NULL, term);
		char* year = strtok(NULL, term);
		strtok(NULL, "*");
		char* chks = strtok(NULL, 13);
		char result[9] = {0};
		strncpy(result, timestr, 2);
		strncpy(result+2, ":", 1);
		strncpy(result+3, timestr+2, 2);
		strncpy(result+5, ":", 1);
		strncpy(result+6, timestr+4, 2);

		char dateres[11] = {0};
		strncpy(dateres, day, 2);
		strncpy(dateres+2, "-", 1);
		strncpy(dateres+3, mon, 2);
		strncpy(dateres+5, "-", 1);
		strncpy(dateres+6, year, 4);

		if(pos != NULL){
			memcpy(&time->hour, timestr, 2);
			memcpy(&time->minute, timestr+2, 2);
			memcpy(&time->second, timestr+4, 2);
			memcpy(&time->timestr, result, 8);
			memcpy(&time->day, day, 2);
			memcpy(&time->month, mon, 2);
			memcpy(&time->year, year, 4);
			memcpy(&time->datestr, dateres, 10);
			memcpy(&time->chks, chks, 2);
	}


}


