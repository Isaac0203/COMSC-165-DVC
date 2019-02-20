#include <iostream>
// Hyunwook Jung
// 02 20 2019 DVC
// Assignment 2 - COMSC 165

using namespace std;

int main()
{
	/*Q1 (coding):

Write a program that asks the user to input a positive number pos that is greater than (>1).

Then the program outputs the Fibonacci sequence as long as it does not exceed the value pos.

The Fibonacci sequence is the series of numbers, such that each number is the sum of the two preceding ones, starting from 0 and 1. For example:

0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...

The next number is found by adding up the two numbers before it.

For example, if the user inputs 6, the program will output 0, 1, 1, 2, 3, 5.*/
	double pos;
	do {
		cout << "Enter a positive value greater than 1: ";
		cin >> pos;
	} while (pos <= 1);	// Filter value <= 1
	cout << endl << endl;

	int fiboValue = 0;
	int fiboValue2 = 1;
	int addedFibo = fiboValue + fiboValue2;
	cout << "0, 1";

	while (pos >= addedFibo)
	{
		cout << ", " << addedFibo;
		fiboValue = fiboValue2;
		fiboValue2 = addedFibo;
		addedFibo = fiboValue + fiboValue2;
	}
	
	cout << "." << endl << endl;
	cout << "=================================================================";
/*Q2 (coding):

Write a program that asks the user for their quarterly water bill for the last 4 quarters.

Then compute and print out their average monthly bill.

If the monthly bill exceeds $75 output that too much water is used, while if the monthly bill is 

under $25 output a positive message, else output that water consumption is normal.*/

	const int fourQuaters = 4;
	double waterBill[fourQuaters];
	double total = 0;
	for (int count = 0; count < fourQuaters; ++count)
	{
		do {
			cout << "Enter the water bill for the no." << count + 1 << " quater: ";
			cin >> waterBill[count];
		} while (waterBill[count] < 0);
		total += waterBill[count];
	}
	double average = total / fourQuaters;
	int positive = 25;
	int negative = 75;
	if (average > negative)
		cout << "You are using too much water!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
	else if (average < positive)
		cout << "The earth loves you!!!!!! I think.";
	else cout << "Huh. It is Okay. Try to save the energy a little bit.";

	cout << endl << endl;
 

 

/*The rest of the questions are multiple choice:

 

3. What will the following code display?

int number = 6;

number++;

cout << number << endl;

a.

6

b.

5

c.

7

d.

0

 
 ######################### MY ANSWER: C
 

 

 

4. What will the following code display?

int number = 6;

++number;

cout << number << endl;

a.

6

b.

5

c.

7

d.

0

 

 ######################### MY ANSWER: C

 

 

5. What will the following code display?

int number = 6;

cout << number++ << endl;

a.

6

b.

5

c.

7

d.

0

 

 
 ######################### MY ANSWER: A
 

 

6. What will the following code display?

int number = 6;

cout << ++number << endl;

a.

6

b.

5

c.

7

d.

0


######################### MY ANSWER: C

*/
	return 0;
}