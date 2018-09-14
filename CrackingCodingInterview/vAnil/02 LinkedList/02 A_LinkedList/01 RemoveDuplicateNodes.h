#pragma once
#include "SLinkedList.h"


#ifdef MY02ALINKEDLIST_EXPORTS
#define LINKEDLIST_API __declspec(dllexport)
#else
#define LINKEDLIST_API __declspec(dllimport)
#endif

LINKEDLIST_API bool RemoveDuplicateNodesV1(SLinkedList<int>&list);