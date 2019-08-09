#include "TripleStep.h"
#include <unordered_map>

std::unordered_map<size_t, size_t> map;

size_t CountStairCaseHopMethods(const size_t num, size_t sum, size_t branch)
{
	size_t result = 0;
	size_t curSum = sum + branch;

	if (curSum > num)
	{
		return 0;
	}
	else if (curSum == num)
	{
		return 1;
	}
	else
	{
		result += CountStairCaseHopMethods(num, curSum, 1);
		result += CountStairCaseHopMethods(num, curSum, 2);
		result += CountStairCaseHopMethods(num, curSum, 3);
	}

	return result;
}

_API size_t CountStairCaseHopMethods(size_t numOfStairs)
{
	return CountStairCaseHopMethods(numOfStairs, 0, 0);
}


size_t helper(size_t num)
{
	if (map.find(num) == map.end())
	{
		map[num] = CountStairCaseHopMethods(num);
	}
	else
	{
		return map[num];
	}
}

_API size_t CountStairCaseHopMethodsDP(size_t numOfStairs)
{
	map[1] = 1;
	map[2] = 2;
	map[3] = 4;
	for (size_t stair = 4; stair <= numOfStairs; stair++)
	{
		map[stair] = helper(stair-3) + helper(stair - 2) + helper(stair - 1);
	}

	return map[numOfStairs];
}