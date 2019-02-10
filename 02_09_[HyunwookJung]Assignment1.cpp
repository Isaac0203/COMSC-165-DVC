#include <iostream>
#include <string>
#include <iomanip>
// Hyunwook Jung
// 02/09/2019 DVC
using namespace std;

int main()
{
	/*Q1 (coding): Ask the user to enter 2 strings. 
	Then determine if the 2 strings have any characters in common. 
	Print out the common characters if the two strings have any, else print "no common characters".*/
	
	cout << "Q1: Print out the common characters if the two strings have any." << endl << endl;
	string string1A, string1B;

	cout << "Enter the first string: ";
	getline(cin, string1A);

	cout << endl << "Enter the second string: ";
	getline(cin, string1B);

	unsigned int numChar1A = string1A.length();	// How many characters does string1A has??
	unsigned int numChar1B = string1B.length();	// How many characters does string1B has??

	// Sort the string1A in ascending order!!!!
	bool sortDone1A = false;
	do
	{
		sortDone1A = true;
		for (int count1A = 0; (count1A + 1) < numChar1A; count1A++)
		{
			if (string1A[count1A] > string1A[count1A + 1])
			{
				int tempElement1A = string1A[count1A];
				string1A[count1A] = string1A[count1A + 1];
				string1A[count1A + 1] = tempElement1A;		// string1A[count1] < string1A[count1 + 1]
				sortDone1A = false;
			}
		}
	} while (sortDone1A == false);

	// Sort the string1B in ascending order!!!!
	bool sortDone1B = false;
	do
	{
		sortDone1B = true;
		for (int count1B = 0; (count1B + 1) < numChar1B; count1B++)
		{
			if (string1B[count1B] > string1B[count1B + 1])
			{
				int tempElement1B = string1B[count1B];
				string1B[count1B] = string1B[count1B + 1];
				string1B[count1B + 1] = tempElement1B;		// string1A[count1] < string1A[count1 + 1]
				sortDone1B = false;
			}
		}
	} while (sortDone1B == false);


	cout << string1A << endl;
	cout << string1B << endl;
	
	// @@@@@@@@@@@@@@@@@@@@@@@@Sort all done@@@@@@@@@@@@@@@@@@@@@@@@!!

	// string1A[0] == string1B[0], string1B[1], string1B[2],..., string1B[numChar1B - 1] ?? 
	
	bool sameChar = false;	// Is there at least one same character between two strings?
	cout << "The same characters between two strings: ";
	for (int count1A = 0; count1A < numChar1A; count1A++)
	{
		// If the count is not 0 and the element of count is the same as the previous element,
		// skip this whole loop.
		if (count1A != 0 && string1A[count1A - 1] == string1A[count1A])
			continue;

		// string1A[count1A]

		for (int count1B = 0; count1B < numChar1B; count1B++)
		{
			if (count1B != 0 && string1B[count1B - 1] == string1B[count1B])
				continue;

			if (string1A[count1A] == string1B[count1B])
			{
				sameChar = true;
				cout << string1B[count1B] << " ";
			}
		}
	}

	cout << endl;

	if (sameChar == false) // No.
		cout  << "No common characters between two strings...";

	cout << endl << "*****************************************************************" << endl;

/*Q2 (coding): Ask the user to -enter the *length and *width dimensions (in feet) for a new construction. 
Then ask the user to -enter the *cost (as $/square foot). 
Then compute and -output the *total cost for the construction.*/

	cout << "Q2: Output the *total cost for the construction." << endl << endl;

	double length2, width2, cost2, totalArea2, totalCost2;
	cout << "Enter the length for a new construction(in feet): ";
	cin >> length2;
	cout << "Enter the width for a new construction(in feet): ";
	cin >> width2;
	cout << "Enter the cost per square foot: ";
	cin >> cost2;

	totalArea2 = length2 * width2;
	totalCost2 = cost2 * totalArea2;

	cout << fixed << showpoint << setprecision(2);

	cout << "The total cost of the new construction will be " << totalCost2 << "$." << endl;
	

	cout << endl << "*****************************************************************" << endl;

	cout << "Press any key to close the program.";
	getchar();
/*The rest are multiple choice questions:

Q3: Using C++11: What data type does the compiler determine for the variable cost in the following statement?

auto cost = 14.95;

a.

int

b.

double

c.

bool

d.

char

e.

string

 
	########################## My answer: b. double
 

Q4: What is the value stored in the variable myNum after the following assignment statement executes?

myNum = 23 % 5

a.

3

b.

4

c.

4.6

d.

115

e.

None of these

 
	########################## My answer: a. 3
 

 

 

Q5: What is the value of cookies after the following statements execute?

int number = 38, children = 4, cookies;

cookies = number % children;

a.

2

b.

4

c.

9

d.

9.5

e.

.5

 

 

 ########################## My answer: a. 2

 

Q6: What is the value of number after the following statements execute?

int number;

number = 18 / 4;

a.

4.5

b.

4

c.

2

d.

0

e.

unknown

 

 

 ########################## My answer: b. 4

 

Q7: What is the value of number after the following statements execute?

int number;

number = 18 % 4 + 2;

a.

3

b.

4

c.

6.5

d.

0

e.

unknown

 

 

 ########################## My answer: b. 4

 

Q8: What is output of the following statement?

cout << 4 * (15 / (1 + 3)) << endl;

a.

15

b.

12

c.

63

d.

72

e.

None of these


########################## My answer: b. 12


*/
getchar();
	return 0;
}