#include "pch.h"
#include "../../01 A_SortedMerge/SortedMerge.h"
#include "../../02 A_GroupAnagrams/groupAnagrams.h"


TEST(A_01_SortedMerge, Test1) {

	int arr1[6] = {8, 24, 31};
	int arr2[3] = { 6, 7, 44 };

	mergeArray(arr1, 3, arr2, 3);

  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}


TEST(A_02_GroupAnagrams, Test1) {

	std::vector<std::string> in = {
		"asdf","abc","adsf","bca"
	};

	auto val = groupAnagrams(in);
	
	
}