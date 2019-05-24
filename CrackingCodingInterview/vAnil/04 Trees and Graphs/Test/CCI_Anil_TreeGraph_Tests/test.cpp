#include "pch.h"
#include "../../01 A_RouteBetweenNodes/routebetweennodes.h"
#include "../../02 MinimalTree/MinimalTree.h"
#include "../../03 A_ListsOfDepths/ListsofDepths.h"
#include "../../04 A_CheckBalanced/CheckBalanced.h"
#include "../../05 A_IsBST/IsBST.h"
#include "../../06 A_Successor/Successor.h"

TEST(TreeGraphTests, Test1) {
	Graph gh;
	gh.addEdge("A", { "B", 0 });
	gh.addEdge("B", { "C", 0 });
	gh.addEdge("C", { "E", 0 });
	gh.addEdge("E", { "D", 0 });
	gh.addEdge("E", { "F", 0 });
	gh.addEdge("D", { "B", 0 });

	bool val = gh.IsRouteExist("A", "E");

	EXPECT_EQ(val, true);
}

TEST(TreeGraphTests, Test2) {
	Graph gh;
	gh.addEdge("A", { "B", 0 });
	gh.addEdge("B", { "C", 0 });
	gh.addEdge("C", { "E", 0 });
	gh.addEdge("E", { "D", 0 });
	gh.addEdge("E", { "F", 0 });
	gh.addEdge("D", { "B", 0 });

	bool val = gh.IsRouteExist("B", "D");

	EXPECT_EQ(val, true);
}

TEST(TreeGraphTests, Test3) {
	Graph gh;
	gh.addEdge("A", { "B", 0 });
	gh.addEdge("B", { "C", 0 });
	gh.addEdge("C", { "E", 0 });
	gh.addEdge("E", { "D", 0 });
	gh.addEdge("E", { "F", 0 });
	gh.addEdge("D", { "B", 0 });

	bool val = gh.IsRouteExist("B", "H");

	EXPECT_EQ(val, false);
}

TEST(TreeGraphTests, Test4) {
	Graph gh;
	gh.addEdge("A", { "B", 0 });
	gh.addEdge("B", { "C", 0 });
	gh.addEdge("C", { "E", 0 });
	gh.addEdge("E", { "D", 0 });
	gh.addEdge("E", { "F", 0 });
	gh.addEdge("D", { "B", 0 });
	gh.addEdge("G", { "F", 0 });

	bool val = gh.IsRouteExist("A", "G");

	EXPECT_EQ(val, false);
}


TEST(TreeGraphTests, Test5) {
	Graph gh;
	gh.addEdge("A", { "B", 0 });
	gh.addEdge("B", { "C", 0 });
	gh.addEdge("C", { "E", 0 });
	gh.addEdge("E", { "D", 0 });
	gh.addEdge("E", { "F", 0 });
	gh.addEdge("D", { "B", 0 });
	gh.addEdge("G", { "F", 0 });

	bool val = gh.IsRouteExist("A", "A");

	EXPECT_EQ(val, false);
}


TEST(MinimalTreeTests, Test1) {	
	auto result = makeMinimalTree({1,2,3,4,5,6,7,8,9,10});
}

TEST(ListsOfDepths, Test1) {
	BinaryTree<int> binaryTree;
	binaryTree.insert({100, 50, 150, 25, 75, 125, 175, 15, 90, 10});

	auto lists1 = binaryTree.createLevelLinkedList();
	auto lists2 = binaryTree.createLevelLinkedListIterative();

	EXPECT_EQ(true, lists1 == lists2);

}


TEST(ListsOfDepths, Test2) {
	BinaryTree<int> binaryTree;

	auto lists1 = binaryTree.createLevelLinkedList();
	auto lists2 = binaryTree.createLevelLinkedListIterative();

	EXPECT_EQ(true, lists1 == lists2);
}


TEST(CheckBalanced, Test1) {
	BinaryTreeA<int> binaryTree;
	binaryTree.insert({ 100, 50, 150, 25, 75, 125, 175, 15, 90 });
	auto val = binaryTree.IsBinaryTreeBalanced();

	EXPECT_EQ(true, val);
}

TEST(CheckBalanced, Test2) {
	BinaryTreeA<int> binaryTree;
	binaryTree.insert({ 100, 50, 150, 25, 75, 125, 175, 15, 90, 10 });
	auto val = binaryTree.IsBinaryTreeBalanced();

	EXPECT_EQ(false, val);
}

TEST(IsBST, Test1) {
	BinaryTree5<int> binaryTree;
	binaryTree.insert({ 100, 50, 150, 25, 75, 125, 175, 15, 90, 10 });
	auto val = binaryTree.IsBSTv1();

	EXPECT_EQ(true, val);
}



TEST(IsBST, Test2) {
	BinaryTree5<int> binaryTree;
	binaryTree.insert({ 100, 50, 150, 25, 75, 125, 175, 15, 90, 10, 1, 14, 44,67,43 });
	auto val = binaryTree.IsBSTv1();

	EXPECT_EQ(true, val);
}

TEST(IsBST, Test3) {
	BinaryTree5<int> binaryTree;
	binaryTree.insert({ 100, 50, 150, 25, 75, 125, 175, 15, 90, 10 });
	auto val = binaryTree.IsBSTv2();

	EXPECT_EQ(true, val);
}



TEST(IsBST, Test4) {
	BinaryTree5<int> binaryTree;
	binaryTree.insert({ 100, 50, 150, 25, 75, 125, 175, 15, 90, 10, 1, 14, 44,67,43 });
	auto val = binaryTree.IsBSTv2();

	EXPECT_EQ(true, val);
}


TEST(SUCCESSOR, Test1) {
	BST6<int> binaryTree;
	binaryTree.insert({ 100, 50, 150, 25, 75, 125, 175, 15, 90, 10, 1, 14, 44,67,43 });

	auto ptr = binaryTree.getNodePtr(10);
	auto val = binaryTree.GetSuccessor(ptr);

	EXPECT_EQ(14, val->data);
}

TEST(SUCCESSOR, Test2) {
	BST6<int> binaryTree;
	binaryTree.insert({ 100, 50, 150, 25, 75, 125, 175, 15, 90, 10, 1, 14, 44,67,43 });

	auto ptr = binaryTree.getNodePtr(175);
	auto val = binaryTree.GetSuccessor(ptr);

	EXPECT_EQ(nullptr, val);
}

TEST(SUCCESSOR, Test3) {
	BST6<int> binaryTree;
	binaryTree.insert({ 100, 50, 150, 25, 75, 125, 175, 15, 90, 10, 1, 14, 44,67,43 });

	auto ptr = binaryTree.getNodePtr(100);
	auto val = binaryTree.GetSuccessor(ptr);

	EXPECT_EQ(125, val->data);
}

TEST(SUCCESSOR, Test4) {
	BST6<int> binaryTree;
	binaryTree.insert({ 100, 50, 150, 25, 75, 125, 175, 15, 90, 10, 1, 14, 44,67,43 });

	auto ptr = binaryTree.getNodePtr(1);
	auto val = binaryTree.GetSuccessor(ptr);

	EXPECT_EQ(10, val->data);
}