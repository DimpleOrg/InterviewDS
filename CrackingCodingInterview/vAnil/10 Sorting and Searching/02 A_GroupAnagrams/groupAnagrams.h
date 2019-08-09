#pragma once

#ifdef MY02AGROUPANAGRAMS_EXPORTS
#define _API __declspec(dllexport)
#else
#define _API __declspec(dllimport)
#endif


#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>


_API std::vector<std::string> groupAnagrams(std::vector<std::string> arrStrings);


