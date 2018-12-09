#include "DecimalFractionToBinary.h"

using namespace std;
	
MY02DECIMALFRACTIONTOBINARY_API std::string DecimalFractionToString(double decimalFraction)
{
	string result;
	result.resize(32);

	for (int i = 0; i < 32; i++)
	{
		if (decimalFraction == 0)
		{
			//To make 0.0
			if (i==0)
				result[i] = '0';
			
			break;
		}
		else
		{
			decimalFraction *= 2;

			if (decimalFraction >= 1)
			{
				result[i] = '1';
				decimalFraction -= 1;
			}
			else
			{
				result[i] = '0';
			}
		}
	}

	if (decimalFraction != 0)
		throw string("Error");

	return "0." + result;

}
