#pragma once
#ifndef __ROUTE_BETWEEN_NODES_H__
#define __ROUTE_BETWEEN_NODES_H__
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>

class Graph
{
public:
	void addEdge(std::string vertex, std::pair<std::string, size_t> edge) {
		graph[vertex].push_back(edge);
	}

	bool IsRouteExist(std::string v1, std::string v2)
	{
		std::queue<std::string> bfs;

		bfs.push(v1);

		while (!bfs.empty())
		{
			auto val = bfs.front();
			bfs.pop();

			for (auto x = graph[val].begin(); x != graph[val].end(); x++)
			{
				if (visitedNodes.find((*x).first) == visitedNodes.end())
				{
					bfs.push((*x).first);
					visitedNodes.insert((*x).first);
				}

				if ((*x).first == v2)
					return true;
			}
		}

		return false;
	}

private:
	std::unordered_map<std::string, std::vector<std::pair<std::string, size_t>>> graph;
	std::unordered_set<std::string> visitedNodes;
};


#endif //__ROUTE_BETWEEN_NODES_H__
