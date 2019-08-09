#include "pch.h"
#include "..\01 TripleStep_D\header.h"	//header file for TripleStep
#include "..\02 RobotGrid\RobotGrid.h"

TEST(RobotGridD, DPTest1) {
	std::string output;
	testing::internal::CaptureStdout();

	std::vector < std::vector<int>> mat = { {{-1}, {0}, {-1}},
											{{-1}, {-1}, {-1}},
											{{-1}, {0}, {-1}} };
	std::vector<point> res = findPathDP(mat, 3, 3);

	output = testing::internal::GetCapturedStdout();

	//EXPECT_EQ(res, 13);
	//EXPECT_TRUE(true);
}

TEST(RobotGridD, DPTest2) {
	std::string output;
	testing::internal::CaptureStdout();

	std::vector < std::vector<int>> mat = { {{-1}, {0}, {-1},{-1}},
											{{-1}, {0}, {-1},{-1}},
											{{-1}, {0}, {-1},{-1}},
											{{-1}, {0}, {-1},{-1}} };
	
	std::vector<point> res = findPathDP(mat, 4, 4);

	output = testing::internal::GetCapturedStdout();

	//EXPECT_EQ(res, 13);
	//EXPECT_TRUE(true);
}

TEST(RobotGridD, Test1) {
	std::string output;
	testing::internal::CaptureStdout();

	std::vector<std::vector<point>> res = findPath(3, 4);
	
	output = testing::internal::GetCapturedStdout();

	//EXPECT_EQ(res, 13);
	//EXPECT_TRUE(true);
}

TEST(RobotGridD, Test2) {
	std::string output;
	testing::internal::CaptureStdout();

	std::vector<std::vector<point>> res = findPath(4, 4);

	output = testing::internal::GetCapturedStdout();

	//EXPECT_EQ(res, 13);
	//EXPECT_TRUE(true);
}


TEST(TripleStepD, Test1) {
	std::string output;
	testing::internal::CaptureStdout();

	TripleStep obj(5);
	int res = obj.possibleWays();

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(res, 13);
	//EXPECT_TRUE(true);
}

TEST(TripleStepD, Test2) {
	std::string output;
	testing::internal::CaptureStdout();

	TripleStep obj(5);
	int res = obj.possibleWaysDP(5);

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(res, 13);
	//EXPECT_TRUE(true);
}

TEST(TripleStepD, Test3) {
	std::string output;
	testing::internal::CaptureStdout();

	TripleStep obj(37);
	int res = obj.possibleWaysDP(37);

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(res, 3831006429);
	//EXPECT_TRUE(true);
}

TEST(TripleStepD, Test4) {
	//Exceeds int limit...so this test would fail

	std::string output;
	testing::internal::CaptureStdout();

	TripleStep obj(51);
	int res = obj.possibleWaysDP(51);	

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(res, 19426970897100);
	//EXPECT_TRUE(true);
}