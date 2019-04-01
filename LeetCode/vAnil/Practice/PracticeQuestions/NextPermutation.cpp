#include "NextPermutation.h"
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

PRACTICEQUESTIONS_API void nextPermutation(std::vector<int>& nums)
{
	size_t len = nums.size();

	size_t index = len - 1;

	for (; index >= 1; index--)
	{
		if (nums[index] >nums[index - 1] )
			break;
	}

	if (index == 0)
	{
		sort(nums.begin(), nums.end());
	}
	else
	{
		bool flag = false;
		for (size_t i = index+1; i < len; i++)
		{
			if (nums[index-1] >= nums[i])
			{
				swap(nums[index-1], nums[i-1]);
				flag = true;
				break;
			}
		}

		if (!flag)
			swap(nums[index - 1], nums[len-1]);

		sort(nums.begin() + index, nums.end());

	}

	return;
}
