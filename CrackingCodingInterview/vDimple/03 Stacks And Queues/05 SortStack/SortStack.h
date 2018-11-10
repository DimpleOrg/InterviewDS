#pragma once
#include<iostream>
#include<stack>

template <typename t>
class SortStack
{
	std::stack<t> st1, st2;
public:
	void inputStack(t elem);
	void sort();
	t getTop() const;
};

template<typename t>
inline void SortStack<t>::inputStack(t elem)
{
	st1.push(elem);
}

template<typename t>
void SortStack<t>::sort()
{
	if (st1.empty())
		throw std::exception("Stack Empty");
	while (!st1.empty())
	{
		auto top1 = st1.top();
		st1.pop();

		if (!st2.empty() && (top1 < st2.top()))
		{
			while (!st2.empty() && (top1 < st2.top()))
			{
				st1.push(st2.top());
					st2.pop();
			}
		}

		st2.push(top1);
	}
	while (!st2.empty())
	{
		st1.push(st2.top());
		st2.pop();
	}
}

template<typename t>
inline t SortStack<t>::getTop() const
{
	if (st1.empty())
		throw std::exception("Stack Empty");

	return st1.top();
}
