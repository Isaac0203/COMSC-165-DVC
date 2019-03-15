#include <iostream>
#include <string>
// Hyunwook Jung DVC
// 03 14 2019 COMSC 165
// QUIZ #4

using namespace std;
int main()
{
	string a;
	cout << "Enter a string: ";
	cin >> a;

	// Sort!! in reverse order.
	int largest = a[0];
	int largestIndex = 0;
	int aLength = a.length();
	cout << endl << aLength;
	int temp;	// For swapping values

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

	cout << endl << a;
	return 0;
}
