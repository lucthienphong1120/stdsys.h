#include <stdio.h>
#include <unistd.h>
#include <windows.h>
#include <conio.h>

void gotoxy(short x, short y) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };
    SetConsoleCursorPosition(h,c);
}

void textcolor(int color) {
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, color);
}

void print(const char *s, int time_total, int color){
	int n = strlen(s);
	int time_each = time_total/n;
	textcolor(color);
	for(int i = 0; i < n; i++){
		printf("%c", s[i]);
		Sleep(time_each);
	}
}

void SetConsoleSize(short width, short height){
	HANDLE Stdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SMALL_RECT Size;
	Size.Top = 0; Size.Left = 0;
	Size.Right = width; Size.Bottom = height;
	SetConsoleWindowInfo(Stdout, 1, &Size);
}

void check(char* path, char* name){
	if(access( path, F_OK) != -1 ) {
		gotoxy(20, 5);
	    printf("Copy %s successful", name);
		gotoxy(18, 6);
		printf("Press any key to continue ...");
	} else {
		gotoxy(22, 5);
	    printf("Copy %s failed!", name);
	    gotoxy(12, 6);
		printf("Please right click and run this file");
		gotoxy(15, 7);
		printf("with administrator permission");
	}
}

int main(){
	SetConsoleSize(80,25);
	gotoxy(22, 5);
	print("copying . . .", 5000, 9);
	ShellExecute(NULL , "open", "loading.exe", NULL, NULL, SW_NORMAL);
	system("timeout 5 /nobreak");
	system("copy basic.h \"C:\\Program Files (x86)\\Dev-Cpp\\MinGW64\\include\" /Y");
	system("copy stdsys.h \"C:\\Program Files (x86)\\Dev-Cpp\\MinGW64\\include\" /Y");
	system("cls");
	system("timeout 5 /nobreak");
	system("cls");
	textcolor(9);
	check("C:\\Program Files (x86)\\Dev-Cpp\\MinGW64\\include\\basic.h", "basic.h");
	getch();
	check("C:\\Program Files (x86)\\Dev-Cpp\\MinGW64\\include\\stdsys.h", "stdsys.h");
	getch();
}
