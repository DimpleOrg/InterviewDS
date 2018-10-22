#pragma once
#include<iostream>


template<typename E>
class stack
{
	int top;
	int sz;

	struct data
	{
		int minimum;;
		E elem;
	};

	std::unique_ptr<data[]> arr;

public:
	stack(int n = 10)
		: top(-1), sz(n)
	{
		arr = std::make_unique<data[]>(sz);
	}
	void push(const E input);
	void pop();
	E min()
	{
		int minIndex = arr.get()[top].minimum;
		return arr.get()[minIndex].elem;
	}

	void print();
};

template<typename E>
inline void stack<E>::push(const E input)
{
	int min;

	if (top < sz-1)
	{
		if (top == -1)
			min = 0;
		else
		{
			min = arr.get()[top].minimum;
			if (arr.get()[min].elem > input)
				min = top + 1;;
		}

		arr.get()[++top].elem = input;
		arr.get()[top].minimum = min;
	}
	else
	{
		std::cout << "\n Stack Full\n";
	}
}

template<typename E>
inline void stack<E>::pop()
{
	if (top < 0)
		std::cout << "\nEmpty Stack\n";
	else
		--top;
}

template<typename E>
inline void stack<E>::print()
{
	for (int i = 0; i <= top; i++)
	{
		std::cout << "\n" << arr.get()[i].elem << "\t" << arr.get()[i].minimum;
	}
}
