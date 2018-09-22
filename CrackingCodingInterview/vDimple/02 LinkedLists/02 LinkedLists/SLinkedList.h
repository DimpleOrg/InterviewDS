#pragma once
#include<iostream>
#include<thread>
#include<mutex>
#include<unordered_set>
#include<list>

//using namespace std;

template<typename E>
class SLinkedList;

template<typename E>
class SLLIterator;

template<typename E>
std::shared_ptr<SLinkedList<E>> sumLists(std::shared_ptr<SLinkedList<E>>& list1, std::shared_ptr<SLinkedList<E>>& list2);

template <typename E> 
class SNode
{
private:
	E data;
	std::shared_ptr<SNode<E>> next = nullptr;
	friend class SLinkedList<E>;
	friend class SLLIterator<E>;
public:
	~SNode() { std::cout<< "\n Destroying " <<data; }
};

template<typename E>
class SLinkedList
{
private:
	std::shared_ptr<SNode<E>> head = nullptr;
	std::mutex m_mutex;

	std::shared_ptr<SNode<E>> getKthFromLastRecursive(std::shared_ptr<SNode<E>>, int k, int &i) const;

public:
	SLinkedList() {}
	~SLinkedList() {}
	void addFront(const E& e);
	void addToTail(const E& val);
	void RemoveDuplicateNodesV1();
	void RemoveDuplicateNodesV2();
	const E& getKthFromLast(int k) const;
	const E& getKthFromLastRecursive(int k) const;
	void deleteMiddleNode(std::shared_ptr<SNode<E>> ptr);
	void partitionAroundPivot(int pivot);
	

	void print();
	SLLIterator<E> begin() const;
	SLLIterator<E> end() const;
};

template<typename E>
class SLLIterator
{
public:
	SLLIterator<E>(std::shared_ptr<SNode<E>> ptr)
	{
		current = ptr;
	}

	bool operator == (const SLLIterator<E> &rhs)
	{
		return this->current == rhs.current; //current is a pointer and this is also a pointer??
	}

	bool operator != (const SLLIterator<E> &rhs)
	{
		return this->current != rhs.current;
	}

	E operator *()
	{
		return current->data;
	}

	SLLIterator<E> operator ++()
	{
		current = current->next;
		//return SLLIterator<E>(current);
		return *this;
	}

private:
	std::shared_ptr<SNode<E>> current;
};

template<typename E>
SLLIterator<E> SLinkedList<E>::begin() const
{
	return std::move(SLLIterator<E> (head));
}

template<typename E>
SLLIterator<E> SLinkedList<E>::end() const
{
	return std::move(SLLIterator<E> (nullptr));
}

template<typename E>
void SLinkedList<E>::addFront(const E& e)
{
	std::lock_guard<std::mutex> locker(m_mutex);
	if (head == nullptr)
	{
		head = std::make_shared<SNode<E>>();
		head->data = e;
		head->next = nullptr;
	}
	else
	{
		std::shared_ptr<SNode<E>> temp = std::make_shared<SNode<E>>();
		temp->data = e;
		temp->next = head;
		head = temp;
	}
}

template<typename E>
void SLinkedList<E>::print()
{
	std::shared_ptr<SNode<E>> temp;
	std::lock_guard<std::mutex> locker(m_mutex);
	temp = head;
	std::cout << "\n";
	while (temp->next != nullptr)
	{
		std::cout << temp->data << "\t";
		temp = temp->next;
	}
	std::cout << temp->data;

}

template<typename E>
std::shared_ptr<SLinkedList<E>> sumLists(std::shared_ptr<SLinkedList<E>>& list1, std::shared_ptr<SLinkedList<E>>& list2)
{
	if (list1==nullptr && list2 == nullptr)
		return nullptr;
	if (list1 != nullptr && list2 == nullptr)
		return list1;
	if (list2 != nullptr && list1 == nullptr)
		return list2;

	std::shared_ptr<SLinkedList<E>> list3 = std::make_shared<SLinkedList<E>>();

	int sum = 0, carry = 0;

	for (auto iter1 : list1, iter2 : list2)
	{
		sum = 0;
		if (iter1 != nullptr)
			sum += iter1;
		if (iter2 != nullptr)
			sum += iter2;
		sum += carry;

		if (sum > 9)
		{
			carry = sum / 10;
			sum = sum % 10;
		}
		addToTail(sum);
	}
	addToTail(carry);

	return list3;
}

template<typename E>
void SLinkedList<E>::addToTail(const E& val)
{
	std::shared_ptr<SNode<E>> ptr = std::make_shared<SNode<E>>();
	ptr->data = val;
	ptr->next = nullptr;

	if (head == nullptr)
	{
		head = ptr;
	}
	else
	{
		std::shared_ptr<SNode<E>> temp = head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = ptr;
	}
}

template<typename E>
void SLinkedList<E>::RemoveDuplicateNodesV1()
{
	//O(N2) time

	std::shared_ptr<SNode<E>> temp = head;
	if (head!=nullptr && head->next != nullptr)
	{
		std::shared_ptr<SNode<E>> temp1;
		std::shared_ptr<SNode<E>> prev;
		prev = temp;
		while (temp != nullptr)
		{
			temp1 = temp->next;
			while (temp1 != nullptr)
			{
				if (temp->data == temp1->data)
				{
					prev->next = temp1->next;
					temp1 = prev->next;
					
					continue;
				}
				prev = temp1;
				temp1 = temp1->next;
			}
			temp = temp->next;
			prev = temp;
		}
	}
}

template<typename E>
void SLinkedList<E>::RemoveDuplicateNodesV2()
{
	if (head == NULL)
	{
		cout << "Empty list";
		throw std::exception("Empty List");
	}
	if (head->next == nullptr)
	{
		cout << "\n Only one element in list ";
	}

	std::shared_ptr<SNode<E>> temp = head;
	unordered_set<E> listSet;
	std::shared_ptr<SNode<E>> prev = temp;
	while (temp != nullptr)
	{
		if (listSet.find(temp->data)!=listSet.end())
		{
			prev->next = temp->next;
			temp = prev->next;

			continue;
		}
		listSet.insert(temp->data);
		prev = temp;
		temp = temp->next;
	}
}


template<typename E>
const E& SLinkedList<E>::getKthFromLast (int k) const
{
	if (head == NULL)
	{
		cout << "Empty list";
		throw std::exception("Empty List");
	}
	if (head->next == nullptr)
	{
		cout << "\n Only one element in list ";
		if (k == 1)
		{
			cout << head->data;
			return head->data;
		}
		else
			throw  std::exception("Only one element in List");
	}

	std::shared_ptr<SNode<E>> temp1 = head;
	std::shared_ptr<SNode<E>> temp2 = head;
	
	for (int i = 1; i < k; i++)
	{
		//if(temp2->next!=nullptr)
			temp2 = temp2->next;
	}
	while (temp2->next != nullptr)
	{
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	return temp1->data;
}

template<typename E>
std::shared_ptr<SNode<E>> SLinkedList<E>::getKthFromLastRecursive(std::shared_ptr<SNode<E>> head, int k, int &i) const
{
	if (head == nullptr)
	{
		return nullptr;
	}
	/*if (head->next == nullptr)
	{
		return head;
	}*/

	std::shared_ptr<SNode<E>> temp = getKthFromLastRecursive(head->next, k, i);
	i++;
	if (i == k)
		return head;
	return temp;
}

template<typename E>
const E& SLinkedList<E>::getKthFromLastRecursive(int k) const
{
	int i = 0;
	std::shared_ptr<SNode<E>> snd = getKthFromLastRecursive(head, k, i);
	return snd->data;
}

template<typename E>
void SLinkedList<E>::deleteMiddleNode(std::shared_ptr<SNode<E>> ptr)
{
	std::shared_ptr<SNode<E>> temp = ptr->next;
	if (temp != nullptr)
	{
		ptr->data = temp->data;
		ptr->next = temp->next;
	}
}

template<typename E>
void SLinkedList<E>::partitionAroundPivot(int pivot)
{
	if (head == nullptr)
		return;

	std::shared_ptr<SNode<E>> newHead, tail;
	newHead = head;
	head = head->next;
	newHead->next = nullptr;
	
	tail = newHead;
	while (head != nullptr)
	{
		if (head->data < pivot)
		{
			std::shared_ptr<SNode<E>> temp = head;
			head = head->next;
			temp->next = newHead;
			newHead = temp;
		}
		else
		{
			tail->next = head;
			tail = tail->next;
			head = head->next;
			tail->next = nullptr;
		}
	}
	head = newHead;
}