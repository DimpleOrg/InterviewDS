// BFS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>


using namespace std;

vector<int> graphAdjList[10];
bool isVisited[10] = {false};
int vertices;
int edges;


//undirected graph
void AdjacencyListGraph()
{
	for (int i = 0; i < edges; i++)
	{
		int x, y;
		cout << "\nEnter edge vertices";
		cout << "\n Vertex1:";
		cin >> x;
		cout << "\n Vertex2:";
		cin >> y;

		graphAdjList[x].push_back(y);
		graphAdjList[y].push_back(x);
	}
}

void BFS(int s)
{
	queue<int> q;

	q.push(s);
	isVisited[s] = true;

	while (!q.empty())
	{
		int cur = q.front();
		cout << cur << endl;
		
		q.pop();

		for (int i = 0; i < graphAdjList[cur].size(); i++)
		{
			if (!isVisited[graphAdjList[cur][i]])
			{
				q.push(graphAdjList[cur][i]);
				isVisited[graphAdjList[cur][i]] = true;
			}
		}
	}
}





int main()
{
	cout << "\nInput Number of vertices (max:10):";
	cin >> vertices;
	cout << "\nInput Number of edges:";
	cin >> edges;

	AdjacencyListGraph();

	BFS(1);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
