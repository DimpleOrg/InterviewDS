#include "pch.h"
#include "../../01 Insertion_A/Insertion.h"

TEST(InsertionTest, Test1) {
	std::string output;
	testing::internal::CaptureStdout();


	auto result = Insert_M_into_N(127, 5, 2, 4);

	output = testing::internal::GetCapturedStdout();


  EXPECT_EQ(result, 119);
}