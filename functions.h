#pragma once
#include "AdjacencyList.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <unordered_map>
#include <queue>

AdjacencyList* BFS(vector<AdjacencyList*> adjacencyLists, unordered_map<string, int> &mapKeys, string start, string end);

void goPath(AdjacencyList* adjacencyList);