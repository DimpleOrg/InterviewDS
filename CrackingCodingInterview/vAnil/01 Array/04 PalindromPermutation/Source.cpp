#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;


bool IsPalindromPermutation(const string& str)
{
	unordered_map<char, int> hash;

	int count = 0;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] != ' ')
		{
			hash[toupper(str[i])]++;
			count++;
		}
	}

	if ((count % 2 == 0))
	{
		for (auto val : hash)
		{
			if ((val.second % 2) != 0)
			{
				return false;
			}
		}
	}
	else 
	{
		int odd = 0;
		for (auto val : hash)
		{
			if ((val.second % 2 != 0))
			{
				odd++;
			}
		}

		if (odd > 1)
		{
			return false;
		}
		else 
		{
			return true;
		}
	}


	return true;
}


int main(int argc, char *argv[])
{
	string str = "Tact Coa";

	string result = IsPalindromPermutation(str) ? "TRUE" : "FALSE";

	cout << "Input :" << str <<"\nOutput:" << result;

	return 0;
}