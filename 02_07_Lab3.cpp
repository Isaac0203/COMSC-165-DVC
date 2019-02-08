#include <iostream>
#include <string>
// Hyunwook Jung, Isaac
// 02/07/2019
// Diablo Valley College

using namespace std;

int main()
{
	// Lab 1:
	// Write a program that takes as input a string of characters and prints out
	// the integer value of each character, one at a time. 
	// Hint: cast the characters to integers.

	cout << "Lab 1: " << endl;
	string string1;
	cout << "Enter a string: ";
	getline(cin, string1);	// Get a line of string

	int charNum = string1.length();	// How many characters doese the string have??
	
	cout << endl << "The length of the string is " << charNum << endl;

	for (int count = 0; count < charNum; count++)
	{
		cout << static_cast<int>(string1[count]) << endl;
	}
	
	
	
	cout << "**************************************************" << endl;
	


	cout << "Lab 2: " << endl;
	// User enters a sequence of characters.
	// Convert it to the phone number the way the old-school phones worked
	// ABC = 1, DEF = 2, GHI = 3, JKL = 4, MNO = 5, PQR = 6, ST = 7, UV = 8, WX = 9, YZ = 0
	string string2;
	cout << "Enter a string: ";
	getline(cin, string2);
	int charNum2 = string2.length();
	for (int count2 = 0; count2 < charNum2; count2++)
	{
		switch (static_cast<int>(string2[count2]))
		{
			case 65: //A
			case 66:
			case 67: cout << 1;
				break;
			case 68: //D
			case 69:
			case 70: cout << 2;
				break;
			case 71: //G
			case 72:
			case 73: cout << 3;
				break;
			case 74: //J
			case 75:
			case 76: cout << 4;
				break;
			case 77: //M
			case 78:
			case 79: cout << 5;
				break;
			case 80: //P
			case 81:
			case 82: cout << 6;
				break;
			case 83: //S
			case 84: cout << 7;
				break;
			case 85: //U
			case 86: cout << 8;
				break;
			case 87: //W
			case 88: cout << 9;
				break;
			case 89: //Y
			case 90: cout << 0;
				break;
		}
	}

	return 0;
}