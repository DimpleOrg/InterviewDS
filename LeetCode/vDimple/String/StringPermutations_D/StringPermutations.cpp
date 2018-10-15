#include"StringPermutations.h"
#include<map>

void getStringPermutations(std::string const& str, std::vector<char>& charArr, std::vector<size_t>& charCount, size_t level, std::string& resStr, std::vector<std::string>& result)
{
	try
	{
		if (level >= str.length())
		{
			result.push_back(resStr);
		}
		else
		{
			for (size_t i = 0; i < charArr.size(); i++)
			{
				if (charCount[i] > 0)
				{
					resStr[level] = charArr[i];
					--charCount[i];
					getStringPermutations(str, charArr, charCount, level + 1, resStr, result);
					++charCount[i];
				}
			}
		}
	}
	catch (...)
	{
		throw;
	}
}

STRINGPERMUTATIONSD_API std::vector<std::string> getStringPermutations(std::string const& str)
{
	try
	{
		if (str.length() < 2)
			throw new std::exception ("\nPlease enter more than 1 character to see its permutations.\n");
			
		std::map<char, size_t> sMap;
		for (auto e : str)
			++sMap[e];

		std::vector<char> charArr;
		std::vector<size_t> charCount;

		for (auto e : sMap)
		{
			charArr.push_back(e.first);
			charCount.push_back(e.second);
		}

		std::string resStr(str.length(), '-');
		std::vector<std::string> result;

		getStringPermutations(str, charArr, charCount, 0, resStr, result);

		return result;
	}
	catch (...)
	{
		throw;
	}
}