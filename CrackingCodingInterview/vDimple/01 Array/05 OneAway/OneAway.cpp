#include<iostream>
#include<string>
#include<math.h>

using namespace std;

bool isOneAway(string, string);
bool isInsert(string str1, string str2);
bool isReplace(string str1, string str2);

int main()
{
	string str1 = "pale", str2 = "ple";
	
	bool res = isOneAway(str1, str2);
	if (res == false)
		cout << "\nNot one edit away\n";
	if (res == true)
		cout << "\nYes, One edit away\n";
	return 0;
}

bool isOneAway(string str1, string str2)
{
	bool res = true;;
	if (abs(int(str1.length() - str2.length())) > 1)
		return false;

	if (str1 == str2)
		return true;

	if (str1.length() == str2.length())
	{
		res = isReplace(str1, str2);
	}
	else if (abs(int(str1.length() - str2.length())) == 1)
	{
		res = isInsert(str1, str2);
	}
	/*
	//previous code when trying to do in single pass 
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
		return false;*/
	return res;
}

bool isInsert(string str1, string str2)
{
	int j = 0, k = 0, count = 0;
	while (j < str1.length() && k < str2.length())
	{
		if (str1[j] == str2[k])
		{
			j++;
			k++;
		}
		else
		{
			count += 1;
			if (count > 1)
				return false;
			if (str1.length() > str2.length())
				j++;
			else
				k++;
		}
	}
	/*if (count > 1)
		return false;*/
	
	return true;
}

bool isReplace(string str1, string str2)
{
	int count = 0;
	bool res = true;
	for (int i = 0; i < str1.length(); i++)
	{
		if (str1[i] != str2[i])
			count++;
	}
	if (count > 1)
		res = false;

	return res;
}