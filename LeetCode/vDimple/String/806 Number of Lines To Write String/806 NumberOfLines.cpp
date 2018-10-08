//https://leetcode.com/problems/number-of-lines-to-write-string/description/

#include"806 NumberOfLines.h"

__declspec(dllexport) std::vector<int> numberOfLines(std::vector<int>& widths, std::string s)
{
	size_t sum = 0;
	for (size_t i = 0; i < s.length(); i++)
	{
		sum += widths[int(s[i] - 'a')];
	}

	size_t nolines = 0, diff = sum, nochars = 0;

	nolines = sum / 100;
	diff = sum % 100;

	if (diff > 0)
	{
		size_t i = s.length() - 1;
		while (i > 0)
		{
			if (nochars >= diff)
			{
				break;
			}

			nochars += widths[int(s[i]) - 'a'];
			i--;
		}
	}

	std::vector<int> res;
	res.push_back(nolines);
	res.push_back(nochars);

	return res;
}