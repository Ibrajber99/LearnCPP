#include "Account.h"

Account::Account()
{
	Account(0.0);
}

Account::~Account()
{
}
Account::Account(double value) : value(value) {

}
void Account::deposit(double amount)
{
	std::cout << "Account deposit is called with " << amount << std::endl;
}

void Account::withdrawal(double amount)
{
	std::cout << "Account withdrawal called with" << amount << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Account& account)
{
	os << "Accoutn balance is " << account.value;
}
