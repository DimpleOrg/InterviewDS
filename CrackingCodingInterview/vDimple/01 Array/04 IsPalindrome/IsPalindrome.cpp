#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;


unordered_map<char, int> hash1;

void hashValues(string);
bool isPalindrome(string, int);
int getHashLen();

int main()
{
	string str = "abcd  cd";
	int hashLen = 0;
	hashValues(str);
	hashLen = getHashLen();
	bool res = isPalindrome(str, hashLen);
	cout << "\n" << res << "\n";
	return 0;
}

bool isPalindrome(string str, int len)
{
	bool res = true;
	int countOdd = 0;
	for (auto i : hash1)
	{
		if (len % 2 == 0)
		{
			if (i.second %2!=0)
			{
				res = false;
				break;
			}
		}

		else
		{
			
			if (i.second%2!=0)
				countOdd++;

		}
	}
	if (countOdd > 1)
	{
		res = false;
	}
	return res;
}

void hashValues(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] != ' ')
		{
			hash1[toupper(str[i])]++;
		}
	}
}

int getHashLen()
{
	int sumOfHshValues = 0;
	for (auto i : hash1)
	{
		sumOfHshValues += i.second;
	}
	return sumOfHshValues;
}