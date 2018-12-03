#include "NextNumber.h"

MY04NEXTNUMBER_API unsigned NextBigger(unsigned num)
{
	unsigned nBig = 0;

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
		if (!(num & mask))
		{
			num = num | mask;
			break;
		}

		mask = mask << 1;
	}

	return nBig;	
}

MY04NEXTNUMBER_API unsigned NextSmaller(unsigned num)
{
	unsigned nSmall = 0;



	return nSmall;
}
