#include "Queue.h"
#include <iostream>
using namespace std;

void initQueue(Queue* q, unsigned int size)
{
	q->array = new int[size];
	q->size = size;
	q->start = 0;
	q->end = 0;
	q->counter = 0;
}

void cleanQueue(Queue* q)
{
	int i = 0;
	for (i = 0; i < q->counter; i++)
	{
		q->array[i] = -1;
	}
}

void enqueue(Queue* q, unsigned int newValue)
{
	if (q->counter == q->size)
	{
		cout << "Queue is full" << endl;
	}
	else
	{
		//cout << q->counter << endl;
		//cout << q->end << endl;
		q->array[q->end] = newValue;
		q->end++;
		q->counter++;
	}
}

int dequeue(Queue* q)
{
	if (q->counter == 0)
	{
		cout << "Queue is empty" << endl;
		return 1;
	}
	else
	{		
		q->counter--;
		int i = 0;
		int topElement = q->array[0];
		int* tempArr = new int[q->size];
		for (i = 0; i < q->counter; i++)
		{
			tempArr[i] = q->array[i + 1];
			//cout << tempArr[i] << " ";
		}
		q->array = new int[q->size];
		for (i = 0; i < q->size; i++)
		{
			q->array[i] = tempArr[i];
			//cout << q->array[i] << " ";
		}
		cout << endl;
		q->end--;

		return topElement;
	}
}

void printQueue(Queue* q, unsigned int size)
{
	unsigned int i = 0;
	for (i = 0; i < q->counter; i++)
	{
		cout << q->array[i] << " ";
	}
}


bool isEmpty(Queue* s)
{
	if (s->counter == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool isFull(Queue* s)
{
	if (s->counter == s->size)
	{
		return true;
	}
	else
	{
		return false;
	}
}