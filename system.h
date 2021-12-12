// library includes used for precompiling C/C++
//
// Copyright (C) 2021 Coding Reshape Future Inc.
//
// This library is free and is an open source library
// you can redistribute it and/or modify it.
// but it is imperative that you keep the original content and the author's name
//
// This library is distributed in the hope that it will be useful
// and bring convenience for everyone, but WITHOUT ANY WARRANTY, 
// without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// 
// the main features are functions for handling console, 
// system, animation and basic useful functions for programmers.
// 
// Author: LTP 
//
// to use this library, please copy this file to the following link
// C:\Program Files (x86)\Dev-Cpp\MinGW64\include
// this library must be called after other library when #include
// to avoid library conflicts and unexpected bugs occurred
//
// this library include system library and basic library

#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

#ifndef _SYSTEM_H_
#define _SYSTEM_H_

/* -----------------------include librarys-------------------------------------- */
#include <stdio.h>
#include <iostream>
#include <string>
#include <windows.h>
#include <basic.h>
using namespace std;
/* -----------------------define colors-------------------------------------- */
#define Black			0
#define DarkBlue		1
#define DarkGreen		2
#define Cyan			3
#define Red				4
#define Purple			5
#define DarkYellow		6
#define Sliver			7
#define Grey			8
#define Blue			9
#define Green			10
#define LightCyan		11
#define RedPink			12
#define Magenta			13
#define LightYellow		14
#define White			15

#define DeTextColor		7
#define DeBgColor		0
/* ----------------------system functions--------------------------------------- */
// maximize the console
#define MaxConsole ShowWindow(GetConsoleWindow(),SW_MAXIMIZE);
// minimize the console
#define MinConsole ShowWindow(GetConsoleWindow(),SW_MINIMIZE);
// enable vietnamese mode
#define UTF_8 SetConsoleOutputCP(65001);
// fast Input/Output
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"
// clear the console
#define clear system("cls");
// press any key to continue . . .
#define pause system("pause");
// exit the program
#define exit system("exit");
// exit current process
#define exitprocess ExitProcess(0);
// move the cursor to coordinates
void gotoxy(short x, short y) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };
    SetConsoleCursorPosition(h,c);
}
// change text color
void textcolor(int color) {
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, color);
}
// change text and background color
void bgcolor(int text_color = DeTextColor, int bg_color = DeBgColor){
	char color[2];
    sprintf(color, "%X%X", bg_color, text_color);
	string command = "color " + string(color);
	system(command.c_str());
}
// change text and line color
void linecolor(int text_color, int line_color){
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    int color = line_color * 16 + text_color;
    SetConsoleTextAttribute(hStdout, color);
}
// get current cursor position in x axis
int whereX() {
	CONSOLE_SCREEN_BUFFER_INFO x;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &x);
    return x.dwCursorPosition.X;
}
// get current cursor position in y axis
int whereY() {
	CONSOLE_SCREEN_BUFFER_INFO y;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &y);
	return y.dwCursorPosition.Y;
}
//set cursor visible or not
void cursor(bool show = true) {
	//true is show (default), false is hide
	// must be call after other function of console and before code start
	HANDLE x = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO y;
    y.dwSize = 10;
    y.bVisible = show;
    SetConsoleCursorInfo(x, &y);
}
// hide scroll bar
void Scrollbar(bool show = true){
	// true is show (default)
	// false is hide
    HWND hWnd = GetConsoleWindow();
    ShowScrollBar(hWnd, SB_BOTH, show);
}
// set the console size
void SetConsoleSize(short width, short height){
	HANDLE Stdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SMALL_RECT Size;
	Size.Top = 0; Size.Left = 0;
	Size.Right = width; Size.Bottom = height;
	SetConsoleWindowInfo(Stdout, 1, &Size);
}
// change console buffer size
void SetConsoleBufferSize(short width, short height){
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Size;
    Size.X = width;
    Size.Y = height;
    SetConsoleScreenBufferSize(hStdout, Size);
}
// disable the console resize
void DisableResize(){
    HWND hWnd = GetConsoleWindow();
    SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_SIZEBOX);
}
// disable minimize, maximize, close console
void DisableMenu(bool Minimize = true, bool Maximize = true, bool Close = true){
	// true is turn on (default)
	// false is turn off
    HWND hWnd = GetConsoleWindow();
    HMENU hMenu = GetSystemMenu(hWnd, false);
    if (Minimize == false){
        DeleteMenu(hMenu, SC_MINIMIZE, MF_BYCOMMAND);
    }
    if (Maximize == false){
        DeleteMenu(hMenu, SC_MAXIMIZE, MF_BYCOMMAND);
    }
    if (Close == false){
        DeleteMenu(hMenu, SC_CLOSE, MF_BYCOMMAND);
    }
}
// disable selection text
void DisableSelect(){
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    SetConsoleMode(hStdin, ~ENABLE_QUICK_EDIT_MODE);
}
// print string with slow motion and color
void print(const char *s, int time_total = 0, int color = DeTextColor){
	int n = strlen(s);
	int time_each = time_total/n;
	textcolor(color);
	for(int i = 0; i < n; i++){
		printf("%c", s[i]);
		Sleep(time_each);
	}
}
// print string with flashing and color
void flashing(const char *s, int time_delay, int time_total){
	int time = 0, flag = 0;
	short x = whereX(), y = whereY();
	while(time < time_total){
		textcolor(flag % 16);
		gotoxy(x,y); puts(s);
		Sleep(time_delay);
		time += time_delay; flag++;
	}
}
// change title of console
void SetConsoleTitle(char* title){
	SetConsoleTitle(TEXT(title));
}
// change title of console using cmd
void title(char title[]){
	string command = "title " + string(title);
	system(command.c_str());
}
//this function is in the process of development
void ShowMousePosition(int placeX, int placeY){
	int x = 0, y = 0;
	DWORD cNumRead, fdwMode, i; 
    INPUT_RECORD inrecord[128];
    
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE); 
    if (hStdin == INVALID_HANDLE_VALUE){
    	printf("ErrorGetStdHandle"); ExitProcess(0);
	}
    fdwMode = ENABLE_EXTENDED_FLAGS; 
    if (! SetConsoleMode(hStdin, fdwMode)){
        printf("ErrorSetConsoleMode"); ExitProcess(0);
    }
	//open "open mode"
    fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
    if (!SetConsoleMode(hStdin, fdwMode)){
        printf("ErrorSetConsoleMode"); ExitProcess(0);
    }
    while (1){
        if (!ReadConsoleInput(hStdin,inrecord,128,&cNumRead)){
            printf("ErrorReadConsoleInput"); ExitProcess(0);
        }
        for (i = 0; i < cNumRead; i++){
            switch(inrecord[i].EventType){
	            case MOUSE_EVENT:
	            	{
	            		MOUSE_EVENT_RECORD get = inrecord[i].Event.MouseEvent;
					    INPUT_RECORD Inrec;
					    DWORD eventRead;
					    bool Captured = false;
					
					    if( SetConsoleMode(hStdin, fdwMode | ENABLE_MOUSE_INPUT) == true)
							GetConsoleMode(hStdin, &fdwMode);
					        SetConsoleMode(hStdin, (fdwMode & (ENABLE_MOUSE_INPUT)));
					
					        do{
					            PeekConsoleInput(hStdin, &Inrec, 1, &eventRead);
					            if( eventRead ) {
					                ReadConsoleInput(hStdin, &Inrec, 1, &eventRead);
					                x = Inrec.Event.MouseEvent.dwMousePosition.X ;
					                y = Inrec.Event.MouseEvent.dwMousePosition.Y ;
					                switch (Inrec.EventType ){
					                	case MOUSE_EVENT:
					                    {
					                        Captured = true;
					                        gotoxy(placeX,placeY);
					                        printf("%3d",x);
					                        gotoxy(placeX,placeY+1);
					                        printf("%3d",y);
					                        break;  
					                    }
									}
					            }
					
					        }while(!Captured);
					}
	                break;
	            default:
	                break;
            }
        }
    }
}












#endif
