#include <iostream>
#include <vector>
// Hyunwook Jung
// 02 21 2019 DVC
// COMSC 165 LAB 7

// LAB 7 -> LAB 9 TUNED
// 02 28 2019 DVC
// COMSC 165 LAB 9
using namespace std;
int main()
{
	// Lab 1
	// Ask the user to input test scores for 3 tests for 5 students
	// Then for each student compute the average test score, the highest and the lowest test score
	// and print them out
	int numTest, numStu;
	do
	{
		cout << "Enter a positive integer higher than zero for the number of tests: ";
		cin >> numTest;
	} while (numTest <= 0);

	do
	{
		cout << "Enter a positive integer higher than zero for the number of students: ";
		cin >> numStu;
	} while (numStu <= 0);

	// Declair 2D dynamic array
	int **testptr = new int* [numTest];
	for (int i = 0; i < numTest; ++i)
	{
		testptr[i] = new int[numStu];
	}

	for (int count1A = 0; count1A < numStu; ++count1A)	// count1A ==> student index 0~4
	{
		for (int count1B = 0; count1B < numTest; ++count1B)	// count1B ==> test index 0~2
		{
			cout << "Enter the score of NO." << (count1A + 1) << " student's Test #" << (count1B + 1) << ": ";
			cin >> testptr[count1A][count1B];
			while (testptr[count1A][count1B] < 0)
			{
				cout << "Please enter a positive integer between 0 ~ 100." << endl;
				cout << "Enter the score of NO." << (count1A + 1) << " student's Test #" << (count1B + 1) << ": ";
				cin >> testptr[count1A][count1B];
			}
		}
	}
	int highest		= testptr[0 ][ 0];
	int lowest		= testptr[0 ][ 0];
	double total = 0, average;
	for (int count1A = 0; count1A < numStu; ++count1A)	// count1A ==> student index 0~4
	{
		for (int count1B = 0; count1B < numTest; ++count1B)	// count1B ==> test index 0~2
		{
			if (highest < testptr[count1A][count1B])
				highest = testptr[count1A][count1B];

			if (lowest > testptr[count1A][count1B])
				lowest = testptr[count1A][count1B];
		}
	}
	cout << endl << endl;

	for (int count1A = 0; count1A < numStu; ++count1A)	// count1A ==> student index 0~4
	{
		for (int count1B = 0; count1B < numTest; ++count1B)	// count1B ==> test index 0~2
		{
			total += testptr[count1A][count1B];
		}
	}
	cout << endl << endl;
	cout << "The highest value of all tests scores is " << highest << endl;
	cout << "The lowest value of all tests scores is " << lowest << endl;
	cout << "The total value of all tests scores is " << total << endl;
	int numberIndex = numStu * numTest;
	average = total / numberIndex;

	cout << "The average value of all tests scores is " << average << endl;

	// Clean Up
	for (int i = 0; i < numTest; ++i)
		delete[] testptr[i];

	delete[] testptr;

	getchar();
	return 0;
}