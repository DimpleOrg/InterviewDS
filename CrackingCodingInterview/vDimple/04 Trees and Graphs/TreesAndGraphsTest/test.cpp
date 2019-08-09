#include "pch.h"
#include"..\GraphsAlgorithms\BellmanFord\BellmanFord.h"
#include"..\GraphsAlgorithms\TopologicalSort\TopologicalSort.h"
#include"..\GraphsAlgorithms\PriorityQueue_MaxHeap\PriorityQueue_MaxHeap.h"
#include"..\..\04 Trees and Graphs\RouteBetweenNodes\RouteBetweenNodes.h"
#include"..\..\04 Trees and Graphs\MinimalTreeD\MinimalTree.h"
#include"..\..\04 Trees and Graphs\ListOfDepthD\ListOfDepthD.h"
#include"..\..\04 Trees and Graphs\isBalancedD\isBalancedD.h"
#include"..\..\04 Trees and Graphs\05 isBSTD\isBSTD.h"
#include"..\..\04 Trees and Graphs\06 Successor\Successor.h"
#include"..\..\04 Trees and Graphs\07 BuildOrder\BuildOrder.h"
#include"..\..\04 Trees and Graphs\08 FirstCommonAncestorD\FirstCommonAncestorD.h"
#include"..\..\04 Trees and Graphs\09 BSRSequenceD\BSTSequenceD.h"
#include"..\..\04 Trees and Graphs\10 ChkSubTreeD\ChkSubTreeD.h"
#include"..\..\04 Trees and Graphs\11 RandomNode\RandomNode.h"
#include"..\..\04 Trees and Graphs\12 PathsWithSumD\PathsWithSumD.h"

TEST(D_PathsWithSum, Test1)
{
	std::string output;
	testing::internal::CaptureStdout();

	BTree_03<int> obj;
	obj.insertNode(2);	//				 2
	obj.insertNode(4);	/*				/ \			*/
	obj.insertNode(6);	//			    4  6
	obj.insertNode(1);	/*			   / \ /\		*/
	obj.insertNode(3);	//			  1  3 0 0
	obj.insertNode(0);	/*			 /\  /\			*/
	obj.insertNode(0);	//			 8 2 0 1
	obj.insertNode(8);
	obj.insertNode(2);
	obj.insertNode(0);
	obj.insertNode(1);

	int res = obj.countPaths(6);
	int expRes = 6;

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(res, expRes);
}

TEST(D_PathsWithSum, Test2)
{
	std::string output;
	testing::internal::CaptureStdout();

	BTree_03<int> obj;
	obj.insertNode(2);	//				 2
	obj.insertNode(4);	/*				/ \			*/
	obj.insertNode(6);	//			    4  6
	obj.insertNode(1);	/*			   / \ /\		*/
	obj.insertNode(3);	//			  1  3 0 0
	obj.insertNode(0);	/*			 /\  /\			*/
	obj.insertNode(0);	//			 8 2 0 1
	obj.insertNode(8);
	obj.insertNode(2);
	obj.insertNode(0);
	obj.insertNode(1);

	int res = obj.countPaths(8);
	int expRes = 6;

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(res, expRes);
}

TEST(D_PathsWithSum, Test3)
{
	std::string output;
	testing::internal::CaptureStdout();

	BTree_03<int> obj;
	obj.insertNode(2);	//				 2
	obj.insertNode(4);	/*				/ \			*/
	obj.insertNode(6);	//			    4  6
	obj.insertNode(1);	/*			   / \ /\		*/
	obj.insertNode(3);	//			  1  3 0 0
	obj.insertNode(0);	/*			 /\  /\			*/
	obj.insertNode(0);	//			 8 2 0 1
	obj.insertNode(8);
	obj.insertNode(2);
	obj.insertNode(0);
	obj.insertNode(1);

	int res = obj.countPaths(50);
	int expRes = 0;

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(res, expRes);
}

TEST(D_PathsWithSum, Test4)
{
	std::string output;
	testing::internal::CaptureStdout();

	BTree_03<int> obj;
	obj.insertNode(1);	//				 1
	obj.insertNode(5);	/*				/ \			*/
	obj.insertNode(-3);	//			    5  -3
	obj.insertNode(3);	/*			   / \  /\		*/
	obj.insertNode(1);	//			  3   1 0 11
	obj.insertNode(0);	/*			 /\   /\		*/
	obj.insertNode(11);	//			 3 -2 0 2
	obj.insertNode(3);
	obj.insertNode(-2);
	obj.insertNode(0);
	obj.insertNode(2);

	int res = obj.countPaths(6);
	int expRes = 8;

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(res, expRes);
}


TEST(D_GetRandomNode, Test1)
{
	std::string output;
	testing::internal::CaptureStdout();

	BTree_02<int> obj;
	obj.insertNode(90);	//https://upload.wikimedia.org/wikipedia/commons/9/9e/Бинарлық_іздеу.gif
	obj.insertNode(50);
	obj.insertNode(150);
	obj.insertNode(20);
	obj.insertNode(75);
	obj.insertNode(95);
	obj.insertNode(175);

	obj.print();

	auto node = obj.getRandomNode();
	node = obj.getRandomNode();
	node = obj.getRandomNode();

	obj.insertNode(5);
	obj.insertNode(25);
	obj.insertNode(66);
	obj.insertNode(80);
	obj.insertNode(92);
	obj.insertNode(111);
	obj.insertNode(166);
	obj.insertNode(200);

	cout << "\n\n";
	obj.print();

	node = obj.getRandomNode();

	obj.deleteNode(50);
	obj.deleteNode(150);
	obj.deleteNode(20);
	obj.deleteNode(75);
	obj.deleteNode(95);
	obj.deleteNode(175);
	obj.deleteNode(5);
	obj.deleteNode(25);
	obj.deleteNode(66);
	obj.deleteNode(80);
	obj.deleteNode(92);
	obj.deleteNode(111);
	obj.deleteNode(166);

	cout << "\n\n";
	obj.print();

	node = obj.getRandomNode();
	node = obj.getRandomNode();
	node = obj.getRandomNode();

	output = testing::internal::GetCapturedStdout();

}

TEST(D_GetRandomNode, Test2)
{
	std::string output;
	testing::internal::CaptureStdout();

	BTree_02<int> obj;
	obj.insertNode(90);	//https://upload.wikimedia.org/wikipedia/commons/9/9e/Бинарлық_іздеу.gif
	obj.insertNode(50);
	obj.insertNode(150);
	obj.insertNode(20);
	obj.insertNode(95);

	obj.print();

	auto node = obj.getRandomNode();
	node = obj.getRandomNode();
	node = obj.getRandomNode();

	cout << "\n\n";
	obj.print();

	node = obj.getRandomNode();

	obj.deleteNode(50);
	obj.deleteNode(150);
	obj.deleteNode(20);

	cout << "\n\n";
	obj.print();

	node = obj.getRandomNode();
	node = obj.getRandomNode();
	node = obj.getRandomNode();
	node = obj.getRandomNode();
	node = obj.getRandomNode();
	node = obj.getRandomNode();
	node = obj.getRandomNode();
	node = obj.getRandomNode();
	node = obj.getRandomNode();

	output = testing::internal::GetCapturedStdout();

}


TEST(D_ChkSubTree, Test1)
{
	std::string output;
	testing::internal::CaptureStdout();

	BTree_01<int> obj;
	obj.insertNode(90);	//https://upload.wikimedia.org/wikipedia/commons/9/9e/Бинарлық_іздеу.gif
	obj.insertNode(50);
	obj.insertNode(150);
	obj.insertNode(20);
	obj.insertNode(75);
	obj.insertNode(95);
	obj.insertNode(175);
	obj.insertNode(5);
	obj.insertNode(25);
	obj.insertNode(66);
	obj.insertNode(80);
	obj.insertNode(92);
	obj.insertNode(111);
	obj.insertNode(166);
	obj.insertNode(200);

	std::cout << "Printing 1st Tree:\n";
	obj.print(obj.root);

	BTree_01<int> obj2;
	obj2.insertNode(93);
	obj2.insertNode(76);
	obj2.insertNode(105);
	obj2.insertNode(75);
	obj2.insertNode(0);
	obj2.insertNode(75);
	obj2.insertNode(0);
	obj2.insertNode(67);
	obj2.insertNode(80);
	obj2.insertNode(66);
	obj2.insertNode(80);

	std::cout << "\n\nPrinting 2nd Tree:\n";
	obj2.print(obj2.root);

	auto r1 = obj.getNode(90);
	auto r2 = obj2.getNode(93);

	bool res = obj.chkSubTree(r1, r2);
	bool expRes = false;

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(res, expRes);
}

TEST(D_ChkSubTree, Test2)
{
	std::string output;
	testing::internal::CaptureStdout();

	BTree_01<int> obj;
	obj.insertNode(90);	//https://upload.wikimedia.org/wikipedia/commons/9/9e/Бинарлық_іздеу.gif
	obj.insertNode(50);
	obj.insertNode(150);
	obj.insertNode(20);
	obj.insertNode(75);
	obj.insertNode(95);
	obj.insertNode(175);
	obj.insertNode(5);
	obj.insertNode(25);
	obj.insertNode(66);
	obj.insertNode(80);
	obj.insertNode(92);
	obj.insertNode(111);
	obj.insertNode(166);
	obj.insertNode(200);

	std::cout << "Printing 1st Tree:\n";
	obj.print(obj.root);

	BTree_01<int> obj2;
	obj2.insertNode(75);
	obj2.insertNode(66);
	obj2.insertNode(80);

	std::cout << "\n\nPrinting 2nd Tree:\n";
	obj2.print(obj2.root);

	auto r1 = obj.getNode(90);
	auto r2 = obj2.getNode(75);

	bool res = obj.chkSubTree(r1, r2);
	bool expRes = true;

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(res, expRes);
}

TEST(D_BSTSequence, Test1)
{
	std::string output;
	testing::internal::CaptureStdout();

	BinSTree<int> obj;
	obj.insertNode(2);	//https://upload.wikimedia.org/wikipedia/commons/9/9e/Бинарлық_іздеу.gif
	obj.insertNode(1);
	obj.insertNode(3);

	auto root = obj.getNode(2);
	std::list<std::list<int>> res = obj.getBSTSequences(root);
	std::list<std::list<int>> expRes = { {2,1,3},{2,3,1} };
	
	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(res, expRes);
}

TEST(D_FindCommonAncestorV2, Test1)
{
	std::string output;
	testing::internal::CaptureStdout();

	BSrchTree<int> obj;
	obj.insertNode(90);	//https://upload.wikimedia.org/wikipedia/commons/9/9e/Бинарлық_іздеу.gif
	obj.insertNode(50);
	obj.insertNode(150);
	obj.insertNode(20);
	obj.insertNode(75);
	obj.insertNode(95);
	obj.insertNode(175);
	obj.insertNode(5);
	obj.insertNode(25);
	obj.insertNode(66);
	obj.insertNode(80);
	obj.insertNode(92);
	obj.insertNode(111);
	obj.insertNode(166);
	obj.insertNode(200);

	std::shared_ptr<bsrchtnode<int>> root = obj.getNode(90);
	std::shared_ptr<bsrchtnode<int>> node1 = obj.getNode(5);
	std::shared_ptr<bsrchtnode<int>> node2 = obj.getNode(111);

	std::shared_ptr<bsrchtnode<int>> node3 = obj.getCommonAncestorV2(root, node1, node2);

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(node3->data, 90);
}

TEST(D_FindCommonAncestorV2, Test2)
{
	std::string output;
	testing::internal::CaptureStdout();

	BSrchTree<int> obj;
	obj.insertNode(90);	//https://upload.wikimedia.org/wikipedia/commons/9/9e/Бинарлық_іздеу.gif
	obj.insertNode(50);
	obj.insertNode(150);
	obj.insertNode(20);
	obj.insertNode(75);
	obj.insertNode(95);
	obj.insertNode(175);
	obj.insertNode(5);
	obj.insertNode(25);
	obj.insertNode(66);
	obj.insertNode(80);
	obj.insertNode(92);
	obj.insertNode(111);
	obj.insertNode(166);
	obj.insertNode(200);

	std::shared_ptr<bsrchtnode<int>> root = obj.getNode(90);
	std::shared_ptr<bsrchtnode<int>> node1 = obj.getNode(5);
	std::shared_ptr<bsrchtnode<int>> node2 = obj.getNode(20);

	std::shared_ptr<bsrchtnode<int>> node3 = obj.getCommonAncestorV2(root, node1, node2);

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(node3->data, 20);
}

TEST(D_FindCommonAncestorV2, Test3)
{
	std::string output;
	testing::internal::CaptureStdout();

	BSrchTree<int> obj;
	obj.insertNode(90);	//https://upload.wikimedia.org/wikipedia/commons/9/9e/Бинарлық_іздеу.gif
	obj.insertNode(50);
	obj.insertNode(150);
	obj.insertNode(20);
	obj.insertNode(75);
	obj.insertNode(95);
	obj.insertNode(175);
	obj.insertNode(5);
	obj.insertNode(25);
	obj.insertNode(66);
	obj.insertNode(80);
	obj.insertNode(92);
	obj.insertNode(111);
	obj.insertNode(166);
	obj.insertNode(200);

	std::shared_ptr<bsrchtnode<int>> root = obj.getNode(90);
	std::shared_ptr<bsrchtnode<int>> node1 = obj.getNode(20);
	std::shared_ptr<bsrchtnode<int>> node2 = obj.getNode(76);		//not in the tree

	std::shared_ptr<bsrchtnode<int>> node3 = obj.getCommonAncestorV2(root, node1, node2);

	if (!node3)
		std::cout << "NULL";

	output = testing::internal::GetCapturedStdout();
}

TEST(D_FindCommonAncestorV2, Test4)
{
	std::string output;
	testing::internal::CaptureStdout();

	BSrchTree<int> obj;
	obj.insertNode(90);	//https://upload.wikimedia.org/wikipedia/commons/9/9e/Бинарлық_іздеу.gif
	obj.insertNode(50);
	obj.insertNode(150);
	obj.insertNode(20);
	obj.insertNode(75);
	obj.insertNode(95);
	obj.insertNode(175);
	obj.insertNode(5);
	obj.insertNode(25);
	obj.insertNode(66);
	obj.insertNode(80);
	obj.insertNode(92);
	obj.insertNode(111);
	obj.insertNode(166);
	obj.insertNode(200);

	std::shared_ptr<bsrchtnode<int>> root = obj.getNode(90);
	std::shared_ptr<bsrchtnode<int>> node1 = obj.getNode(90);
	std::shared_ptr<bsrchtnode<int>> node2 = obj.getNode(150);		//not in the tree

	std::shared_ptr<bsrchtnode<int>> node3 = obj.getCommonAncestorV2(root, node1, node2);

	if (!node3)
		std::cout << "NULL";
	else
		EXPECT_EQ(node3->data, 90);

	output = testing::internal::GetCapturedStdout();
}


TEST(D_FindCommonAncestorV1, Test1)
{
	std::string output;
	testing::internal::CaptureStdout();

	BSrchTree<int> obj;
	obj.insertNode(90);	//https://upload.wikimedia.org/wikipedia/commons/9/9e/Бинарлық_іздеу.gif
	obj.insertNode(50);
	obj.insertNode(150);
	obj.insertNode(20);
	obj.insertNode(75);
	obj.insertNode(95);
	obj.insertNode(175);
	obj.insertNode(5);
	obj.insertNode(25);
	obj.insertNode(66);
	obj.insertNode(80);
	obj.insertNode(92);
	obj.insertNode(111);
	obj.insertNode(166);
	obj.insertNode(200);

	std::shared_ptr<bsrchtnode<int>> node1 = obj.getNode(5);
	std::shared_ptr<bsrchtnode<int>> node2 = obj.getNode(111);

	std::shared_ptr<bsrchtnode<int>> node3 = obj.getCommonAncestorV1(node1, node2);

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(node3->data, 90);
}

TEST(D_FindCommonAncestorV1, Test2)
{
	std::string output;
	testing::internal::CaptureStdout();

	BSrchTree<int> obj;
	obj.insertNode(90);	//https://upload.wikimedia.org/wikipedia/commons/9/9e/Бинарлық_іздеу.gif
	obj.insertNode(50);
	obj.insertNode(150);
	obj.insertNode(20);
	obj.insertNode(75);
	obj.insertNode(95);
	obj.insertNode(175);
	obj.insertNode(5);
	obj.insertNode(25);
	obj.insertNode(66);
	obj.insertNode(80);
	obj.insertNode(92);
	obj.insertNode(111);
	obj.insertNode(166);
	obj.insertNode(200);

	std::shared_ptr<bsrchtnode<int>> node1 = obj.getNode(5);
	std::shared_ptr<bsrchtnode<int>> node2 = obj.getNode(20);

	std::shared_ptr<bsrchtnode<int>> node3 = obj.getCommonAncestorV1(node1, node2);

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(node3->data, 20);
}

TEST(D_FindCommonAncestorV1, Test3)
{
	std::string output;
	testing::internal::CaptureStdout();

	BSrchTree<int> obj;
	obj.insertNode(90);	//https://upload.wikimedia.org/wikipedia/commons/9/9e/Бинарлық_іздеу.gif
	obj.insertNode(50);
	obj.insertNode(150);
	obj.insertNode(20);
	obj.insertNode(75);
	obj.insertNode(95);
	obj.insertNode(175);
	obj.insertNode(5);
	obj.insertNode(25);
	obj.insertNode(66);
	obj.insertNode(80);
	obj.insertNode(92);
	obj.insertNode(111);
	obj.insertNode(166);
	obj.insertNode(200);

	std::shared_ptr<bsrchtnode<int>> node1 = obj.getNode(20);
	std::shared_ptr<bsrchtnode<int>> node2 = obj.getNode(76);		//not in the tree

	std::shared_ptr<bsrchtnode<int>> node3 = obj.getCommonAncestorV1(node1, node2);
	
	if (!node3)
		std::cout << "NULL";

	output = testing::internal::GetCapturedStdout();
}

TEST(D_FindCommonAncestorV1, Test4)
{
	std::string output;
	testing::internal::CaptureStdout();

	BSrchTree<int> obj;
	obj.insertNode(90);	//https://upload.wikimedia.org/wikipedia/commons/9/9e/Бинарлық_іздеу.gif
	obj.insertNode(50);
	obj.insertNode(150);
	obj.insertNode(20);
	obj.insertNode(75);
	obj.insertNode(95);
	obj.insertNode(175);
	obj.insertNode(5);
	obj.insertNode(25);
	obj.insertNode(66);
	obj.insertNode(80);
	obj.insertNode(92);
	obj.insertNode(111);
	obj.insertNode(166);
	obj.insertNode(200);

	std::shared_ptr<bsrchtnode<int>> node1 = obj.getNode(90);
	std::shared_ptr<bsrchtnode<int>> node2 = obj.getNode(150);		//not in the tree

	std::shared_ptr<bsrchtnode<int>> node3 = obj.getCommonAncestorV1(node1, node2);

	if (!node3)
		std::cout << "NULL";
	else
		EXPECT_EQ(node3->data, 90);

	output = testing::internal::GetCapturedStdout();
}

TEST(D_BuildOrder, Test1)
{
	std::string output;
	testing::internal::CaptureStdout();

	BuildOrder<char> obj;
	std::stack<char> res;
	std::vector<char> projs { 'a','b','c','d','e','f' };
	std::list<std::pair<char, char>> pop{ std::make_pair<char,char>('a','d'), std::make_pair<char,char>('f','b'),std::make_pair<char,char>('b','d'),std::make_pair<char,char>('f','a'),std::make_pair<char,char>('d','c') };
	res = obj.getBuildOrder(projs, pop);

	output = testing::internal::GetCapturedStdout();
}

TEST(D_GetSuccessorV2, Test1)
{
	std::string output;
	testing::internal::CaptureStdout();

	BSTree<int> obj;
	obj.insertNode(90);	//https://upload.wikimedia.org/wikipedia/commons/9/9e/Бинарлық_іздеу.gif
	obj.insertNode(50);
	obj.insertNode(150);
	obj.insertNode(20);
	obj.insertNode(75);
	obj.insertNode(95);
	obj.insertNode(175);
	obj.insertNode(5);
	obj.insertNode(25);
	obj.insertNode(66);
	obj.insertNode(80);
	obj.insertNode(92);
	obj.insertNode(111);
	obj.insertNode(166);
	obj.insertNode(200);

	std::shared_ptr<bstnode<int>> srcNode = obj.getNode(90);
	std::shared_ptr<bstnode<int>> resNode = obj.getSuccessorV2(srcNode);
	int res = resNode->data;
	int expectedOutput = 92;

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(res, expectedOutput);
}

TEST(D_GetSuccessorV2, Test2)
{
	std::string output;
	testing::internal::CaptureStdout();

	BSTree<int> obj;
	obj.insertNode(90);	//https://upload.wikimedia.org/wikipedia/commons/9/9e/Бинарлық_іздеу.gif
	obj.insertNode(50);
	obj.insertNode(150);
	obj.insertNode(20);
	obj.insertNode(75);
	obj.insertNode(95);
	obj.insertNode(175);
	obj.insertNode(5);
	obj.insertNode(25);
	obj.insertNode(66);
	obj.insertNode(80);
	obj.insertNode(92);
	obj.insertNode(111);
	obj.insertNode(166);
	obj.insertNode(200);

	std::shared_ptr<bstnode<int>> srcNode = obj.getNode(5);
	std::shared_ptr<bstnode<int>> resNode = obj.getSuccessorV2(srcNode);
	int res = resNode->data;
	int expectedOutput = 20;

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(res, expectedOutput);
}

TEST(D_GetSuccessorV2, Test3)
{
	std::string output;
	testing::internal::CaptureStdout();

	BSTree<int> obj;
	obj.insertNode(90);	//https://upload.wikimedia.org/wikipedia/commons/9/9e/Бинарлық_іздеу.gif
	obj.insertNode(50);
	obj.insertNode(150);
	obj.insertNode(20);
	obj.insertNode(75);
	obj.insertNode(95);
	obj.insertNode(175);
	obj.insertNode(5);
	obj.insertNode(25);
	obj.insertNode(66);
	obj.insertNode(80);
	obj.insertNode(92);
	obj.insertNode(111);
	obj.insertNode(166);
	obj.insertNode(200);

	std::shared_ptr<bstnode<int>> srcNode = obj.getNode(80);
	std::shared_ptr<bstnode<int>> resNode = obj.getSuccessorV2(srcNode);
	int res = resNode->data;
	int expectedOutput = 90;

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(res, expectedOutput);
}

TEST(D_GetSuccessorV2, Test4)
{
	std::string output;
	testing::internal::CaptureStdout();

	BSTree<int> obj;
	obj.insertNode(90);	//https://upload.wikimedia.org/wikipedia/commons/9/9e/Бинарлық_іздеу.gif
	obj.insertNode(50);
	obj.insertNode(150);
	obj.insertNode(20);
	obj.insertNode(75);
	obj.insertNode(95);
	obj.insertNode(175);
	obj.insertNode(5);
	obj.insertNode(25);
	obj.insertNode(66);
	obj.insertNode(80);
	obj.insertNode(92);
	obj.insertNode(111);
	obj.insertNode(166);
	obj.insertNode(200);

	int res;
	std::shared_ptr<bstnode<int>> expectedOutput;

	std::shared_ptr<bstnode<int>> srcNode = obj.getNode(200);
	std::shared_ptr<bstnode<int>> resNode = obj.getSuccessorV2(srcNode);

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(resNode, expectedOutput);
}



TEST(D_GetSuccessorV1, Test1)
{
	std::string output;
	testing::internal::CaptureStdout();

	BSTree<int> obj;
	obj.insertNode(90);	//https://upload.wikimedia.org/wikipedia/commons/9/9e/Бинарлық_іздеу.gif
	obj.insertNode(50);
	obj.insertNode(150);
	obj.insertNode(20);
	obj.insertNode(75);
	obj.insertNode(95);
	obj.insertNode(175);
	obj.insertNode(5);
	obj.insertNode(25);
	obj.insertNode(66);
	obj.insertNode(80);
	obj.insertNode(92);
	obj.insertNode(111);
	obj.insertNode(166);
	obj.insertNode(200);

	std::shared_ptr<bstnode<int>> resNode = obj.getSuccessorV1(90);
	int res = resNode->data;
	int expectedOutput = 92;

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(res, expectedOutput);
}

TEST(D_GetSuccessorV1, Test2)
{
	std::string output;
	testing::internal::CaptureStdout();

	BSTree<int> obj;
	obj.insertNode(90);	//https://upload.wikimedia.org/wikipedia/commons/9/9e/Бинарлық_іздеу.gif
	obj.insertNode(50);
	obj.insertNode(150);
	obj.insertNode(20);
	obj.insertNode(75);
	obj.insertNode(95);
	obj.insertNode(175);
	obj.insertNode(5);
	obj.insertNode(25);
	obj.insertNode(66);
	obj.insertNode(80);
	obj.insertNode(92);
	obj.insertNode(111);
	obj.insertNode(166);
	obj.insertNode(200);

	std::shared_ptr<bstnode<int>> resNode = obj.getSuccessorV1(5);
	int res = resNode->data;
	int expectedOutput = 20;

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(res, expectedOutput);
}

TEST(D_GetSuccessorV1, Test3)
{
	std::string output;
	testing::internal::CaptureStdout();

	BSTree<int> obj;
	obj.insertNode(90);	//https://upload.wikimedia.org/wikipedia/commons/9/9e/Бинарлық_іздеу.gif
	obj.insertNode(50);
	obj.insertNode(150);
	obj.insertNode(20);
	obj.insertNode(75);
	obj.insertNode(95);
	obj.insertNode(175);
	obj.insertNode(5);
	obj.insertNode(25);
	obj.insertNode(66);
	obj.insertNode(80);
	obj.insertNode(92);
	obj.insertNode(111);
	obj.insertNode(166);
	obj.insertNode(200);

	std::shared_ptr<bstnode<int>> resNode = obj.getSuccessorV1(80);
	int res = resNode->data;
	int expectedOutput = 90;

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(res, expectedOutput);
}

TEST(D_GetSuccessorV1, Test4)
{
	std::string output;
	testing::internal::CaptureStdout();

	BSTree<int> obj;
	obj.insertNode(90);	//https://upload.wikimedia.org/wikipedia/commons/9/9e/Бинарлық_іздеу.gif
	obj.insertNode(50);
	obj.insertNode(150);
	obj.insertNode(20);
	obj.insertNode(75);
	obj.insertNode(95);
	obj.insertNode(175);
	obj.insertNode(5);
	obj.insertNode(25);
	obj.insertNode(66);
	obj.insertNode(80);
	obj.insertNode(92);
	obj.insertNode(111);
	obj.insertNode(166);
	obj.insertNode(200);

	int res;
	std::shared_ptr<bstnode<int>> expectedOutput;

	std::shared_ptr<bstnode<int>> resNode = obj.getSuccessorV1(200);

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(resNode, expectedOutput);
}

TEST(D_isBST, Test1)
{
	std::string output;
	testing::internal::CaptureStdout();

	BTree<int> obj;
	obj.insertNode(7);	//https://www.google.com/url?sa=i&rct=j&q=&esrc=s&source=images&cd=&cad=rja&uact=8&ved=2ahUKEwiTgtqHw4niAhURiqwKHZKXDssQjRx6BAgBEAU&url=https%3A%2F%2Fopendatastructures.org%2Fversions%2Fedition-0.1d%2Fods-java%2Fnode37.html&psig=AOvVaw3GOC7lcMh0mRbwLq5ChJN5&ust=1557146817963642
	obj.insertNode(3);
	obj.insertNode(11);
	obj.insertNode(1);
	obj.insertNode(5);
	obj.insertNode(9);
	obj.insertNode(13);
	obj.insertNode(4);
	obj.insertNode(6);
	obj.insertNode(8);
	obj.insertNode(12);
	obj.insertNode(14);

	bool res = obj.isBalanced();
	bool expectedOutput = true;

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(res, expectedOutput);
}

TEST(D_isBalanced, Test1)
{
	std::string output;
	testing::internal::CaptureStdout();

	BTree<int> obj;
	obj.insertNode(7);	//https://www.google.com/url?sa=i&rct=j&q=&esrc=s&source=images&cd=&cad=rja&uact=8&ved=2ahUKEwiTgtqHw4niAhURiqwKHZKXDssQjRx6BAgBEAU&url=https%3A%2F%2Fopendatastructures.org%2Fversions%2Fedition-0.1d%2Fods-java%2Fnode37.html&psig=AOvVaw3GOC7lcMh0mRbwLq5ChJN5&ust=1557146817963642
	obj.insertNode(3);
	obj.insertNode(11);
	obj.insertNode(1);
	obj.insertNode(5);
	obj.insertNode(9);
	obj.insertNode(13);
	obj.insertNode(4);
	obj.insertNode(6);
	obj.insertNode(8);
	obj.insertNode(12);
	obj.insertNode(14);

	bool res = obj.isBalanced();
	bool expectedOutput = true;

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(res, expectedOutput);
}

TEST(D_ListOfNodes, Test1)
{
	std::string output;
	testing::internal::CaptureStdout();

	bTree<int> obj;
	obj.insertNode(7);	//https://www.google.com/url?sa=i&rct=j&q=&esrc=s&source=images&cd=&cad=rja&uact=8&ved=2ahUKEwiTgtqHw4niAhURiqwKHZKXDssQjRx6BAgBEAU&url=https%3A%2F%2Fopendatastructures.org%2Fversions%2Fedition-0.1d%2Fods-java%2Fnode37.html&psig=AOvVaw3GOC7lcMh0mRbwLq5ChJN5&ust=1557146817963642
	obj.insertNode(3);
	obj.insertNode(11);
	obj.insertNode(1);
	obj.insertNode(5);
	obj.insertNode(9);
	obj.insertNode(13);
	obj.insertNode(4);
	obj.insertNode(6);
	obj.insertNode(8);
	obj.insertNode(12);
	obj.insertNode(14);

	vector<list<int>> res = obj.listOfNodes();

	output = testing::internal::GetCapturedStdout();

	//EXPECT_EQ(res, expectedOutput);
}


TEST(D_MinimalTree, Test1)
{
	std::string output;
	testing::internal::CaptureStdout();

	int arr[7] = { 2,5,10,23,35,48,52 };
	std::vector<int> res = makeMT(arr, 7);

	std::vector<int> expectedOutput = { 23,5,2,10,48,35,52 };
	output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(res, expectedOutput);
}

TEST(D_RouteBetweenNodes, Test1)
{
	std::string output;
	testing::internal::CaptureStdout();

	std::vector<std::vector<int>> adj;	//0->1->2  1->3  2->4  3->2  4-->
	std::vector<int> subvec;
	subvec.push_back(1);
	subvec.push_back(2);
	adj.push_back(subvec);
	
	subvec.clear();
	subvec.push_back(3);
	adj.push_back(subvec);
	
	subvec.clear();
	subvec.push_back(4);
	adj.push_back(subvec);
	
	subvec.clear();
	subvec.push_back(2);
	adj.push_back(subvec);

	subvec.clear();
	subvec.push_back(4);
	adj.push_back(subvec);

	bool res = rootBetweenNodes(0, 4, adj);

	output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(res, true);
}

TEST(D_TreesAndGraphsTest, PriorityQueue_Test1) {
	std::string output;
	testing::internal::CaptureStdout();

	MaxHeap<int> mh;
	mh.push(3);
	mh.push(2);
	mh.push(15);

	std::cout << mh.top();
	mh.pop();
	std::cout << "	";
	std::cout << mh.top();
	mh.pop();
	std::cout << std::endl;

	mh.push(5);
	mh.push(4);
	mh.push(45);

	std::cout << mh.top();
	mh.pop();
	std::cout << "	";
	std::cout << mh.top();
	mh.pop();
	std::cout << "	";
	std::cout << mh.top();
	mh.pop();
	std::cout << "	";
	std::cout << mh.top();
	mh.pop();

	output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(1, 1);
}

TEST(D_TreesAndGraphsTest, BellmanFordTest1) {
	std::string output;
	testing::internal::CaptureStdout();

	GraphBellmanFord obj(5, 8);
	obj.setEdges(0, 1, -1);
	obj.setEdges(0, 2, 4 );
	obj.setEdges(1, 2, 3 );
	obj.setEdges(1, 3, 2 );
	obj.setEdges(1, 4, 2 );
	obj.setEdges(3, 2, 5 );
	obj.setEdges(3, 1, 1 );
	obj.setEdges(4, 3, -3 );

	obj.bellmanFord(0);
	bool negCycleFound = obj.isNegativeCycleFound();
	
	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(1, 1);
}

TEST(D_TreesAndGraphsTest, TopologicalSortTest1) {
	std::string output;
	testing::internal::CaptureStdout();

	TopologicalSort ts(6);
	ts.addEdge(5, 2);
	ts.addEdge(5, 0);
	ts.addEdge(4, 0);
	ts.addEdge(4, 1);
	ts.addEdge(2, 3);
	ts.addEdge(3, 1);

	ts.topologicalSorting();
	ts.print();

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(1, 1);
}