#include "myString.h"

using namespace std;

int main() {
	myString str1("Ronak");

	str1.print();
	//printf("Length :: %d\n", str1.getsize());
	myString str2("SHAH");
	str2.print();

	//appending 2 str
	cout << "concatenate method calling" << endl;
	myString newStr = str1.concatenate(str2);
	//copy constructor is called as you are passing by value str2
	cout << "printing" << endl;
	newStr.print();

	cout << "main method ending" << endl;
	//3 destructors shall be called, str1, str2, newStr
}