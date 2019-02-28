#include <iostream>
// Hyunwook Jung DVC
// 02 26 2019
using namespace std;

void swap(int&, int&);
void printing(int [], int);

int main()
{
	/*Lab 1
	Read in a list of integers from the user named "list".
	Then ask the user to enter a value "findVal" to search for.
	Output if the value appears in the list or not using linear search (as shown in the slides).

	Then run both bubble sort and selection sort on the list of numbers (as shown in the slides).
	For each sorted version of the list, use binary search to output if the "findVal" value appears on the list.
	If not, output "number not found". */

	cout << "Lab 1" << endl;
	cout << "Enter a number of integers." << endl;
	int intArray[10];
	for (int count1A = 0; count1A < 10; ++count1A)
	{
		cout << "Enter No." << (count1A + 1) << ": ";
		cin >> intArray[count1A];
	}
	cout << endl << endl;
	cout << "Enter a value to search for: ";
	int findVal;
	cin >> findVal;

	// LINEAR SEARCH START
	bool found = false;
	int searchedIndex = -1;
	for (int count1B = 0; count1B < 10; ++count1B)
	{
		if (intArray[count1B] == findVal)
		{
			found = true;
			searchedIndex = count1B;
		}
	}
	cout << endl << endl;

	if (!found)
	{
		cout << "The value you are looking for is not in the list." << endl << endl;
	}
	else if (found || searchedIndex == -1)
	{
		cout << "The value you are looking for is in the list(index: " << searchedIndex << ")" << endl << endl;
	}
	cout << "=========================================================" << endl;
	cout << "Original Array: ";
	printing(intArray, 10);
	cout << endl << endl;
	bool changed = false;
	// Bubble Sort Start
	int lowest = intArray[0];
	do
	{
		changed = false;
		for (int bubbleCount = 1; bubbleCount < 10; bubbleCount++)
		{
			if (intArray[bubbleCount - 1] > intArray[bubbleCount])
			{
				swap(intArray[(bubbleCount - 1)], intArray[(bubbleCount)]);
				changed = true;
			}
		}
		printing(intArray, 10);
		cout << endl;
	} while (changed);

	cout << "Enter a value to search for: ";
	cin >> findVal;

	int firstIndex = 0;
	int lastIndex = 9;
	int middleIndex = (lastIndex + firstIndex) / 2;
	int foundIndex;
	found = false;
	while ( firstIndex <= lastIndex && !found)
	{
		middleIndex = (firstIndex + lastIndex) / 2;
		if (intArray[middleIndex] == findVal)
		{
			found = true;
			foundIndex = middleIndex;
		}
		else if (intArray[middleIndex] > findVal)
			lastIndex = middleIndex - 1;
		else
			firstIndex = middleIndex + 1;
}
	if (!found)
		cout << endl << "Number Not Found.";
	else if (found)
		cout << endl << "Number is found at index NUM " << foundIndex << ".";

	cout << endl << endl;
	// Selection Sort Start
	int intArray2[10];
	for (int count1D = 0; count1D < 10; ++count1D)
	{
		cout << "Enter No." << (count1D + 1) << ": ";
		cin >> intArray2[count1D];
	}

	int lowest2 = intArray2[0];
	int lowestIndex = 0;
	for (int count1C = 0; count1C < 10; count1C++)
	{
		lowest2 = intArray2[count1C];
		lowestIndex = count1C;
		for (int lowestChecker = count1C; lowestChecker < 10; lowestChecker++)
		{
			if (intArray2[lowestChecker] < lowest2)
			{
				lowest2 = intArray2[lowestChecker];
				lowestIndex = lowestChecker;
			}
		}
		swap(intArray2[count1C], intArray2[lowestIndex]);
		printing(intArray2, 10);
		cout << endl;
	}
	cout << "Enter a value to search for: ";
	cin >> findVal;
	firstIndex = 0;
	lastIndex = 9;
	middleIndex = (lastIndex + firstIndex) / 2;

	bool found2 = false;
	while (firstIndex <= lastIndex && !found2)
	{
		middleIndex = (firstIndex + lastIndex) / 2;
		if (intArray2[middleIndex] == findVal)
		{
			found2 = true;
			foundIndex = middleIndex;
		}
		else if (intArray2[middleIndex] > findVal)
			lastIndex = middleIndex - 1;
		else
			firstIndex = middleIndex + 1;
	}
	if (!found2)
		cout << endl << "Number Not Found.";
	else if (found2)
		cout << endl << "Number is found at index NUM " << foundIndex << ".";
	cout << endl << endl;
	return 0;
}

void swap(int &lowValue, int &highValue)
{
	int temp;
	temp = lowValue;
	lowValue = highValue;
	highValue = temp;
}
void printing(int intArray[], int size)
{
	for (int count = 0; count < size; count++)
	{
		cout << intArray[count] << ' ';
	}/*
	for (int val : intArray)
	{
		cout << endl << val;
	}*/
}