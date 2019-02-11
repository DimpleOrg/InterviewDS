#include "StringToInteger.h"

using namespace std;

int32_t stringToInt(string str)
{
	int32_t result = 0;
	string intStr;
	bool flag = false;

	size_t ilen = 0;
	for (; ilen < str.length(); ilen++)
	{
		char ch = str[ilen];
		if (ch == ' ')
			continue;
		else
			break;
	}

	for (size_t len = ilen; len < str.length(); len++)
	{
		char ch = str[len];

		if (!flag)
		{
			flag = true;
			if (ch != '+' &&
				ch != '-' &&
				!isDigitChar(ch))
			{
				return 0;
			}
			else
			{
				intStr += ch;
				continue;
			}
		}

		if (isDigitChar(ch))
			intStr += ch;
		else
			break;
	}

	if (intStr.length() > 0)
	{
		if (intStr[0] == '-')
			flag = false;
		else
			flag = true;

		int32_t tens = 1;
		for (char ch : intStr)
		{
			if (ch == '+' || ch == '-')
				continue;

			result += (ch - '0') * tens;

			if (result < 0)
			{
				if (flag)
					return INT32_MAX;
				else
					return INT32_MIN;
			}
			tens *= 10;
		}

		if (!flag)
			result *= -1;
	}

	return result;
}


bool isDigitChar(char ch)
{
	if (ch >= '0' && ch <= '9')
		return true;
	else
		return false;
}
