#include "ReverseWordInString.h"
using namespace std;

PRACTICEQUESTIONS_API std::string ReverseWordsInString(std::string& str)
{
	// remove prefix spaces
	size_t len = str.length();
	size_t count = 0;
	for (size_t i = 0; i < len; i++)
	{
		if (str[i] == ' ')
		{
			count++;
		}
		else
			break;
	}
	str.erase(0, count);

	// remove suffix spaces
	len = str.length();
	count = 0;
	for (size_t i = len; i >= 1  ; i--)
	{
		if (str[i - 1] == ' ')
			count++;
		else
			break;
	}
	str.erase(len - count, count);

	//remove innter duplicate spaces
	len = str.length();
	count = 0;
	for (size_t i = 0; i < len; i++)
	{
		if (str[i] == ' ')
		{
			while (str[i + 1] == ' ') {
				count++;
				len--;
				i++;
			}

			if (count > 1)
			{
				str.erase(i-1 , count);
				count = 0;
			}
		}
	}

	//Reverse the string
	len = str.length();
	for (size_t i = 0; i < len/2; i++)
	{
		char temp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = temp;

	}

	//reverse word by word
	for (size_t i = 0; i < len; i++)
	{
		size_t start = i;

		while (i < len && str[i] != ' ' )
		{
			i++;
		}

		size_t end = i-1;
		

		for (size_t j = start; j <= end ; j++)
		{
			char temp = str[j];
			str[j] = str[end];
			str[end] = temp;
			end--;
		}
	}

	return str;
}
