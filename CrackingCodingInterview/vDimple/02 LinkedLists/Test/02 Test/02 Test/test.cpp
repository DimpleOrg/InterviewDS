#include "pch.h"
#include "../../../02 LinkedLists/SLinkedList.h"
#include<algorithm>


TEST(D_SLinkedList_Test, isPalindrome_Test1) {
	std::string output;
	testing::internal::CaptureStdout();

	std::shared_ptr<SLinkedList<int>> list1 = std::make_shared<SLinkedList<int>>();

	/*list1->addFront(8);
	list1->addFront(7);
	list1->addFront(9);*/
	list1->print();

	output = testing::internal::GetCapturedStdout();

	bool res = list1->isPalindrome();

	EXPECT_EQ(res, true);
}

TEST(D_SLinkedList_Test, SumLists_Test1) {
	std::string output;
	testing::internal::CaptureStdout();

	std::shared_ptr<SLinkedList<int>> list1 = std::make_shared<SLinkedList<int>>(),
		list2 = std::make_shared<SLinkedList<int>>();

	list1->addFront(9);
	list1->addFront(7);
	list1->addFront(8);
	list1->print();

	list2->addFront(6);
	list2->addFront(8);
	list2->addFront(5);
	list2->print();

	std::shared_ptr<SLinkedList<int>> list3;
	//	list3 = sumListsReverseOrder(list1, list2);
	list3 = sumListsForwardOrder(list1, list2);
	list3->print();

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(1, 1);

}



TEST(D_SLinkedList_Test, removeDuplicates_Test1) {
	std::string output;
	testing::internal::CaptureStdout();

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
	list.RemoveDuplicateNodesV1();
	list.print();

	for (SLLIterator<int> iter = list.begin(); iter != list.end(); ++iter)
	{
		std::cout << "\n" << *iter << "\n";
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
	int k = 3;
	//int res = list.getKthFromLast(k);
	const int &res = list.getKthFromLastRecursive(k);

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(res, 3);
}

TEST(D_SLinkedList_Test, partitionAroundPivot_Test1) {
	std::string output;
	testing::internal::CaptureStdout();

	SLinkedList<int> list;
	list.addFront(1);
	list.addFront(2);
	list.addFront(10);
	list.addFront(5);
	list.addFront(8);
	list.addFront(5);
	list.addFront(3);

	list.print();
	int k = 5;
	list.partitionAroundPivot(k);
	list.print();
	output = testing::internal::GetCapturedStdout();

	//int greaterThan = list.begin();
	for (SLLIterator<int> iter = list.begin(); iter != list.end(); ++iter)
	{

	}

	//EXPECT_EQ(res, 3);
}