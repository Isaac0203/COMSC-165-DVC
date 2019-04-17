#include <iostream>
using namespace std;
// Hyunwook Jung
// 04 16 2019
// Diablo Valley College - COMSC 165
// Quiz 5

/*
Define a class named Account that stores a balance (monetary amount).
The class should have a private double variable balance.
dd one accessor getBalance function that returns the balance
and one deposit function that increases the balance by a given double amount.

Then subclass Account with a SavingsAccount class.
This class should have a private double variable interest.
Add an addInterest function that increases the balance 
(from the superclass Account) according to the interest.

Demonstrate the use in a main function.

Both classes should have a default constructor and a custom constructor, as follows:

public Account() 
public Account(double initial)
public SavingsAccount()
public SavingsAccount(double inter)

*/

class Account
{
private:
	double balance;
public:
	// Constructor
	Account();
	Account(double initial);

	// Deposit -> balance(Mutator)
	void deposit(double b);

	// Accessor
	const double getBalance() const;
};

Account::Account()
{
	balance = 0.0;
	cout << "Account made" << endl;
}
Account::Account(double initial)
{
	balance = initial;
	cout << "Account made" << endl;

}
void Account::deposit(double b)
{
	balance += b;
}
const double Account::getBalance() const
{
	return balance;
}


class SavingsAccount:public Account
{
private:
	double interest;
public:
	// Constructor
	SavingsAccount();
	SavingsAccount(double inter);
	// Mutator
	void addInterest();
};

SavingsAccount::SavingsAccount()
{
	interest = 0.0;
	cout << "Saving Account made" << endl;

}
SavingsAccount::SavingsAccount(double inter)
{
	interest = inter;
	cout << "Saving Account made with interest " << inter << endl;

}
void SavingsAccount::addInterest()
{
	// Increased balance is balance's 100% + balance*interest
	double increasedInterest = getBalance() * interest;
	deposit(increasedInterest);
}

int main()
{	
	SavingsAccount myAccount(0.01);
	myAccount.deposit(1000.0);
	cout << "Before interest: " << myAccount.getBalance() << endl;
	myAccount.addInterest();
	cout << "After interest: " << myAccount.getBalance() << endl;

	return 0;
}