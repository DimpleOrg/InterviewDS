#pragma once
#include <tuple>
#include <unordered_map>
#include <vector>

#ifdef MY02AROBOTINGRID_EXPORTS
#define _API __declspec(dllexport)
#else
#define _API __declspec(dllimport)
#endif

_API size_t coutNumWaysV1(int r, int c, std::unordered_multimap<int,int> dlist);
_API size_t coutNumWaysV2(int r, int c, std::unordered_multimap<int,int> dlist);

_API std::vector<std::pair<int,int>> getPath(int r, int c, std::unordered_multimap<int, int> dlist);
