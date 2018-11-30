#include "BFS.h"

void getInput()
{
	std::vector<int> adj[10];
	int x, y, nodes, edges;
	std::cout << "\nEnter number of nodes: ";
	std::cin >> nodes;
	std::cout << "\nEnter number of edges: ";
	std::cin >> edges;

	std::cout << "\nEnter vertices for existing edges \n";
	for (int i = 0; i < edges; i++)
	{
		std::cin >> x;
		std::cin >> y;
		adj[x].push_back(y);
	}

	std::cout << "\nDoing Breadth First Search: ";
	bfs(0, adj);
	
	std::cout << "\n\nDepth First Search: \n";
	dfs(0, adj);
	
	std::cout << "\n\nDepth First Search Recursive: \n";
	dfsRecursive(0, adj);
}

void bfs(int s, std::vector<int> adj[])
{
	std::cout << "\n";
	bool isVisited[10] = {false};
	int level[10];
	std::queue<int> q;
	q.push(s);
	level[s] = 0;
	isVisited[s] = true;
	while (!q.empty())
	{
		int temp = q.front();
		std::cout << temp <<"\t";
		q.pop();
		for (int i = 0; i < adj[temp].size(); i++)
		{
			if(isVisited[adj[temp][i]]==false)
			{
				q.push(adj[temp][i]);
				level[adj[temp][i]] = temp + 1;
				std::cout << "\n";
				isVisited[adj[temp][i]] = true;
			}
		}
	}
}

int main()
{
	getInput();
}

void dfs(int s, std::vector<int> adj[])
{

	std::stack<int> st;
	bool isVisited[10] = { false };
	st.push(s);
	isVisited[s] = true;

	while (!st.empty())
	{
		int temp = st.top();
		st.pop();
		std::cout << temp << "\t";
		for (int i = 0; i < adj[temp].size(); i++)
		{
			if (isVisited[adj[temp][i]] == false)
			{
				st.push(adj[temp][i]);
				isVisited[adj[temp][i]] = true;
				
			}
		}
	}
}

void dfsRecursive(int s, std::vector<int> adj[])
{
	static bool isVisited[10] = { false };
	isVisited[s] = true;
	std::cout << s << "\t";
	for (int i = 0; i < adj[s].size(); i++)
	{
		if (isVisited[adj[s][i]] == false)
			dfsRecursive(adj[s][i], adj);
	}
	
}