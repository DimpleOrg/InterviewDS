#include"CompressString.h"

using namespace std;



//int main()
//{
//	try
//	{
//		string str = "abcd";
//		string cstr = compressString(str);
//		if (cstr.size() < str.length())
//		{
//			for (auto i : cstr)
//			{
//				cout << i;
//			}
//		}
//		else
//			cout << str;
//	}
//	catch (...)
//	{
//		cout << "Program crashed";
//	}
//	return 0;
//}

__declspec(dllexport) string compressString(string str)
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

	if (cvec.size() < str.length())
	{
		unique_ptr<char[]> ch = make_unique<char[]>(cvec.size() + 1);
		int i = 0;
		for (auto j : cvec)
		{
			ch[i] = j;
			i++;
		}
		ch[i] = '\0';

		str = ch.get();
	}


	return str;
}