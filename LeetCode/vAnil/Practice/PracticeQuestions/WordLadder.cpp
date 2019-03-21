#include "WordLadder.h"
using namespace std;


inline bool IsOneLetterDifferent(string &first, string &second)
{
	size_t count = 0;

	for (size_t i = 0; i < first.length(); i++)
	{
		if (first[i] != second[i])
			count++;
		if (count > 1)
			return false;
	}

	return (count == 1) ? true : false;
}

size_t ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList)
{
	pair<string, size_t> x = make_pair(beginWord, 1);

	queue<pair<string, size_t>> itemQueue;
	itemQueue.push(x);

	while (!itemQueue.empty())
	{
		auto var = itemQueue.front();
		itemQueue.pop();

		for (auto y = wordList.begin(); y != wordList.end(); )
		{
			string yStr = *y;
			if (IsOneLetterDifferent(yStr, var.first))
			{
				x = make_pair(yStr, var.second + 1);
				itemQueue.push(x);
				
				if (yStr == endWord) {
					return x.second;
				}

				y = wordList.erase(y);		
			}
			else
			{
				y++;
			}
		}
	}

	return 0;
}
