#include "pch.h"
#include"..\01 Insertion\\Insertion.h"
#include"..\02 BinaryToString\BinaryToString.h"
#include"..\03 FlipBitToWin\FlipBitToWin.h"

TEST(D_FlipBitToWinTest, Test1) {
	std::string output;
	testing::internal::CaptureStdout();

	size_t n = longestSeq(1775);
	
	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(n, 8);
}

TEST(D_BinaryToStringTest, Test1) {
	std::string output;
	testing::internal::CaptureStdout();
	
	std::string res;
	try
	{
		res = convert(0.125);
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
	}
	std::cout << res;
	output = testing::internal::GetCapturedStdout();

	ASSERT_STREQ(res.c_str(), "0.001");
}


TEST(D_InsertionTest, Test1) {
	std::string output;
	testing::internal::CaptureStdout();

	int res = bitInsertion(127,5,2,4);

	output = testing::internal::GetCapturedStdout();
	
	EXPECT_EQ(res, 119);
}