#pragma once
#ifdef ROUTEBETWEENNODES_EXPORTS
#define ROUTEBETWEENNODES_API __declspec(dllexport)
#else
#define ROUTEBETWEENNODES_API __declspec(dllimport)
#endif // ROUTEBETWEENNODES_EXPORTS

#include<iostream>
#include<vector>
#include<queue>

ROUTEBETWEENNODES_API bool rootBetweenNodes(int src, int dest, std::vector<std::vector<int>> adj);