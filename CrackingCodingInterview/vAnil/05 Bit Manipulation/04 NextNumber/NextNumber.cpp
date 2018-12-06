#include "NextNumber.h"

MY04NEXTNUMBER_API unsigned NextBigger(unsigned num)
{
	if (~num == 0)
		throw "Bigger unsigned int is not possible.";

	unsigned mask = 1;
	
	while (mask != 0)
	{
		if (num & mask)
		{
			//first one
			num = num & ~mask;

			break;
		}
		mask = mask << 1;
	}

	while (mask != 0)
	{
		mask = mask << 1;

		if (!(num & mask))
		{
			num = num | mask;
			break;
		}
	}

	unsigned count = 0;
	while (mask != 0)
	{
		mask = mask >> 1;

		if (num & mask)
		{
			count++;
			num = num & ~mask;
		}
	}

	mask = 1;
	while (count != 0)
	{
		num = num | mask;
		mask = mask << 1;
		count--;
	}

	return num;
}

MY04NEXTNUMBER_API unsigned NextSmaller(unsigned num)
{
	if (num == 0 || num == 1)
		throw "Smaller unsigned int is not possible.";

	unsigned mask = 1;

	while (mask != 0)
	{
		if (!(num & mask))
		{
			//first zero
			num = num | mask;

			break;
		}
		mask = mask << 1;
	}

	while (mask != 0)
	{
		mask = mask << 1;

		if ((num & mask))
		{
			num = num & ~mask;
			break;
		}
	}

	unsigned count = 0;
	while (mask != 1)
	{
		mask = mask >> 1;

		if (!(num & mask))
		{
			count++;
			num = num | mask;
		}
	}

	mask = 1;
	while (count != 0)
	{
		num = num & ~mask;
		mask = mask << 1;
		count--;
	}

	return num;
}


	
//http://cs-fundamentals.com/tech-interview/c/c-program-to-count-number-of-ones-in-unsigned-integer.php

/* Brian Kernighan's algorithm  of counting set bits*/
int countSetBits(unsigned int n)
{
	unsigned int c; // the total bits set in n
	for (c = 0; n; n = n & (n - 1))
	{
		c++;
	}
	return c;
}

MY04NEXTNUMBER_API unsigned NextBiggerV1(unsigned num)
{

	if (~num == 0)
		throw "Next Bigger is not possible";

	unsigned setBits = countSetBits(num);

	while (++num != ~0U)
	{
		if (setBits == countSetBits(num))
			break;
	}

	return num;
}


MY04NEXTNUMBER_API unsigned PrevBiggerV1(unsigned num)
{
	if (num == 0)
		throw "Prev Bigger is not possible";

	unsigned setBits = countSetBits(num);

	while (--num != ~0U)
	{
		if (setBits == countSetBits(num))
			break;
	}

	return num;
}