#pragma once
#include <iostream>
#include <string>
#include <vector>

#ifdef PRACTICEQUESTIONS_EXPORTS
#define PRACTICEQUESTIONS_API __declspec(dllexport)
#else
#define PRACTICEQUESTIONS_API __declspec(dllimport)
#endif

PRACTICEQUESTIONS_API std::string MultiplyString(std::string num1, std::string num2);

PRACTICEQUESTIONS_API std::string MultiplyStringToChar(std::string num, char ch);
PRACTICEQUESTIONS_API std::string AddStringsOfVector(std::vector<std::string> vecOfStr);
