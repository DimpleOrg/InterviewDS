#include "TopologicalSort.h"

void TopologicalSort::dfs(int src)
{
	isVisited[src] = true;

	for (auto each : adj[src])
	{
		if (!isVisited[each])
			dfs(each);
	}
	sortedOrder.push(src);
}

void TopologicalSort::topologicalSorting()
{
	for (int i = 0; i < noOfVertices; i++)
	{
		isVisited.push_back(false);
	}

	for (int i = 0; i < noOfVertices; i++)
	{
		if (!isVisited[i])
			dfs(i);
	}
}

void TopologicalSort::addEdge(int src, int dest)
{
	adj[src].push_back(dest);
}

void TopologicalSort::print()
{
	while(!sortedOrder.empty())
	{
		std::cout << sortedOrder.top();
		sortedOrder.pop();
	}
}
