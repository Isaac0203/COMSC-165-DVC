#include <iostream>
// Hyunwook Jung
// COMSC 165 LAB 18
// Diablo Valley College
// 05 02 2019

/*
LAB 18: 

Download "C++ Exception handling_2.cpp" from the Files folder. 

Then re-engineer the code to handle the case of (milk <= 0)

with exception handling.*/

using namespace std; 

class Error
{ };

int main() 
{ 
	int donuts, milk; 
	double dpg; 
	cout << "Enter number of donuts:\n";
	cin >> donuts;
	do {
		
		try
		{
			cout << "Enter number of glasses of milk:\n";
			cin >> milk;
			if (milk <= 0)
			{
				Error error;
				throw error;
			}

			dpg = donuts / static_cast<double>(milk);
			cout << donuts << " donuts.\n" << milk << " glasses of milk.\n" << "You have " << dpg << " donuts for each glass of milk.\n";
		}
		catch (Error error)
		{
			cout << donuts << " donuts, and No Milk!\n" << "Go buy some milk.\n";
		}
		cout << "End of program.\n";

		cout << "==================================================================" << endl << endl << endl;
		cout << "Enter number of donuts. ";
		cout << "Or enter a negative number if you want to terminate this program : \n";
		cin >> donuts;
	} while (donuts >= 0);
	return 0; 
}
