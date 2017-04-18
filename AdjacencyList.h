#pragma once
#include <iostream>
using namespace std;

class AdjacencyList;

struct Node {

	string name;
	int color = -1;
	int d = INTMAX_MAX;
	AdjacencyList * parent;

	Node(string name);
};


struct PtrListNode {
	AdjacencyList * adjacencyList;
	PtrListNode * next;
	Node * node;

	PtrListNode(AdjacencyList * adjacencyList);
};

struct ListNode {
	PtrListNode* next;
	Node * node;

	ListNode(Node* node);
};

class AdjacencyList
{
	private:
		ListNode * l;
		int numberOfChildren = 0;
	public:
		AdjacencyList(string name);
		~AdjacencyList();
		void addNode(AdjacencyList * adjacencyList);
		string getMainName();
		ListNode* getPtrToMainNode();
		void setColor(int color);
		int getColor();
		void setDistance(int d);
		int getDistance();
		void setParent(AdjacencyList* parent);
		AdjacencyList* getParent();
		int getNumberOfChildren();
};

