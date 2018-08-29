#include<iostream>
#include<string>
#include<math.h>

using namespace std;

bool isOneAway(string, string);

int main()
{
	string str1 = "pale", str2 = "ple";
	
	bool res = isOneAway(str1, str2);
	if (res == false)
		cout << "\nNot one edit away\n";
	if (res == true)
		cout << "\Yes, One edit away\n";
	return 0;
}

bool isOneAway(string str1, string str2)
{

	if (abs(int(str1.length() - str2.length())) > 1)
		return false;

	if (str1 == str2)
		return true;

	int count = 0;
	int minLen = str1.length();
	if (minLen > str2.length())
		minLen = str2.length();
	for (int i = 0; i < minLen; i++)
	{
		if (str1[i] != str2[i])
			count++;
	}

	if (abs(int(str1.length() - str2.length())) == 1)
	{
		if (count >= 1)
			return false;
	}
	if (count > 1)
		return false;
	return true;
}