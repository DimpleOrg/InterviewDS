#pragma once
#ifndef __A_STACKS_OF_PLATES_
#define __A_STACKS_OF_PLATES_
#include <vector>
#include <iostream>

template <typename T>
class StacksOfPlates
{
public:
	void push(T input);
	void pop();
	T peek();
	void subStackPop(int index);

	StacksOfPlates(int subStackSizeVal = 10): subStackSize(subStackSizeVal){}

private:
	int subStackSize;
	std::vector<std::vector<T>> sVector;
};

template<typename T>
inline void StacksOfPlates<T>::push(T input)
{
	if (sVector.empty())
	{
		sVector.push_back(std::vector<T>());
	}

	std::vector<T> &subStack = sVector.back();

	if (subStack.size() < subStackSize)
	{
		subStack.push_back(input);
	}
	else
	{
		std::vector<T> newSubStack;
		newSubStack.push_back(input);
		sVector.push_back(newSubStack);
	}
}


template<typename T>
inline void StacksOfPlates<T>::pop()
{
	if (sVector.empty())
	{
		throw std::exception("Stack Underflow");
	}

	std::vector<T> &subStack = sVector.back();

	if (subStack.size() == 1)
	{
		subStack.pop_back();
		sVector.pop_back();
	}
	else
	{
		subStack.pop_back();
	}
}

//starting from 0 
template<typename T>
inline void StacksOfPlates<T>::subStackPop(int index)
{
	if (index > sVector.size() - 1 || index < 0)
	{
		throw std::exception("This index substack do not exist.");
	}
	else
	{
		std::vector<T> &subStack = sVector[index];
		subStack.pop_back();
	}
}

template<typename T>
inline T StacksOfPlates<T>::peek()
{
	if (sVector.empty())
	{
		throw std::exception("Stack Underflow");
	}

	std::vector<T> &subStack = sVector.back();

	return subStack.back();
}

#endif // !__A_STACKS_OF_PLATES_
