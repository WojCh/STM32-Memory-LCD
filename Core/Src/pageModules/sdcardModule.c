/*
 * sdcardModule.c
 *
 *  Created on: 25 kwi 2022
 *      Author: wojch
 *
 *      module displaying watchfaces
 */
#include "sdcardModule.h"
#include "fonts/fonts.h"
#include "File_Handling.h"

static void setDefaultClbcks(void){
	// module callbacks
//	btn_B2.onSinglePressHandler = &showCntxMenu;
	btn_BA.onSinglePressHandler = &nextScreen;
	btn_BC.onSinglePressHandler = &prevScreen;
}

//static void setTimeAction(void){
//	guiApplyView(&timeInputModule);
//}
//static void setDateAction(void){
//	guiApplyView(&dateInputModule);
//}

//static const struct ContextAction action1 = {"Mount SD card", &setTimeAction};
//static const struct ContextAction action2 = {"Unmount SD card", &setDateAction};
//static const struct ContextAction action3 = {"Customize", &setTimeAction};
//static const struct ContextAction action4 = {"Lock", &setTimeAction};
//static const struct ContextAction* ContextActions[] = {&action1, &action2, &action3, &action4};

void sdcardSetup(void){
	setDefaultClbcks();
//	setupCntxMenu(&setDefaultClbcks);
//	setupCntxMenu(&setDefaultClbcks, cntxActions, 3);
}
void sdcardMain(void){
	char title[50] = {0};
	sprintf(&title, "SD card explorer");
	lcdPutStr(0, 0, title, smallestFont);
	char freeTotal[50];
	Check_SD_Space(&freeTotal);
	sprintf(&title, "Free/total space: %s [kB]", freeTotal);
	lcdPutStr(0, 12, title, smallestFont);

    DIR dir;
	UINT i;
	char *path = malloc(20*sizeof (char));
	sprintf (path, "%s","/");
    f_opendir(&dir, path);                       /* Open the directory */
	for(uint8_t i = 1; i<10; i++){
		Scan_SD_my(&dir, &title);
		lcdPutStr(0, 12+i*12, title, smallestFont);
	}
	f_closedir(&dir);
    free(path);

//	lcdPutStr(0,60, fileText, smallestFont);
//	lcdRefresh();
//	enableCntxMenu();
}


