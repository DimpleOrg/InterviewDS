#pragma once
#include<iostream>


template<typename E>
class SLinkedList;

template <typename E> 
class SNode
{
private:
	E data;
	std::shared_ptr<SNode<E>> next = nullptr;
	friend class SLinkedList<E>;
};

template<typename E>
class SLinkedList
{
private:
	std::shared_ptr<SNode<E>> head = nullptr;
public:
	SLinkedList();
	~SLinkedList();
	void addFront(const E& e);
};

