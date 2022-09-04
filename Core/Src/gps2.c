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

#include "gps2.h"

struct NmeaInfo_t{
	char GNGGA[85];
//	char* GNGLL[85];
//	char* GNGSA[85];
//	char* GPGSV[85];
//	char* BDGSV[85];
//	char* GNRMC[85];
//	char* GNVTG[85];
//	char* GNZDA[85];
//	char* GPTXT[85];
} NmeaInfo;

void getAllMessages(char* buffer){

}
void getMessage(void);

location_t getLocation(struct gpsDevice* dev){
	char tmpBuf[300];
	strncpy(&tmpBuf, dev->buffer, 300);
// convert buffer to sentences
// find msg start - 1 character after $
	char* start = strchr(tmpBuf, '$')+1;
// tokenize on CLCR
	char* sentence = strtok(start, "\r");
// calculate checksum
	uint8_t chksum = 0;
	uint8_t i = 0;
	while(sentence[i] != '*' & sentence[i]!=NULL){
		chksum ^= sentence[i];
		i++;
	}
// validate chksum
	if(hexCharToInt(&sentence[i+1])==chksum){
// save sentence
// identify sentence type
		strcpy(NmeaInfo.GNGGA, sentence);
	} else {
// skip to next sentence
//		sentence = strtok(NULL, "\n");
	}
// tokenize on ,


// convert sentence to words

//parse nmea sentences

//   check if has fix - GPGGA

//   get position information

//convert to format

//write to struct
	location_t currPosition;
	strcpy(&currPosition.debug, sentence);
	currPosition.chk = chksum;
	return currPosition;
}

