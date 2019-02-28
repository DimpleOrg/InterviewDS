#include "BellmanFord.h"

void GraphBellmanFord::bellmanFord(int src)
{
	for (int i = 0; i < v; i++)
	{
		dist.push_back(INT_MAX);
	}
	dist[src] = 0;

	for (int i = 0; i < v-1; i++)
	{
		for(auto each:edges)
		relaxEdge(each);
	}

	negativeCycleFound = false;

	for (auto each : edges)
	{
		if ((dist[each.source] != INT_MAX) && 
			(dist[each.dest] > dist[each.source] + each.wt))
		{
			negativeCycleFound = true;
		}
	}
}

void GraphBellmanFord::relaxEdge(const Edge & e)
{
	if ((dist[e.source] != INT_MAX) && 
		(dist[e.dest] > dist[e.source] + e.wt))
	{
		dist[e.dest] = dist[e.source] + e.wt;
	}
}
