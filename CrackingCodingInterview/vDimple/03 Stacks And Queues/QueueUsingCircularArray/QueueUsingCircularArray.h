#pragma once

#ifndef __QUEUE_USING_CIRCULAR_ARRAY_
#define __QUEUE_USING_CIRCULAR_ARRAY_
#include<iostream>

template<typename T>
class Queue
{
	int fr = 0, rear = 0, len = 0;
	int max_len;
	std::unique_ptr<T[]> arr;
public:
	Queue(int n=5): max_len(n) 
	{
		arr = std::make_unique<T[]>(max_len);
	}
	void enqueue(T elem);
	void dequeue();
	T front();
	void print();
};

template<typename T>
inline void Queue<T>::enqueue(T elem)
{
	if (len == max_len)
		throw std::exception("Queue is full");
	
	arr.get()[rear] = elem;
	if (rear == max_len-1)
		rear = 0;
	else
		++rear;
	++len;
}

template<typename T>
inline void Queue<T>::dequeue()
{
	if (len == 0)
		throw std::exception("Queue Empty");
	
	if (fr == max_len-1)
		fr = 0;
	else
		++fr;

	--len;
}

template<typename T>
inline T Queue<T>::front()
{
	if(len==0)
		throw std::exception("Queue Empty");
	
	return arr.get()[fr];
}

template<typename T>
inline void Queue<T>::print()
{
	if (len == 0)
		throw std::exception("Queue Empty");

	if (fr >= rear)
	{
		for (auto i = fr; i < max_len ; i++)
		{
			std::cout << arr.get()[i] << "\t";
		}
		for (auto i = 0; i < rear; i++)
		{
			std::cout << arr.get()[i] << "\t";
		}
	}
	else
	{
		for (auto i = fr; i < rear; i++)
		{
			std::cout << arr.get()[i] << "\t";
		}
	}
}

#endif // __QUEUE_USING_CIRCULAR_ARRAY_


