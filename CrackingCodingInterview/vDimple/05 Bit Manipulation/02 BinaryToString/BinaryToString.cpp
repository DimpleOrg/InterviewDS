//Decimal fraction to Binary
#include "BinaryToString.h"

BINARYTOSTRING_API std::string convert(double n)
{
	int count = 0;
	std::string s;
	s.resize(33);
	while (n != 0.0 && count != 31)
	{
		n = n * 2;
		if (n >= 1)
		{
			s[count] = '1';
			n = n - 1;
		}
		else 
			s[count] = '0';
		count++;
	}
	if (n != 0.0)
		throw std::exception("ERROR");

	return "0." + s;
}
