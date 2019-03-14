#pragma once
#ifdef PRIORITYQUEUEMAXHEAP_EXPORTS
#define PRIORITYQUEUEMAXHEAP_API __declspec(dllexport)
#else
#define PRIORITYQUEUEMAXHEAP_API __declspec(dllimport)
#endif // PRIORITYQUEUEMAXHEAP_EXPORTS

#include<iostream>
#include<vector>

class PRIORITYQUEUEMAXHEAP_API MaxHeap
{
private:
	std::vector<int> arr;

public:
	int Parent(int i)
	{
		return (i - 1) / 2;
	}
	int Left(int i)
	{
		return (2 * i) + 1;
	}
	int Right(int i)
	{
		return (2 * i) + 2;
	}

	void heapify_up(int i);
	void heapify_down(int i);
	void push(int i);
	void pop();
	int top();
};