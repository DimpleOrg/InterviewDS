#include "ValidateIPAddress.h"
#include <vector>
#include <array>
using namespace std;

PRACTICEQUESTIONS_API std::string validIPAddress(std::string IP)
{
	size_t len = IP.length();

	if (len < 7 || len > 39)
		return "Neither";

	size_t countDot = 0;
	size_t countColon = 0;

	vector < array<char, 4>> ds;

	array<char, 4> temp;
	temp.fill(0);
	size_t tCount = 0;
	for (size_t i = 0; i < len; i++)
	{	
		if (isxdigit(IP[i]))
		{
			if (tCount > 3)
				return "Neither";

			temp[tCount++] = IP[i];
		}
		else
		{
			if (IP[i] == '.')
				countDot++;
			else if (IP[i] == ':')
				countColon++;
			else
				return "Neither";

			ds.push_back(temp);
			temp.fill(0);
			tCount = 0;
		}
	}
	ds.push_back(temp);


	if (countDot > 0 && countColon > 0)
		return "Neither";
	else if (countDot > 0)
	{
		if (countDot != 3)
			return "Neither";

		for (auto x : ds)
		{
			if ((x[1] != 0 && x[0] == '0') || (x[3] != 0) || (x[0] == 0))
				return "Neither";

			size_t num  = 0;

			if (x[2] != 0)
			{
				num = (x[2]-'0') + ((x[1] - '0') * 10) + ((x[0] - '0') * 100);
			}
			else if (x[1] != 0)
			{
				num = (x[1] - '0') + ((x[0] - '0') * 10);
			}
			else
			{
				num = x[0] - '0';
			}
			
			if (num > 255)
				return "Neither";
		}

		return "IPv4";
	}
	else if (countColon > 0)
	{
		if (countColon != 7)
			return "Neither";

		for (auto x : ds)
		{
			if (((x[0] == 0) && (x[1] == 0) && (x[2] ==0) && (x[3] ==0))
				
				)
				return "Neither";
		}

		return "IPv6";

	}

	return "Neither";
}
