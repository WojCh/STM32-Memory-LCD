/*
 * gps2.c
 *
 *  Created on: Sep 4, 2022
 *      Author: wojch
 */

/* strtoke example */
#include <stdio.h>
#include <string.h>

/* behaves like strtok() except that it returns empty tokens also
 */
char* strtoke(char *str, const char *delim)
{
  static char *start = NULL; /* stores string str for consecutive calls */
  char *token = NULL; /* found token */
  /* assign new start in case */
  if (str) start = str;
  /* check whether text to parse left */
  if (!start) return NULL;
  /* remember current start as found token */
  token = start;
  /* find next occurrence of delim */
  start = strpbrk(start, delim);
  /* replace delim with terminator and move start to follower */
  if (start) *start++ = '\0';
  /* done */
  return token;
}

uint8_t validateChecksum(char* nmeaSentence){
	uint8_t chksum = 0;
	uint8_t i = 0;
	while(nmeaSentence[i] != '*' & nmeaSentence[i]!=NULL){
		chksum ^= nmeaSentence[i];
		i++;
	}
	return hexCharToInt(&nmeaSentence[i+1])==chksum;
}

#include "gps2.h"


void getAllMessages(char* buffer){

}
uint8_t getMessage(char* destination, char* source, nmeaSentence_t type){
	char* start = strstr(source, gpsCmd[type]);
	if(start == NULL) return(0);
	if(strtok(start,"\n\r") == NULL) return(0);
	if(validateChecksum(start)){
		return strcpy(destination,start);
	} else {
		return NULL;
	}
}

struct nmeaSentence{
	char sentence[NMEA_MAX_SENTENCE_LENGTH];
	char* wordPtrs[20];
	uint8_t wordNum;
};
//function not tested
struct nmeaSentence tokenizeSentence(char* sentence){
	struct nmeaSentence result;
	strcpy(result.sentence, sentence);
	result.wordNum = 0;
	char* prevPointer = 0;
	for(char* parsePointer = strtoke(result.sentence, ","); parsePointer != NULL; parsePointer = strtoke(NULL, ",")){
		result.wordPtrs[result.wordNum] = parsePointer;
		result.wordNum++;
		prevPointer = parsePointer;
	}
	return result;
}



location_t getLocation(struct gpsDevice* dev){
//	copy buffer - prevent from mutating (when DMA updated)
	char tmpBuf[GPS_BUFFER_SIZE];
	strncpy(&tmpBuf, dev->buffer, GPS_BUFFER_SIZE);

	location_t currPosition;
	char sentence[NMEA_MAX_SENTENCE_LENGTH+1];
	// receive and validate message
	if(getMessage(&sentence, &tmpBuf, NMEA_GNGGA) == NULL){
		strcpy(&currPosition.debug, "invalid sentence");
		currPosition.isValid = 0;
		return currPosition;
	}
	struct nmeaSentence snt = tokenizeSentence(sentence);
	//write to struct whole sentence
	strcpy(&currPosition.debug, sentence);
	// tokenize
	// GNGGA
	char* parsePointer = strtoke(sentence, ",");
	strcpy(&currPosition.words[0][0], parsePointer);
	// UTC Time
	parsePointer = strtoke(NULL, ",");
	strcpy(&currPosition.words[1][0], parsePointer);
	// DDMM.MMM Latitude
	parsePointer = strtoke(NULL, ",");
	strcpy(&currPosition.words[2][0], parsePointer);
	// Latitude N/S
	parsePointer = strtoke(NULL, ",");
	strcpy(&currPosition.words[3][0], parsePointer);
	// DDDMM.MMM Longitude
	parsePointer = strtoke(NULL, ",");
	strcpy(&currPosition.words[4][0], parsePointer);
	// Longitude W/E
	parsePointer = strtoke(NULL, ",");
	strcpy(&currPosition.words[5][0], parsePointer);
	// Fix type - 0-nofix, 1-GPS, 2-DGPS
	parsePointer = strtoke(NULL, ",");
	strcpy(&currPosition.words[6][0], parsePointer);
	// Number of used satellites
	parsePointer = strtoke(NULL, ",");
	strcpy(&currPosition.words[7][0], parsePointer);
	// HDOP
	parsePointer = strtoke(NULL, ",");
	strcpy(&currPosition.words[8][0], parsePointer);
	// Altitude above mean sea level
	parsePointer = strtoke(NULL, ",");
	strcpy(&currPosition.words[9][0], parsePointer);
	// Altitude units
	parsePointer = strtoke(NULL, ",");
	strcpy(&currPosition.words[10][0], parsePointer);
	// Height of mean sea level above WGS-84 earth ellipsoid
	parsePointer = strtoke(NULL, ",");
	strcpy(&currPosition.words[11][0], parsePointer);
	// Units of the above geoid seperation (M for meters)
	parsePointer = strtoke(NULL, ",");
	strcpy(&currPosition.words[12][0], parsePointer);
//   check if has fix - GPGGA
//	strtoke()
//   get position information

//convert to format

	return currPosition;
}

// get multiple sentences - test
//location_t getLocation(struct gpsDevice* dev){
//	char tmpBuf[300];
//	strncpy(&tmpBuf, dev->buffer, 300);
//// convert buffer to sentences
//// find msg start - 1 character after $
//	char* start = strchr(tmpBuf, '$');
//// tokenize on CLCR
//	char* sentence = strtok(start, "\r");
//	while((sentence != NULL) & (sentence - start <= GPS_BUFFER_SIZE)){
//// validate chksum
//	if(validateChecksum(sentence)){
//// save sentence
//// identify sentence type
//		uint8_t msgType = 0;
//		char msgId[6];
//		strncpy(msgId, sentence+1, 5);
//		while(strcmp(msgId, gpsCmd[msgType])!=0){
//			if(msgType < NMEA_MSG_TYPE_NUM){
//				msgType++;
//			} else {
//				break;
//			}
//		}
//		strcpy(gpsSentences[msgType], sentence);
//	}
//// skip to next sentence
//		sentence = strtok(NULL, "\n");
//	}
//// tokenize on comma
//	char localSentence[85];
//	strncpy(localSentence, gpsSentences[GNZDA], 84);
//
//	char* currentWord = strtoke(localSentence, ",");
//	char* words[20];
//	uint8_t i = 0;
//	while(currentWord != NULL){
//		currentWord = strtoke(NULL, ",");
//		words[i] = currentWord;
//		i++;
//	}
//// convert sentence to words
//
////parse nmea sentences
//
////   check if has fix - GPGGA
//
////   get position information
//
////convert to format
//
////write to struct
//	location_t currPosition;
//	strcpy(&currPosition.debug, sentence);
//	return currPosition;
//}

