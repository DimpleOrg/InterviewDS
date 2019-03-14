#include "PriorityQueue_MaxHeap.h"

void MaxHeap::heapify_up(int i)
{
	int parent = Parent(i);
	if ((parent >=0)&& (arr[parent] < arr[i]))
	{
		std::swap(arr[parent], arr[i]);
		heapify_up(parent);
	}
}

void MaxHeap::heapify_down(int i)
{
	int lc = Left(i);
	int rc = Right(i);
	int max = i;
	
	if ((lc < arr.size() - 1) && (arr[lc] > arr[max]))
		max = lc;
	if ((rc < arr.size() - 1) && (arr[rc] > arr[max]))
		max = rc;

	if (max != i)
	{
		std::swap(arr[i], arr[max]);
		heapify_down(max);
	}
}

void MaxHeap::push(int i)
{
	arr.push_back(i);
	int index = arr.size() - 1;
	heapify_up(index);
}

void MaxHeap::pop()
{
		if (arr.size() == 0)
			throw("No Elements to pop.");

		std::swap(arr[arr.size() - 1], arr[0]);
		std::vector<int>::iterator it = arr.begin() + arr.size() - 1;
		arr.erase(it);
		if (arr.size() > 0)
			heapify_down(0);
}

int MaxHeap::top()
{
	if (arr.size() == 0)
		throw("No Elements in Heap/Queue");

	return arr.at(0);
}
