#pragma once
#include<iostream>
#define DllExport   __declspec( dllexport )

template<typename T>
class DllExport SNode
{
public:
	T data;
	std::shared_ptr <SNode<T>> next;
};

template<typename T>
class DllExport SLinkedList
{
public:
	void removeNodeNFromLast(int n);
	void addNode(int val);
	void print();

private:
	std::shared_ptr<SNode<T>> head;
};

template<typename T>
void SLinkedList<T> ::removeNodeNFromLast(int n)
{
	if (!head || n < 1)
		return;
	if (!head->next && n > 1)
		return;
	std::shared_ptr<SNode<T>> t1, t2;
	t1 = head; t2 = head;
	for (int i = 0; i < n; i++)
	{
		if (t1->next)
			t1 = t1->next;
		else
			throw("\nKth node from last does not exist");
	}
	for (int i = 0; t1->next != nullptr; i++)
	{
		t1 = t1->next;
		t2 = t2->next;
	}
	t2->next = t2->next->next;
}

template<typename T>
inline void SLinkedList<T>::addNode(int val)
{
	std::shared_ptr<SNode<T>> newNode = std::make_shared<SNode<T>>();
	newNode->data = val;
	newNode->next = nullptr;

	if (!head)
	{
		head = newNode;
	}
	else
	{
		newNode->next = head;
		head = newNode;
	}
}

template<typename T>
inline void SLinkedList<T>::print()
{
	std::shared_ptr<SNode<T>> temp = head;
	while (!temp)
	{
		std::cout << temp->data << "\t";
		temp = temp->next;
	}
}