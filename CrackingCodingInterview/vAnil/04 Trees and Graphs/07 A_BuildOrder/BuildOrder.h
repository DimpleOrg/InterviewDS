#pragma once
#include <iostream>
#include <string>
#include <set>
#include <unordered_map>

template <typename T>
class BuildOrder
{
public:
	void insertVertex(std::string V)
	{
		vertices.push_back(V);
	}
	void insertVertices(std::vector<std::string> vList) {
		for (auto val : vList)
		{
			vertices.push_back(val);
		}
	}
	void addEdge(std::string src, std::string dest) {
		adjList[src].push_back(dest);
	}

	std::vector<std::string> getBuildOrder()
	{	
		buildOrder.clear();
		for (auto val : vertices) {
			if (isVisited.find(val) == isVisited.end())
			{
				std::set<std::string> detectCycle;
				toplogicalSort(detectCycle, val);
			}
		}
		return buildOrder;
	}
private:
	std::set<std::string> isVisited;
	std::vector<std::string> vertices;
	std::unordered_map<std::string, std::vector < std::string >> adjList;
	std::vector<std::string> buildOrder;

	void toplogicalSort(std::set<std::string> &cycleTrack, std::string src)
	{
		
		cycleTrack.insert(src);

		isVisited.insert(src);
		for (auto val : adjList[src])
		{
			if (cycleTrack.find(val) != cycleTrack.end())
				throw "Cyclic Dependency Detected";

			if (isVisited.find(val) == isVisited.end())
			{
				toplogicalSort(cycleTrack, val);
			}
		}
		buildOrder.push_back(src);
	}
};


