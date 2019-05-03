#include "pch.h"
#include"..\GraphsAlgorithms\BellmanFord\BellmanFord.h"
#include"..\GraphsAlgorithms\TopologicalSort\TopologicalSort.h"
#include"..\GraphsAlgorithms\PriorityQueue_MaxHeap\PriorityQueue_MaxHeap.h"
#include"..\..\04 Trees and Graphs\RouteBetweenNodes\RouteBetweenNodes.h"
#include"..\..\04 Trees and Graphs\MinimalTreeD\MinimalTree.h"

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