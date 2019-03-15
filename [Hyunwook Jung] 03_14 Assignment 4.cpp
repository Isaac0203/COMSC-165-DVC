#include <iostream>
#include <string>

using namespace std;
int main()
{
	/*
	Question #1

Write a program that takes as input 2 strings from the user. 
Then it determines if one string is a permutation of the other string.*/

	string a, b;
	cout << "Enter the first string: ";
	cin >> a;
	cout << "Enter the second string: ";
	cin >> b;
	int aLength, bLength;

	aLength = a.length();	// Number of characters in a
	bLength = b.length();	// Number of characters in b
	cout << aLength << endl << bLength;
	
	bool permutation = true;

	// Sort!!
	int lowest;
	int temp;	// For swapping values

	// Sort!! in reverse order. in case of a
	int largest = a[0];
	int largestIndex = 0;

	for (int count1 = 0; count1 + 1 < aLength; ++count1)
	{
		largest = a[count1];
		largestIndex = count1;
		for (int count2 = count1 +1; count2 < aLength; ++count2)
		{

			if (largest < a[count2])
			{
				largest = a[count2];
				largestIndex = count2;
			}
		}
		// After finding the largest value, swap the value of a[count1] <> a[largest]
		temp = a[count1];
		a[count1] = a[largestIndex];
		a[largestIndex] = temp;
		cout << endl << a;
	}

	// Sort b this time!
	largest = b[0];
	largestIndex = 0;

	for (int count1 = 0; count1 + 1 < bLength; ++count1)
	{
		largest = b[count1];
		largestIndex = count1;

		for (int count2 = count1 + 1; count2 < bLength; ++count2)
		{

			if (largest < b[count2])
			{
				largest = b[count2];
				largestIndex = count2;
			}
		}
		// After finding the largest value, swap the value of a[count1] <> a[largest]
		temp = b[count1];
		b[count1] = b[largestIndex];
		b[largestIndex] = temp;
	}

	cout << endl << a << endl << b;


	if (aLength != bLength)
	{
		permutation = false;
	}
	else     // a and b has the same number of characters
	{
		for (int count1 = 0; count1 < aLength; ++count1)
		{
			if (a[count1] != b[count1])
				permutation = false;
		}
	}

	if (permutation)
		cout << endl << "This is a permutation!!!!!";
	else
		cout << endl << "This is not a permutation!!!!!!";

	/*Question #2

If the program answers "yes" to the previous question, 
meaning the two strings are permutations of each other, 
determine if each string has all unique characters.

Hint: you can use sorting as we implemented it in class (see Lab #8). 
For comparing strings you can use functions like length(), strcmp(), 
or write your own check_equality(string, string) function. */

	// If permutation == true;
	// Check if a[n-1] == a[n]
	if (permutation)
	{
		bool sameChar = true;

		for (int count = 1; count < aLength; ++count)
		{
			if (a[count - 1] == a[count])
				sameChar = false;
		}

		if (sameChar)
			cout << endl << "This has all unique characters!!!!!";
		else
			cout << endl << "This does not have unique characters!!!!!!!!!!!!";
	}

	return 0;
}