#pragma once
#include<iostream>
#include<thread>
#include<mutex>
#include<unordered_set>

using namespace std;

template<typename E>
class SLinkedList;

template <typename E> 
class SNode
{
private:
	E data;
	std::shared_ptr<SNode<E>> next = nullptr;
	friend class SLinkedList<E>;
public:
	~SNode() { cout<< "\n Destroying " <<data; }
};

template<typename E>
class SLinkedList
{
private:
	std::shared_ptr<SNode<E>> head = nullptr;
	std::mutex m_mutex;

	shared_ptr<SNode<E>> getKthFromLastRecursive(shared_ptr<SNode<E>>, int k, int &i) const;

public:
	SLinkedList() {}
	~SLinkedList() {}
	void addFront(const E& e);
	//void deleteNode(shared_ptr<SNode<E>>& temp);
	void RemoveDuplicateNodesV1();
	void RemoveDuplicateNodesV2();
	const E& getKthFromLast(int k) const;
	const E& getKthFromLastRecursive(int k) const;
	
	void print();
	
};



template<typename E>
void SLinkedList<E>::addFront(const E& e)
{
	std::lock_guard<mutex> locker(m_mutex);
	if (head == nullptr)
	{
		head = make_shared<SNode<E>>();
		head->data = e;
		head->next = nullptr;
	}
	else
	{
		shared_ptr<SNode<E>> temp = make_shared<SNode<E>>();
		temp->data = e;
		temp->next = head;
		head = temp;
	}
}

template<typename E>
void SLinkedList<E>::print()
{
	shared_ptr<SNode<E>> temp;
	std::lock_guard<mutex> locker(m_mutex);
	temp = head;
	cout << "\n";
	while (temp->next != nullptr)
	{
		cout << temp->data << "\t";
		temp = temp->next;
	}
	cout << temp->data;

}


template<typename E>
void SLinkedList<E>::RemoveDuplicateNodesV1()
{
	//O(N2) time

	shared_ptr<SNode<E>> temp = head;
	if (head!=nullptr && head->next != nullptr)
	{
		shared_ptr<SNode<E>> temp1;
		shared_ptr<SNode<E>> prev;
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

	shared_ptr<SNode<E>> temp = head;
	unordered_set<E> listSet;
	shared_ptr<SNode<E>> prev = temp;
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

	shared_ptr<SNode<E>> temp1 = head;
	shared_ptr<SNode<E>> temp2 = head;
	
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
shared_ptr<SNode<E>> SLinkedList<E>::getKthFromLastRecursive(shared_ptr<SNode<E>> head, int k, int &i) const
{
	if (head == nullptr)
	{
		return nullptr;
	}
	/*if (head->next == nullptr)
	{
		return head;
	}*/

	shared_ptr<SNode<E>> temp = getKthFromLastRecursive(head->next, k, i);
	i++;
	if (i == k)
		return head;
	return temp;
}

template<typename E>
const E& SLinkedList<E>::getKthFromLastRecursive(int k) const
{
	int i = 0;
	shared_ptr<SNode<E>> snd = getKthFromLastRecursive(head, k, i);
	return snd->data;
}

// 1) Fn Overloading
// 2) i=0 not working correctly
// 3) &i