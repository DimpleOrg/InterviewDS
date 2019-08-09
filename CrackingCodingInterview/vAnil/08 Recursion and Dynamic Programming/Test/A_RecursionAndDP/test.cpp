#include "pch.h"
#include "../../01 A_TripleStep/TripleStep.h"
#include "../../02 A_RobotInGrid/robotheader.h"

TEST(A_01_TripleStep, Test1) {

	size_t count = CountStairCaseHopMethods(5);
	EXPECT_EQ(count, 13);

}

TEST(A_01_TripleStep, Test2) {
	size_t count = CountStairCaseHopMethods(37);
	EXPECT_EQ(count, 3831006429);
}


TEST(A_01_TripleStep, Test3) {
	size_t count = CountStairCaseHopMethodsDP(37);
	EXPECT_EQ(count, 3831006429);
}


TEST(A_01_TripleStep, Test4) {
	size_t count = CountStairCaseHopMethodsDP(51);
	EXPECT_EQ(count, 19426970897100);
}

TEST(A_02_RobotGrid, Test1) {
	std::unordered_multimap<int, int> dlist;
	dlist.insert({ 0,1 });
	dlist.insert({ 0,2 });
	size_t count = coutNumWaysV1(3,3, dlist);
	EXPECT_EQ(count, 3);
}

TEST(A_02_RobotGrid, Test2) {
	std::unordered_multimap<int, int> dlist;
	dlist.insert({ 0,1 });
	dlist.insert({ 0,2 });
	size_t count = coutNumWaysV2(3, 3, dlist);
	EXPECT_EQ(count, 3);
}


TEST(A_02_RobotGrid, Test3) {
	std::unordered_multimap<int, int> dlist;
	dlist.insert({ 0,1 });
	dlist.insert({ 0,2 });
	size_t count1 = coutNumWaysV1(9, 9, dlist);
	size_t count2 = coutNumWaysV2(9, 9, dlist);
	EXPECT_EQ(count1, count2);
}

TEST(A_02_RobotGrid, Test4) {
	std::unordered_multimap<int, int> dlist;
	dlist.insert({ 0,1 });
	dlist.insert({ 0,2 });
	dlist.insert({ 4,4 });
	auto val = getPath(9, 9, dlist);
	EXPECT_EQ(17, val.size());
}


TEST(A_02_RobotGrid, Test5) {
	std::unordered_multimap<int, int> dlist;
	dlist.insert({ 0,1 });
	dlist.insert({ 1,0 });

	auto val = getPath(9, 9, dlist);
	EXPECT_EQ(0, val.size());
}