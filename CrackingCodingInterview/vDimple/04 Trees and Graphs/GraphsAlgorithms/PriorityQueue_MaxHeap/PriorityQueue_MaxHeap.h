#pragma once
//#ifdef PRIORITYQUEUEMAXHEAP_EXPORTS
//#define PRIORITYQUEUEMAXHEAP_API __declspec(dllexport)
//#else
//#define PRIORITYQUEUEMAXHEAP_API __declspec(dllimport)
//#endif // PRIORITYQUEUEMAXHEAP_EXPORTS

#include<iostream>
#include<vector>

template<typename T>
class MaxHeap
{
private:
	std::vector<T> arr;

public:
	size_t Parent(size_t i)
	{
		return (i - 1) / 2;
	}
	size_t Left(size_t i)
	{
		return (2 * i) + 1;
	}
	size_t Right(size_t i)
	{
		return (2 * i) + 2;
	}

	void heapify_up(size_t i);
	void heapify_down(size_t i);
	void push(T i);
	void pop();
	size_t top();
};

template<typename T>
void MaxHeap<T>::heapify_up(size_t i)
{
	int parent = Parent(i);
	if ((parent >= 0) && (arr[parent] < arr[i]))
	{
		std::swap(arr[parent], arr[i]);
		heapify_up(parent);
	}
}

template<typename T>
void MaxHeap<T>::heapify_down(size_t i)
{
	size_t lc = Left(i);
	size_t rc = Right(i);
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

template<typename T>
void MaxHeap<T>::push(T i)
{
	arr.push_back(i);
	int index = arr.size() - 1;
	heapify_up(index);
}

template<typename T>
void MaxHeap<T>::pop()
{
	if (arr.size() == 0)
		throw("No Elements to pop.");

	std::swap(arr[arr.size() - 1], arr[0]);
	std::vector<int>::iterator it = arr.begin() + arr.size() - 1;
	arr.erase(it);
	if (arr.size() > 0)
		heapify_down(0);
}

template<typename T>
size_t MaxHeap<T>::top()
{
	if (arr.size() == 0)
		throw("No Elements in Heap/Queue");

	return arr.at(0);
}
