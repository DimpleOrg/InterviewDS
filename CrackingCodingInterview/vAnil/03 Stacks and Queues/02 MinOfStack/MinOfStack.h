#pragma once
#include <iostream>

template <typename T>
class StackMin
{
private:
	struct Element
	{
		T data;
		int minIndex;
	};

	std::unique_ptr<Element[]> arr;

	int top = -1;
	int maxSize = 10;
	int minIndex = 0;
public:

	StackMin(int size = 10)
	{
		maxSize = size;

		arr = std::make_unique<Element[]>(maxSize);
	}

	void push(T data)
	{
		if (top + 1 < maxSize)
		{
			++top;
			arr.get()[top].data = data;

			if (data < arr.get()[minIndex].data)
				minIndex = top;

			arr.get()[top].minIndex = minIndex;
		}
		else
		{
			throw new std::exception("Stack Overloaded");
		}
	}

	T pop()
	{
		if (top > -1)
		{
			return arr.get()[top--];
		}
		else
		{
			throw new std::exception("Stack Underflow");
		}
	}

	T min()
	{
		if (top > -1)
		{
			int curMin = arr.get()[top].minIndex;

			return arr.get()[curMin].data;
		}
		else
		{
			throw new std::exception("Stack Underflow");
		}
	}
};