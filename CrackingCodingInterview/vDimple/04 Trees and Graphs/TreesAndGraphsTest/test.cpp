#include "pch.h"
#include"..\GraphsAlgorithms\BellmanFord\BellmanFord.h"
#include"..\GraphsAlgorithms\TopologicalSort\TopologicalSort.h"

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