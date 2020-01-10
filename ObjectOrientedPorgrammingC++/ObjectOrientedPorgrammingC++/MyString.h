#pragma once
#include <ostream>
#include <istream>
class MyString
{
	//Global  friend functions
	//friend bool operator==(const MyString& lhs, const MyString& rhs);
	//friend MyString operator-(const MyString& obj);
	//friend MyString operator+(const MyString& lhs, const MyString& rhs);
	
private:
	char* str;//C-style string
public:
	MyString();  //no-args constructor
	~MyString(); //Destructor
	MyString(const char* s); //Overloaded constructor
	MyString(const MyString& source); //Copy constructor
	MyString(MyString&& source);
	void display() const;
	int getLength() const;           //Getters
	const char* getStr() const;
	MyString& operator=(const MyString& rhs); //Copy Assignment overloading
	MyString& operator=( MyString&& rhs); //Move assignment
	MyString operator-() const;  //make lower case version of the string
	MyString operator+(const MyString& rhs) const; //concatenate
	bool operator==(const MyString& rhs) const;
	friend std::ostream& operator << (std::ostream& os, const MyString& rhs);
	friend std::istream& operator >>(std::istream& is, MyString& rhs);
};

