#include "pch.h"
#include "../../../02 LinkedLists/SLinkedList.h"

TEST(SLinkedList_Test, Test1) {
	SLinkedList<int> list;
	list.addFront(5);
	list.addFront(4);
	list.addFront(4);
	list.addFront(5);
	list.addFront(1);
	list.print();
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}