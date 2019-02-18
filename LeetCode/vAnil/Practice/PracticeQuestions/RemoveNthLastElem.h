#pragma once
#include <iostream>


template <typename T>
class Node
{
public:
	T data;
	std::shared_ptr<Node<T>> next;

	Node(T in) {
		data = in;
	}
};

template <typename T>
class List
{
public:
	void AddElem(T data);
	void RemoveNthFromLast(size_t n);
	void Print();

private:
	std::shared_ptr<Node<T>> head = nullptr;
};

template<typename T>
inline void List<T>::AddElem(T data)
{
	if (head == nullptr)
	{
		head = std::make_shared<Node<T>>(data);
	}
	else
	{
		std::shared_ptr<Node<T>> iter(head);

		while (iter->next)
		{
			iter = iter->next;
		}
		iter->next = std::make_shared < Node<T>>(data);
	}
}

template<typename T>
inline void List<T>::RemoveNthFromLast(size_t n)
{
	std::shared_ptr<Node<T>> fast(head);
	std::shared_ptr<Node<T>> slow(head);

	while (n != 0)
	{
		n--;
		if (fast != nullptr)
			fast = fast->next;
		else
			throw "Input Error";
	}

	while (fast != nullptr && fast->next != nullptr)
	{
		fast = fast->next;
		slow = slow->next;
	}

	if (slow != nullptr && slow->next != nullptr)
		slow->next = slow->next->next;
	else
		head = nullptr;

}

template<typename T>
inline void List<T>::Print()
{
	std::shared_ptr<Node<T>> iter(head);

	std::cout << "\nPrint the list data: ";
	while (iter != nullptr)
	{
		std::cout << iter->data << "\t";
		iter = iter->next;
	}
}
