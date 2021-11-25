#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;

float sinx(float x){
	return 100 * sin(x * M_PI / 180);
}
float cosx(float x){
	return 100 * cos(x * M_PI / 180);
}
float tanx(float x){
	return 100 * tan(x * M_PI / 180);
}
float cotx(float x){
	return 100 * 1/tan(x * M_PI / 180);
}
void init(char key){
	switch(key){
		case 'a': case 'A': 
			for(float x = 0; x <= 360; x += 0.5){
		    	float y = sinx(x);
	    		putpixel(x,y+300,2);
	    		delay(10);
			}
			break;
		case 'b': case 'B':
			for(float x = 0; x <= 360; x += 0.5){
		    	float y = cosx(x);
	    		putpixel(x,y+300,3);
	    		delay(10);
			}
			break;
		case 'c': case 'C':
			for(float x = 0; x <= 360; x += 0.5){
		    	float y = tanx(x);
	    		putpixel(x,y+300,4);
	    		delay(10);
			}
			break;
		case 'd': case 'D':
			for(float x = 0; x <= 360; x += 0.5){
		    	float y = cotx(x);
	    		putpixel(x,y+300,5);
	    		delay(10);
			}
			break;
	}
}
void draw(char key){
	initwindow(800,600);
	switch(key){
		case 'a': case 'A': setcolor(3); settextstyle(3,0,3); outtextxy(150,460,"y = sin(x) by CRF"); break;
		case 'b': case 'B': setcolor(3); settextstyle(3,0,3); outtextxy(150,460,"y = cos(x) by CRF"); break;
		case 'c': case 'C': setcolor(3); settextstyle(3,0,3); outtextxy(150,460,"y = tan(x) by CRF"); break;
		case 'd': case 'D': setcolor(3); settextstyle(3,0,3); outtextxy(150,460,"y = cot(x) by CRF"); break;
		default: cout << "khong co lua chon\n"; closegraph(); exit(0);
	}
    init(key);
	closegraph(0);
}
int main(){
	char key;
	cout << "chon do thi:" << endl << "A. y = sin(x)" << endl << "B. y = cos(x)" << endl << "C. y = tan(x)" << endl << "D. y = cot(x)" << endl;
	cin >> key;
	draw(key);
    return 0;
}
