#include "myString.h"
#include <cstdio>

myString::myString(char str[]) {
	string = str;
	size = getsize();
}

myString::myString(myString &str) {
	cout << "Copy constructor" << endl;
	string = str.string;
	size = str.size;
}

int myString::getsize() {
	char *ptr = string;
	int count = 0;
	while (*ptr) {
		count++;
		ptr++;
	}
	return count;
}
void myString::print() {
	char *ptr = string;
	while (*ptr) {
		printf("%c", *ptr);
		ptr++;
	}
	printf("\n");
}

myString myString::concatenate(myString str) {
	//dynamic memory allocation
	char *newString = new char[size + str.size + 1];
	int count = 0;
	while (*string) {
		*newString = *string;
		string++;
		newString++;
	}
	while (*str.string) {
		*newString = *str.string;
		str.string++;
		newString++;
	}
	*newString = NULL;
	//move pointer back to the start of char array
	cout << "creating new object" << endl;
	myString newStr(newString - size - str.size);
	cout << "returning object" << endl;
	//copy constructor is called as a clone of the object is returned
	return newStr;
	//destructor is called as the scope of the newStr ends here
	//destructor is called for the copied object
}
myString myString::subString(int start, int end) {
	//start = start index
	//end = end index
	char *substring = new char[end - start + 1];
	int count = 0;
	while (*string) {
		if (count >= start && count <=end ) {
			*substring = *string;
			substring++;
		}
		//move pointer ahead
		string++;
	}
	myString newSubString(substring - end + start);
	return newSubString;
}
myString::~myString() {
	cout << "destructor" << endl;
}