#include "MaxProductCountInChat.h"
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;

void ProductCatalogue::AddProduct(std::string product)
{
	if (product.length() > 0) {
		products.insert(product);
	}
	else
	{
		throw "Invalid Product";
	}
}

bool ProductCatalogue::IsFound(std::string product)
{
	std::set<std::string>::iterator iter = products.find(product);
	return iter != products.end() ? true : false;
}

std::string FileParser::GetUserName(const std::vector<std::string>& words)
{
	return words[0];
}

std::map<std::string, size_t> FileParser::GetProductCountMap(const std::vector<std::string>& words)
{
	std::map<std::string, size_t> pMap;

	for (size_t i = 1; i < words.size(); i++)
	{
		if (pCatalogue.IsFound(words[i]))
			pMap[words[i]]++;
	}

	return move(pMap);
}

std::vector<std::string> FileParser::SplitChatMessage(std::string & lineStr)
{
	vector <string> tokens;

	stringstream stream(lineStr);

	string token;

	// Tokenizing w.r.t. space ' ' 
	while (getline(stream, token, ' '))
	{
		tokens.push_back(token);
	}

	return move(tokens);
}

ParseResult FileParser::Parse(std::string file, const ProductCatalogue& pInput)
{
	pCatalogue = pInput;

	ParseResult pResult;

	string line;
	ifstream f(file);
	if (!f.is_open())
	{
		throw("error while opening file");
	}

	while (getline(f, line)) 
	{
		auto val = SplitChatMessage(line);
		string userName = GetUserName(val);
		auto pCountMap = GetProductCountMap(val);

		if (pResult.find(userName) == pResult.end()) {
			pResult.insert(pair<std::string, std::map<std::string, size_t>>(GetUserName(val), GetProductCountMap(val)));
		}
		else {
			auto prev = pResult[userName];

			for (auto it = prev.begin(); it != prev.end(); ++it)
			{
				string key = it->first;

				if (pCountMap.find(key) != pCountMap.end())
				{
					prev[key] = it->second + pCountMap[key];
				}
			}

			prev.insert(pCountMap.begin(), pCountMap.end());
			pResult[userName] = prev;
		}

	}

	if (f.bad())
	{
		throw("error while reading file");
	}

	return move(pResult);
}

FreqResult ProductFequencyAnalyzer::AnalyzeParseResult(const ParseResult & pInput, ProductCatalogue& products)
{

	//printing the map
	for (auto it = pInput.begin(); it != pInput.end(); ++it)
	{
		cout << it->first << endl << endl;

		for (auto it1 = it->second.begin(); it1 != it->second.end(); ++it1)
		{
			cout << "\t\t" << it1->first << "-->" << it1->second << endl;
		}
	}

	cout << "\n\n\n\n\t\t Result\n";

	FreqResult result;
	const std::set<std::string> recProducts = products.GetProducts();

	for (std::set<std::string>::iterator iter = recProducts.begin(); iter != recProducts.end(); iter++)
	{
		string product = *iter;
		string username;
		
		size_t max_freq = 0;
		for (auto it = pInput.begin(); it != pInput.end(); ++it)
		{
			
			std::map<std::string, size_t> feqMap = it->second;
			if (feqMap.find(product) != feqMap.end())
			{
				if (feqMap[product] > max_freq)
				{
					username = it->first;
					max_freq = feqMap[product];
				}
			}
		}

		if (username.length())
		{
			cout << "***** " << product << "<------> " << username << endl;

			pair< std::string, std::string> p(product, username);
			result.insert(p);
		}
		//result.insert({ product, username });
	}

	return result;
}
