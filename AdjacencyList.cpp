#include "AdjacencyList.h"

Node::Node(string name) {
	this->name = name;
}

ListNode::ListNode(Node * node) {
	this->node = node;
}
PtrListNode::PtrListNode(AdjacencyList * adjacencyList) {
	this->adjacencyList = adjacencyList;
}

AdjacencyList::AdjacencyList(string name) {
	l = new ListNode(new Node(name));
	l->next = NULL;
}

AdjacencyList::~AdjacencyList() {
	
}

void AdjacencyList::addNode(AdjacencyList * adjacencyList)
{
	PtrListNode * tmp;
	tmp = l->next;
	l->next = new PtrListNode(adjacencyList);
	l->next->next = tmp;
	numberOfChildren++;
}

string AdjacencyList::getMainName()
{
	return l->node->name;
}

ListNode* AdjacencyList::getPtrToMainNode()
{
	return l;
}

void AdjacencyList::setColor(int color)
{
	this->l->node->color = color;
}

int AdjacencyList::getColor()
{
	return this->l->node->color;
}

void AdjacencyList::setDistance(int d)
{
	this->l->node->d = d;
}

int AdjacencyList::getDistance()
{
	return this->l->node->d;
}

void AdjacencyList::setParent(AdjacencyList * parent)
{
	this->l->node->parent = parent;
}

AdjacencyList * AdjacencyList::getParent()
{
	return this->l->node->parent;
}

int AdjacencyList::getNumberOfChildren()
{
	return this->numberOfChildren;
}

