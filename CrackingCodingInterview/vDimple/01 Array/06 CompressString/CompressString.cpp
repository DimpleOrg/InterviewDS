#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<char> compressString(string str);

int main()
{
	try
	{
		string str = "abcd";
		vector<char> cstr = compressString(str);
		if (cstr.size() < str.length())
		{
			for (auto i : cstr)
			{
				cout << i;
			}
		}
		else
			cout << str;
	}
	catch (...)
	{
		cout << "Program crashed";
	}
	return 0;
}

vector<char> compressString(string str)
{
	vector<char> cvec;
	int count = 1;
	cvec.push_back(str[0]);
	for (int i = 1; i < str.length(); i++)
	{
		if (str[i] == str[i - 1])
		{
			count++;
		}
		else
		{
			cvec.push_back(char('0' + count));
			cvec.push_back(str[i]);
			count = 1;
		}
	}
	cvec.push_back(char('0' + count));

	return cvec;
}