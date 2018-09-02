#include <iostream>
#include <string>

using namespace std;

bool CompressString(string& str)
{
	bool status = true;
	size_t slen = str.length();
	
	char *tempArr = new char[slen];

	int tlen = 0;

	for (int i = 0; i < slen; i++)
	{
		if (tlen > slen)
		{
			status = false;
			break;
		}

		tempArr[tlen++] = str[i];

		int j = 0;
		while (str[i] == str[i + j])
		{
			j++;
		}

		if (tlen > slen)
		{
			status = false;
			break;
		}

		tempArr[tlen++] = '0' + j;

		i = j - 1;
	}

	if (status)
	{
		str = tempArr;
	}

	delete[] tempArr;
	return status;
}




int main()
{
	string str;
	getline()

	return 0;
}