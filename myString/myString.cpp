#include "myString.h"
#include <cstdio>

//argument based constructor
myString::myString(char str[]) {
	string = str;
	size = getsize();
	cout << "arg constructor" << endl;
}

//copy constructor
myString::myString(myString &str) {
	string = str.string;
	size = str.size;
	cout << "Copy constructor" << endl;
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

myString myString::concatenate(myString &str) {
	//dynamic memory allocation
	char *newString = new char[size + str.size + 1];
	int count = 0;
	char *ptr = string;
	while (*ptr) {
		*newString = *ptr;
		ptr++;
		newString++;
	}
	ptr = str.string;
	while (*ptr) {
		*newString = *ptr;
		ptr++;
		newString++;
	}
	
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
		string = string-size;
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

void myString::replace(char c, char d) {
	char *ptr = string;
	while (*ptr) {
		if (*ptr == c) {
			*ptr = d;
			break;
		}
		ptr++;
	}
};

myString myString::operator = (myString &str) {
	cout << "operator overload" << endl;
	if (this != &str) {
		string = str.string;
		size = str.size;
	}
	return *this;
};

//operator overload
myString myString::operator+ (myString &str) {
	cout << "+ operator overload inside method" << endl;
	myString s = myString(this->string);
	s.print();
	s.concatenate(str);
	myString s1 = s.concatenate(str);
	myString concatStr = s1;
	return concatStr;
};

int myString::operator == (myString &str) {	
	cout << "== equals operator overloading" << endl;
	//if sizes of the string is not equal, they are not equal
	if (str.size != size)
		return false;

	char *p = string;
	char *p2 = str.string;
	int expr = 0;
	
	while (*p) {
		if (*p != *p2) {
			expr += 1;
			break;
		}
		p++;
		p2++;
	}
	return expr == 0 ? true : false;
};

myString::operator char* const () {
	return string;
};

//destructor
myString::~myString() {
	cout << "destructor" << endl;
	//delete string;
}