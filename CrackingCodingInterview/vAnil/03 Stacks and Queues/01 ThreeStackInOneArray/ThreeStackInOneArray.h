#pragma once
#ifndef __THREE_STACK_IN_ONE_ARRAY_
#define __THREE_STACK_IN_ONE_ARRAY_
#include <iostream>
#include<tuple>

template <typename E>
class ThreeStack
{
	std::unique_ptr<E[]> stackData;
	std::unique_ptr<int[]> topOfStack;
	std::unique_ptr<int[]> nextIndex;
					
	int arrayLen, numStacks;
	int nextAvailable;
	
public:
	ThreeStack(int numStacks = 3, int arrayLen =30);

	bool isFull() { return (nextAvailable == -1); }

	void push(int sn, E item);

	E pop(int sn);

	bool isEmpty(int sn) { return (topOfStack[sn] == -1); }
};


template<typename E>
inline ThreeStack<E>::ThreeStack(int k1, int n1)
{
	if (k1 < 1 || n1 < 1)
		throw new std::exception("Invalid Input");

	numStacks = k1, arrayLen = n1;
	
	stackData = std::make_unique<E[]>(arrayLen);

	topOfStack = std::make_unique<int[]>(numStacks);
	nextIndex = std::make_unique<int[]>(arrayLen);

	for (int i = 0; i < numStacks; i++)
		topOfStack.get()[i] = -1;

	nextAvailable = 0;
	
	for (int i = 0; i < arrayLen - 1; i++)
		nextIndex.get()[i] = i + 1;
	nextIndex.get()[arrayLen - 1] = -1;
}

template<typename E>
inline void ThreeStack<E>::push(int sn, E item)
{
	if (isFull())
	{
		throw new std::exception("Stack Overflow");	
	}

	int i = nextAvailable;  

	nextAvailable = nextIndex.get()[i];

	nextIndex.get()[i] = topOfStack.get()[sn];
	topOfStack.get()[sn] = i;

	stackData.get()[i] = item;
}

template<typename E>
inline E ThreeStack<E>::pop(int sn)
{
	if (isEmpty(sn))
	{
		throw new std::exception("Stack Underflow");
	}

	int i = topOfStack.get()[sn];
	topOfStack.get()[sn] = nextIndex.get()[i];
	nextIndex.get()[i] = nextAvailable;
	nextAvailable = i;

	return stackData.get()[i];
}

#endif //__THREE_STACK_IN_ONE_ARRAY_
