#pragma once
#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>

using HEAPNODE = std::pair<std::string, size_t>;

class MinHeap
{
private:
	std::vector<HEAPNODE> minHeap;
	std::unordered_map<std::string, size_t> lookup;

	void heapify_up(size_t index);
	void heapify_down(size_t index);

public:
	MinHeap() = delete;
	MinHeap(std::string startV, std::vector<std::string> graphNodes);
	//void push(HEAPNODE in);
	void pop();
	HEAPNODE top();
	void update(std::string V, size_t newVal);
	bool empty() {
		return minHeap.empty();
	}

	size_t LeftChild(size_t index)
	{
		return (2 * index) + 1;
	}
	size_t RightChild(size_t index)
	{
		return (2 * index) + 2;
	}
	size_t Parent(size_t index)
	{
		if (index == 1 || index == 0)
			return 0;
		else
			return (index - 1) / 2;
	}
};

class Dijkstra
{
private:	
	std::unordered_map<std::string, std::vector<std::pair<std::string, size_t>>> graph;
	std::unordered_map<std::string, size_t> distanceMap;

	void relaxEdge(MinHeap& heap, std::string& start, std::pair<std::string, size_t>& end);
public:
	void AddEdge(std::string first, std::string second, size_t dist);
	void Run(std::string startV);
	std::unordered_map<std::string, size_t> Result();
};