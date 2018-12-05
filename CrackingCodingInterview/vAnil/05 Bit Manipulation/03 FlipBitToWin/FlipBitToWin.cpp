#include "FlipBitToWin.h"
/*
//1110111101111
cur = 1
prev = 0
max = 2


//0111011110111
max = 3
prev = 0


//0000111011110
max = 5
prev = 4
current = 0

*/

MY03FLIPBITTOWIN_API int Longest1Sequence(unsigned num)
{
	int max = 0;

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

			if (prev + cur + 1 > max)
				max = prev + cur + 1;

			num = num >> 1;
		}

		return max;
	}
}
