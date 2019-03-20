#include "ReverseWordsInAString.h"

REVERSEWORDSINASTRING_API std::string reverseWords(std::string s)
{
	if (s.length() == 0)
		return s;
	
	int k = s.length() - 1;
	while ((k >= 0) && (s[k] == ' '))
	{
		k--;
	}

	if (k >= 0)
	{
		if (k != s.length() - 1)	//this means trailing spaces at the end of string.
			s.erase(k + 1, s.length() - 1);

		size_t l = k;

		while ((k >= 0) && (s[k] != ' '))
		{
			k--;
		}

		std::string slast = s.substr(k + 1, l-k);
		size_t slastlen = slast.length();
		size_t pos = s.find(slast);

		size_t i = 0;
		while (i < pos)
		{
			while (s[i] == ' ')
			{
				i++;
			}

			size_t j = i;

			if (i < pos)
			{

				while (s[j] != ' ')
				{
					j++;
				}

				std::string s1 = s.substr(i, j - i);

				auto it = s.insert(s.begin() + pos + slastlen, ' ');
				it = s.insert(it + 1, s1.begin(), s1.end());
			}
			i = j;
		}

		s.erase(0, pos);
	}
	else
	{
		s = "";
	}

	return s;
}
