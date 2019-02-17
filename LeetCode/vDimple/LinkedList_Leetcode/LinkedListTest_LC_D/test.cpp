#include "pch.h"
#include"..\LinkedList_LC\LinkedList_LC.h"

TEST(removeNodeNFromLast, removeNodeNFromLastTest1) {
	std::string output;
	testing::internal::CaptureStdout();

	SLinkedList<int> LL;
	LL.addNode(4);
	LL.addNode(3);
	LL.addNode(2);
	LL.addNode(1);
	LL.print();
	int k = 2;
	LL.removeNodeNFromLast(k);
	LL.print();

	output = testing::internal::GetCapturedStdout();
}