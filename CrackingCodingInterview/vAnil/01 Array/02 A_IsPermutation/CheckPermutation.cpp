#include <iostream>
#include<unordered_map>
#include <string>

using namespace std;

bool IsPermutationString(string str1, string str2)
{
	bool result = false;


	if (str1.length() != str2.length())
		return false;


	using Type = unordered_map<char, uint32_t>;

	Type uMap1, uMap2;

	for (int i = 0; i < str1.length(); i++)
	{
		if (uMap1.find(str1[i]) == uMap1.end())
		{
			uMap1[str1[i]] = 0;
		}
		else
		{
			uMap1[str1[i]] = uMap1[str1[i]] + 1;
		}
	}


	for (int i = 0; i < str2.length(); i++)
	{
		if (uMap2.find(str2[i]) == uMap2.end())
		{
			uMap2[str2[i]] = 0;
		}
		else
		{
			uMap2[str2[i]] = uMap2[str2[i]] + 1;
		}
	}

	if (uMap1 == uMap2)
	{
		result = true;
	}
	else
	{
		result = false;
	}

	return result;
}


int main(int argc, char *argv[])
{
	string str1, str2;

	cout << "\nGet first string   :";
	getline(cin, str1);

	cout << "\nGet second string  :";
	getline(cin, str2);

	cout << "\n\nResult:";// << IsPermutationString(str1, str2) ? "TRUE" : "FALSE";

	bool result = IsPermutationString(str1, str2);

	if (result)
	{
		cout << "Strings are permutation of each other.";
	}
	else
	{
		cout << "Strings are not permutation of each other.";
	}
	return 0;
}