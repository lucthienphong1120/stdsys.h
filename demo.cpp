#include <stdsys.h>

int main(){
	gotoxy(5,10);
	bgcolor(White, Blue);
	delay(3);
	bgcolor();
	cursor(false);
	clear;
	while(1){
		flashing("You are using stdsys.h library!", 100, 10000);
	}
    return 0;
}
