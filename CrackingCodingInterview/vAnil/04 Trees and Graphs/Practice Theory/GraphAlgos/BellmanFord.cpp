#include "BellmanFord.h"

using namespace BellmanFord;

void Graph::BellmanFord(int source)
{

	for (int i = 0; i < V; i++)
	{
		distance.push_back(INT32_MAX);
	}
	distance[source] = 0;

	for (int i = 1; i < V; i++)
	{
		for (auto edge : edges)
		{
			RelaxEdge(edge);
		}
	}

	negativeCycleFound = false;
	for (auto e : edges)
	{
		if (distance[e.source] != INT32_MAX
			&& distance[e.source] + e.weight < distance[e.dest])
		{
			negativeCycleFound = true;
			break;
		}
	}
}

void Graph::RelaxEdge(const Edge & e)
{
	if (distance[e.source] != INT32_MAX
		&& distance[e.source] + e.weight < distance[e.dest])
	{
		distance[e.dest] = distance[e.source] + e.weight;
	}
}
