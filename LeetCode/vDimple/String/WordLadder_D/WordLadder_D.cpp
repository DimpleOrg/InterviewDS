#include "WordLadder_D.h"

WORDLADDERD_API size_t ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList)
{
	std::unordered_set<std::string> wl(wordList.begin(), wordList.end());
	
	if (wl.find(endWord) == wl.end())
		return 0;
	
	std::pair<std::string, size_t> x = std::make_pair(beginWord, 1);

	std::queue<std::pair<std::string, size_t>> qu;
	qu.push(x);
	
	while (!qu.empty())
	{
		auto var = qu.front();
		qu.pop();

		for (auto each = wl.begin();each!=wl.end();)
		{
			if (isOneLetterDiff(*each, var.first))
			{
				x = std::make_pair(*each, var.second + 1);
				qu.push(x);

				if (*each == endWord)
					return x.second;

				each = wl.erase(each);
			}
			else
			{
				each++;
			}
		}
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
