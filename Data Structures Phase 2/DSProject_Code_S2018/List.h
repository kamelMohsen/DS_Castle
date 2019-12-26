#pragma once
#include "Node.h"
class List
{
	int Count;
	Node *head;
public:
	List();
	bool isEmpty() const;
	int getLength() const;
	bool insert( Enemy * item);
	bool remove(int pos);
	void clear();
	Enemy * getEntry(int pos);
	void setEntry(int pos, Enemy * item);
	void sort();
	~List();
};

