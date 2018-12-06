#pragma once
#ifndef __GRAPH_H_
#define __GRAPH_H_

#include <iostream>
#include <vector>

namespace BellmanFord
{

	struct Edge
	{
		int source;
		int dest;
		int weight;
	};

	class Graph
	{
	public:
		void setNumberOfVertices(int num)
		{
			V = num;
		}
		void setNumberOfEdges(int num)
		{
			E = num;
		}

		void setEdges(const std::vector<Edge>& val)
		{
			edges = val;
		}
		std::vector<int> distanceFromSource()
		{
			return distance;
		}

		void BellmanFord(int source);
		void RelaxEdge(const Edge &e);
		bool IsNegativeCycleFound() {
			return negativeCycleFound;
		}

	private:
		int V;
		int E;

		bool negativeCycleFound = false;

		std::vector<Edge> edges;
		std::vector<int> distance;
	};
}


#endif //__GRAPH_H
