#include <iostream>
#include <string>
// Hyunwook Jung DVC
// 03 05 2019 COMSC 165
// Assignment 03

using namespace std;
int main()
{
	/*Question #1 (coding):

Write a function that takes as input a string from the user.

Then it checks if the string is a palindrome.

A palindrome is a string that is the same forwards and backwards.

The code outputs "yes it is a palindrome" or "not a palindrome".*/

	string palindString;

	cout << "Enter a string that may be a palindrome: ";
	getline(cin, palindString);
	// User Input Done
	// ASCII Number of blank space is '32'
	cout << static_cast<int>(palindString[0]) << palindString[1];
	int numChar = palindString.length(); // Number of characters of the string palindString

	if (numChar == 1)
	{
		cout << "This string is a palindrome.";
	}
	else if (numChar == 2)
	{
		if (palindString[0] == palindString[1])
			cout << "This string is a palindrome.";
		else if (palindString[0] != palindString[1])
			cout << "This string is not a palindrome.";
	}
	else if (numChar >= 3)
	{

			/***Middle Index Simulation and Planning***
			(1) In case string has odd number of characters,
			[5] => 0  1  2  3  4
			the middle index == (numChar / 2) = 2.5 => 2.0

			(2) In case string has even number of characters,
			[6] => 0  1  2  3  4  5
			the middle index == (numChar / 2) - 1 and (numChar / 2) */

			int middleIndex = numChar / 2;
		cout << endl << endl << "==================================" << endl;

		// With only one wrong couple of two elements, it is not a palindrome.
		bool pal = true;
		for (int count1A = 0; count1A < middleIndex; ++count1A)
			if (palindString[count1A] != palindString[((numChar - 1) - count1A)])
			{
				pal = false;
			}

		if (pal == true)
			cout << "This string is a palindrome.";
		else if (pal == false)
			cout << "This string is not a palindrome.";
	}

	return 0;

	/*Multiple-choice questions:

2. After the following code executes, what is the value of my_value if the user enters 0?

cin >> my_value;

if (my_value > 5)

    my_value = my_value + 5;

else if (my_value > 2)

    my_value = my_value + 10;

else

    my_value = my_value + 15;

a.

15

b.

10

c.

25

d.

0

e.

5

 

 ########### MY ANSWER: a. 15

 

3. After the following code executes, what is the output if the user enters 0?

int x = -1;

cout << "Enter a 0 or 1: ";

cin >> x;

if (x)

    cout << "true" << endl;

else

    cout << "false" << endl;

a.

nothing will be displayed

b.

false

c.

x

d.

true

e.

0

 

 
 ########### MY ANSWER: b. false

 

4. What is the output of the following segment of code if the value 4 is input by the user?

int num;

int total = 0;

cout << "Enter a number from 1 to 10: ";

cin >> num;

switch (num)

{

    case 1:

    case 2:   total = 5;

    case 3:   total = 10;

    case 4:   total = total + 3;

    case 8:   total = total + 6;

    default:  total = total + 4;

}

cout << total << endl;

a.

0

b.

3

c.

13

d.

23

e.

None of these

 

 
 ########### MY ANSWER: c. 13

 

5. What will the following code display?

int x = 0;

for (int count = 0; count < 3; count++)

     x += count;

cout << x << endl;

a.

0

1

2

b.

0

c.

6

d.

3

 

 

 ########### MY ANSWER: d. 3
 

 

6. How many times will the following loop display "Hello world!"?

for (int i = 0; i < 20; i++)

     cout << "Hello world!" << endl;

a.

20

b.

19

c.

21

d.

an infinite number of times



 ########### MY ANSWER: a. 20

*/
}