#include "SortedMerge.h"

_API void mergeArray(int arr1[], int len1, int arr2[], int len2)
{
	int j = len1 - 1;
	int k = len2 - 1;
	for (int i = len1+len2 - 1; i >= 0 && k >=0; i--)
	{
		if (arr1[j] > arr2[k])
		{
			arr1[i] = arr1[j];
			j--;
		}
		else
		{
			arr1[i] = arr2[k];
			k--;
		}
	}
}
