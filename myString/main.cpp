/*
Author:: rsh5
version:: 0.1
*/
#include "myString.h"

using namespace std;
/*
@TODO:: 
1. pass the object reference and not object -> object is getting destroyed once the function call ends
This is 'cause the new temp object's scope is local to the function.

2. << operator overload, for working it with cout
*/
int main() {
	myString str1("Ronak");

	str1.print();
	//printf("Length :: %d\n", str1.getsize());
	myString str2("SHAH");
	str2.print();

	//appending 2 str
	myString newStr = str1.concatenate(str2);
	//copy constructor is called as you are passing by value str2
	newStr.print();
	
	myString subStr = newStr.subString(1, 3);
	subStr.print();
	
	int index = newStr.indexOf('S');
	printf("index of R = %d\n", index);
	
	myString operStr = str1 + str2;
	operStr.print();
	
	operStr.replace('S', 'G');
	operStr.print();

	operStr = newStr;
	operStr.print();
	
	//3 destructors shall be called, str1, str2, newStr
}