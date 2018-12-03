#include "FlipBitToWin.h"

MY03FLIPBITTOWIN_API int Longest1Sequence(unsigned num)
{
	int count = 0;

	if (~num == 0)
	{
		return sizeof(num) * 8;
	}
	else
	{
		int cur = 0;
		int prev = 0;

		while (num != 0)
		{
			if (num & 1 == 1)
			{
				cur++;
			}
			else
			{
				//check next second last bit
				if ((num & (1 << 1)) == 0)
				{
					prev = 0;
				}
				else
				{
					prev = cur;
				}
				cur = 0;
			}

			if (prev + cur + 1 > count)
				count = prev + cur + 1;

			num = num >> 1;
		}

		return count;
	}
}
