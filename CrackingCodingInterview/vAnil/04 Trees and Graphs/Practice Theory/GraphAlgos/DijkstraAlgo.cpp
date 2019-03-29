#include "DijkstraAlgo.h"
using namespace std;

void MinHeap::heapify_up(size_t index)
{
	size_t curLen = minHeap.size();
	size_t parent;

	parent = Parent(index);

	if (parent >= 0 && minHeap[parent] > minHeap[index])
	{
		swap(lookup[minHeap[parent].first],lookup[minHeap[index].first]);
		swap(minHeap[parent], minHeap[index]);
		heapify_up(parent);
	}
}

void MinHeap::heapify_down(size_t index)
{
	size_t curLen = minHeap.size();
	size_t left, right, parent, smallest;

	left = LeftChild(index);
	right = RightChild(index);
	parent = Parent(index);

	smallest = index;
	if (left < curLen && minHeap[left] < minHeap[smallest])
		smallest = left;

	if (right < curLen && minHeap[right] < minHeap[smallest])
		smallest = right;

	if (smallest != index)
	{
		swap(lookup[minHeap[smallest].first], lookup[minHeap[index].first]);
		swap(minHeap[index], minHeap[smallest]);
		heapify_down(smallest);
	}
}

MinHeap::MinHeap(std::string startV, std::vector<std::string> graphNodes)
{
	size_t index = 0;
	minHeap.push_back({startV, 0});
	lookup[startV] = index++;
	for (auto v : graphNodes)
	{
		if (startV != v) 
		{
			minHeap.push_back({ v, SIZE_MAX });
			lookup[v] = index++;
		}
	}
}

void MinHeap::pop()
{
	size_t len = minHeap.size();

	if (len != 0)
	{
		if (len == 1)
		{
			minHeap.pop_back();
			lookup.clear();
		}
		else
		{
			lookup.erase(minHeap[0].first);
			lookup[minHeap[len - 1].first] = 0;

			swap(minHeap[0], minHeap[len - 1]);
			minHeap.pop_back();
			heapify_down(0);
		}
	}
	else
	{
		throw "Empty";
	}

}

HEAPNODE MinHeap::top()
{
	if (!empty())
		return minHeap[0];
	else
		throw "Empty Heap";
}

void MinHeap::update(std::string V, size_t newVal)
{
	minHeap[lookup[V]] = { V, newVal };
	heapify_up(lookup[V]);
}




inline void Dijkstra::relaxEdge(MinHeap& heap,string& V, pair<string, size_t>& end)
{
	if (distanceMap[V] != SIZE_MAX)
	{
		size_t add = distanceMap[V] + end.second;
		if (add < distanceMap[end.first])
		{
			distanceMap[end.first] = add;
			heap.update(end.first, add);
		}
	}
}

void Dijkstra::AddEdge(string first, string second, size_t dist)
{
	graph[first].push_back({ second, dist });
	graph[second].push_back({ first, dist });
}

std::unordered_map<std::string, size_t> Dijkstra::Result()
{
	return distanceMap;
}

void Dijkstra::Run(string startV)
{
	vector<string> vlist;
	for (auto iter = graph.begin(); iter != graph.end(); iter++)
	{
		vlist.push_back((*iter).first);
		distanceMap[(*iter).first] = SIZE_MAX;
	}
	distanceMap[startV] = 0;

	MinHeap heap(startV, vlist);

	while (!heap.empty())
	{
		auto top = heap.top();
		heap.pop();

		for (auto adj = graph[top.first].begin(); adj != graph[top.first].end(); adj++)
			relaxEdge(heap, top.first, (*adj));
	}
}
