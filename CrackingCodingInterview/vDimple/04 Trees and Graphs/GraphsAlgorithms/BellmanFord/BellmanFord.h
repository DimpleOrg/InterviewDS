#pragma once
#ifdef BELLMANFORD_EXPORTS
#define BELLMANFORD_API __declspec(dllexport)
#else
#define BELLMANFORD_API __declspec(dllimport)
#endif // BELLMANFORD_EXPORTS

#include<iostream>
#include<vector>

struct Edge
{
public:
	int source;
	int dest;
	int wt;
};

class BELLMANFORD_API GraphBellmanFord
{
public:
	GraphBellmanFord(int vertices, int edges) : v(vertices), e(edges) {}
	void setEdges(int u, int v, int weight)
	{
		Edge tempEdge;
		tempEdge.source = u;
		tempEdge.dest = v;
		tempEdge.wt = weight;
		edges.push_back(tempEdge);
	}
	void bellmanFord(int src);
	void relaxEdge(const Edge& e);
	bool isNegativeCycleFound()
	{
		return negativeCycleFound;
	}
private:
	int e, v;
	bool negativeCycleFound;
	std::vector<Edge> edges;
	std::vector<int> dist;
};