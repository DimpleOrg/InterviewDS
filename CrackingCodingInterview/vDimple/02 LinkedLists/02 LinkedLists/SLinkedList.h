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
std::shared_ptr<SLinkedList<E>> sumListsReverseOrder(std::shared_ptr<SLinkedList<E>>& list1, std::shared_ptr<SLinkedList<E>>& list2);

template<typename E>
std::shared_ptr<SLinkedList<E>> sumListsForwardOrder(std::shared_ptr<SLinkedList<E>>& list1, std::shared_ptr<SLinkedList<E>>& list2);

template <typename E>
class SNode
{
private:
	E data;
	std::shared_ptr<SNode<E>> next = nullptr;
	friend class SLinkedList<E>;
	friend class SLLIterator<E>;
public:
	~SNode() { std::cout << "\n Destroying " << data; }
};

template<typename E>
SLLIterator<E> getListIntersection(SLinkedList<E>& list1, SLinkedList<E>& list2);

template<typename E>
class SLinkedList
{
public:
	SLinkedList() {}
	~SLinkedList() {}
	void addFront(const E& e);
	void addToTail(const E& val);
	void reverseSLListRec();
	void reverseSLListIter();
	void RemoveDuplicateNodesV1();
	void RemoveDuplicateNodesV2();
	const E& getKthFromLast(int k) const;
	const E& getKthFromLastRecursive(int k) const;
	void deleteMiddleNode(std::shared_ptr<SNode<E>> ptr);
	void partitionAroundPivot(int pivot);
	void modify(int count);
	bool isPalindrome() const;
	void attatchNodeToTail(SLinkedList<E>&);

	void print();
	SLLIterator<E> begin() const;
	SLLIterator<E> end() const;

private:
	std::shared_ptr<SNode<E>> head = nullptr;
	std::mutex m_mutex;

	void revListRec(std::shared_ptr<SNode<E>> head);
	std::shared_ptr<SNode<E>> getKthFromLastRecursive(std::shared_ptr<SNode<E>>, int k, int &i) const;
	bool isListPalindrome(std::shared_ptr<SNode<E>> head, int count) const;
};

template<typename E>
class SLLIterator
{
public:
	SLLIterator<E>(std::shared_ptr<SNode<E>> ptr)
	{
		current = ptr;
	}

	std::shared_ptr<SNode<E>> getNodeAddress()
	{
		return current;
	}

	bool operator == (const SLLIterator<E> &rhs)
	{
		return current == rhs.current; //current is a pointer and this is also a pointer??
	}

	bool operator != (const SLLIterator<E> &rhs)
	{
		return current != rhs.current;
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

	SLLIterator<E> operator ++(int)
	{

		std::shared_ptr<SNode<E>> temp = nullptr;
		temp = current;
		SLLIterator<E> iter(temp);
		current = current->next;

		return iter;
	}

private:
	std::shared_ptr<SNode<E>> current;
};

template<typename E>
SLLIterator<E> SLinkedList<E>::begin() const
{
	return std::move(SLLIterator<E>(head));
}

template<typename E>
SLLIterator<E> SLinkedList<E>::end() const
{
	return std::move(SLLIterator<E>(nullptr));
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
void SLinkedList<E>::print()
{
	std::shared_ptr<SNode<E>> temp;
	std::lock_guard<std::mutex> locker(m_mutex);
	temp = head;
	std::cout << "\n";
	while (temp != nullptr)
	{
		std::cout << temp->data << "\t";
		temp = temp->next;
	}

}

template<typename E>
void SLinkedList<E>::reverseSLListIter()
{
	if (head == nullptr)
		return;


	std::shared_ptr<SNode<E>> prev = nullptr;
	std::shared_ptr<SNode<E>> curr = head;
	std::shared_ptr<SNode<E>> nxt = curr->next;

	while (curr != nullptr)
	{
		curr->next = prev;
		prev = curr;
		curr = nxt;
		if (curr != nullptr)
			nxt = nxt->next;
	}
	head = prev;
}

template<typename E>
void SLinkedList<E>::reverseSLListRec()
{
	revListRec(head);
}

template<typename E>
void SLinkedList<E>::revListRec(std::shared_ptr<SNode<E>> ptr)
{
	static std::shared_ptr<SNode<E>> temp = nullptr;

	if (ptr == nullptr)
		return;

	revListRec(ptr->next);

	if (ptr != nullptr && ptr->next == nullptr)
	{
		head = ptr;
		temp = ptr;
		return;
	}
	
	if (ptr->next != nullptr)
	{
			temp->next = ptr;
			temp = temp->next;
			temp->next = nullptr;
	}
}

template<typename E>
void SLinkedList<E>::attatchNodeToTail(SLinkedList<E>& commonNode)			//if i dont take list by ref it is giving error
{
	SLLIterator<E> iter = commonNode.begin();
	std::shared_ptr<SNode<E>> temp = head;
	while (temp->next != nullptr)
		temp = temp->next;
	temp->next = iter.getNodeAddress();

}

template<typename E>
SLLIterator<E> getListIntersection(SLinkedList<E>& list1, SLinkedList<E>& list2)
{
	int count1 = 0, count2 = 0;
	for (auto iter1 : list1)
		count1 += 1;
	for (auto iter2 : list2)
		count2 += 1;

	auto iter1 = list1.begin();
	auto iter2 = list2.begin();

	//void setIterator(iter1, iter2, count1, count2);
	if (count1 > count2)
	{
		int loop = 0;
		while (loop < (count1 - count2))
		{
			++iter1;
			loop++;
		}
	}
	if (count2 > count1)
	{
		int loop = 0;
		while (loop < (count2 - count1))
		{
			++iter2;
			loop++;
		}
	}

	while (iter1 != list1.end())
	{
		if (iter1.getNodeAddress() == iter2.getNodeAddress())
			return iter1;
		
		++iter1;
		++iter2;
	}
	
	return SLLIterator<E>(nullptr);
}


template<typename E>
bool SLinkedList<E>::isPalindrome() const
{
	int count = 0;
	bool res = true;
	//	for (auto iter : this) count++;			how to use iter?
	std::shared_ptr<SNode<E>> temp = head;
	while (temp != nullptr)
	{
		count++;
		temp = temp->next;
	}
	return isListPalindrome(head, count);
}

template<typename E>
bool SLinkedList<E>::isListPalindrome(std::shared_ptr<SNode<E>> head, int count) const
{
	static std::shared_ptr<SNode<E>> temp = head;
	static int loop = 0;

	if (head == nullptr)
		return true;

	bool res = isListPalindrome(head->next, count);
	if (res == true)
	{
		if (head != nullptr)
		{
			if (loop < count / 2)
			{
				++loop;
				if (temp->data != head->data)
					return false;
				else
				{
					temp = temp->next;
					return true;
				}
			}
			else
				return true;
		}
	}
	else
		return false;
}

template<typename E>
std::shared_ptr<SLinkedList<E>> sumListsReverseOrder(std::shared_ptr<SLinkedList<E>>& list1, std::shared_ptr<SLinkedList<E>>& list2)
{
	if (list1 == nullptr && list2 == nullptr)
		return nullptr;
	if (list1 != nullptr && list2 == nullptr)
		return list1;
	if (list2 != nullptr && list1 == nullptr)
		return list2;

	std::shared_ptr<SLinkedList<E>> list3 = std::make_shared<SLinkedList<E>>();

	int sum = 0, carry = 0;

	SLLIterator<E> iter1 = list1->begin();
	SLLIterator<E> iter2 = list2->begin();

	while (iter1 != list1->end() || iter2 != list2->end())
	{
		sum = 0;
		if (iter1 != list1->end())
		{
			sum += *iter1;
			++iter1;
		}
		if (iter2 != list2->end())
		{
			sum += *iter2;
			++iter2;
		}
		sum += carry;

		if (sum > 9)
		{
			carry = sum / 10;
			sum = sum % 10;
		}
		else
			carry = 0;

		list3->addToTail(sum);

	}
	if (carry>0)
		list3->addToTail(carry);

	return list3;
}

template<typename E>
std::shared_ptr<SLinkedList<E>> sumListsForwardOrder(std::shared_ptr<SLinkedList<E>>& list1, std::shared_ptr<SLinkedList<E>>& list2)
{
	if (list1 == nullptr && list2 == nullptr)
		return nullptr;
	if (list1 != nullptr && list2 == nullptr)
		return list1;
	if (list2 != nullptr && list1 == nullptr)
		return list2;

	std::shared_ptr<SLinkedList<E>> list3 = std::make_shared<SLinkedList<E>>();

	int count1 = 0, count2 = 0;
	for (SLLIterator<E> iter1 = list1->begin(); iter1 != list1->end(); ++iter1)
		count1 += 1;
	//for (SLLIterator<E> iter2 : list2)		//not working???
	for (SLLIterator<E> iter2 = list2->begin(); iter2 != list2->end(); ++iter2)
		count2 += 1;
	if (count1 > count2)
		list2->modify(count1 - count2);

	if (count2 > count1)
		list1->modify(count2 - count1);

	SLLIterator<E> iter1 = list1->begin(), iter2 = list2->begin();

	int carry = sumTwoLL(iter1, iter2, list1, list2, list3);
	int sum = *(list1->begin()) + *(list2->begin()) + carry;
	list3->addFront(sum % 10);
	if (sum > 9)
	{
		list3->addFront(sum / 10);
	}
	return list3;
}

template<typename E>
int sumTwoLL(SLLIterator<E>& iter1, SLLIterator<E>& iter2, std::shared_ptr<SLinkedList<E>>& list1, std::shared_ptr<SLinkedList<E>>& list2, std::shared_ptr<SLinkedList<E>>& list3)
{
	static int carry = 0;
	if (iter1 == list1->end() && iter2 == list2->end())
		return 0;

	sumTwoLL(++iter1, ++iter2, list1, list2, list3);
	if (iter1 != list1->end())
	{
		int sum = 0;
		sum = *iter1 + *iter2 + carry;
		carry = sum / 10;
		sum = sum % 10;
		list3->addFront(sum);
	}
	return carry;
}

template<typename E>
void SLinkedList<E>::modify(int count)
{
	for (int i = 0; i < count; i++)
	{
		addFront(0);
	}
}

template<typename E>
void SLinkedList<E>::RemoveDuplicateNodesV1()
{
	//O(N2) time

	std::shared_ptr<SNode<E>> temp = head;
	if (head != nullptr && head->next != nullptr)
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
		if (listSet.find(temp->data) != listSet.end())
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
const E& SLinkedList<E>::getKthFromLast(int k) const
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