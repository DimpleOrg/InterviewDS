#pragma once
#include <iostream>
#include <string>
#include <vector>

#ifdef PRACTICEQUESTIONS_EXPORTS
#define PRACTICEQUESTIONS_API __declspec(dllexport)
#else
#define PRACTICEQUESTIONS_API __declspec(dllimport)
#endif

PRACTICEQUESTIONS_API std::string ReverseWordsInString(std::string& str);

