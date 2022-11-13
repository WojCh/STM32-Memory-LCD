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
#include "fonts/fonts.h"

struct tm testTime;
uint8_t localModuleNum = 0;

void addDay(){
	testTime.tm_mday++;
	mktime(&testTime);

}
void remDay(){
	testTime.tm_mday--;
	mktime(&testTime);

}
void switchLocalView(void){
	if(localModuleNum<=3){
		localModuleNum++;
	} else {
		localModuleNum = 0;
	}
}

static void setDefaultClbcks(void){
	// module callbacks
	btn_BA.onSinglePressHandler = &nextScreen;
	btn_BC.onSinglePressHandler = &prevScreen;
	btn_BB.onSinglePressHandler = &switchLocalView;
}
void localSetup(void){
	setDefaultClbcks();
}

enum SOLAR_EVENT{
	SOLAR_SUNRISE = 0,
	SOLAR_NOON,
	SOLAR_SUNSET
};

struct local_location{
	int8_t timezone;	// [h] east+ west-
	double longitude; 	// [deg]
	double latitude;	// [deg]
};
// fractional year = gamma [rad]
float fractionalYear(struct tm *timeStr, struct local_location *location){
	int dayOfTheYear = testTime.tm_yday+1;
	return (2*M_PI/365)*(dayOfTheYear-1+(timeStr->tm_hour-location->timezone-12)/24);
}
// equation of time [min]
float equationOfTime(float fyear){
	return 229.18*(0.000075+0.001868*cos(fyear)-0.032077*sin(fyear)-0.014615*cos(2*fyear)-0.040849*sin(2*fyear));
}
// solar declination angle [rad]
float solarDeclination(float fyear){
	return 0.006918-0.399912*cos(fyear)+0.070257*sin(fyear)-0.006758*cos(2*fyear)+0.000907*sin(2*fyear)-0.002697*cos(3*fyear)+0.00148*sin(3*fyear);
}
// time offset [min]
float timeOffset(struct local_location *location, float fyear){
	return equationOfTime(fyear)+4*location->longitude-60*location->timezone;
}
// true solar time [min]
float trueSolarTime(struct tm *timeStr, float timeOffset){
	return timeStr->tm_hour*60+timeStr->tm_min+(float)timeStr->tm_sec/60+timeOffset;
}
//sunrise/sunset/noon times [min]
int solarEventTime(enum SOLAR_EVENT event,struct tm *timeStr, struct local_location *location, float cha){
	float fyear = fractionalYear(timeStr, location);
	float eqTime = equationOfTime(fyear);
	// add atmospheric refraction
	// https://gml.noaa.gov/grad/solcalc/calcdetails.html
	switch(event){
		case SOLAR_SUNRISE:
			return 720-4*(location->longitude+cha*180/M_PI)-eqTime+60*location->timezone;
		case SOLAR_NOON:
			return 720-4*location->longitude-eqTime+60*location->timezone;
		case SOLAR_SUNSET:
			return 720-4*(location->longitude-cha*180/M_PI)-eqTime+60*location->timezone;
	}
}
//sunrise/sunset/noon times [min]
struct sunEventsTimes{
	int sunrise, noon, sunset; //[min]
};



void localMain(void){
	testTime.tm_hour = RtcTime.Hours;
	testTime.tm_min = RtcTime.Minutes;
	testTime.tm_sec = RtcTime.Seconds;
	testTime.tm_mday = RtcDate.Date ;
	testTime.tm_mon = RtcDate.Month-1;
	testTime.tm_year = RtcDate.Year+100;
	mktime(&testTime);

	double longitude; 	// [deg]
	double latitude;	// [deg]
	if(location.hasFix){
		longitude = (double)location.longitudeDeg+location.longitudeMin/60; 	// [deg]
		latitude = (double)location.latitudeDeg+location.latitudeMin/60;	// [deg]
		if(location.n_s == 'S') longitude = longitude*(-1);
		if(location.w_e == 'W') latitude = latitude*(-1);
	} else {
		longitude = 17; 	// [deg]
		latitude = 51;	// [deg]
		if(longitude>=0) location.n_s = 'N';
		if(latitude>=0) location.w_e = 'E';
	}
	struct local_location myLocation = {GLOBAL_timezone, longitude, latitude};

	// fractional year = gamma [rad]
	float fyear = fractionalYear(&testTime, &myLocation);
	// equation of time [min]
	float eqtime = equationOfTime(fyear);
	// solar declination angle [rad]
	float decl = solarDeclination(fyear);

	float time_off = timeOffset(&myLocation, fyear);
	float tst = trueSolarTime(&testTime, time_off);
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
	int sunrise = solarEventTime(SOLAR_SUNRISE, &testTime, &myLocation, cha);
	int sunset = solarEventTime(SOLAR_SUNSET, &testTime, &myLocation, cha);
	int noon = solarEventTime(SOLAR_NOON, &testTime, &myLocation, cha);
	struct sunEventsTimes suntimes = {sunrise, sunset, noon};


	double saDeg;
	if(cha<0) saDeg = -sa*180/M_PI;
	else saDeg = 360+sa*180/M_PI;

	char textBuffer[50] = {0};

	switch(localModuleNum){
	case 0:{
		uint8_t shiftedWeekDay = (testTime.tm_wday+7-1)%7+1;
		uint8_t weekOfTheYear = (testTime.tm_yday+1+7-shiftedWeekDay)/7;
		sprintf(&textBuffer, "%s week %d day %d", asctime(&testTime), weekOfTheYear, testTime.tm_yday+1);
		lcdPutStr(10, 10, textBuffer, font_12_zekton);
		sprintf(&textBuffer, "%02.3f`", 90-phi*180/M_PI);
		lcdPutStr(420-(*(zekton45font.font_Width)*(strlen(textBuffer)+1)), 66, textBuffer, zekton45font);
		sprintf(&textBuffer, "%02.3f`", saDeg);
		lcdPutStr(420-(*(zekton45font.font_Width)*(strlen(textBuffer)+1)), 115, textBuffer, zekton45font);

		sprintf(&textBuffer, "%c%.3f %c%.3f", location.n_s, latitude, location.w_e, longitude);
		lcdPutStr(10, 25, textBuffer, font_12_zekton);

		drawSunlightGraph(215, 10, 399-10, 50, &suntimes);
		break;
		}
	case 1:
		break;
	case 2:
		sprintf(&textBuffer, "Sunrise: %02d:%02d", sunrise/60, sunrise%60);
		lcdPutStr(10, 28, textBuffer, font_12_zekton_bold);
		sprintf(&textBuffer, "Noon: %02d:%02d", noon/60, noon%60);
		lcdPutStr(10, 44, textBuffer, font_12_zekton_bold);
		sprintf(&textBuffer, "Sunset: %02d:%02d", sunset/60, sunset%60);
		lcdPutStr(10, 60, textBuffer, font_12_zekton_bold);
		break;
	case 3:
		sprintf(&textBuffer, "solar elevation angle: %02.3f deg", 90-phi*180/M_PI);
		lcdPutStr(10, 80, textBuffer, font_12_zekton_bold);
		sprintf(&textBuffer, "solar azimuth angle: %02.3f deg", saDeg);
	//	sprintf(&textBuffer, "solar azimuth angle: %02.3f deg", fmod(360+sa*180/M_PI, 360));
		lcdPutStr(10, 96, textBuffer, font_12_zekton_bold);

		double perc = (testTime.tm_hour*60+testTime.tm_min+(double)testTime.tm_sec/60-sunrise)*100/(sunset-sunrise);
		sprintf(&textBuffer, "percentage daylight: %2.3f%%", perc);
		lcdPutStr(10, 116, textBuffer, font_12_zekton_bold);
		sprintf(&textBuffer, "day length: %02dh %02dmin", (sunset-sunrise)/60, (sunset-sunrise)%60);
		lcdPutStr(10, 132, textBuffer, font_12_zekton_bold);
		break;
	case 4:{
		break;
		}
	}
}

void drawSunlightGraph(uint8_t yPos, uint16_t x1, uint16_t x2, uint8_t height, struct sunEventsTimes *suntimes){
	lcdHLine(x1,x2,yPos,1);
	lcdVLine(x1, yPos-2, yPos+2, 1);
	lcdVLine(x2, yPos-2, yPos+2, 1);

	uint16_t scaleXrise = x1+(x2-x1+1)*suntimes->sunrise/(24*60-0);
	uint16_t scaleXset = x1+(x2-x1+1)*suntimes->sunset/(24*60-0);
	uint16_t scaleXnoon = x1+(x2-x1+1)*suntimes->noon/(24*60-0);
	uint16_t scaleXnow = x1+(x2-x1+1)*(testTime.tm_hour*60+testTime.tm_min)/(24*60-0);
	lcdVLine(scaleXrise, yPos-5, yPos+5, 2);
	lcdVLine(scaleXset, yPos-5, yPos+5, 2);
	lcdVLine(scaleXnoon, yPos-5, yPos+5, 2);
	lcdVLine(scaleXnow, yPos-10, yPos+10, 2);

	char textBuffer[50] = {0};
	sprintf(&textBuffer, "%02d:%02d", suntimes->sunrise/60, suntimes->sunrise%60);
	lcdPutStr(scaleXrise-19, yPos+5, textBuffer, smallestFont);
	sprintf(&textBuffer, "%02d:%02d", suntimes->sunset/60, suntimes->sunset%60);
	lcdPutStr(scaleXset-19, yPos+5, textBuffer, smallestFont);
	sprintf(&textBuffer, "%02d:%02d", suntimes->noon/60, suntimes->noon%60);
	lcdPutStr(scaleXnoon-19, yPos+5, textBuffer, smallestFont);
//	int sunElev = (90-phi(testTime)*180/M_PI)*height/90;
//	for(uint16_t pix = x1; pix <= x2; pix++){
//		lcdPutPix(pix, sunElev, 1);
//	}
}

void localScreen1(void){

}

void localScreen2(void){

}

void localScreen3(void){

}
