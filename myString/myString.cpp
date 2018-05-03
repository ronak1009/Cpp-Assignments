#include "myString.h"
#include <cstdio>

myString::myString(char str[]) {
	string = str;
	size = getsize();
}

myString::myString(myString &str) {
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
	//resetting the pointer on string
	(string - size);
	*newString = NULL;
	//move pointer back to the start of char array
	myString newStr(newString - size - str.size);
	//copy constructor is called as a clone of the object is returned
	return newStr;
	//destructor is called as the scope of the newStr ends here
	//destructor is called for the copied object
}
myString myString::subString(int start, int end) {
	//start = start index
	//end = end index
	char *substring = new char[end - start];
	int count = 0;
	char *ptr = string;
	while (*ptr) {
		if (count >= start && count <=end ) {
			*substring = *ptr;
			substring++;
		}
		//move pointer ahead
		ptr++;
		count++;
	}
	*substring = NULL;
	//resetting the pointer on string
	//string = string - size;
	myString newSubString(substring - (end - start+1));
	return newSubString;
}
int myString::indexOf(char c) {
	int index = 0;
	if (*string == '\0' || *string == NULL)
		string-size;
	char *ptr = string;
	while (*ptr) {
		if (*ptr == c) 
			break;
		index++;
		ptr++;
	}
	//returning -1 means that the char is not present
	return index > size-1 ? -1 : index;
};
//destructor
myString::~myString() {
	//cout << "destructor" << endl;
	//delete[] string;
	//delete &size;
}