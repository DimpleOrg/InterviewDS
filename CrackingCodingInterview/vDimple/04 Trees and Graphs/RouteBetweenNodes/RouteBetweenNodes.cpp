#include "RouteBetweenNodes.h"

ROUTEBETWEENNODES_API bool rootBetweenNodes(int src, int dest, std::vector<std::vector<int>> adj)
{
	std::vector<bool> isVisited;
	for (int i = 0; i < adj.size(); i++)
	{
		isVisited.push_back(false);
	}

	bool flag = false;
	std::queue<int> qu;
	qu.push(src);
	isVisited[src] = true;
	while (!qu.empty())
	{
		int var = qu.front();
		qu.pop();
		for (int i = 0; i < adj[var].size(); i++)
		{
			if (adj[var][i] == dest)
			{
				flag = true;
				break;
			}
			if (isVisited[adj[var][i]] == false)
			{
				qu.push(adj[var][i]);
				isVisited[adj[var][i]] = true;
			}
		}
		if (flag == true)
			return true;
	}

	return flag;
}
