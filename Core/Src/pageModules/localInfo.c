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

#define SOLAR_DISC_ANGLE 			0.833
#define GEOMETRICAL_TWILIGHT_DEG	0.833
#define CIVIL_TWILIGHT_DEG 			6
#define NAUTICAL_TWILIGHT_DEG 		12
#define ASTRONOMICAL_TWILIGHT_DEG 	18

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

struct solarAngles{
	float za, sa;
};

void calcSolarAngles(struct solarAngles *output, struct tm *timeStr, struct local_location *location){
	// fractional year = gamma [rad]
	float fyear = fractionalYear(timeStr, location);
	// equation of time [min]
	float eqtime = equationOfTime(fyear);
	// solar declination angle [rad]
	float decl = solarDeclination(fyear);

	float time_off = timeOffset(location, fyear);
	float tst = trueSolarTime(timeStr, time_off);
	// solar hour angle [deg]
	float sha = (tst/4)-180;
	// solar zenith angle = phi [rad]
	float cosphi = sin(location->latitude*M_PI/180)*sin(decl)+cos(location->latitude*M_PI/180)*cos(decl)*cos(sha*M_PI/180);
	output->za = acos(cosphi);
	float sinphi = sqrt(1-cosphi*cosphi);
	// solar azimuth = theta [rad]
	output->sa = -acos(-(sin(location->latitude*M_PI/180)*cosphi-sin(decl))/(cos(location->latitude*M_PI/180)*sinphi));
}



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

//	struct solarAngles angles = {0,0};
//	calcSolarAngles(&angles, &testTime, &location);
//	float phi = angles.za;
//	float sa = angles.sa;

	// setting for sunrise/sunset zenith angle [rad]
	double zenith = (90+GEOMETRICAL_TWILIGHT_DEG)*M_PI/180;
	// calculated hour angle [rad]
	float cha = acos(cos(zenith)/(cos(latitude*M_PI/180)*cos(decl))-tan(latitude*M_PI/180)*tan(decl));

	//sunrise/sunset/noon times [min]
	int sunrise = solarEventTime(SOLAR_SUNRISE, &testTime, &myLocation, cha);
	int sunset = solarEventTime(SOLAR_SUNSET, &testTime, &myLocation, cha);
	int noon = solarEventTime(SOLAR_NOON, &testTime, &myLocation, cha);
	struct sunEventsTimes suntimes = {sunrise, sunset, noon};


	double saDeg;
	if(sha>180) saDeg = -sa*180/M_PI;
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

		sprintf(&textBuffer, "%c%.3f %c%.3f, day length:%02dh %02dmin", location.n_s, latitude, location.w_e, longitude, (sunset-sunrise)/60, (sunset-sunrise)%60);
		lcdPutStr(10, 25, textBuffer, font_12_zekton);

		drawSunlightGraph(200, 10, 399-10, 50, &suntimes, &myLocation);
		break;
		}
	case 1:
		sprintf(&textBuffer, "%02d:%02d", sunrise/60, sunrise%60);
		lcdPutStr(10, 10, textBuffer, zekton24font);
		sprintf(&textBuffer, "SUNRISE");
		lcdPutStr(10, 35, textBuffer, font_12_zekton);
		sprintf(&textBuffer, "%02d:%02d", noon/60, noon%60);
		lcdPutStr(200-(*(zekton24font.font_Width)*(strlen(textBuffer)))/2, 10, textBuffer, zekton24font);
		sprintf(&textBuffer, "NOON");
		lcdPutStr(200-(*(font_12_zekton.font_Width)*(strlen(textBuffer)))/2, 35, textBuffer, font_12_zekton);
		sprintf(&textBuffer, "%02d:%02d", sunset/60, sunset%60);
		lcdPutStr(390-(*(zekton24font.font_Width)*(strlen(textBuffer))), 10, textBuffer, zekton24font);
		sprintf(&textBuffer, "SUNSET");
		lcdPutStr(390-(*(font_12_zekton.font_Width)*(strlen(textBuffer))), 35, textBuffer, font_12_zekton);

		// setting for sunrise/sunset zenith angle [rad]
		double zenith = (90+CIVIL_TWILIGHT_DEG)*M_PI/180;
		// calculated hour angle [rad]
		float cha = acos(cos(zenith)/(cos(latitude*M_PI/180)*cos(decl))-tan(latitude*M_PI/180)*tan(decl));
		//sunrise/sunset/noon times [min]
		int civil_sunrise = solarEventTime(SOLAR_SUNRISE, &testTime, &myLocation, cha);
		int civil_sunset = solarEventTime(SOLAR_SUNSET, &testTime, &myLocation, cha);
		sprintf(&textBuffer, "CIVIL");
		lcdPutStr(200-(*(font_12_zekton.font_Width)*(strlen(textBuffer)))/2, 80, textBuffer, font_12_zekton);
		sprintf(&textBuffer, "%02d:%02d", civil_sunrise/60, civil_sunrise%60);
		lcdPutStr(10, 80, textBuffer, zekton24font);
		sprintf(&textBuffer, "%02d:%02d", civil_sunset/60, civil_sunset%60);
		lcdPutStr(390-(*(zekton24font.font_Width)*(strlen(textBuffer))), 80, textBuffer, zekton24font);

		// setting for sunrise/sunset zenith angle [rad]
		zenith = (90+NAUTICAL_TWILIGHT_DEG)*M_PI/180;
		// calculated hour angle [rad]
		cha = acos(cos(zenith)/(cos(latitude*M_PI/180)*cos(decl))-tan(latitude*M_PI/180)*tan(decl));
		//sunrise/sunset/noon times [min]
		int naut_sunrise = solarEventTime(SOLAR_SUNRISE, &testTime, &myLocation, cha);
		int naut_sunset = solarEventTime(SOLAR_SUNSET, &testTime, &myLocation, cha);
		sprintf(&textBuffer, "NAUTICAL");
		lcdPutStr(200-(*(font_12_zekton.font_Width)*(strlen(textBuffer)))/2, 120, textBuffer, font_12_zekton);
		sprintf(&textBuffer, "%02d:%02d", naut_sunrise/60, naut_sunrise%60);
		lcdPutStr(10, 120, textBuffer, zekton24font);
		sprintf(&textBuffer, "%02d:%02d", naut_sunset/60, naut_sunset%60);
		lcdPutStr(390-(*(zekton24font.font_Width)*(strlen(textBuffer))), 120, textBuffer, zekton24font);

		// setting for sunrise/sunset zenith angle [rad]
		zenith = (90+ASTRONOMICAL_TWILIGHT_DEG)*M_PI/180;
		// calculated hour angle [rad]
		cha = acos(cos(zenith)/(cos(latitude*M_PI/180)*cos(decl))-tan(latitude*M_PI/180)*tan(decl));
		//sunrise/sunset/noon times [min]
		int astro_sunrise = solarEventTime(SOLAR_SUNRISE, &testTime, &myLocation, cha);
		int astro_sunset = solarEventTime(SOLAR_SUNSET, &testTime, &myLocation, cha);
		sprintf(&textBuffer, "ASTRONOMICAL");
		lcdPutStr(200-(*(font_12_zekton.font_Width)*(strlen(textBuffer)))/2, 160, textBuffer, font_12_zekton);
		sprintf(&textBuffer, "%02d:%02d", astro_sunrise/60, astro_sunrise%60);
		lcdPutStr(10, 160, textBuffer, zekton24font);
		sprintf(&textBuffer, "%02d:%02d", astro_sunset/60, astro_sunset%60);
		lcdPutStr(390-(*(zekton24font.font_Width)*(strlen(textBuffer))), 160, textBuffer, zekton24font);


		sprintf(&textBuffer, "SUNSET");
		lcdPutStr(390-(*(font_12_zekton.font_Width)*(strlen(textBuffer))), 35, textBuffer, font_12_zekton);
		break;
	case 2:
	{
		double perc = (testTime.tm_hour*60+testTime.tm_min+(double)testTime.tm_sec/60-sunrise)*100/(sunset-sunrise);
		sprintf(&textBuffer, "percentage daylight:");
		lcdPutStr(10, 116, textBuffer, font_12_zekton_bold);
		sprintf(&textBuffer, "%2.3f%%", perc);
		lcdPutStr(390-(*(zekton24font.font_Width)*(strlen(textBuffer))), 116, textBuffer, zekton24font);
		sprintf(&textBuffer, "day length:");
		lcdPutStr(10, 160, textBuffer, font_12_zekton_bold);
		sprintf(&textBuffer, "%02dh %02dmin", (sunset-sunrise)/60, (sunset-sunrise)%60);
		lcdPutStr(390-(*(zekton24font.font_Width)*(strlen(textBuffer))), 160, textBuffer, zekton24font);
		break;
	}
	case 3:

		drawSunlightGraph(120, 5, 395, 160, &suntimes, &myLocation);
		break;
	case 4:{
		sprintf(&textBuffer, "18250d");
		lcdPutStr(420-(*(zekton45font.font_Width)*(strlen(textBuffer)+1)), 30, textBuffer, zekton45font);
		sprintf(&textBuffer, "20h");
		lcdPutStr(420-(*(zekton45font.font_Width)*(strlen(textBuffer)+1)), 80, textBuffer, zekton45font);
		sprintf(&textBuffer, "54min");
		lcdPutStr(420-(*(zekton45font.font_Width)*(strlen(textBuffer)+1)), 130, textBuffer, zekton45font);
		sprintf(&textBuffer, "12s");
		lcdPutStr(420-(*(zekton45font.font_Width)*(strlen(textBuffer)+1)), 180, textBuffer, zekton45font);

		break;
		}
	}
}

void drawSunlightGraph(uint8_t yPos, uint16_t x1, uint16_t x2, uint8_t height, struct sunEventsTimes *suntimes, struct local_location *location){
	lcdHLine(x1,x2,yPos,1);
	lcdVLine(x1, yPos-2, yPos+2, 1);
	lcdVLine(x2, yPos-2, yPos+2, 1);

	uint16_t scaleXrise = x1+(x2-x1+1)*suntimes->sunrise/(24*60-0);
	uint16_t scaleXset = x1+(x2-x1+1)*suntimes->sunset/(24*60-0);
	uint16_t scaleXnoon = x1+(x2-x1+1)*suntimes->noon/(24*60-0);
	uint16_t scaleXnow = x1+(x2-x1+1)*(testTime.tm_hour*60+testTime.tm_min)/(24*60-0);
	lcdVLine(scaleXrise, yPos-5, yPos+5, 2);
	lcdVLine(scaleXset, yPos, yPos+5, 2);
	lcdVLine(scaleXnoon, yPos-5, yPos+5, 2);
//	lcdVLine(scaleXnow, yPos-10, yPos+10, 2);

	char textBuffer[50] = {0};
	sprintf(&textBuffer, "%02d:%02d", suntimes->sunrise/60, suntimes->sunrise%60);
	lcdPutStr(scaleXrise-42, yPos-15, textBuffer, smallestFont);
	sprintf(&textBuffer, "%02d:%02d", suntimes->sunset/60, suntimes->sunset%60);
	lcdPutStr(scaleXset-19, yPos+5, textBuffer, smallestFont);
	sprintf(&textBuffer, "%02d:%02d", suntimes->noon/60, suntimes->noon%60);
	lcdPutStr(scaleXnoon+4, yPos-15, textBuffer, smallestFont);
	struct solarAngles angles = {0,0};
	struct tm myTime;
	myTime = testTime;
	int sunElev;

	calcSolarAngles(&angles, &testTime, location);
	sunElev = (90-angles.za*180/M_PI)*height/90;
	lcdRect(scaleXnow-1, scaleXnow+1, yPos-sunElev-1, yPos-sunElev+1, 1);

	for(uint16_t pix = x1; pix <= x2; pix+=3){
		uint16_t min_sum = (pix-x1)*24*60/(x2-x1);
		uint8_t hrs = min_sum/60;
		uint8_t min = min_sum%60;
		myTime.tm_hour = hrs;
		myTime.tm_min = min;
		calcSolarAngles(&angles, &myTime, location);
		sunElev = (90-angles.za*180/M_PI)*height/90;
		lcdPutPix(pix, yPos-sunElev, 1);
		if(pix < scaleXnow) lcdVLine(pix, yPos-sunElev, yPos, 1);
	}
}

void localScreen1(void){

}

void localScreen2(void){

}

void localScreen3(void){

}
