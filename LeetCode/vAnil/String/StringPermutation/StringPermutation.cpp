#include "StringPermutation.h"
#include <map>
#include <array>



void getStringPermutations(std::vector<char> const &charArray, std::vector<size_t> &countArray, std::vector<std::string>& stringVec, size_t const strLength, size_t level, std::string &result)
{
	try
	{
		if (charArray.size() == 0
			|| countArray.size() == 0
			|| strLength == 0
			|| result.length() != strLength)
		{
			throw new std::exception("Internal error occured.");
		}

		if (level >= strLength)
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

					getStringPermutations(charArray, countArray, stringVec, strLength, level + 1, result);

					countArray[i] = countArray[i] + 1;
				}
			}
		}
	}
	catch (...)
	{
		throw;
	}
}

STRINGPERMUTATION_API std::vector<std::string> getStringPermutations(std::string const & str)
{
	try
	{
		if (str.empty())
		{
			throw new std::exception("Invalid input");
		}

		std::map<char, size_t> strMap;

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

		//creating result string length same as input to hold the permutation of string
		std::string result(str.length(), '-');

		getStringPermutations(charArray, countArray, stringVec, str.length(), 0, result);

		return stringVec;
	}
	catch (...)
	{
		throw;
	}
}

