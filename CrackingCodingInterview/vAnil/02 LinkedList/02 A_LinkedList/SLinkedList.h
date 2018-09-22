#pragma once
#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <unordered_set>

using namespace std;
template <typename TYPE>
class SLinkedList;

template <typename TYPE>
class SLLIterator;


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
	friend class SLLIterator<TYPE>;
};


template <typename TYPE>
class SLLIterator
{
public:
	SLLIterator(std::shared_ptr<SNode<TYPE>> ptr)
	{
		current = ptr;
	}

	bool operator == (const SLLIterator<TYPE> &rhs)
	{
		return this->current == rhs.current;
	}

	bool operator != (const SLLIterator<TYPE> &rhs)
	{
		return this->current != rhs.current;
	}

	TYPE operator*()
	{
		return current->elem;
	}

	SLLIterator<TYPE> operator ++()
	{
		current = current->next;
		return *this;
	}
private:
	std::shared_ptr<SNode<TYPE>> current;
};

template <typename TYPE>
class SLinkedList {
public:
	SLinkedList(); 
	~SLinkedList();
	bool empty() const;
	const TYPE& front() const; 
	void addFront(const TYPE& e); 
	void addBack(const TYPE& e);
	void removeFront();
	void print();
	void RemoveDuplicateNodesV1();
	void RemoveDuplicateNodesV2();
	TYPE GetKthLastElement(size_t k) const;
	TYPE GetKthLastElementRec(size_t k) const;

	SLLIterator<TYPE> begin() const {
		return SLLIterator<TYPE>(head);
	}

	SLLIterator<TYPE> end() const {
		return SLLIterator<TYPE>(nullptr);
	}

	void PartitionListAroundPivot(TYPE pivot);

private:

	size_t  GetKethLastELementRec(std::shared_ptr < SNode<TYPE>> iter,
		size_t kthfromend, std::shared_ptr < SNode<TYPE>> &result) const;

	std::shared_ptr<SNode<TYPE>> head = nullptr;
	std::mutex slMutex;
};

template <typename TYPE>
TYPE SLinkedList<TYPE>::GetKthLastElementRec(size_t k) const
{
	std::shared_ptr < SNode<TYPE>> result;
	
	GetKethLastELementRec(head, k, result);

	return result->elem;
}

template<typename TYPE>
void SLinkedList<TYPE>::PartitionListAroundPivot(TYPE pivot)
{
	if (head != nullptr)
	{
		std::shared_ptr<SNode<TYPE>> newhead;
		std::shared_ptr<SNode<TYPE>> end;

		std::shared_ptr<SNode<TYPE>> iter;

		newhead = head;
		head = head->next;

		newhead->next = nullptr;
		end = newhead;

		
		while (head)
		{
			if (head->elem < pivot)
			{
				std::shared_ptr<SNode<TYPE>> temp;
				temp = head->next;

				head->next = newhead;
				newhead = head;

				head = temp;
			}
			else
			{
				end->next = head;
				head = head->next;

				end = end->next;
				end->next = nullptr;

				//end = end->next;
			}
		}

		head = newhead;
	}
}

template <typename TYPE>
size_t SLinkedList<TYPE>::GetKethLastELementRec(std::shared_ptr < SNode<TYPE>> iter, size_t kthfromend,
	std::shared_ptr < SNode<TYPE>> &result) const
{
	if (iter == nullptr)
	{
		return 0;
	}
	else
	{
		int indexFromEnd = GetKethLastELementRec(iter->next, kthfromend,  result)  + 1;
		
		if (indexFromEnd == kthfromend + 1)
		{
			result = iter;
		}

		return indexFromEnd;
	}
}

template <typename TYPE>
TYPE SLinkedList<TYPE>::GetKthLastElement(size_t k) const
{
	std::shared_ptr<SNode<TYPE>> ptr1 = head, ptr2 = head;

	while (ptr2 != nullptr && k != 0)
	{
		ptr2 = ptr2->next;
		k--;
	}

	if (k > 0) {
		throw std::exception("List does not have kth last element");
	}

	while (ptr2->next)
	{
		ptr2 = ptr2->next;
		ptr1 = ptr1->next;
	}

	return ptr1->elem;
}

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
	cout << "Adding Front Elem:" << e << endl;
	lock_guard<mutex> lock(slMutex);
	shared_ptr<SNode<TYPE>> v = make_shared<SNode<TYPE>>();
	v->elem = e; 
	v->next = head;
	head = v;
}

template <typename TYPE>
void SLinkedList<TYPE>::addBack(const TYPE& e) {
	cout << "Adding Back Elem:" << e << endl;
	lock_guard<mutex> lock(slMutex);
	shared_ptr<SNode<TYPE>> v = make_shared<SNode<TYPE>>();
	v->elem = e;
	v->next = nullptr;

	if (head == nullptr)
	{
		head = v;
	}
	else
	{
		auto iter = head;
		while (iter->next != nullptr)
			iter = iter->next;

		iter->next = v;
	}
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

template<typename TYPE>
inline void SLinkedList<TYPE>::RemoveDuplicateNodesV1()
{
	std::shared_ptr<SNode<TYPE>> temp = head;
	while (temp)
	{
		TYPE curVal = temp->elem;
		
		std::shared_ptr<SNode<TYPE>> prev = temp;
		std::shared_ptr<SNode<TYPE>> temp1 = temp->next;

		while (temp1)
		{
			if (curVal == temp1->elem)
			{
				prev->next = temp1->next;
				temp1 = temp1->next;
				continue;
			}

			prev = temp1;
			temp1 = temp1->next;
		}


		temp = temp->next;
	}
}


template<typename TYPE>
inline void SLinkedList<TYPE>::RemoveDuplicateNodesV2()
{
	std::shared_ptr<SNode<TYPE>> temp = head;

	std::unordered_set<TYPE> foundSet;

	std::shared_ptr<SNode<TYPE>> prev = temp;
	while (temp)
	{	
		if (foundSet.find(temp->elem) == foundSet.end())
		{
			foundSet.insert(temp->elem);
		}
		else
		{
			prev->next = temp->next;
			temp = temp->next;
			continue;
		}

		prev = temp;
		temp = temp->next;
	}
}


template <typename E>
std::shared_ptr < SLinkedList<E>> AddTwoListNumerically(const SLinkedList<E> &list1, const SLinkedList<E> &list2)
{
	SLLIterator<E> begin1 = list1.begin();
	SLLIterator<E> begin2 = list2.begin();

	std::shared_ptr<SLinkedList<E>> rlist = std::make_shared<SLinkedList<E>>();
//	SLinkedList<E> rlist;

	E carryOver = 0;
	while (begin1 != list1.end()
		&& begin2 != list2.end())
	{
		E sum = *begin1 + *begin2 + carryOver;

		if (sum > 9) {
			carryOver = 1;
		}
		else {
			carryOver = 0;
		}

		rlist->addBack(sum % 10);

		++begin1;
		++begin2;
	}

	while (begin1 != list1.end())
	{
		rlist->addBack(*begin1 + carryOver);
		carryOver = 0;
		++begin1;
	}

	while (begin2 != list2.end())
	{
		rlist->addBack(*begin2 + carryOver);
		carryOver = 0;
		++begin2;
	}

	return rlist;

}