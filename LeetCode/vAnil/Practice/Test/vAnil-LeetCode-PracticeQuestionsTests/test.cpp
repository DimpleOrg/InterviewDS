#include "pch.h"
#include "../../PracticeQuestions/StringToInteger.h"
#include "../../PracticeQuestions/MultiplyBigNumbers.h"



TEST(StringToInteger, T1) {

	int32_t res;
	res = stringToInt("   +328989768878768778623");

  EXPECT_EQ(res, INT32_MAX);
}

TEST(StringToInteger, T2) {

	int32_t res;
	res = stringToInt("   -323234234234234223123");


	EXPECT_EQ(res, INT32_MIN);
}

TEST(StringToInteger, T3) {

	int32_t res;

	res = stringToInt("   3223sdfsdf123");


	EXPECT_EQ(res, 3223);
}

TEST(MultiplyBigNumbers, T1) {

	std::string res;
	res = MultiplyString("25", "25");

	EXPECT_EQ(res, "625");
}

TEST(MultiplyBigNumbers, T2) {

	std::string res;
	res = MultiplyString("111111", "111111");
	
	EXPECT_EQ(res, "12345654321");
}

