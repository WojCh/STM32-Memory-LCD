#include "lcd.h"
#include "gps.h"
#include "font13.h"

#define LCD_ROWS 10

void gpsTestSentence(gpsDevice* gpsModule, char cmd[6]){
	char text[50] = { 0 };

	gpsSentence testSentence;
	readSentence(&gpsModule->buffer, &testSentence, cmd);
	if(testSentence.valid == 1){
		  for(uint8_t i = 0; i <= testSentence.wordNum; i++){
			  sprintf(text, "W#%d %s", i, testSentence.words[i]);
//			  printf("W#%d: %s\n", i, testSentence.words[i]);
			  if(i < LCD_ROWS) lcdPutStr(0,i+1, text ,font13);
			  // only 11 lines can be displayed with this font
			  if(i >= LCD_ROWS) lcdPutStr(200,i+1-LCD_ROWS, text ,font13);
//			  if(i >= LCD_ROWS) break;
		  }
		  } else {
			  lcdPutStr(0,1, "Checksum invalid!!!" ,font13);
		  }
}
