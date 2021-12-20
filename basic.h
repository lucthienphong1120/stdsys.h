// library includes used for precompiling C/C++
//
// Copyright (C) 2021 Coding Reshape Future Inc.
//
// This library is free and is an open source library
// you can redistribute it and/or modify it under the
// It is imperative to keep the original content and author's name
//
// This library is distributed in the hope that it will be useful
// and bring convenience for everyone, but WITHOUT ANY WARRANTY.
//
//
// the main features are about effects, system, computer and basic useful functions
//
// 
// Author: LTP - copyright 2021
//
// to use this library, please copy this file to the following path
// C:\Program Files (x86)\Dev-Cpp\MinGW64\include
// this library must be called after other library when #include
// to avoid library conflicts and unexpected bugs occurred
//
// this is a sub library of <stdsys.h>


#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

#ifndef _BASIC_H_
#define _BASIC_H_

/* -----------------------include librarys-------------------------------------- */
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
using namespace std;
/* -------------------basic functions------------------------------------------ */
// greatest common divisor of a and b
int gcd(int a,int b){
	return __gcd(a,b);
}
// least common multiple of a and b
int lcm(int a,int b){
	return a*b/__gcd(a,b);
}
// swap two elements
void swap(int &a, int &b){
	int temp = a;
	a = b; b = temp;
}
// random a number in range [min, max)
int random(int min, int max){
    return min + rand() % (max - min + 1);
}
// factorial of n
long long fact(int n){
    long long s = 1;
    int temp;
    if (n < 0) temp = -n;
    else temp = n;
    for (int i = 1; i <= temp; i++){
    	s *= i;
	}
	if (n < 0) return -s;
    return s;
}
// input Array
void inArr(int a[],int n){
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
}
// output Array
void outArr(int a[],int n){
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
	}	
}
// merge sort array (stable sort)
void sort(int a[],int n,bool reverse=false){
	if(reverse){
		stable_sort(a,a+n,greater<int>());
	} else {
		stable_sort(a,a+n);
	}
}
// find position of the first index of element
int sfind(char *s, int value, int start = 0){
	int n = strlen(s);
	for(int i = start; i < n; i++){
		if(s[i] == value) return i;
	}
	return -1;
}
// find position of the first index of element
int afind(int a[], int n, int value, int start = 0){
	for(int i = start; i < n; i++){
		if(a[i] == value) return i;
	}
	return -1;
}
// delete a character in string
void sdel(char s[],int index){
	int n = strlen(s);
	for(int i=index;i<n;i++){
		s[i]=s[i+1];
	}	
	s[n-1]='\0';
}
// delete a element in array
void adel(int a[],int &n,int index){
	for(int i=index;i<n;i++){
		a[i]=a[i+1];
	}
	n--;
}
// insert a character in string
void sinsert(char s[], int index, char value){
	int n = strlen(s); n++;
	s = (char *)malloc(sizeof(char));
	for(int i=n-1;i>index;i--)
		s[i]=s[i-1];
	s[index]=value;
	s[n]='\0';
}
// insert an element in array
void aadd(int a[],int &n,int index,int value){
	n++;
	for(int i=n-1;i>index;i--)
		a[i]=a[i-1];
	a[index]=value;
}
// absolute value of a
int abs(int &n){
	if (n < 0) n = -n;
	return n;
}
// max of 2 number
int max(int a,int b){
	return a>=b?a:b;
}
// max of 3 number
int max(int a,int b,int c){
	return (a>=b&&a>=c)?a:b>=c?b:c;
}
// min of 2 number
int min(int a,int b){
	return a<=b?a:b;
}
// min of 3 number
int min(int a,int b,int c){
	return (a<=b&&a<=c)?a:b<=c?b:c;
}
// max of array
int max(int a[], int n){
	int max = a[0];
	for(int i = 1; i < n; i++){
		if(a[i] > max) max = a[i];
	}
	return max;
}
// min of array
int min(int a[], int n){
	int min = a[0];
	for(int i = 1; i < n; i++){
		if(a[i] < min) min = a[i];
	}
	return min;
}
int sum(int a[], int n){
	int sum = 0;
	for(int i = 0; i < n; i++){
		sum += a[i];
	}
	return sum;
}
// combination k of n elements
int combination(int k, int n){
	if(k == 0 || k == n) return 1;
	if(k == 1 || k == n-1) return n;
	return combination(k-1,n-1) + combination(k,n-1);
}
// permutation k of n elements
int permutation(int k, int n){
	return fact(n)/fact(n-k);
}
// count the number of words in a sentence
int wc(char *s){
	int n = strlen(s), count = 0;
	if(s[0] != ' ') count = 1;
	for(int i = 0; i < n; i++){
		if(s[i] == ' ' && ((s[i+1] >= 'a' && s[i+1] <= 'z') || (s[i+1] >= 'A' && s[i+1] <= 'Z'))){
			count++;
		}
	}
	return count;
}
// format a string
void format(char s[], bool upper_each_first_letter = true){
	while(s[0]==' ')
		sdel(s,0);
	while(s[strlen(s)-1]==' ')
		sdel(s,strlen(s)-1);
	strupr(s);
	for(int i=1;i<strlen(s);i++){
		while(s[i]==' '&&s[i+1]==' '){
			sdel(s,i);
			i--;
		}
		if(upper_each_first_letter){
			if(s[i-1]==' ' && s[i]>='A'&&s[i]<='Z'){
				continue;
			}
		}
		if(s[i]>='A'&&s[i]<='Z'){
			s[i]+=32;
		}
	}
}
// reverse words in string
string reverseWord(string &s){
	int n = s.size(), j = n-1;
	string ans = "";
	for(int i = n-1; i >= 0; i--) {
		if(s[i] == ' ') { 
			for(int k = i+1; k <= j; k++) ans += s[k];
			j = i-1;
			ans += " ";
		}
		if(i == 0) {
			for(int k = i; k <= j; k++) ans += s[k];
		}
	}
	ans += '\0';
	return ans;
}
// reverse string
char* reverse(char *s){
	return strrev(s);
}
// reverse string
string reverse(string s){
	reverse(s.begin(), s.end());
	return s;
}








#endif