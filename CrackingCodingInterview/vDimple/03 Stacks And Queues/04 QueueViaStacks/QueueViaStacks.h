#pragma once
#ifndef __QUEUE_VIA_STACKS_
#define __QUEUE_VIA_STACKS_
#include<iostream>
#include<stack>

template<typename T>
class MyQueue
{
	std::stack<T> st1, st2;
public:
	void enqueue(T const elem);
	void dequeue();
	auto front()->T;

};

template<typename T>
inline void MyQueue<T>::enqueue(T const elem)
{
	if (!st2.empty())
	{
		while (!st2.empty())
		{
			st1.push(st2.top());
			st2.pop();
		}
	}
	st1.push(elem);
}

template<typename T>
inline void MyQueue<T>::dequeue()
{
	if (st2.empty())
	{
		if (st1.empty())
			throw std::exception("MyQueue is empty");
		else
		{
			while (!st1.empty())
			{
				st2.push(st1.top());
				st1.pop();
			}
		}
	}
	st2.pop();
}

template<typename T>
inline auto MyQueue<T>::front()->T
{
	if (st2.empty())
	{
		if (st1.empty())
			throw std::exception("MyQueue is empty");
		else
		{
			while (!st1.empty())
			{
				st2.push(st1.top());
				st1.pop();
			}
		}
	}
	return st2.top();
}

#endif