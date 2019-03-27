#include "ValidateIPAddress_D.h"

VALIDATEIPADDRESSD_API string validIPAddress(string IP)
{
	if (isIPV4(IP))
		return "IPv4";
	else
		return "invalid IPv4";
}

bool isIPV4(string str)
{
	int count = 0;
	bool res = false;
	stringstream s(str);
	string n;
	try
	{
		while (getline(s, n, '.'))
		{
			count++;
			if (stoi(n) > 0)
			{
				if (n[0] != 0)
				{
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
			else
			{
				if (stoi(n) == 0)
					res = true;
				else
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
