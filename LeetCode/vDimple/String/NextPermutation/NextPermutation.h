#pragma once
#ifdef NEXTPERMUTATION_EXPORTS
#define NEXTPERMUTATION_API __declspec(dllexport)
#else
#define NEXTPERMUTATION_API __declspec(dllimport)
#endif // NEXTPERMUTATION_EXPORTS

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

NEXTPERMUTATION_API void nextPermutation(vector<int>& nums);