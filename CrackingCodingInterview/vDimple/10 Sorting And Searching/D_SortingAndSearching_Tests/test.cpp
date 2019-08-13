#include "pch.h"
#include"..\01 SortedMergeD\SortedMergeD.h"
#include"..\02 GroupAnagrams_D\GroupAnagrams_D.h"


TEST(GroupAnagrams, Test1)
{
	std::string output;
	testing::internal::CaptureStdout();

	std::vector<std::string> arrOfStrings = { "smarty", "ab","a","martys","ba","a","tamsry","a" };
	groupAnagrams(arrOfStrings);

	output = testing::internal::GetCapturedStdout();
}

TEST(SortedMerge, Test1) {

	std::string output;
	testing::internal::CaptureStdout();

	int arrA[8] = {6, 8, 10, 12};
	int arrB[4] = { 1,5,11,15 };
	sortedMerge(arrA, arrB, 4, 4);

	for (int i = 0; i < 8; i++)
	{
		std::cout << arrA[i]<<"\t";
	}

	output = testing::internal::GetCapturedStdout();
}

TEST(SortedMerge, Test2) {

	std::string output;
	testing::internal::CaptureStdout();

	int arrA[6] = { 20,22,24,28 };
	int arrB[2] = { 1,5 };
	sortedMerge(arrA, arrB, 4, 2);

	for (int i = 0; i < 6; i++)
	{
		std::cout << arrA[i] <<"\t";
	}

	output = testing::internal::GetCapturedStdout();
}

TEST(SortedMerge, Test3) {

	std::string output;
	testing::internal::CaptureStdout();

	int arrA[6] = { 20,22,600,700 };
	int arrB[2] = { 100,500 };
	sortedMerge(arrA, arrB, 4, 2);

	for (int i = 0; i < 6; i++)
	{
		std::cout << arrA[i] << "\t";
	}

	output = testing::internal::GetCapturedStdout();
}