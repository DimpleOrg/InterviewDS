//WAP to find if one string is permutation of other

#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

bool isPermutation(string , string );

int main()
{
	string str1 = "carsbus", str2 = "buscars";
	bool res = isPermutation(str1, str2);
	cout << "\n" << res << "\n";
	return 0;
}

bool isPermutation(string str1, string str2)
{
	if (str1.length() != str2.length())
		return false;

	unordered_map<char, int> hash1, hash2;
	for (int i = 0; i < str1.length(); i++)
	{
		hash1[str1[i]]++;
		hash2[str2[i]]++;
	}
	if (hash1 == hash2)
		return true;
	else
		return false;
}