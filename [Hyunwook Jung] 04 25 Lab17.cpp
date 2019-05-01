#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
// Hyunwook Jung
// 04 25 2019
// COMSC 165 Diablo Valley College
// Lab 17

/*Aim: The purpose is to practice using exceptions.

Write a program with a while loop that asks for an employee's total monthly pay, 
days worked in the last month, hours worked in the last month.

Then it outputs: pay rate per day and pay rate per hour 
for the employee for the last month. 

The program should have exception handling for these cases:

division by zero,
if days is a value that does not make sense (> 31 or <0) or
hours does not make sense (>720 or <0).
The program's while loop only exits 
when the total monthly pay entered is a negative value!

*/

double getDays();
double getHours();
double divide(double totalPay, int time);

int main()
{
	double	totalMonthlyPay = 0;
	int		daysWorkedInOneMonth;
	int		hoursWorkedInOneMonth;

	// Goal variables
	double	payRatePerDay;
	double	payRatePerHour;
	cout << fixed << setprecision(2);
	cout << "This is pay rate calculator." << endl;
	cout << "Enter the total monthly pay." << endl;
	cout << "Or if you want to stop the program, enter a negative value." << endl;
	cin >> totalMonthlyPay;

	while (totalMonthlyPay >= 0)
	{
		

		try
		{
			daysWorkedInOneMonth = getDays();
			hoursWorkedInOneMonth = getHours();
			payRatePerDay = divide(totalMonthlyPay, daysWorkedInOneMonth);
			payRatePerHour = divide(totalMonthlyPay, hoursWorkedInOneMonth);
			cout << "Your pay rate per day is " << payRatePerDay << endl;
			cout << "Your pay rate per hour is " << payRatePerHour << endl;
			cout << "===================================================================" << endl;
		}
		catch (string exceptionString)
		{
			cout << exceptionString;
		}

		cout << "Enter the total monthly pay." << endl;
		cout << "Or if you want to stop the program, enter a negative value." << endl;
		cin >> totalMonthlyPay;
	}
	return 0;
}

double getDays()
{
	double	daysWorkedInOneMonth;
	cout	<< "Enter the number of days you worked last month: ";
	cin		>> daysWorkedInOneMonth;

	if (daysWorkedInOneMonth < 0 || daysWorkedInOneMonth > 31)
	{
		string daysExceptionString = "Error: Days value cannot be under 0 or over 31.\n";
		throw daysExceptionString;
	}
	
	return daysWorkedInOneMonth;
}

double getHours()
{
	double hoursWorkedInOneMonth;
	cout	<< "Enter the number of hours you worked last month: ";
	cin		>> hoursWorkedInOneMonth;

	if (hoursWorkedInOneMonth < 0 || hoursWorkedInOneMonth > 720)
	{
		string hoursExceptionString = "Error: Hours value cannot be under 0 or over 720.\n";
		throw hoursExceptionString;
	}

	return hoursWorkedInOneMonth;
}

double divide(double totalPay, int time)
{
	
	if (time == 0)
	{
		string divideByZeroExceptionString = "Error: Total payment cannot be divided by zero.\n";
		throw divideByZeroExceptionString;
	}

	return totalPay / time;
}