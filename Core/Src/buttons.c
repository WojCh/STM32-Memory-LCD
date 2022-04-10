#include "buttons.h"

buttons btns;


void pressedA_one(void){
	printf("fOne\n");
}
void pressedA_two(void){
	printf("fTwo\n");

}


void changeMode(void){
//	if(mode == 0){
		btns.BA_handler = &pressedA_two;
//	} else {
//		btns.BA_handler = pressedA_one;

//	}
}
