#pragma once
#include <iostream>
#include <string>
#include <vector>

#ifdef PRACTICEQUESTIONS_EXPORTS
#define PRACTICEQUESTIONS_API __declspec(dllexport)
#else
#define PRACTICEQUESTIONS_API __declspec(dllimport)
#endif

PRACTICEQUESTIONS_API int32_t stringToInt(std::string str);
bool isDigitChar(char ch);

