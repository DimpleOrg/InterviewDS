#include "pch.h"
#include "../../01 Insertion_A/Insertion.h"
#include "../../02 DecimalFractionToBinary/DecimalFractionToBinary.h"
#include "../../03 FlipBitToWin/FlipBitToWin.h"

TEST(InsertionTest, Test1) {
	std::string output;
	testing::internal::CaptureStdout();


	auto result = Insert_M_into_N(127, 5, 2, 4);

	output = testing::internal::GetCapturedStdout();


  EXPECT_EQ(result, 119);
}

TEST(DecimalFractionToBinaryString, Test1) {
	std::string output;
	testing::internal::CaptureStdout();


	auto result = DecimalFractionToString(0.125);

	output = testing::internal::GetCapturedStdout();


	EXPECT_EQ(1, 1);
}


TEST(FlipBitToWin, Test1) {
	std::string output;
	testing::internal::CaptureStdout();


	auto result = Longest1Sequence(1775);

	output = testing::internal::GetCapturedStdout();


	EXPECT_EQ(8, result);
}