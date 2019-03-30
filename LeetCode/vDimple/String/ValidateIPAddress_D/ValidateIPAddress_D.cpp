#include "ValidateIPAddress_D.h"

VALIDATEIPADDRESSD_API string validIPAddress(string IP)
{
	if (isIPV4(IP))
		return "IPv4";
	if (isIPV6(IP))
		return "IPv6";

	return "Neither";

}

bool isIPV4(string str)
{
	if (str[str.length() - 1] == '.')
		return false;

	int count = 0;
	bool res = false;
	stringstream s(str);
	string n;
	try
	{
		while (getline(s, n, '.'))
		{
			if (n.length() > 0 && n.length() < 4)
			{
				if ((n.length() > 1) && (n[0] == '0'))
					return false;

				for (int i = 0; i < n.length(); i++)
				{
					if (!isdigit(n[i]))
						return false;
				}

				count++;

				if ((stoi(n) >= 0) && (stoi(n) <= 255))
				{
					res = true;
				}
				else
				{
					res = false;
					break;
				}
			}
			else
			{
				res = false;
				break;
			}
		}

		if (count != 4)
			res = false;
	} //try

	catch (exception& e)
	{
		cout << "Exception thrown: " << e.what();
	}

	return res;
}

bool isIPV6(string str)
{
	if (str[str.length() - 1] == ':')
		return false;

	int count = 0;
	bool res = true;
	stringstream s(str);
	string n;

	while (getline(s, n, ':'))
	{
		if (n.length() > 0 && n.length() < 5)
		{
			for (int i = 0; i < n.length(); i++)
			{
				if (!isxdigit(n[i]))
					return false;
			}
		}
		else
			return false;

		count++;
	}

	if (count != 8)
		res = false;

	return res;
}