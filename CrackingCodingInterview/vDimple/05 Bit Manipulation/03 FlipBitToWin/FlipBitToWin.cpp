#include "FlipBitToWin.h"

FLIPBITTOWIN_API size_t longestSeq(size_t n)
{
	if (n = ~0)
		return sizeof(n) * 8;

	size_t prev_ln = 0, curr_ln = 0;
	size_t max_ln = 1;
	while (n > 0)
	{
		if (n & 1 > 0)
		{
			curr_ln++;
		}
		else
		{
			if (n & 2 > 0)
			{
				prev_ln = curr_ln;
			}
			else
			{
				prev_ln = 0;
			}
			curr_ln = 0;
		}

		if (max_ln < curr_ln + prev_ln + 1)
			max_ln = curr_ln + prev_ln + 1;

		n >> 1;
	}
	return max_ln;
}
