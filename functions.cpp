#include "functions.h"

AdjacencyList* BFS(vector<AdjacencyList*> adjacencyLists, unordered_map<string, int> &mapKeys, string start, string end) {

	auto search = mapKeys.find(start);
	AdjacencyList* firstVertex = adjacencyLists[search->second];
	queue<AdjacencyList*> queue;

	firstVertex->setColor(0);
	firstVertex->setDistance(0);
	firstVertex->setParent(NULL);
	queue.push(firstVertex);

	AdjacencyList* u;
	AdjacencyList* t;
	PtrListNode * lastListNode;

	while (!queue.empty()) {
		u = queue.front();
		queue.pop();
		if (u->getMainName() == end) {
			return u;
		}
		if (u->getColor() == 0) {
			lastListNode = u->getPtrToMainNode()->next;
			for (int i = 0; i < u->getNumberOfChildren(); i++) {
				t = lastListNode->adjacencyList;
				if (t != NULL && t->getColor() == -1) {
					t->setColor(0);
					t->setDistance(u->getDistance() + 1);
					t->setParent(u);
					queue.push(t);
				}
				lastListNode = lastListNode->next;
			}
		}
		u->setColor(1);
	}

	return NULL;
}

void goPath(AdjacencyList* adjacencyList) {
	AdjacencyList* u;
	vector<string> path;
	while (adjacencyList != NULL) {
		path.push_back(adjacencyList->getMainName());
		adjacencyList = adjacencyList->getParent();
	}
	for (int i = path.size() - 1; i >= 0; i--) {
		cout << "[" << path.size() - i - 1 << "] " << path[i] << endl;
	}
}