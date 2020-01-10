#pragma once
#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include <string>
#include <vector>
#include <cstring>
#include <ostream>
#include <istream>
class Account
{
public:
	friend std::ostream& operator<<(std::ostream& os, const Account& account);
	Account();
	~Account();
	Account(double value) {};
	void deposit(double amount);
	void withdrawal(double amount);
	double value;
private:
	
};

