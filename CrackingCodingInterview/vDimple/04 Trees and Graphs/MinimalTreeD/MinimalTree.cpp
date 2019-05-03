#include "MinimalTree.h"

MINIMALTREED_API std::vector<int> makeMT(int arr[], int size)
{
	std::vector<int> res;
	makeMTHelper(arr, size, res, 0, size - 1);
	return res;
}

void makeMTHelper(int arr[], int size, std::vector<int>& res, int low, int high)
{
	if (low <= high)
	{
		int mid = (low + high) / 2;
		res.push_back(arr[mid]);
		makeMTHelper(arr,size, res, low, mid - 1);
		makeMTHelper(arr, size, res, mid + 1, high);
	}
}
