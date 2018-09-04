#include "CompressString.h"

using namespace std;

__declspec(dllexport) string CompressString(string str)
{
	bool status = true;
	size_t slen = str.length();
	
	unique_ptr<char[]> tempArr = make_unique<char[]>(slen + 1);

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

		i = i + j -1;
	}

	

	if (status)
	{
		tempArr[tlen] = 0;
		str = tempArr.get();
	}

	return str;
}

