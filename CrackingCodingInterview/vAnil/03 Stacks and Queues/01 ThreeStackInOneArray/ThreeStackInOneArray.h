#pragma once
#ifndef __THREE_STACK_IN_ONE_ARRAY_
#define __THREE_STACK_IN_ONE_ARRAY_
#include <iostream>
#include<tuple>

template <typename E>
class ThreeStack
{
	std::unique_ptr<E[]> stackData;
	int *topOfStack = nullptr;  
	int *nextIndex = nullptr;  
				
	int arrayLen, numStacks;
	int nextAvailable;
	
public:
	ThreeStack(int numStacks = 3, int arrayLen =30);

	bool isFull() { return (nextAvailable == -1); }

	void push(E item, int sn);

	E pop(int sn);

	bool isEmpty(int sn) { return (topOfStack[sn] == -1); }

	~ThreeStack() {
		delete[] topOfStack;
		delete[] nextIndex;
	}
};


template<typename E>
inline ThreeStack<E>::ThreeStack(int k1, int n1)
{
	numStacks = k1, arrayLen = n1;
	
	stackData = std::make_unique<E[]>(arrayLen);

	topOfStack = new int[numStacks];
	nextIndex = new int[arrayLen];

	for (int i = 0; i < numStacks; i++)
		topOfStack[i] = -1;

	nextAvailable = 0;
	
	for (int i = 0; i < arrayLen - 1; i++)
		nextIndex[i] = i + 1;
	nextIndex[arrayLen - 1] = -1;  
}

template<typename E>
inline void ThreeStack<E>::push(E item, int sn)
{
	if (isFull())
	{
		throw new std::exception("Stack Overflow");	
	}

	int i = nextAvailable;  

	nextAvailable = nextIndex[i];

	nextIndex[i] = topOfStack[sn];
	topOfStack[sn] = i;

	stackData.get()[i] = item;
}

template<typename E>
inline E ThreeStack<E>::pop(int sn)
{
	if (isEmpty(sn))
	{
		throw new std::exception("Stack Underflow");
	}

	int i = topOfStack[sn];
	topOfStack[sn] = nextIndex[i];   
	nextIndex[i] = nextAvailable;
	nextAvailable = i;

	return stackData.get()[i];
}

#endif //__THREE_STACK_IN_ONE_ARRAY_
