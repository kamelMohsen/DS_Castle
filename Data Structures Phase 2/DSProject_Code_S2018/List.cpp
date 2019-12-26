#include "List.h"



List::List()
{
	Count = 0;
	head = nullptr;
}


bool List::isEmpty() const
{
	return Count == 0;
}


int List::getLength() const
{
	return Count;
}

bool List::insert(Enemy * item)
{

	if (Count == 300)
		return false;

	
	
		Node * NewNode = new Node(item);
		NewNode->setNext(head);
		head = NewNode;
		Count += 1;
		return true;
	
	
}


bool List::remove(int pos)
{
	if (pos<1 || pos > Count)
		return false;
	else if (Count == 1 && pos==1)
	{
		clear();
		return true;
	}
	else if (pos == 1 && Count>1)
	{
		head = head->getNext();
		Count -= 1;
	}
	else if (pos == Count)
	{
		Node*Temp;
		Temp = head;
		int c = 2;
		while (Temp != nullptr)
		{

			if (pos == c)
			{
				
				Temp->setNext(nullptr);
				Count -= 1;
				return true;
			}
			Temp = Temp->getNext();
			c += 1;
		}
	}
	else if (Count != 1)
	{
		Node*Temp;
		Temp = head;
		int c = 2;
		while (Temp != nullptr)
		{

			if (pos == c )
			{
				Node *temp1 = Temp->getNext();
				Temp->setNext(temp1->getNext());
				Count -= 1;
				return true;
			}
			Temp = Temp->getNext();
			c += 1;
		}



	}
}

void List::clear()
{
	head = nullptr;
	Count = 0;
}


Enemy * List::getEntry(int pos)
{
	if (Count == 0)
	{
		return 0;
	}
	Node*Temp;
	Temp = head;
	int c = 1;
	while ( !isEmpty() && Temp != nullptr )
	{

		if (pos == c)
		{

			return Temp->getItem();
		}
		Temp = Temp->getNext();
		c += 1;
	
	}
	

}


void List::setEntry(int pos, Enemy* item)
{

	Node*Temp;
	Temp = head;
	int c = 1;

	while (!isEmpty() && Temp != nullptr)
	{

		if (pos == c)
		{

			Temp->setItem(item);
		}
		Temp = Temp->getNext();
		c += 1;
	}

}


void List::sort()
{
	Enemy*temp;
	bool sorted;
	for (int i = 0; i < Count-1; i++)
	{
		sorted = true;
			for (int n = i; n < Count-1;n++)
			{
				if (getEntry(n+1)->GetPr()<getEntry(n+2)->GetPr())
				{
					temp = getEntry(n + 2);
					setEntry(n + 2, getEntry(n + 1));
					setEntry(n + 1, temp);
					sorted = false;
				}



			}
			if (sorted)
				break;
		
	}
}



List::~List()
{
}

