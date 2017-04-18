#include "AdjacencyList.h"
#include "functions.h"
#include <sstream>
#include <fstream>
using namespace std;

int main()
{
	vector<AdjacencyList*> adjacencyLists;
	unordered_map<string, int> mapKeys;

	fstream file;
	file.open("database.txt");
	if (!file.is_open()) { cout << "File is not load" << endl; }
	string data;
	int i = 0;
	while (!file.eof()) {

		getline(file, data);

		if(data[0] != ' ') {
			adjacencyLists.push_back(new AdjacencyList(data));
			mapKeys.insert(make_pair(data, i));
			i++;
		}
	}
	file.seekg(0);
	i = 0;
	while (!file.eof()) {

		getline(file, data);

		if (data[0] == ' ') {
			data.erase(0, 2);
			auto search = mapKeys.find(data);
			if (search != mapKeys.end()) {
				adjacencyLists[i - 1]->addNode(adjacencyLists[search->second]);
			}
		} else {
			i++;
		}
	}

	string start, end;
	cout << "start path: " << endl;
	cin >> start;
	cout << "end path: " << endl;
	cin >> end;

	AdjacencyList* t = BFS(adjacencyLists, mapKeys, start, end);
	cout << "Path length: " << t->getDistance() << endl;
	goPath(t);

}
