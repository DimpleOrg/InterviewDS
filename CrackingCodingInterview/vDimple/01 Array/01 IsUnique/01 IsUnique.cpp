// 01 IsUnique.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>

using namespace std;

unsigned long int n = 0;

bool setBit(char ch);
bool getBit(char ch);

int main()
{
	try
	{
		bool res;
		string str = "aabbbbccccbcd";
		for (int i = 0; i < str.length(); i++)
		{
			res = setBit(str[i]);
			if (res == false)
			{
				cout << "\nNot Unique\n";
				break;
			}
		}
		if (res)
			cout << "\n Unique string\n";
	}
	catch (...)
	{
		cout << "\nException thrown\n";
	}
    return 0;
}

bool setBit(char ch)
{
	if (getBit(ch))
		return false;
	unsigned long mask = 1;
	mask = mask << (int(ch) - 1);
	n = n | mask;
	return n | mask;
}

bool getBit(char ch)
{
	unsigned long mask = 1;
	mask = mask << (int(ch) - 1);
	return n & mask;
}

