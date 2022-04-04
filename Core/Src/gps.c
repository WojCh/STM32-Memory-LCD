#include "gps.h"


//const uint8_t gpsCmds[] = {"GNGSA", "GNGLL", "GNGGA", "GPTXT", "GNZDA", "GNVTG", "GNRMC", "GPGSV", "BDGSV"};
char gpsBuffer[600] = {0};

void getDataFromUart(gpsDevice* gps){
	  HAL_UART_Receive(&huart6, &gps->buffer, 600, 1000);
//	  HAL_UART_Receive(&huart6, &gpsModule.buffer, 600, 1000);
}

gpsDevice initGps(UART_HandleTypeDef* uartPort){
	gpsDevice gpsModule;
	gpsModule.uartPort = uartPort;
	strncpy(&gpsModule.buffer, 0, 600);
	gpsModule.getData = &getDataFromUart;
	return(gpsModule);
}

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

int hexCharToInt(char* value){
	int msb = 0;
	if((*value >= 48) &(*value <= 57)){
		msb = *value - 48;
	} else {
		msb = *value - 48 - 7;
	}
	int lsb = 0;
	if((*(value+1) >= 48) &(*(value+1) <= 57)){
		lsb = *(value+1) - 48;
	} else {
		lsb = *(value+1) - 48 - 7;
	}
	int result = lsb | (msb << 4);
	return(result)
;}


void readSentence(char* buffer, gpsSentence* sentence){

//	char code[] = "BDGSV";
//	char code[] = "GNZDA";
//	char code[] = "GPGSV";
//	char code[] = "GNGSA";
//	char code[] = "GPTXT";
	char code[] = "GNGGA";
	char term[] = ",";

	char* pos = strstr(buffer, code);
	if(pos != NULL){
		char* end = strchr(pos, 13); // carriage return
		uint8_t strl = end - pos;

		char myStr[84] = {0};
		strncpy(myStr, pos, 83);

		// Checksum control
		char chksum = 0;
		uint8_t j = 0;
		char tcode = 'b';
		while((myStr[j] != '*') & (myStr[j] != NULL)){
				tcode = 'c';
			if(j < 84){
				chksum ^= myStr[j];
				tcode = 'd';
				j++;
				tcode = 'e';
			} else {
				break;
			}

		}
		tcode = 'f';
		char* chkPos = strchr(pos, '*')+1;
		char readChkSum = hexCharToInt(chkPos);
		if(readChkSum == chksum){
			sentence->valid = '+';
			int wordLen = 0;
			char* position = myStr;
			int i = 0;
			while((*position != 10) & (i < 24)){
				sscanf(position, "%[^,\r*]", sentence->words[i]);
				wordLen = strlen(sentence->words[i]);
				position = position + wordLen + 1;
				i++;
			}
			sentence->wordNum = i-1;
			strncpy(&sentence->msgId, sentence->words[0], 5);
		} else {
			sentence->valid = 'x';
		}
	}
}

void test3(void){
	char sentence[10][15];
	strcpy(sentence[0], "GPGGA");
	strcpy(sentence[1], "GPZDA");
}


