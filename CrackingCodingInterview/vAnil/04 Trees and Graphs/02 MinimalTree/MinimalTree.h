#pragma once
#ifndef __MINIMAL_TREE_H__
#define __MINIMAL_TREE_H__
#include <vector>


void makeMTHelper(const std::vector<long>& input,
	std::vector<long>& result, long start, long end)
{
	if (end < start)
		return;

	long mid = (start + end) / 2;
	result.push_back(input[mid]);
	makeMTHelper(input, result, start, mid - 1);
	makeMTHelper(input, result, mid+1, end);

}


std::vector<long> makeMinimalTree(const std::vector<long>& input)
{
	std::vector<long> result;
	makeMTHelper(input, result, 0, input.size() - 1);
	return std::move(result);
}


#endif // __MINIMAL_TREE_H__
