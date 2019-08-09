#include "groupAnagrams.h"
#include <algorithm>

using namespace std;

_API std::vector<std::string> groupAnagrams(std::vector<std::string> arrStrings)
{
	unordered_map<string, vector<string>> mp;

	for (auto x : arrStrings)
	{
		string sorted = x;
		std::sort(sorted.begin(), sorted.end());
		mp[sorted].push_back(x);
	}

	arrStrings.clear();

	for (auto x : mp)
	{
		for (auto iter = x.second.begin(); iter != x.second.end(); iter++)
			arrStrings.push_back(*iter);
	}

	return move(arrStrings);
}
