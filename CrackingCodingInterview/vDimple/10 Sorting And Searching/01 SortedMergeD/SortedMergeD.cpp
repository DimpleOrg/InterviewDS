#include "SortedMergeD.h"

void sortedMerge(int arrA[], int arrB[], int lastA, int lastB)
{
	if (lastA>0 && lastB>0)
	{
		int indexA = lastA - 1;		//last index of A -1
		int indexB = lastB - 1;
		int indexMerged = lastA + lastB - 1;

		while (indexB >= 0)
		{
			if (indexA >= 0 && arrA[indexA] > arrB[indexB])
			{
				arrA[indexMerged] = arrA[indexA];
				indexA--;
			}
			else
			{
				arrA[indexMerged] = arrB[indexB];
				indexB--;
			}

			indexMerged--;
		}
	}
}
