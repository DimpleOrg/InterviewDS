#pragma once
#include <iostream>
#include <string>
#include <thread>
#include <mutex>

using namespace std;
template <typename TYPE>
class SLinkedList;

template <typename TYPE>
class SNode {
public:
	~SNode()
	{
		std::cout << "Destruct Element:" << elem << endl;
	}
private:
	TYPE elem; 
	std::shared_ptr<SNode<TYPE>> next = nullptr; 
	friend class SLinkedList<TYPE>; 
};



template <typename TYPE>
class SLinkedList {
public:
	SLinkedList(); 
	~SLinkedList();
	bool empty() const;
	const TYPE& front() const; 
	void addFront(const TYPE& e); 
	void removeFront();
	void print();
private:
	std::shared_ptr<SNode<TYPE>> head = nullptr;
	std::mutex slMutex;
};

template <typename TYPE>
SLinkedList<TYPE>::SLinkedList()
{
}


template <typename TYPE>
bool SLinkedList<TYPE>::empty() const
{
	lock_guard<mutex> lock(slMutex);
	return head == nullptr;
}


template <typename TYPE>
const TYPE& SLinkedList<TYPE>::front() const
{
	lock_guard<mutex> lock(slMutex);
	return head->elem;
}

template <typename TYPE>
SLinkedList<TYPE>::~SLinkedList()
{
	lock_guard<mutex> lock(slMutex);
	while (head != nullptr)
	{
		head = head->next;
	}
}

template <typename TYPE>
void SLinkedList<TYPE>::addFront(const TYPE& e) { 
	cout << "Adding Elem:" << e << endl;
	lock_guard<mutex> lock(slMutex);
	shared_ptr<SNode<TYPE>> v = make_shared<SNode<TYPE>>();
	v->elem = e; 
	v->next = head;
	head = v;
}


template <typename TYPE>
void SLinkedList<TYPE>::removeFront() { 
	lock_guard<mutex> lock(slMutex);
	shared_ptr<SNode<TYPE>> old = head;
	head = old->next;
	delete old;
}

template <typename TYPE>
void SLinkedList<TYPE>::print()
{
	lock_guard<mutex> lock(slMutex);
	shared_ptr<SNode<TYPE>> temp = head;
	cout  << "Single Linked List:\n";
	while (temp != nullptr)
	{
		cout << temp->elem << " ";
		temp = temp->next;
	}
	cout << "\n";
}