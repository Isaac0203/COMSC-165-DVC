#include <iostream>
#include <iomanip>

using namespace std;
// Hyunwook Jung
// 05 16 2019
// Diablo Valley College
// COMSC 165
// Lab 19

/*Design a stack in C++ that in addition to push, pop, and top functions, 
also has a min function that returns the minimum element in the entire stack. 
The stack can contain the minimum element in the top.

The purpose of having a min function is for runtime purposes, 
such that the minimum element can be retrieved quickly when needed 
(as opposed to traversing an entire linked list 
from start to end just to find the minimum object).

You can implement this by modifying the push function, 
so that each time a new element is pushed it is checked 
if the new element is less than the top or greater than the top 
(if the new element is greater than the top then the top and new are swapped).*/
const int SIZE = 5;
class Stack
{
private:
	int stackArray[SIZE];
	int top;
public:
	Stack()
	{
		top = -1;
	}
	~Stack()
	{
		// delete stackArray;
		cout << "- Stack deleted -" << endl;
	}
	void push(int);
	int pop();
	bool isEmpty();
	bool isFull();
};

void Stack::push(int newNum)
{
	if (isFull())
	{
		cout << "This stack is already full." << endl;
		return;
	}
	else if (top == -1)
	{
		top = 0;
		stackArray[0] = newNum;
	}
	else if (newNum > stackArray[top])
	{
		// If new number is larger than the current min value
		// Maintain the min value on the top and put new number under the top
		int tempTop = stackArray[top];
		stackArray[top] = newNum;
		top++;
		stackArray[top] = tempTop;
	}
	else if (top < SIZE)
	{
		top++;
		stackArray[top] = newNum;
	}
	
}
int Stack::pop()
{
	int tempInt;
	if (isEmpty())
	{
		cout << "This stack is already empty." << endl;
		return -99;
	}
	else
	{
		tempInt = stackArray[top];
		top--;
		return tempInt;
	}
}
bool Stack::isEmpty()
{
	if (top == -1)
		return true;
	else
		return false;
}
bool Stack::isFull()
{
	if (top == 4)
		return true;
	else
		return false;
}

void display(Stack S)
{
	if (S.isEmpty())
		cout << "This stack is empty." << endl;
	else
	{
		cout << "============================================" << endl;
		cout << "TOP" << setw(8) << "ELEMENT" << endl;
		int count = 0;
		while (!(S.isEmpty()))
		{
			cout << count << setw(8) << S.pop() << endl;
			count++;
		}
		cout << "============================================" << endl << endl;
	}
}
int main()
{
	Stack what;
	
	display(what);
	int menu;
	int tempInt = -999;
	do
	{
		cout << "1. push     2. pop    3. End"  << endl;
		cin >> menu;
		switch (menu)
		{
			tempInt = -999;
		case 1:
			
			cout << "Enter a number to push: " << endl;
			cin >> tempInt;
			what.push(tempInt);
			display(what);
			break;
		case 2:
			cout << what.pop() << " is removed." << endl;
			display(what);
			break;
		case 3:
			cout << "Program terminating..." << endl;
			break;
		default:
			cout << "Enter a number between 1 ~ 3." << endl;
			break;
		}
	} while (menu != 3);
	return 0;
}