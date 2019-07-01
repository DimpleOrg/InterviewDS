#include "pch.h"
#include "../../01 A_SortedMerge/SortedMerge.h"

TEST(A_01_SortedMerge, Test1) {

	int arr1[6] = {8, 24, 31};
	int arr2[3] = { 6, 7, 44 };

	mergeArray(arr1, 3, arr2, 3);

  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}