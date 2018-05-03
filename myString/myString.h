/*
myString <header>
author: rsh5
year: 2018
version: 0.1
*/
#pragma once
#include <iostream>
using namespace std;

class myString{
	//private section
	char *string;
	int size;
	//don't have blank initialization
	myString() {}; 
	
	//public section
	public: 
		//constructors & destructors
		myString(char str[]);
		myString(myString &str);
		~myString();

		//methods
		int getsize();
		void print();
		myString concatenate(myString str);
		myString subString(int start, int end);

		//operator overloads
};