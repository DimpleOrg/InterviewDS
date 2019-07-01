#include "pch.h"
#include "../../01 A_TripleStep/TripleStep.h"

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