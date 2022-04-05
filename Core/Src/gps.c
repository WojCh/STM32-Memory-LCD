#include "gps.h"

//const uint8_t gpsCmds[] = {"GNGSA", "GNGLL", "GNGGA", "GPTXT", "GNZDA", "GNVTG", "GNRMC", "GPGSV", "BDGSV"};
char gpsBuffer[600] = {0};

void getDataFromUart(gpsDevice* gps){
	  HAL_UART_Receive(&huart6, &gps->buffer, GPS_BUFFER_SIZE, 1000);
//	  HAL_UART_Receive(&huart6, &gpsModule.buffer, 600, 1000);
}

gpsDevice initGps(UART_HandleTypeDef* uartPort){
	gpsDevice gpsModule;
	gpsModule.uartPort = uartPort;
	strncpy(&gpsModule.buffer, 0, GPS_BUFFER_SIZE);
	gpsModule.getData = &getDataFromUart;
	return(gpsModule);
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

//	char code[] = "BDGSV";
//	char code[] = "GNZDA";
//	char code[] = "GPGSV";
//	char code[] = "GNGSA";
//	char code[] = "GPTXT";
//	char code[6] = "GNGGA";
void readSentence(char* buffer, gpsSentence* sentence, char code[6]){
	// word terminator
	char term[] = ",";
	// beginning of the sentence
	char* pos = strstr(buffer, code);
	if(pos != NULL){					// if found
		char* end = strchr(pos, 13); 	// end of buffer on /r carriage return
//		uint8_t strl = end - pos;		// string length - might be used for malloc
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

//void gpsUpdateField(enum gpsFields){
//
//}

void gpsUpdateStatus(gpsStatus* gpsState, gpsSentence* sentence){
	if(strncmp(sentence->msgId, "GNZDA", 6)==0){

		strncpy(&gpsState->time.second, (sentence->words[1])+4, 2);
		memset(&gpsState->time.second+2, NULL, 1);
	}
}



