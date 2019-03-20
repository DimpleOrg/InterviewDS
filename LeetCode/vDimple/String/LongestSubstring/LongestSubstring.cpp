#include "LongestSubstring.h"

int Solution::lengthOfLongestSubstring(std::string s)
{
	if (s.length() == 0)
		return 0;
	int currLen = 0, maxLen = 0;
	std::unordered_set<char> seq;
	for (const char x : s)
	{
		if (seq.find(x) == seq.end())
		{
			seq.insert(x);
			currLen++;
		}
		else
		{
			if (currLen > maxLen)
				maxLen = currLen;
			seq.clear();
			seq.insert(x);
			currLen = 1;
		}
	}
	return (currLen > maxLen ? currLen : maxLen);
}
