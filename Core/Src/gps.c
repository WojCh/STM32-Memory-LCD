#include "gps.h"

//const uint8_t gpsCmds[] = {"GNGSA", "GNGLL", "GNGGA", "GPTXT", "GNZDA", "GNVTG", "GNRMC", "GPGSV", "BDGSV"};
char gpsBuffer[600] = {0};

void getDataFromUart(gpsDevice* gps){
	  HAL_UART_Receive(&huart6, &gps->buffer, GPS_BUFFER_SIZE, 1000);
//	  HAL_UART_Receive(&huart6, &gpsModule.buffer, 600, 1000);
}
// Initialization of gpsDefice struct
gpsDevice initGps(UART_HandleTypeDef* uartPort){
	gpsDevice gpsModule;
	gpsModule.uartPort = uartPort;
	strncpy(&gpsModule.buffer, 0, GPS_BUFFER_SIZE);
	gpsModule.getData = &getDataFromUart;
	gpsModule.updateStatus = &gpsUpdateStatus;
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
		printf("b ");
		while((myStr[j] != '*') & (myStr[j] != NULL)){
			printf("c ");
				if(j < 84){
				printf("j: %d\n", j);
				printf("mystr[j] %c\n", myStr[j]);
				chksum ^= myStr[j];
				printf("d ");
				j++;
				printf("e ");
					} else {
				break;
			}
		}
		printf("f\n");
		char* chkPos = strchr(pos, '*')+1;
		char readChkSum = hexCharToInt(chkPos);
		if(readChkSum == chksum){
			sentence->valid = 1;
			int wordLen = 0;
			char* position = myStr;
			int i = 0;
			while((*position != 10) & (i < 24)){
				int res = sscanf(position, "%[^,\r*]", sentence->words[i]);
				if(res==0){
					memset(sentence->words[i], 0, sizeof(sentence->words[i]));
				}
//				printf("iter: %d: %s, res: %d\n", i, sentence->words[i], res);
				wordLen = strlen(sentence->words[i]);
				position = position + wordLen + 1;
				i++;
			}
			sentence->wordNum = i-1;
			strncpy(&sentence->msgId, sentence->words[0], 5);
		} else {
			sentence->valid = 0;
		}

	}
}

void gpsUpdateStatus(gpsDevice* gpsModule){
	gpsParseTime(&gpsModule->status, &gpsModule->buffer);
	gpsParsePosition(&gpsModule->status, &gpsModule->buffer);
}

void gpsParseTime(gpsStatus* status, char* buffer){
	gpsSentence sentence;
	readSentence(buffer, &sentence, "GNZDA");
// 		Check correctness
//		Add return value to indicate need for re-reading data
	if((strncmp(sentence.msgId, "GNZDA", 6)==0) & sentence.valid){
//		Set valid flag
			memset(&status->time.isValid, 1, sizeof(char));
//		Set time fields
			strncpy(&status->time.hour, (sentence.words[1]), 2);
			memset(&status->time.hour[2], NULL, sizeof(char));
			strncpy(&status->time.minute, (sentence.words[1])+2, 2);
			memset(&status->time.minute[2], NULL, sizeof(char));
			strncpy(&status->time.second, (sentence.words[1])+4, 2);
			memset(&status->time.second[2], NULL, sizeof(char));
//		Set date fields
			strncpy(&status->time.day, (sentence.words[2]), 2);
			memset(&status->time.day[2], NULL, sizeof(char));
			strncpy(&status->time.month, (sentence.words[3]), 2);
			memset(&status->time.month[2], NULL, sizeof(char));
			strncpy(&status->time.year, (sentence.words[4]), 4);
			memset(&status->time.year[4], NULL, sizeof(char));
		}
}

void gpsParsePosition(gpsStatus* status, char* buffer){
	gpsSentence sentence;
		readSentence(buffer, &sentence, "GNRMC");
	// 		Check correctness
		if((strncmp(sentence.msgId, "GNRMC", 6)==0) & sentence.valid){

		}
}



