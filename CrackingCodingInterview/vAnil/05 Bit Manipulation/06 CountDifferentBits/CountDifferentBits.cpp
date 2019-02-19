#include "CountDifferentBits.h"

MY06COUNTDIFFERENTBITS_API unsigned CountDifferentBits(size_t x, size_t y)
{
	unsigned count = 0;

	for (int i = x ^ y; i != 0; i = i & (i - 1))
	{
		count++;
	}

	return count;
}
