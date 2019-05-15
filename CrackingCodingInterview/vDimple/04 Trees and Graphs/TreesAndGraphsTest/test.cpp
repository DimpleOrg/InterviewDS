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