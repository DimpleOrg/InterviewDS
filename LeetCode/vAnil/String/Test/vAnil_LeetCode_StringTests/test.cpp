#include "pch.h"
#include "../../NumberOfLinesToWriteString/NumberOfLinesToWriteString.h"
#include "../../StringPermutation/StringPermutation.h"

TEST(NumberOfLines, test1) {
	std::string output;
	testing::internal::CaptureStdout();
	std::vector<size_t> widths = { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };
	std::string S;
	S = "abcdefghijklmnopqrstuvwxyz";

	std::vector<size_t> res = numberOfLines(widths, S);
	std::cout << res[0] << "\t" << res[1];

	output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(res[0], 3);
  EXPECT_EQ(res[1], 60);
}

TEST(NumberOfLines, test2) {

	std::string output;
	testing::internal::CaptureStdout();
	std::vector<size_t> widths = { 4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10 };
	std::string S;
	S = "bbbcccdddaaa";

	std::vector<size_t> res = numberOfLines(widths, S);
	std::cout << res[0] << "\t" << res[1];

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(res[0], 2);
	EXPECT_EQ(res[1], 4);
}


TEST(StringPermutation, test1) {

	std::string output;
	testing::internal::CaptureStdout();
	std::string str = "EEBC";

	std::vector<std::string> result = getStringPermutations(str);

	for (auto val : result)
		std::cout << val << "\n";

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(result.size(), 12);
}