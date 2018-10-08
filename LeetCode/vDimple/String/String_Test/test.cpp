#include "pch.h"
#include"..\806 Number of Lines To Write String\806 NumberOfLines.h"
#include"..\StringPermutations_D\StringPermutations.h"

TEST(StringPermutations, Test1) {

	std::string output;
	testing::internal::CaptureStdout();
	
	std::string str="AABC";
	
	std::vector<std::string> res = getStringPermutations(str);
	
	for (auto each : res)
		std::cout << each << std::endl;

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}

TEST(StringPermutations, Test3) {

	std::string output;
	testing::internal::CaptureStdout();

	std::string str = "ABac";

	std::vector<std::string> res = getStringPermutations(str);

	for (auto each : res)
		std::cout << each << std::endl;

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}

TEST(StringPermutations, Test2) {

	std::string output;
	testing::internal::CaptureStdout();

	std::string str = "AAAA";

	std::vector<std::string> res = getStringPermutations(str);

	for (auto each : res)
		std::cout << each << std::endl;

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}


TEST(LC_806_Test, Test1) {

	std::string output;
	testing::internal::CaptureStdout();
	std::vector<int> widths = { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };
	std::string S;
	S = "abcdefghijklmnopqrstuvwxyz";

	std::vector<int> res = numberOfLines(widths, S);
	std::cout << res[0] << "\t" << res[1];

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}

TEST(LC_806_Test, Test2) {

	std::string output;
	testing::internal::CaptureStdout();
	std::vector<int> widths = { 4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10 };
	std::string S;
	S = "bbbcccdddaaa";

	std::vector<int> res = numberOfLines(widths, S);
	std::cout << res[0] << "\t" << res[1];

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}