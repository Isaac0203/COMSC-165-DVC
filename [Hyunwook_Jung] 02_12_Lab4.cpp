#include <iostream>
#include <iomanip>
#include <string>
// Hyunwook Jung 1728369 - DVC
// 02_12_Lab4_COMSC_165
using namespace std;

int main()
{
	/*You are sending a shipment between 2 countries
	The program asks the user for information on a shipment

	First: Ask the user if the shipment is 1. Perishable or 2. Non-perishable
	Second: Then ask the user for the weight of the shipment in lbs.
	Validate if the input makes sense
	Then the program proposes shipment by air if it is perishable and weight<1000lb
	Then the program proposes shipment by boat if it is not perishable and weight<2000lb
	Else output that it cannot be shipped.*/
	cout << "*Lab 1" << endl;
	bool perishable;
	int buttonPerishable;
	do {
		cout << "Is this shipment perishable or non-perishable? (Enter 1 or 2)" << endl;
		cout << "1. Perishable\t\t\t2. Non-perishable" << endl;	// One OR TWO!!!!!!!!!!!!
		cin >> buttonPerishable;
	} while (buttonPerishable < 1 || 2 < buttonPerishable);

	if (buttonPerishable == 1)
		perishable = true;
	else perishable = false;

	double weight1; // How heavy?
	do {
		cout << "How much weight is this shipment in lbs? ";	// Input Positive Value
		cin >> weight1;
	} while (weight1 <= 0);

	cout << endl << endl;

	// Then the program proposes shipment by air if it is perishable and weight<1000lb
	if (perishable == true && weight1 < 1000)
	{
		cout << "This shipment is perishable and weight under 1000lb." << endl
			<< "This will be shipped by air.";
	}
	//Then the program proposes shipment by boat if it is not perishable and weight<2000lb
	else if (perishable == false && weight1 < 2000)
	{
		cout << "This shipment is non-perishable and weight under 2000lb." << endl
			<< "This will be shipped by boat.";
	}
	// Else output that it cannot be shipped.
	else
	{
		cout << "Sorry but this shipment is unavailable." << endl;
	}

	cout << endl << "===========================================================" << endl << endl;

	/*Lab2
	Ask the user to make a menu choice:
	1. Bananas
	2. Grapefruits
	3. Bread
	4. Milk
	5. Coffee
	6. Cookies
	Then the program proposes to the user a store
	with the most affordable prices in the area
	*/
	cout << "*Lab 2" << endl;
	cout << "Please select the stuff you would like to have." << endl;

	string menu[6] = { "Bananas", "Grapefruits", "Bread", "Milk", "Coffee", "Cookies" };
	for (int count2 = 0; count2 < 6; count2++)
	{	// Print whole menus
		cout << (count2 + 1) << "." << setw(13) << menu[count2] << endl;
	}
	int command;
	do {
		cout << "Enter a number between 1~6: ";
		cin >> command;	// Still index + 1
	} while (command < 1 || 6 < command);

	cout << "You selected " << menu[command - 1] << "." << endl;
	switch (command)
	{
	case 1: cout << "For " << menu[command - 1] << ", you should go to BANANASHOP.";
		break;
	case 2: cout << "For " << menu[command - 1] << ", you should go to Safeway.";
		break;
	case 3: cout << "For " << menu[command - 1] << ", you should go to IKEA.";
		break;
	case 4: cout << "For " << menu[command - 1] << ", you should go to BARN.";
		break;
	case 5: cout << "For " << menu[command - 1] << ", you should go to SOMEWHEREWITHCOFFEE.";
		break;
	case 6: cout << "For " << menu[command - 1] << ", you should go to MYHOUSE.";
		break;
	default: cout << "UHHHHHHHHHHHHHH?";
	}
	return 0;
}