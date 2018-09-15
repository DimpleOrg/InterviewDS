#include "pch.h"
#include "../../02 A_LinkedList/SLinkedList.h"
#include "../../02 A_LinkedList/01 RemoveDuplicateNodes.h"


TEST(SLinkedListTest, Test1) {
	
	std::string output;
	testing::internal::CaptureStdout();
	
	//create scope
	{
		SLinkedList<int> list;

		list.addFront(10);
		list.addFront(11);
		list.addFront(12);
		list.addFront(13);

		list.print();
	}

	output = testing::internal::GetCapturedStdout();

	EXPECT_TRUE(true);
}


TEST(RemoveDuplicateNodes, TestV1)
{
	std::string output;
	testing::internal::CaptureStdout();

	{
		SLinkedList<int> list;

		list.addFront(10);
		list.addFront(10);
		list.addFront(10);
		list.addFront(11);
		list.addFront(11);
		list.addFront(12);
		list.addFront(13);
		list.addFront(10);
		list.addFront(11);
		list.addFront(12);
		list.addFront(13);

		list.print();

		RemoveDuplicateNodesV1(list);

		list.print();

	}


	output = testing::internal::GetCapturedStdout();

	EXPECT_TRUE(true);
}


TEST(RemoveDuplicateNodes, TestV2)
{
	std::string output;
	testing::internal::CaptureStdout();

	{
		SLinkedList<int> list;

		list.addFront(10);
		list.addFront(10);
		list.addFront(10);
		list.addFront(11);
		list.addFront(11);
		list.addFront(12);
		list.addFront(13);
		list.addFront(10);
		list.addFront(11);
		list.addFront(12);
		list.addFront(13);

		list.print();

		RemoveDuplicateNodesV2(list);

		list.print();

	}


	output = testing::internal::GetCapturedStdout();

	EXPECT_TRUE(true);
}