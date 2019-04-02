#pragma once
#include <iostream>
#include <vector>

#ifdef PRACTICEQUESTIONS_EXPORTS
#define PRACTICEQUESTIONS_API __declspec(dllexport)
#else
#define PRACTICEQUESTIONS_API __declspec(dllimport)
#endif

PRACTICEQUESTIONS_API void nextPermutation(std::vector<int>& nums);