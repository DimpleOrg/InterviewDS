#pragma once
#ifndef __QUEUEUSINGSTACK_H_
#define __QUEUEUSINGSTACK_H_

#include <iostream>
#include <stack>

template <typename T>
class QueueUsingStacks
{
private:
	std::stack<T> enqStack;
	std::stack<T> deqStack;
public:
	const T& front();
	void enqueue(const T& item);
	void dequeue();
};


template<typename T>
inline const T & QueueUsingStacks<T>::front()
{
	while (!enqStack.empty())
	{
		deqStack.push(enqStack.top());
		enqStack.pop();
	}

	return deqStack.top();
}

template<typename T>
inline void QueueUsingStacks<T>::enqueue(const T & item)
{
	while (!deqStack.empty())
	{
		enqStack.push(deqStack.top());
		deqStack.pop();
	}

	enqStack.push(item);
}

template<typename T>
inline void QueueUsingStacks<T>::dequeue()
{
	while (!enqStack.empty())
	{
		deqStack.push(enqStack.top());
		enqStack.pop();
	}

	if (!deqStack.empty())
		deqStack.pop();
	else
		throw std::exception("Queue is empty");
}


#endif // __QUEUEUSINGSTACK_H_
