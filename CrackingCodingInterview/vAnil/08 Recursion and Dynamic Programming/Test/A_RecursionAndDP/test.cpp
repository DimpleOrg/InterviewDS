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
	size_t count = coutNumWaysV1(3,3);
	EXPECT_EQ(count, 6);
}

TEST(A_02_RobotGrid, Test2) {
	size_t count = coutNumWaysV2(3, 3);
	EXPECT_EQ(count, 6);
}


TEST(A_02_RobotGrid, Test3) {
	size_t count1 = coutNumWaysV1(9, 9);
	size_t count2 = coutNumWaysV2(9, 9);
	EXPECT_EQ(count1, count2);
}