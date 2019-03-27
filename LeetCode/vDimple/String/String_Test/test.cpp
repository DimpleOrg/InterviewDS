#include "pch.h"
#include "..\806 Number of Lines To Write String\806 NumberOfLines.h"
#include "..\StringPermutations_D\StringPermutations.h"
#include "..\LongestSubstring\LongestSubstring.h"
#include "..\ReverseWordsInAString\ReverseWordsInAString.h"
#include "..\WordLadder_D\WordLadder_D.h"
#include"..\ValidateIPAddress_D\ValidateIPAddress_D.h"

TEST(ValidateIPAddress, T1) {
	std::string output;
	testing::internal::CaptureStdout();

	auto result = validIPAddress("172.16.254.01");

	output = testing::internal::GetCapturedStdout();

	ASSERT_STREQ("Neither", result.c_str());
}

TEST(ValidateIPAddress, T2) {
	std::string output;
	testing::internal::CaptureStdout();

	auto result = validIPAddress("2001:0db8:85a3:0000:0:8A2E:0370:733a");

	output = testing::internal::GetCapturedStdout();

	ASSERT_STREQ("IPv6", result.c_str());
}

TEST(ValidateIPAddress, T3) {
	std::string output;
	testing::internal::CaptureStdout();

	auto result = validIPAddress("1ab.1.1.1");
	
	output = testing::internal::GetCapturedStdout();
	
	ASSERT_STREQ("IPv4", result.c_str());
}

TEST(WordLadderTest, T1) {
	std::string output;
	testing::internal::CaptureStdout();

	std::vector<std::string> wordList{ "hot","dot","dog","lot","log" };
	auto result = ladderLength("hit", "cog", wordList);

	output = testing::internal::GetCapturedStdout();
	ASSERT_EQ(0, result);
}

TEST(WordLadderTest, T2) {
	std::string output;
	testing::internal::CaptureStdout();

	std::vector<std::string> wordList{ "hot","dog","dot" };
	auto result = ladderLength("hot", "dog", wordList);

	output = testing::internal::GetCapturedStdout();
	ASSERT_EQ(2, result);
}

TEST(WordLadderTest, T3) {
	std::string output;
	testing::internal::CaptureStdout();

	std::vector<std::string> wordList{ "hot","dot","dog","lot","log" ,"cog" };
	auto result = ladderLength("hit", "cog", wordList);
	
	output = testing::internal::GetCapturedStdout();
	ASSERT_EQ(5, result);
}


TEST(ReverseWordsInAStr, Test1) {

	std::string output;
	testing::internal::CaptureStdout();

	std::string s = "a good   example";
	s = reverseWords(s);

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ("example good a", s);
}

TEST(ReverseWordsInAStr, Test2) {

	std::string output;
	testing::internal::CaptureStdout();

	std::string s = "the sky is blue";
	s = reverseWords(s);

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ("blue is sky the", s);
}

TEST(ReverseWordsInAStr, Test3) {

	std::string output;
	testing::internal::CaptureStdout();

	std::string s = "hi!";
	s = reverseWords(s);

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ("hi!", s);
}

TEST(ReverseWordsInAStr, Test4) {

	std::string output;
	testing::internal::CaptureStdout();

	std::string s = "  hello world!  ";
	s = reverseWords(s);

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ("world! hello", s);
}

TEST(ReverseWordsInAStr, Test5) {

	std::string output;
	testing::internal::CaptureStdout();

	std::string s = "a";
	s = reverseWords(s);

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ("a", s);
}

TEST(LongestSubstring, Test1) {

	std::string output;
	testing::internal::CaptureStdout();
	
	Solution obj;

	std::string str = "abcabcbb";

	auto res = obj.lengthOfLongestSubstring(str);

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(res,3);
}

TEST(LongestSubstring, Test2) {

	std::string output;
	testing::internal::CaptureStdout();

	Solution obj;

	std::string str = "bbbbb";

	auto res = obj.lengthOfLongestSubstring(str);

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(res, 1);
}

TEST(LongestSubstring, Test3) {

	std::string output;
	testing::internal::CaptureStdout();

	Solution obj;

	std::string str = "pwwkew";

	auto res = obj.lengthOfLongestSubstring(str);

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(res, 3);
}

TEST(LongestSubstring, Test4) {

	std::string output;
	testing::internal::CaptureStdout();

	Solution obj;

	std::string str = "pwwkewxyzab";

	auto res = obj.lengthOfLongestSubstring(str);

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(res, 6);
}

TEST(StringPermutations, Test1) {

	std::string output;
	testing::internal::CaptureStdout();
	
	std::string str="AABC";
	
	std::vector<std::string> res = getStringPermutations(str);
	
	for (auto each : res)
		std::cout << each << std::endl;

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(res.size(), 12);
}

TEST(StringPermutations, Test3) {

	std::string output;
	testing::internal::CaptureStdout();

	std::string str = "ABac";

	std::vector<std::string> res = getStringPermutations(str);

	for (auto each : res)
		std::cout << each << std::endl;

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(res.size(), 24);

}

TEST(StringPermutations, Test2) {

	std::string output;
	testing::internal::CaptureStdout();

	std::string str = "AAAA";

	std::vector<std::string> res = getStringPermutations(str);

	for (auto each : res)
		std::cout << each << std::endl;

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(res.size(), 1);

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