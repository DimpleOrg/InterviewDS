#include "pch.h"
#include "../../../02 LinkedLists/SLinkedList.h"

TEST(D_SLinkedList_Test, removeDuplicates_Test1) {
	std::string output;
	testing::internal::CaptureStdout();
	{
		SLinkedList<int> list;
		list.addFront(1);
		list.addFront(4);
		list.addFront(4);
		list.addFront(4);
		list.addFront(5);
		list.addFront(5);
		list.addFront(6);
		list.addFront(4);
		list.addFront(5);
		list.addFront(1);
		list.print();
		list.RemoveDuplicateNodesV2();
		list.print();
	}
	output = testing::internal::GetCapturedStdout();

	

  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(D_SLinkedList_Test, getKthFromLast_Test1) {
	std::string output;
	testing::internal::CaptureStdout();
	
		SLinkedList<int> list;
		list.addFront(1);
		list.addFront(2);
		list.addFront(3);
		list.addFront(4);
		list.addFront(5);
		list.addFront(6);
		list.addFront(7);
		
		list.print();
		int k = 1;
//		int res = list.getKthFromLast(k);
		int res = list.getKthFromLastRecursiveFn(k);
	
	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(res, 1);
}