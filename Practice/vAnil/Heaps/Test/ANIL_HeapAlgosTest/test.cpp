#include "pch.h"
#include "../../MaxHeap/MaxHeap/MaxHeap.h"

TEST(TestCaseName, TestName) {

	std::vector<int> vec{ 2,4,67,234,12,34,56,0,434,12,3,4,6 };
	MaxHeap<int> heap(vec);

	heap.push(500);
	heap.push(44);

	while (!heap.empty())
	{
		int val = heap.pop();
	}



  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}