#include "BellmanFord.h"
#include "TopologicalSort.h"
#include "DijkstraAlgo.h"

void TEST_BELLMAN()
{
	std::vector<BellmanFord::Edge> edges = {
{0, 1, -1},
{0,2,4},
{1,2,3},
{1,3,2},
{1,4,2},
{3,2,5},
{3,1,1},
{4,3,-3},
	};

	BellmanFord::Graph gh;
	gh.setEdges(edges);

	gh.setNumberOfVertices(5);
	gh.setNumberOfEdges(8);

	gh.BellmanFord(0);

	std::vector<int> d = gh.distanceFromSource();

	bool isNegativeCycle = gh.IsNegativeCycleFound();


	TopologicalSort::Graph tgh;
	tgh.setVertex(6);
	tgh.addEdge(5, 2);
	tgh.addEdge(5, 0);
	tgh.addEdge(4, 0);
	tgh.addEdge(4, 1);
	tgh.addEdge(2, 3);
	tgh.addEdge(3, 1);

	tgh.TopologicalSort();
	tgh.Print();
}

int main()
{
	Dijkstra dgraph;

	dgraph.AddEdge("A", "C", 6);
	dgraph.AddEdge("C", "F", 1);
	dgraph.AddEdge("C", "E", 4);
	dgraph.AddEdge("A", "B", 1);
	dgraph.AddEdge("B", "E", 3);
	dgraph.AddEdge("B", "D", 4);

	dgraph.Run("A");

	auto var = dgraph.Result();

	return 0;
}