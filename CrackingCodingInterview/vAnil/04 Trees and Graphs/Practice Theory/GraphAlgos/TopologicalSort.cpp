#include "TopologicalSort.h"
using namespace TopologicalSort;

void TopologicalSort::Graph::addEdge(int src, int dest)
{
	adjList[src].push_back(dest);
}

void Graph::DFS(int src)
{
	isVisited[src] = true;

	for (auto val : adjList[src])
	{
		if (!isVisited[val])
		{
			DFS(val);
		}
	}

	st.push(src);	
}

void Graph::TopologicalSort()
{
	for (int i = 0; i < V; i++)
		isVisited.push_back(false);

	for (int i = 0; i < V; i++)
	{
		if (!isVisited[i])
		{
			DFS(i);
		}
	}
}

void Graph::Print()
{
	std::cout << "\nTopological Sort:\n";
	while (!st.empty())
	{
		std::cout << st.top() << "\t";
		st.pop();
	}
}
