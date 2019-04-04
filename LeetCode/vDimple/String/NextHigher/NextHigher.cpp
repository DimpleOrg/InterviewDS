#include "NextHigher.h"

NEXTHIGHER_API std::vector<int> nextLargerNodes(std::vector<int> res)
{
	std::vector<int> stack;
	for (int i = res.size() - 1; i >= 0; i--)
	{
		int val = res[i];
		while (!stack.empty() && stack.back() <= res[i])
			stack.pop_back();
		res[i] = stack.empty() ? 0 : stack.back();
		stack.push_back(val);
	}
	return res;
}
