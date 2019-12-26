#include "Node.h"




Node::Node() : next(nullptr)
{
}

Node ::Node( Enemy*  anItem) : item(anItem), next(nullptr)
{
}


Node ::Node(Enemy * anItem, Node * nextNodePtr) : item(anItem), next(nextNodePtr)
{
}

void Node ::setItem( Enemy * anItem)
{
	item = anItem;
}


void Node::setNext(Node * nextNodePtr)
{
	next = nextNodePtr;
}

Enemy * Node::getItem() const
{
	return item;
}


Node * Node::getNext() const
{
	return next;
}
