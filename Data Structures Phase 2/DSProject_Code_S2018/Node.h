#pragma once
#include "Enemies\Enemy.h"

class Node
{
private:
	Enemy*  item; 
	Node * next; 
public:
	Node();
	Node(Enemy * anItem);
	Node( Enemy * anItem, Node * nextNodePtr);
	void setItem(Enemy * anItem);
	void setNext(Node * nextNodePtr);
    Enemy * getItem() const;
	Node * getNext() const;
}; 

