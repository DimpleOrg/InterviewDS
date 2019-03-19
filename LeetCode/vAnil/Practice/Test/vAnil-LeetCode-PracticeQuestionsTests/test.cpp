#include "pch.h"
#include "../../PracticeQuestions/StringToInteger.h"
#include "../../PracticeQuestions/MultiplyBigNumbers.h"
#include "../../PracticeQuestions/RemoveNthLastElem.h"
#include "../../PracticeQuestions/ReverseWordInString.h"
#include "../../LongestSubstrWithoutRepeatingChars/LongestSubstrWithoutRepeatingChars.h"



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


TEST(RemoveNthLastElem, T1) {

	std::string output;
	testing::internal::CaptureStdout();



	List<int> list;
	list.AddElem(1);
	list.AddElem(2);
	list.AddElem(3);
	list.AddElem(4);
	list.AddElem(5);

	list.Print();
	list.RemoveNthFromLast(1);
	list.Print();

	output = testing::internal::GetCapturedStdout();

}



TEST(LongestSubstrWithoutRepeatingChars, T1) {

	std::string output;
	testing::internal::CaptureStdout();

	std::string str = "abcabcbb";

	auto count = LongestSubstrWithoutRepeatingChars(str);
	
	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(count, 3);
}

TEST(LongestSubstrWithoutRepeatingChars, T2) {

	std::string output;
	testing::internal::CaptureStdout();

	std::string str = "bbbbb";

	auto count = LongestSubstrWithoutRepeatingChars(str);

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(count, 1);
}

TEST(LongestSubstrWithoutRepeatingChars, T3) {

	std::string output;
	testing::internal::CaptureStdout();

	std::string str = "pwwkew";

	auto count = LongestSubstrWithoutRepeatingChars(str);

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(count, 3);
}

TEST(ReverseWordInString, T1) {

	std::string output;
	testing::internal::CaptureStdout();

	std::string str = "the sky is blue";

	auto result = ReverseWordsInString(str);

	output = testing::internal::GetCapturedStdout();

	ASSERT_STREQ("blue is sky the", result.c_str());
}

TEST(ReverseWordInString, T2) {

	std::string output;
	testing::internal::CaptureStdout();

	std::string str = "  hello world!  ";

	auto result = ReverseWordsInString(str);

	output = testing::internal::GetCapturedStdout();

	ASSERT_STREQ("world! hello", result.c_str());
}

TEST(ReverseWordInString, T3) {

	std::string output;
	testing::internal::CaptureStdout();

	std::string str = "a good   example";

	auto result = ReverseWordsInString(str);

	output = testing::internal::GetCapturedStdout();

	ASSERT_STREQ("example good a", result.c_str());
}