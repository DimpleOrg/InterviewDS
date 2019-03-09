#pragma once
#ifndef  __MAXPRODUCTCOUNTINCHAT_H_
#define __MAXPRODUCTCOUNTINCHAT_H_

#include <set>
#include <map>
#include <string>
#include <vector>

using ParseResult = std::map<std::string, std::map<std::string, size_t>>;
using FreqResult = std::map<std::string, std::string>;

class ProductCatalogue
{
private:
	std::set<std::string> products;
public:
	void AddProduct(std::string product);
	bool IsFound(std::string product);
	std::set<std::string> GetProducts() { return products; }
};

class FileParser
{
private:
	ProductCatalogue pCatalogue;

	std::vector<std::string> SplitChatMessage(std::string& lineStr);
	std::string GetUserName(const std::vector<std::string>& words);
	std::map<std::string, size_t> GetProductCountMap(const std::vector<std::string>& words);
public:
	ParseResult Parse(std::string file, const ProductCatalogue& pInput);
};

class ProductFequencyAnalyzer
{
private:
public:
	FreqResult AnalyzeParseResult(const ParseResult& pInput, ProductCatalogue& products);
};


#endif // ! __MAXPRODUCTCOUNTINCHAT_H_

