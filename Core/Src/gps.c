#include "gps.h"

//const uint8_t gpsCmds[] = {"GNGSA", "GNGLL", "GNGGA", "GPTXT", "GNZDA", "GNVTG", "GNRMC", "GPGSV", "BDGSV"};

void test(char* buffer, gpsTime* time){

	char code[] = "GNZDA";

	if(loc != NULL){
	//	int diff = strncmp(loc+1, "GNZDA", sizeof(uint8_t)*5);
		char* pos = strstr(code, *buffer);
		char* end = strchr(pos, '*');
		int strl = (end-pos);
		char myStr[84] = {0};
//		should check if pos fits in myStr
		strncpy(myStr, pos, 83);

		char* tok = strtok(myStr, ",");
		tok = strtok(NULL, ",");

	//	int diff = strncmp(loc+1, "GPTXT", 5);

		if(pos != NULL){
			memcpy(&time->hour, tok, 7);
			memcpy(&time->minute, "Mm", 3);
			memcpy(&time->second, "Ss", 3);

	}
	}
}


