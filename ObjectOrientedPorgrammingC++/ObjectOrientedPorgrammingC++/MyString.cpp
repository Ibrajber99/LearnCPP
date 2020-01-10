#include "MyString.h"
#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include <string>
#include <vector>
#include <cstring>
#include <ostream>
#include <istream>
#pragma warning(disable : 4996)//ignore an error type: C4996
//No args constructor
MyString::MyString() : str{ nullptr }
{
	str = new char[1];
	*str = '\0';
}
//Destructor
MyString::~MyString()
{
	std::cout << "CTOR has been called\n";
	delete[] str;//Destructing the pointer
}

//Overloaded constructor
MyString::MyString(const char* s) : str{ nullptr }
{
	if (s == nullptr) {
		str = new char[1];
		*str = '\0';
	}
	else {
		str = new char[std::strlen(s) + 1];//allocates a new char on the heap with the same length of s + 1
		std::strcpy(str, s);//copy all data from s to str 
	}
}
//Copy constructor
MyString::MyString(const MyString& source) : str{ nullptr }
{
	str = new char[std::strlen(source.str) + 1];//allocates a new char on the heap with the same length of source.str + 1
	std::strcpy(str, source.str);//copy all data from source.str to str 
}
//Move constructor
MyString::MyString(MyString&& source) : str{ source.str }
{
	source.str = nullptr;
	std::cout << "Move constuctor has been initiated\n";
}
//Display method
void MyString::display() const
{
	std::cout << str << " " << getLength() << std::endl;
}
//length string
int MyString::getLength() const
{
	return std::strlen(str);
}
//string getter
const char* MyString::getStr() const
{
	return str;
}
//Copy Assignment
MyString& MyString::operator=(const MyString& rhs)
{
	std::cout << "Copy Assignment is intiated\n";
	if (this == &rhs) {
		return *this;
	}
	delete[] this->str;
	str = new char[std::strlen(rhs.str) + 1];
	std::strcpy(this->str, rhs.str);
	return *this;
}
//Move assignment
MyString& MyString::operator=(MyString&& rhs)
{
	std::cout << "Move assignment has been intiated\n";
	if (this == &rhs) //checks if current object this->str = to address of &rhs
		return *this;//return current object
	delete[]str; //Deallocate storage for this->str since we are overwritting it
	str = rhs.str;//Steal the pointer from rhs object and assign it to this->str
	rhs.str = nullptr;//Null out the rhs pointer
	return *this;//return the current object by reference to allow chain assignment
}
//Make lower
MyString MyString::operator-() const
{
	char* buff = new char[std::strlen(str) + 1];//new memeory on the heap that has the same length and size as current str this->str
	std::strcpy(buff, this->str);
	for (int i{ 0 }; i < std::strlen(str); i++) {
		buff[i] = (std::tolower(buff[i]));
	}
	MyString temp{ buff };//intializing a current object which we assign buff to it
	delete[] buff; //release the memeory
	return temp;//return temp new value or new modification

}

MyString MyString::operator+(const MyString& rhs) const
{
	char *buff = new char[ std::strlen(str) + std::strlen(rhs.str) + 1];
	std::strcpy(buff, this->str);
	std::strcat(buff, rhs.str);
	MyString temp{ buff };
	delete[] buff;
	return temp;
}
//Equality
bool MyString::operator==(const MyString& rhs) const
{
	return (std::strcmp(str, rhs.str) == 0);//string length comparision 
}


/*
//Friend Global functions

//Equality
bool operator==(const MyString& lhs, const MyString& rhs)
{
	return (std::strcmp(lhs.str, rhs.str) == 0);
}

//Make lowerCase
MyString operator-(const MyString& obj)
{
	char* buff = new char[std::strlen(obj.str) + 1];
	std::strcpy(buff, obj.str);
	for (int i{ 0 }; i < std::strlen(buff); i++) {
		buff[i] = std::tolower(buff[i]);
	}
	MyString temp{ buff };
	delete[] buff;
	return temp;
}
//Concatination
MyString operator+(const MyString& lhs, const MyString& rhs)
{
	char* buff = new char[std::strlen(lhs.str) + std::strlen(rhs.str) + 1];
	std::strcpy(buff, lhs.str);
	std::strcat(buff,rhs.str);
	MyString temp{ buff };
	delete[] buff;
	return temp;
}
*/
//Overloaded insertion operator
std::ostream& operator<<(std::ostream& os, const MyString& rhs)
{
	os << rhs.getStr();
	return os;
}
//Overloaded extraction operator
std::istream& operator>>(std::istream& is, MyString& rhs)
{
	char* buff = new char[1000];
	is >> buff;
	rhs = MyString{ buff };
	delete[] buff;
	return is;
}
