#pragma once
#ifdef MINIMALTREED_EXPORTS
#define MINIMALTREED_API __declspec(dllexport)
#else
#define MINIMALTREED_API __declspec(dllimport)
#endif // MINIMALTREED_EXPORTS

#include<iostream>
#include<vector>

MINIMALTREED_API std::vector<int> makeMT(int arr[], int size);
void makeMTHelper(int arr[], int size, std::vector<int>&, int l, int h);
