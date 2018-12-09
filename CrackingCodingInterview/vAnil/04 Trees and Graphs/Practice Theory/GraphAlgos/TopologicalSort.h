#pragma once
#ifndef __TOPOLOGICAL_SORT_H__
#define __TOPOLOGICAL_SORT_H__
#include <iostream>
#include <vector>
#include <stack>

namespace TopologicalSort
{
	class Graph
	{
	private:
		int V;
		std::vector < std::vector<int>> adjList;
		std::vector<bool> isVisited;
		std::stack<int> st;

	public:
		void setVertex(int num) {
			V = num;
			adjList.resize(V);
		}

		void addEdge(int src, int dest);
		void DFS(int src);
		void TopologicalSort();
		void Print();
	};
}

#endif // __TOPOLOGICAL_SORT_H__