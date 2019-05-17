#include <iostream>
#include <stack>
#include <iomanip>
using namespace std;
// 05 17 2019
// Hyunwook Jung
// Diablo Valley College 
// COMSC 165
// LAB 21
/*Implement a queue data structure using two stacks. 
Remember a queue has enqueue and dequeue functions.

You could use either the array or linked list implementation 
for stacks and queues.

Note I went through both array and linked list implementation 
for stacks and queues in class this week. 
The source code implementations are available under the Canvas directory: 
Files->stacks_queues.*/

struct Queue
{
	stack<int> sDeq, sEnq;
	int total = 0;
	void enqueue(int input)
	{
		sEnq.push(input);
		total++;
	}

	int dequeue()
	{
		if (sDeq.empty())
		{
			cout << "Feeling the dequeue stack..." << endl;

			while (!sEnq.empty())
			{
				sDeq.push(sEnq.top());
				sEnq.pop();
			}
		}

		int temp = sDeq.top();
		sDeq.pop();
		total--;
		return temp;
	}
};

void display(Queue Q)
{
	int curIndex = Q.total;
	for (int count = 0; count < curIndex; count++)
	{
		cout << count << setw(6) << Q.dequeue() << endl;
	}
}
int main()
{
	Queue Q;
	Q.enqueue(99);
	Q.enqueue(91);
	Q.enqueue(9);
	Q.enqueue(6);
	Q.dequeue();
	Q.enqueue(0);
	display(Q);
	cout << endl << "Total elements: " << Q.total << endl;

	return 0;
}