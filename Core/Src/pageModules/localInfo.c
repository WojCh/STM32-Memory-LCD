/*
 * localInfo.c
 *
 *  Created on: 25 kwi 2022
 *      Author: wojch
 *
 *      module displaying watchfaces
 */
#include "localInfo.h"

// fonts
#include "fonts/smallestFont.h"
#include "fonts/zekton24.h"
#include "fonts/zekton84.h"
#include <fonts/zekton45.h>

void prevMonth(void){
	RtcDate.Month--;
	if (HAL_RTC_SetDate(&hrtc, &RtcDate, RTC_FORMAT_BIN) != HAL_OK)
	{
	Error_Handler();
	}
}

struct tm testTime;

void addDay(){
	testTime.tm_mday++;
	mktime(&testTime);

}
void remDay(){
	testTime.tm_mday--;
	mktime(&testTime);

}

static void setDefaultClbcks(void){
	// module callbacks
	btn_BA.onSinglePressHandler = &nextScreen;
	btn_BB.onSinglePressHandler = &prevMonth;
	btn_BC.onSinglePressHandler = &prevScreen;
	btn_B1.onContinuousShortPressHandler = &addDay;
	btn_B3.onContinuousShortPressHandler = &remDay;
}
void localSetup(void){
	setDefaultClbcks();
	testTime.tm_hour = 15;
	testTime.tm_min = 56;
	testTime.tm_sec = 0;
	testTime.tm_mday = 3 ;
	testTime.tm_mon = 1-1;
	testTime.tm_year = 2022-1900;
//	testTime.tm_wday = zellerCongruence(10, 10, 2022);
//	testTime.tm_yday = 10;
	mktime(&testTime);
}


void localMain(void){
	char textBuffer[50] = {0};
	char textBuffer2[50] = {0};
	uint8_t shiftedWeekDay = (testTime.tm_wday+7-1)%7+1;
	uint8_t weekOfTheYear = (testTime.tm_yday+1+7-shiftedWeekDay)/7;
	sprintf(&textBuffer, "week %d, day %d", weekOfTheYear, testTime.tm_yday+1);
	lcdPutStr(10, 10, textBuffer, zekton24font);

	sprintf(&textBuffer, asctime(&testTime));
	lcdPutStr(10, 160, textBuffer, smallestFont);
	strftime(&textBuffer, 40, "%Z day:%j week:%U", &testTime);
	lcdPutStr(10, 170, textBuffer, smallestFont);

	uint8_t hhour = testTime.tm_hour;
	uint8_t mmin = testTime.tm_min;
	uint8_t ssec = testTime.tm_sec;
	int dayOfTheYear = testTime.tm_yday+1;
	float fyear = (2*3.1415/365)*(dayOfTheYear-1+(hhour-12)/24);
	float eqtime = 229.18*(0.000075+0.001868*cos(fyear)-0.032077*sin(fyear)-0.014615*cos(2*fyear)-0.040849*sin(2*fyear));
	float decl = 0.006918-0.399912*cos(fyear)+0.070257*sin(fyear)-0.006758*cos(2*fyear)+0.000907*sin(2*fyear)-0.002697*cos(3*fyear)+0.00148*sin(3*fyear);

	double longitude = 17;
	double latitude = 51;
	int timezone = 1;
	float time_off = eqtime+4*longitude-60*timezone;
	float tst = hhour*60+mmin+(float)ssec/60+time_off;
	float sha = (tst/4)-180;
	float cosphi = sin(latitude*3.1415/180)*sin(decl)+cos(latitude*3.1415/180)*cos(decl)*cos(sha*3.1415/180);
	float phi = acos(cosphi);
	float sinphi = sqrt(1-cosphi*cosphi);
	float sa = -acos(-(sin(latitude*3.1415/180)*cosphi-sin(decl))/(cos(latitude*3.1415/180)*sinphi));


	double zenith = 90.833*3.1415/180;
//	double zenith = (90.833+6)*3.1415/180;
	float cha = acos(cos(zenith)/(cos(latitude*3.1415/180)*cos(decl))-tan(latitude*3.1415/180)*tan(decl));

	int sunrise = 720-4*(longitude+cha*180/3.1415)-eqtime+60*timezone;
	int sunset = 720-4*(longitude-cha*180/3.1415)-eqtime+60*timezone;
	int noon = 720-4*longitude-eqtime+60*timezone;

	sprintf(&textBuffer, "g:%f et:%f decl:%f to:%0.2f", fyear, eqtime, decl, time_off);
	lcdPutStr(0, 190, textBuffer, smallestFont);
	sprintf(&textBuffer2, "tst:%f sha:%f cosphi:%f", tst, sha, cosphi);
	lcdPutStr(0, 200, textBuffer2, smallestFont);
	sprintf(&textBuffer, "sa:%f cha:%f", sa, cha);
	lcdPutStr(0, 210, textBuffer, smallestFont);

	sprintf(&textBuffer, "Sunrise: %02d:%02d", sunrise/60, sunrise%60);
	lcdPutStr(10, 70, textBuffer, zekton24font);
	sprintf(&textBuffer, "Noon: %02d:%02d", noon/60, noon%60);
	lcdPutStr(10, 100, textBuffer, zekton24font);
	sprintf(&textBuffer, "Sunset: %02d:%02d", sunset/60, sunset%60);
	lcdPutStr(10, 130, textBuffer, zekton24font);
}


