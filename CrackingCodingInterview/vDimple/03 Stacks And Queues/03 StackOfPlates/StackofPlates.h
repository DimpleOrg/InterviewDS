#pragma once
#ifndef __STACK_OF_PLATES_VECTOR_OF_ARRAY_
#define __STACK_OF_PLATES_VECTOR_OF_ARRAY_

#include<iostream>
#include<vector>
#include<iterator>

namespace stackOfPlatesVOA
{
	template<typename T>
	class stackOfPlates
	{
		size_t capacity;
		int top = -1;
		T* arr = nullptr;
		std::vector<T*> vec;

	public:
		stackOfPlates(int n = 10) : capacity(n) {}
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
		if (top == -1)
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

			for (auto it = vec.begin(); (it + 1) != vec.end(); it++)
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
}
#endif

#ifndef  __STACK_OF_PLATES_VECTOR_OF_VECTOR_
#define __STACK_OF_PLATES_VECTOR_OF_VECTOR_

#include<iostream>
#include<vector>
#include<iterator>

namespace stackOfPlatesVOV
{

	template<typename T>
	class stackOfPlates
	{
		size_t capacity;
		std::vector<std::vector<T>> vec;
	public:
		stackOfPlates(size_t n = 10) : capacity(n) {}
		void push(T elem);
		T top();
		void pop();
		void popFromSubStack(size_t n);
		void print() const;
	};

	template<typename T>
	inline void stackOfPlates<T>::push(T elem)
	{
		if (vec.empty())
		{
			vec.push_back(std::vector<T>());
		}
		std::vector<T> &subvec = vec.back();

		if (subvec.size() == capacity)
		{
			std::vector<T> temp;
			temp.push_back(elem);
			vec.push_back(temp);
		}
		else
			subvec.push_back(elem);
	}

	template<typename T>
	inline T stackOfPlates<T>::top()
	{
		if (vec.empty())
			throw std::exception("Stack is Empty");

		std::vector<T> &subvec = vec.back();
		return subvec.back();
	}

	template<typename T>
	inline void stackOfPlates<T>::pop()
	{
		if (vec.empty())
			throw std::exception("Stack is Empty");

		std::vector<T> &subvec = vec.back();
		subvec.pop_back();
		if (subvec.empty())
			vec.pop_back();
	}

	template<typename T>
	inline void stackOfPlates<T>::popFromSubStack(size_t n)
	{
		std::vector<T> &substack = vec.at(n-1);	// vec.at() checks for out of bounds error while vec[n-1] does not.
		substack.pop_back();
		
	}

	template<typename T>
	inline void stackOfPlates<T>::print() const
	{
		for (auto &each : vec)
		{
			for (auto &item : each)
			{
				std::cout << item << "\t";
			}
			std::cout << "\n";
		}
	}

}
#endif

