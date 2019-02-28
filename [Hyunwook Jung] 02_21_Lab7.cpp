#include <iostream>
#include <vector>
// Hyunwook Jung
// 02 21 2019 DVC
// COMSC 165 LAB 7
using namespace std;
int main()
{
	// Lab 1
	// Ask the user to input test scores for 3 tests for 5 students
	// Then for each student compute the average test score, the highest and the lowest test score
	// and print them out
	const int numTest = 3;
	const int numStu = 5;
	int tests[numStu] [numTest];

	for (int count1A = 0; count1A < numStu; ++count1A)	// count1A ==> student index 0~4
	{
		for (int count1B = 0; count1B < numTest; ++count1B)	// count1B ==> test index 0~2
		{
			cout << "Enter the score of NO." << (count1A + 1) << " student's Test #" << (count1B + 1) << ": ";
			cin >> tests[count1A] [count1B];
			while (tests[count1A][count1B] < 0)
			{
				cout << "Please enter a positive integer between 0 ~ 100." << endl;
				cout << "Enter the score of NO." << (count1A + 1) << " student's Test #" << (count1B + 1) << ": ";
				cin >> tests[count1A][count1B];
			}
		}
	}
	int highest		= tests[0][0];
	int lowest		= tests[0][0];
	
	for (int count1A = 0; count1A < numStu; ++count1A)	// count1A ==> student index 0~4
	{
		for (int count1B = 0; count1B < numTest; ++count1B)	// count1B ==> test index 0~2
		{
			if (highest < tests[count1A][count1B])
				highest = tests[count1A][count1B];

			if (lowest > tests[count1A][count1B])
				lowest = tests[count1A][count1B];
		}
	}
	cout << endl << endl;
	cout << "The highest value of all tests scores is " << highest << endl;
	cout << "The lowest value of all tests scores is " << lowest;

	
	return 0;
}