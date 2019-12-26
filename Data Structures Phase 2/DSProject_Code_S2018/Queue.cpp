#include "Queue.h"
Queue::Queue()
{
	backPtr = nullptr;
	frontPtr = nullptr;
	count = 0;

}

bool Queue::isEmpty() const
{
	if (frontPtr == nullptr)
		return true;
	else
		return false;
}


Enemy* Queue::peekFront() const 
{
	if (!isEmpty())
	{
		
		return frontPtr->getItem();
	}

}


bool Queue::enqueue( Enemy* newEntry)
{
	Node* newNodePtr = new Node(newEntry);

	if (isEmpty())
	{
		frontPtr = newNodePtr;
	}
	else
	{
		backPtr->setNext(newNodePtr);
	}
		backPtr = newNodePtr; 
		count += 1;

	return true;
} 




bool Queue::dequeue()
{
	bool result = false;
	if (!isEmpty())
	{
		
		Node* nodeToDeletePtr = frontPtr;
		if (frontPtr == backPtr)
		{
			frontPtr = nullptr;
			backPtr = nullptr;
		}
		else
			frontPtr = frontPtr->getNext();
		
		nodeToDeletePtr->setNext(nullptr);
		delete nodeToDeletePtr;
		nodeToDeletePtr = nullptr;
		result = true;
		count -= 1;
	} 
	return result;
}

int Queue::getlength()
{
	return count;
}

 

Queue::~Queue()
{
}