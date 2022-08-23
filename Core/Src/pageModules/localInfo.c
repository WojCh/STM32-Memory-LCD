/*
 * localInfo.c
 *
 *  Created on: 25 kwi 2022
 *      Author: wojch
 *
 *      module displaying sun position information
 *      https://gml.noaa.gov/grad/solcalc/solareqns.PDF
 *      https://gml.noaa.gov/grad/solcalc/sunrise.html
 */
#include "localInfo.h"

// fonts
#include "fonts/smallestFont.h"
#include "fonts/zekton14.h"
#include "fonts/zekton14b.h"
#include "fonts/zekton24.h"
#include "fonts/zekton84.h"
#include <fonts/zekton45.h>


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
	btn_BC.onSinglePressHandler = &prevScreen;
//	btn_B1.onContinuousShortPressHandler = &addDay;
//	btn_B3.onContinuousShortPressHandler = &remDay;
}
void localSetup(void){
	setDefaultClbcks();
	testTime.tm_hour = RtcTime.Hours;
	testTime.tm_min = RtcTime.Minutes;
	testTime.tm_sec = RtcTime.Seconds;
	testTime.tm_mday = RtcDate.Date ;
	testTime.tm_mon = RtcDate.Month-1;
//	testTime.tm_year = 2022-1900;
	testTime.tm_year = RtcDate.Year+100;
//	testTime.tm_wday = zellerCongruence(10, 10, 2022);
//	testTime.tm_yday = 10;
	mktime(&testTime);
}


void localMain(void){
	testTime.tm_hour = RtcTime.Hours;
	testTime.tm_min = RtcTime.Minutes;
	testTime.tm_sec = RtcTime.Seconds;
	testTime.tm_mday = RtcDate.Date ;
	testTime.tm_mon = RtcDate.Month-1;
//	testTime.tm_year = 2022-1900;
	testTime.tm_year = RtcDate.Year+100;
//	testTime.tm_wday = zellerCongruence(10, 10, 2022);
//	testTime.tm_yday = 10;
	mktime(&testTime);

	char textBuffer[50] = {0};
	char textBuffer2[50] = {0};
	uint8_t shiftedWeekDay = (testTime.tm_wday+7-1)%7+1;
	uint8_t weekOfTheYear = (testTime.tm_yday+1+7-shiftedWeekDay)/7;
	sprintf(&textBuffer, "week %d day %d", weekOfTheYear, testTime.tm_yday+1);
	lcdPutStr(10, 10, textBuffer, zekton12font);

	sprintf(&textBuffer, asctime(&testTime));
	lcdPutStr(170, 10, textBuffer, smallestFont);
	strftime(&textBuffer, 40, "%Z day:%j week:%U", &testTime);
	lcdPutStr(170, 22, textBuffer, smallestFont);

	uint8_t hhour = testTime.tm_hour;
	uint8_t mmin = testTime.tm_min;
	uint8_t ssec = testTime.tm_sec;
	int timezone = 2;		// [h] east+ west-
	int dayOfTheYear = testTime.tm_yday+1;
	// fractional year = gamma [rad]
	float fyear = (2*M_PI/365)*(dayOfTheYear-1+(hhour-timezone-12)/24);
	// equation of time [min]
	float eqtime = 229.18*(0.000075+0.001868*cos(fyear)-0.032077*sin(fyear)-0.014615*cos(2*fyear)-0.040849*sin(2*fyear));
	// solar declination angle [rad]
	float decl = 0.006918-0.399912*cos(fyear)+0.070257*sin(fyear)-0.006758*cos(2*fyear)+0.000907*sin(2*fyear)-0.002697*cos(3*fyear)+0.00148*sin(3*fyear);


	double longitude = 17; 	// [deg]
	double latitude = 51;	// [deg]
	float time_off = eqtime+4*longitude-60*timezone; // time offset [min]
	float tst = hhour*60+mmin+(float)ssec/60+time_off; // true solar time [min]
	// solar hour angle [deg]
	float sha = (tst/4)-180;
	// solar zenith angle = phi [rad]
	float cosphi = sin(latitude*M_PI/180)*sin(decl)+cos(latitude*M_PI/180)*cos(decl)*cos(sha*M_PI/180);
	float phi = acos(cosphi);
	float sinphi = sqrt(1-cosphi*cosphi);
	// solar azimuth = theta [rad]
	float sa = -acos(-(sin(latitude*M_PI/180)*cosphi-sin(decl))/(cos(latitude*M_PI/180)*sinphi));

	// setting for sunrise/sunset zenith angle [rad]
	double twilightType[] = {0.833, 6, 12, 18}; // twilight, civil, nautical, astronomical
	double zenith = (90+twilightType[0])*M_PI/180;
	// calculated hour angle [rad]
	float cha = acos(cos(zenith)/(cos(latitude*M_PI/180)*cos(decl))-tan(latitude*M_PI/180)*tan(decl));

	//sunrise/sunset/noon times [min]
	int sunrise = 720-4*(longitude+cha*180/M_PI)-eqtime+60*timezone;
	int sunset = 720-4*(longitude-cha*180/M_PI)-eqtime+60*timezone;
	int noon = 720-4*longitude-eqtime+60*timezone;

//	debugging values
//	sprintf(&textBuffer, "g:%f et:%f decl:%f to:%0.2f", fyear, eqtime, decl, time_off);
//	lcdPutStr(0, 190, textBuffer, smallestFont);
//	sprintf(&textBuffer2, "tst:%f sha:%f cosphi:%f", tst, sha, cosphi);
//	lcdPutStr(0, 200, textBuffer2, smallestFont);
//	sprintf(&textBuffer, "sa:%f cha:%f", sa, cha);
//	lcdPutStr(0, 210, textBuffer, smallestFont);

	// add atmospheric refraction
	// https://gml.noaa.gov/grad/solcalc/calcdetails.html
	sprintf(&textBuffer, "Sunrise: %02d:%02d", sunrise/60, sunrise%60);
	lcdPutStr(10, 28, textBuffer, zekton12font_bold);
	sprintf(&textBuffer, "Noon: %02d:%02d", noon/60, noon%60);
	lcdPutStr(10, 44, textBuffer, zekton12font_bold);
	sprintf(&textBuffer, "Sunset: %02d:%02d", sunset/60, sunset%60);
	lcdPutStr(10, 60, textBuffer, zekton12font_bold);

	sprintf(&textBuffer, "solar elevation angle: %02.3f deg", 90-phi*180/M_PI);
	lcdPutStr(10, 80, textBuffer, zekton12font_bold);

	double saDeg;
	if(cha<0) saDeg = -sa*180/M_PI;
	else saDeg = 360+sa*180/M_PI;
	sprintf(&textBuffer, "solar azimuth angle: %02.3f deg", saDeg);
//	sprintf(&textBuffer, "solar azimuth angle: %02.3f deg", fmod(360+sa*180/M_PI, 360));
	lcdPutStr(10, 96, textBuffer, zekton12font_bold);

	double perc = (hhour*60+mmin+(double)ssec/60-sunrise)*100/(sunset-sunrise);
	sprintf(&textBuffer, "percentage daylight: %2.3f%%", perc);
	lcdPutStr(10, 116, textBuffer, zekton12font_bold);
	sprintf(&textBuffer, "day length: %02dh %02dmin", (sunset-sunrise)/60, (sunset-sunrise)%60);
	lcdPutStr(10, 132, textBuffer, zekton12font_bold);

	uint16_t scaleXrise = 10+380*sunrise/(24*60-0);
	uint16_t scaleXset = 10+380*sunset/(24*60-0);
	uint16_t scaleXnoon = 10+380*noon/(24*60-0);
	uint16_t scaleXnow = 10+380*(hhour*60+mmin)/(24*60-0);

	lcdHLine(10,399-10,165,1);
	lcdVLine(scaleXrise, 160, 170, 2);
	lcdVLine(scaleXset, 160, 170, 2);
	lcdVLine(scaleXnoon, 160, 170, 2);
	lcdVLine(scaleXnow, 150, 175, 2);

	sprintf(&textBuffer, "%02d:%02d", sunrise/60, sunrise%60);
	lcdPutStr(scaleXrise-19, 170, textBuffer, smallestFont);
	sprintf(&textBuffer, "%02d:%02d", sunset/60, sunset%60);
	lcdPutStr(scaleXset-19, 170, textBuffer, smallestFont);
	sprintf(&textBuffer, "%02d:%02d", noon/60, noon%60);
	lcdPutStr(scaleXnoon-19, 170, textBuffer, smallestFont);
}


