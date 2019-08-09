#include "GroupAnagrams_D.h"

typedef std::unordered_map<char, int> un_map;
typedef std::vector<std::string> stringVec;

std::unordered_map<char, int>& getMap(std::string str)
{
	std::unordered_map<char, int> strMap;
	for (char i = str[0]; i < str.length(); i++)
	{
		strMap[i]++;
	}

	return strMap;
	//return std::move(strMap);
}

GROUPANAGRAMS_API void groupAnagrams(std::vector<std::string> vec)
{
	if (vec.size() < 2)
		return;

	std::unordered_map<char, int> strMap;

	/*auto m = std::unordered_map<std::map<char, int>, std::vector<std::string>, std::function<bool(const int&, const int&)>>
	{
		[](const std::map<char, int>& a, const std::map<char, int>& b)
		{
			return a < b;
		}
	};*/

	std::unordered_map < std::unordered_map<char, int>, std::vector<std::string>> imap;
		for (auto each : vec)
	{
		strMap = getMap(each);

		if (imap.find(strMap) != imap.end()) 
			imap[strMap].push_back(each);
		else
			imap.insert({ strMap, std::vector<std::string> {1,each} });
	}
}
