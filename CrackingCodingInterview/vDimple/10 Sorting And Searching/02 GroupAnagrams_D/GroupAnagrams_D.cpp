#include "GroupAnagrams_D.h"

_GROUPANAGRAMS_API void groupAnagrams(std::vector<std::string>& vec)
{
	if (vec.size() < 2)
		return;

	std::unordered_map < std::string, std::vector<std::string>> imap;
	
	for (auto each : vec)
	{
		std::string sorted = each;
		std::sort(sorted.begin(), sorted.end());
		imap[sorted].push_back(each);
	}
	
	vec.clear();

	for (auto x : imap)
	{
		for (auto iter = x.second.begin(); iter != x.second.end(); iter++)
		{
			vec.push_back(*iter);
		}
	}
}
