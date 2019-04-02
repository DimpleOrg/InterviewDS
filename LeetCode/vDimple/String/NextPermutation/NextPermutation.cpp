#include "NextPermutation.h"

NEXTPERMUTATION_API void nextPermutation(vector<int>& n)
{
	bool noOp = true;
	size_t i = n.size() - 1;

	while (i > 0 && n[i - 1] > n[i])
		i--;

	if (i > 0)
	{
		int j = n.size() - 1;
		while ((j >= 0) && (n[j] >= n[i]))
			j--;
		if (j >= 0)
		{
			swap(n[i - 1], n[j]);
			reverse(n.begin() + i, n.end());
			noOp = false;
		}
	}
	
	//for (int i = n.size() - 1; i > 0; i--)
	//{
	//	if (n[i] > n[i - 1])
	//	{
	//		int min = i;

	//		//find first decreasing element
	//		for (int j = i+1; j < n.size() - 1; j++)
	//		{
	//			if ((n[j] > n[i - 1]) && (n[j] < n[min]))
	//				min = j;
	//		}
	//		swap(n[i - 1], n[min]);
	//		
	//		//reverse elements i to last
	//		int k = i, l = n.size() - 1;
	//		while (k < l)
	//		{
	//			swap(n[k], n[l]);
	//			k++, l--;
	//		}
	//		noOp = false;
	//		break;
	//	}
	//}

	if(noOp==true)
		sort(n.begin(), n.end());
}
