#include <iostream>
#include <string>
using namespace std;
// Hyunwook Jung
// 05 07 2019
// COMSC 165
// Diablo Valley College
/*Use a stack to reverse a word. 
A user enters a word and the reverse of the word is printed out using a stack.*/

const int SIZE = 20;

class Word
{
private:
	char charArray[SIZE];
	int top;
public:
	Word(string lastWord)
	{
		top = -1;
		int stringLength = lastWord.length();
		for (int count = 0; count < stringLength; count++)
		{
			push(lastWord[count]);
		}
		cout << endl << endl;
		cout << "============================================" << endl;
		display();
	}
	~Word()
	{
	}
	void push(char C);
	void display();
};
void Word::push(char C)
{
	// empty case first!!
	if (top == -1)
	{
		top = 0;
		charArray[0] = C;
	}
	else
	{
		top++;
		charArray[top] = C;
	}
}

void Word::display()
{
	// Display in a reverse order until top becomes -1
	while (top > -1)
	{
		cout << charArray[top];
		top--;
	}
}
int main()
{
	cout << "What is your last word?" << endl;
	string lastWord;
	getline(cin, lastWord);
	cout << lastWord;
	// -> String input Test Done.

	Word Hello(lastWord);
	return 0;
}