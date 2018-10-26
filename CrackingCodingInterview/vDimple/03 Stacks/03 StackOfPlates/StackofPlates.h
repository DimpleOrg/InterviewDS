#pragma once
#ifndef __STACK_OF_PLATES_
#define __STACK_OF_PLATES_

#include<iostream>
#include<vector>
#include<iterator>

template<typename T>
class stackOfPlates
{
	size_t capacity;
	int top = -1;
	T* arr=nullptr;
	std::vector<T*> vec;

public:
	stackOfPlates(int n=10) : capacity(n) {}
	void push(T elem);
	T peek();
	void pop();
	void print();
	~stackOfPlates();
};

template<typename T>
inline void stackOfPlates<T>::push(T elem)
{
	if (top == capacity - 1)
	{
		vec.push_back(arr);
		top = -1;
	}

	if ((top == -1) || (top == capacity - 1))
		arr = new T[capacity];
	
	arr[++top] = elem;
}

template<typename T>
inline T stackOfPlates<T>::peek()
{
	if(top==-1)
		throw std::exception("\nStack Empty");

	return arr[top];

	return T();
}

template<typename T>
inline void stackOfPlates<T>::pop()
{
	if (top == -1)
		throw std::exception("\nStack Empty");

	if (arr != nullptr)
	{
		--top;
		
		if (top == -1)
		{
			if (vec.size() > 0)
				top = capacity - 1;

			delete[] arr;
			arr = nullptr;
		}

		return;
	}

	if ((top > 0) && (top < capacity))
	{
		--top;
		return;
	}

	if (top == 0)
	{
		if (vec.size() > 1)
			top = capacity - 1;
		else
			--top;
		
		delete[] vec[vec.size() - 1];
		vec.erase(vec.end() - 1);
		
	}
}

template<typename T>
inline void stackOfPlates<T>::print()
{
	if (top > -1)
	{

		for (auto it=vec.begin(); (it+1)!= vec.end();it++)
		{
			for (auto i = 0; i < capacity; i++)
			{
				std::cout << (*it)[i] << "\t";
			}
			std::cout << "\n";
		}
		T* ptr = vec.back();
		int count = arr == nullptr ? top : capacity - 1;
		for (auto i = 0; i <= count; i++)
		{
			std::cout << ptr[i] << "\t";
		}

		std::cout << "\n";

		if (arr != nullptr)
		{
			for (auto i = 0; i <= top; i++)
			{
				std::cout << arr[i] << "\t";
			}
		}
	}
}

template<typename T>
inline stackOfPlates<T>::~stackOfPlates()
{
	int i = 0;
	for (auto each : vec)
	{
		std::cout << "\ndestroying array at index " << ++i;
		delete[] each;
	}
	if (arr != nullptr)
	{
		std::cout << "\ndestroying array out of stack";
		delete[] arr;
	}
}

#endif