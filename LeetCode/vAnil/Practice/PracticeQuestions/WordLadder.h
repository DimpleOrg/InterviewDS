#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <queue>

#ifdef PRACTICEQUESTIONS_EXPORTS
#define PRACTICEQUESTIONS_API __declspec(dllexport)
#else
#define PRACTICEQUESTIONS_API __declspec(dllimport)
#endif

PRACTICEQUESTIONS_API size_t ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList);