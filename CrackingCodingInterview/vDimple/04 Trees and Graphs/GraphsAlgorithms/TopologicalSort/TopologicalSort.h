#pragma once
#ifdef TOPOLOGICALSORT_EXPORTS
#define TOPOLOGICALSORT_API __declspec(dllexport)
#else
#define TOPOLOGICALSORT_API __declspec(dllimport)
#endif
#include<iostream>
#include<vector>
#include<stack>

class TOPOLOGICALSORT_API TopologicalSort
{
public:
	TopologicalSort() = default;
	TopologicalSort(int v) : noOfVertices(v) 
	{
		adj.resize(noOfVertices);
	}
	void dfs(int src);
	void topologicalSorting();
	void addEdge(int src, int dest);
	void print();

private:
	int noOfVertices;
	std::vector<std::vector<int>> adj;
	std::vector<bool> isVisited;
	std::stack<int> sortedOrder;
};

