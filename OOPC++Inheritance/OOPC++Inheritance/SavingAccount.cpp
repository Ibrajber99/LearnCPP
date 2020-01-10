#include "SavingAccount.h"
#include "Account.h"

SavingAccount::SavingAccount():SavingAccount(0.0,0.0)
{
}

SavingAccount::SavingAccount(double balance, double intRate):Account(balance), intRate(intRate)
{
}

void SavingAccount::deposit(double amount)
{
	amount = amount + (amount * intRate / 100);
	Account::deposit(amount);
}

std::ostream& operator<<(std::ostream& os, SavingAccount& account)
{
	os << "The balance is: " << account.value << "Interest rate is: " << account.intRate;
}
