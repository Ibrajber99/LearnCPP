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
class SavingAccount
{
	friend std::ostream &operator << (std::ostream &os, SavingAccount &account)
};

