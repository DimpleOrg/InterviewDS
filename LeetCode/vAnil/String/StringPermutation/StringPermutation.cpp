#include "StringPermutation.h"
#include <unordered_map>
#include <array>



void getStringPermutations(std::vector<char> const &charArray, std::vector<size_t> &countArray, std::vector<std::string>& stringVec, size_t const strLenght, size_t level, std::string &result)
{
	if (level >= strLenght)
	{
		stringVec.push_back(result);
		return;
	}
	else
	{
		for (size_t i = 0; i < countArray.size(); i++)
		{
			if (countArray[i] != 0)
			{
				countArray[i] = countArray[i] - 1;
				result[level] = charArray[i];

				getStringPermutations(charArray, countArray, stringVec, strLenght, level + 1, result);

				countArray[i] = countArray[i] + 1;
			}
		}
	}
}

STRINGPERMUTATION_API std::vector<std::string> getStringPermutations(std::string const & str)
{
	std::unordered_map<char, size_t> strMap;

	for (char ch : str)
		++strMap[ch];

	std::vector<char> charArray;
	std::vector<size_t> countArray;

	for (auto val : strMap)
	{
		charArray.push_back(val.first);
		countArray.push_back(val.second);
	}

	std::vector<std::string> stringVec;
	std::string result = str;
	
	getStringPermutations(charArray, countArray, stringVec, str.length(), 0, result);

	return stringVec;

}

