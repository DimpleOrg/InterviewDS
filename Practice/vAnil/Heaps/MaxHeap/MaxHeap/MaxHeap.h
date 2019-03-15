#pragma once
#ifndef __MAXHEAP_H_
#define __MAXHEAP_H_

#include <iostream>
#include <vector>

template <typename T>
class MaxHeap
{
public:
	MaxHeap() = default;
	MaxHeap(const std::vector<T> &input);
	void push(const T& in);
	T pop();	
	T top();
	bool empty() {
		return heapElems.empty();
	}

private:
	void heapify_up(size_t index);
	void heapify_down(size_t index);
	void swap(T& val1, T& val2)
	{
		T val3 = val1;
		val1 = val2;
		val2 = val3;
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
	void BuildMaxHeap();
	std::vector<T> heapElems;
};

template<typename T>
inline MaxHeap<T>::MaxHeap(const std::vector<T>& input)
{
	heapElems = input;

	BuildMaxHeap();
}

template<typename T>
inline void MaxHeap<T>::push(const T & in)
{
	heapElems.push_back(in);
	heapify_up(heapElems.size() - 1);
}

template<typename T>
inline T MaxHeap<T>::pop()
{
	if (!heapElems.empty())
	{
		T val = heapElems[0];

		heapElems[0] = heapElems[heapElems.size() - 1];
		heapElems.pop_back();

		heapify_down(0);
		return val;
	}
	else
	{
		throw "Empty";
	}
	
}

template<typename T>
inline T MaxHeap<T>::top()
{
	return heapElems[0];
}

template<typename T>
inline void MaxHeap<T>::heapify_up(size_t index)
{
	size_t curLen = heapElems.size();
	size_t left, right, parent, largest;

	left = LeftChild(index);
	right = RightChild(index);
	parent = Parent(index);

	largest = index;
	if (parent >= 0 && heapElems[parent] < heapElems[index])
	{
		swap(heapElems[parent], heapElems[index]);
		heapify_up(parent);
	}
}

template<typename T>
inline void MaxHeap<T>::heapify_down(size_t index)
{
	size_t curLen = heapElems.size();
	size_t left, right, parent, largest;

	left = LeftChild(index);
	right = RightChild(index);
	parent = Parent(index);

	largest = index;
	if (left < curLen && heapElems[left] > heapElems[largest])
		largest = left;

	if (right < curLen && heapElems[right] > heapElems[largest])
		largest = right;

	if (largest != index)
	{
		swap(heapElems[index], heapElems[largest]);
		heapify_down(largest);
	}
}

template<typename T>
inline void MaxHeap<T>::BuildMaxHeap()
{
	size_t len = heapElems.size();
	size_t nonLeaf = len / 2;

	for (size_t i = nonLeaf + 1; i > 0; i--)
		heapify_down(i-1);

}


#endif // __MAXHEAP_H_
