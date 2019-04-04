#include "NextPermutation_D.h"

NEXTPERMUTATION_API void nextPermutation(vector<int>& n)
{
	int index = n.size() - 1;
	/*while (n[index] < n[index - 1])
		index--;*/
	for (; index >= 1; index--)
	{
		if (n[index - 1] < n[index])
			break;
	}

	if (index == 0)
		sort(n.begin(), n.end());
	else
	{
		bool flag = false;
		for (int i = index + 1; i < n.size(); i++)
		{
			if (n[index - 1] >= n[i])
			{
				swap(n[index - 1], n[i - 1]);
				flag = true;
				break;
			}
		}

		if (!flag)
		{
			swap(n[index - 1], n[n.size() - 1]);
		}

		sort(n.begin() + index, n.end());
	}

}
