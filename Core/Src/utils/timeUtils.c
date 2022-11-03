/*
 * timeUtils.c
 *
 *  Created on: Jul 21, 2022
 *      Author: wojch
 */

#include "timeUtils.h"


uint8_t zellerCongruence(uint8_t day, uint8_t month, uint16_t year){
	if (month == 1) {
	        month = 13;
	        year--;
	    }
	    if (month == 2) {
	        month = 14;
	        year--;
	    }
	    uint8_t q = day;
	    uint8_t m = month;
	    uint8_t k = year % 100;
	    uint8_t j = year / 100;
	    int h = q + 13 * (m + 1) / 5 + k + k / 4 +
	                              j / 4 + 5 * j;
	    h = h % 7;
	    return (h+5)%7 + 1;
}
