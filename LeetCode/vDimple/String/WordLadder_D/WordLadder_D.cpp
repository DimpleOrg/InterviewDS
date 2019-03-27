#include "WordLadder_D.h"

WORDLADDERD_API size_t ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList)
{
	std::unordered_set<std::string> wl(wordList.begin(), wordList.end());
	
	if (wl.find(endWord) == wl.end())
		return 0;
	
	std::queue<std::string> qu;
	qu.push(beginWord);
	int level = 1;
	while (!qu.empty())
	{
		std::string var = qu.front();
		qu.pop();

		for (auto each = wl.begin();each!=wl.end();)
		{
			if (isOneLetterDiff(*each, var))
			{
				qu.push(*each);

				if ((*each == endWord) && (var == beginWord))
					return level + 1;

				if (*each == endWord)
					return level;

				each = wl.erase(each);
			}
			else
			{
				each++;
			}
		}
		level++;
	}
	return 0;
}

bool isOneLetterDiff(std::string a, std::string b)
{
	int count = 0;
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] != b[i])
			count++;
		if (count > 1)
			return false;
	}

	return count == 1 ? true : false;
}
