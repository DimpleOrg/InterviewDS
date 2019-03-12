
#include "pch.h"
#include <iostream>
#include <unordered_set>
#include <string>
#include <sstream>
#include <map>
#include<tuple>

std::vector <std::string> getLinesFromFile(std::string str)
{
	std::vector <std::string> vecOfLines;
	std::stringstream ss(str);
	std::string lines;

	//Tokenize lines on basis of '.'
	while (getline(ss, lines, '.'))
	{
		vecOfLines.push_back(lines);
	}
	return std::move(vecOfLines);
}

void printUserForEachProduct(std::map< std::string, std::map<std::string, int>> userVsProdFreq, std::unordered_set<std::string> const& listOfProducts)
{
	for (auto each : listOfProducts)
	{
		std::string username;
		int maxCount = 0;
		for (auto iter = userVsProdFreq.begin(); iter != userVsProdFreq.end(); iter++)
		{
			auto val = iter->second;
			if (val.find(each) != val.end())
			{
				auto iter2 = val.find(each);
				if (iter2->second > maxCount)
				{
					maxCount = iter2->second;
					username = iter->first;
				}
			}
		}
		std::cout << username << " has used " << each << " maximum number of times.\n";
	}
}

std::tuple<std::string, std::map<std::string, int>> getWordsFromLine(std::string tempstr, std::map<std::string, int>& prodFreq, std::unordered_set<std::string> const& listOfProducts)
{
	int count = 0;
	std::string username;
	std::stringstream stream(tempstr);
	std::string word;

	//Tokenize lines on basis of ' '
	while (getline(stream, word, ' '))
	{
		if (count == 0)
		{
			username = word;
			count = 1;
		}
		else
		{
			if (listOfProducts.find(word) != listOfProducts.end())
				prodFreq[word]++;
		}
	}
	return std::move(std::make_tuple( username, prodFreq));
}

void parseFile(std::string const& str, std::unordered_set<std::string> const& listOfProducts)
{
	std::vector <std::string> vecOfLines;	//Tokenize lines on basis of '.'
	vecOfLines = getLinesFromFile(str);
	
	std::map<std::string, int> prodFreq;
	std::map< std::string, std::map<std::string, int>> userVsProdFreq;
	for (int i = 0; i < vecOfLines.size() - 1; i++)
	{
		//count = 0;
		prodFreq.clear();
		std::string tempstr = vecOfLines[i];
		std::tuple<std::string, std::map<std::string, int>> res = getWordsFromLine(tempstr, prodFreq, listOfProducts);
		std::string username = std::get<0>(res);

		if(userVsProdFreq.find(username) != userVsProdFreq.end())
		{
			auto iter = userVsProdFreq.find(username);
			auto& val = iter->second;
			for (auto i = prodFreq.begin(); i != prodFreq.end(); i++)
			{
				if (val.find(i->first) == val.end())
				{
					val.insert({ i->first, i->second });
				}
				else
				{
					val[i->first]++;
				}
			}
		}
		else
		{
			userVsProdFreq.insert({ username, prodFreq });
		}
	}

	printUserForEachProduct(userVsProdFreq, listOfProducts);
}

int main()
{
	std::string str = "John - I like product X , Y , Z .Eric - I like product X , Y .Ira - I like product Y .John - I like product X , Z .Eric - I like product Y .";
	//Use set instead of vector if you you have to do search operation
	//std::vector<std::string> listOfProducts = { "X", "Y", "Z" };
	std::unordered_set<std::string> listOfProducts = { "X", "Y", "Z" };
	parseFile(str, listOfProducts);

	std::string str1 = "RAM I have a CAR CAR CAR .ROHAN I have a CUP GLASS .RAJ I have a CAR .RAJ I have a CAR.RAJ I have a CAR.RAJ I have a CAR.";
	std::unordered_set<std::string> listOfProducts1 = { "CAR", "CUP", "GLASS" };
	parseFile(str1, listOfProducts1);
}
