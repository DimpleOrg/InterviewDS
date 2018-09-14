#include"SLinkedList.h"

using namespace std;

template<typename E>
SLinkedList<E>::SLinkedList():head(nullptr){}

template<typename E>
void SLinkedList<E>::addFront(const E& e)
{
	if (head == nullptr)
	{
		head = make_shared<SNode<E>>();
		head->data = e;
		head->next = nullptr;
	}
	else
	{
		shared_ptr<SNode<E>> temp = make_shared<SNode>;
		temp->data = e;
		temp->next = head;
		head = temp;
	}
}

template<typename E>
void SLinkedList<E>::print()
{
	shared_ptr<SNode<E>> temp;
	temp = head;
	cout << "\n";
	while (temp->next != nullptr)
	{
		cout << temp->data<<"\t";
	}
	cout << temp->data;
	
}
