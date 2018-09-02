#include "pch.h"
#include "../../06 A_CompressString/CompressString.h"
using namespace std;


TEST(COMPRESS_STRING_TEST, TEST1)
{
	string origstr = "aabbccdddd";
	string compressStr;

	compressStr = CompressString(origstr);

	EXPECT_EQ("a2b2c2d4", compressStr);
}



TEST(COMPRESS_STRING_TEST, TEST2)
{
	string origstr = "abcd";
	string compressStr;

	compressStr = CompressString(origstr);

	EXPECT_EQ("abcd", compressStr);
}


TEST(COMPRESS_STRING_TEST, TEST3)
{
	string origstr = "";
	string compressStr;

	compressStr = CompressString(origstr);

	EXPECT_EQ("", compressStr);
}