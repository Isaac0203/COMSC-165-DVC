#include <iostream>
// Hyunwook Jung
// 02 19 2019 DVC
using namespace std;

void normalizeMoney(float&, int);
int main()
{
	/*Q1: Use passing value by reference

Write the function:

void normalizeMoney(float& dollars, int cents);

which is given an integer value in cents and converts it to dollars and cents.

The result (dollars and cents) is sent back to the calling main function

through the parameter dollars (Note: value is passed by reference).*/
	cout << "*Lab1" << endl << endl;
	float dollars = 0.0;
	int cents = 0;
	cout << "Enter how much money do you have in cents." << endl;
	do {
		cout << "Cents: ";
		cin >> cents;
	} while (cents <= 0);
	normalizeMoney(dollars, cents);
	cout << endl << endl;
	cout << "The money you have in dollars is " << dollars << "$.";
	return 0;
}

void normalizeMoney(float& dollars, int cents)
{
	dollars = cents / 100.0;
}