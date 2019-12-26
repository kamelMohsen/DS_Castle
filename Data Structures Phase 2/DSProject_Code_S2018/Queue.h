#pragma once
#include "Node.h"



class Queue
{
private:

	Node* backPtr;
	Node* frontPtr;
	int count;
public:
	Queue();
	bool isEmpty() const;
	bool enqueue( Enemy* newEntry);
	bool dequeue();
	int getlength();
	Enemy* peekFront() const;
	~Queue();
};