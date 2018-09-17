#pragma once
#include "SLinkedList.h"


#ifdef MY02ALINKEDLIST_EXPORTS
#define LINKEDLIST_API __declspec(dllexport)
#else
#define LINKEDLIST_API __declspec(dllimport)
#endif

template <typename TYPE>
void RemoveDuplicateNodesV1(SLinkedList<TYPE>&list);

template <typename TYPE>
void RemoveDuplicateNodesV2(SLinkedList<TYPE>&list);


template <typename TYPE>
void RemoveDuplicateNodesV1(SLinkedList<TYPE>&list)
{
	return list.RemoveDuplicateNodesV2();
}

template <typename TYPE>
void RemoveDuplicateNodesV2(SLinkedList<TYPE>&list)
{
	return list.RemoveDuplicateNodesV2();
}
