#include "pch.h"
#include "../../../02 LinkedLists/SLinkedList.h"
#include<algorithm>

TEST(D_SLinkedList_Test, ReverseSLList_Rec_Test1) {
	std::string output;
	testing::internal::CaptureStdout();

	SLinkedList<int> list;
	list.addToTail(1);
	list.addToTail(2);
	list.addToTail(3);
	list.addToTail(4);
	list.addToTail(5);
	list.print();

	list.reverseSLListRec();
	list.print();

	output = testing::internal::GetCapturedStdout();

	//EXPECT_EQ();
}

TEST(D_SLinkedList_Test, ReverseSLList_Iterative_Test1) {
	std::string output;
	testing::internal::CaptureStdout();

	SLinkedList<int> list;
	list.addToTail(1);
	list.addToTail(2);
	list.addToTail(3);
	list.addToTail(4);
	list.addToTail(5);
	list.print();

	list.reverseSLListIter();
	list.print();

	output = testing::internal::GetCapturedStdout();

	//EXPECT_EQ();
}

TEST(D_SLinkedList_Test, ReverseSLList_Iterative_Test2) {
	std::string output;
	testing::internal::CaptureStdout();

	SLinkedList<int> list;
	list.addToTail(1);
	list.print();

	list.reverseSLListIter();
	list.print();

	output = testing::internal::GetCapturedStdout();

	//EXPECT_EQ();
}


TEST(D_SLinkedList_Test, getListIntersection_DifferentListLength_Test1) {
	std::string output;
	testing::internal::CaptureStdout();

	SLinkedList<int> list1;
	SLinkedList<int> list2;
	SLinkedList<int> commonNode;
	
	commonNode.addFront(100);						//can SNOde object not call SLinkedList member Functions?

	list1.addToTail(1);
	list1.addToTail(2);
	list1.attatchNodeToTail(commonNode);
	list1.addToTail(4);
	list1.addToTail(5);
	list1.addToTail(6);
	list1.print();

	list2.addToTail(7);
	list2.attatchNodeToTail(commonNode);
	list2.print();


	output = testing::internal::GetCapturedStdout();

	auto val = getListIntersection(list1, list2);


	EXPECT_EQ(val.getNodeAddress(), commonNode.begin().getNodeAddress());
}

TEST(D_SLinkedList_Test, getListIntersection_SameLengthLists_Test2) {
	std::string output;
	testing::internal::CaptureStdout();

	SLinkedList<int> list1;
	SLinkedList<int> list2;
	SLinkedList<int> commonNode;

	commonNode.addFront(100);						//can SNOde object not call SLinkedList member Functions?

	list1.addToTail(1);
	list1.addToTail(2);
	list1.attatchNodeToTail(commonNode);
	list1.addToTail(4);
	list1.addToTail(5);
	list1.addToTail(6);
	list1.print();

	list2.addToTail(7);
	list2.addToTail(8);
	list2.attatchNodeToTail(commonNode);
	list2.print();


	output = testing::internal::GetCapturedStdout();

	auto val = getListIntersection(list1, list2);


	EXPECT_EQ(val.getNodeAddress(), commonNode.begin().getNodeAddress());

}

TEST(D_SLinkedList_Test, getListIntersection_NoCommonNode_Test3) {
	std::string output;
	testing::internal::CaptureStdout();

	SLinkedList<int> list1;
	SLinkedList<int> list2;
	SLinkedList<int> commonNode;

	commonNode.addFront(100);						//can SNOde object not call SLinkedList member Functions?

	list1.addToTail(1);
	list1.addToTail(2);
	//list1.attatchNodeToTail(commonNode);
	list1.addToTail(4);
	list1.addToTail(5);
	list1.addToTail(6);
	list1.print();

	list2.addToTail(7);
	list2.addToTail(8);
	list2.addToTail(9);
	//list2.attatchNodeToTail(commonNode);
	list2.print();


	output = testing::internal::GetCapturedStdout();

	auto val = getListIntersection(list1, list2);

	EXPECT_EQ(val.getNodeAddress(), nullptr);

}



TEST(D_SLinkedList_Test, isPalindrome_Test1) {
	std::string output;
	testing::internal::CaptureStdout();

	std::shared_ptr<SLinkedList<int>> list1 = std::make_shared<SLinkedList<int>>();

	list1->addFront(8);
	list1->addFront(7);
	list1->addFront(9);
	list1->print();

	output = testing::internal::GetCapturedStdout();

	bool res = list1->isPalindrome();

	EXPECT_EQ(res, true);
}

TEST(D_SLinkedList_Test, isPalindrome_Test2) {
	std::string output;
	testing::internal::CaptureStdout();

	std::shared_ptr<SLinkedList<int>> list1 = std::make_shared<SLinkedList<int>>();

	list1->addFront(9);
	list1->addFront(7);
	list1->addFront(9);
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