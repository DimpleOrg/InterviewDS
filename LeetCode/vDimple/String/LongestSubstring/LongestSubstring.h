#pragma once
#ifdef LONGESTSUBSTRING_EXPORTS
#define LONGESTSUBSTRING_API __declspec(dllexport)
#else
#define LONGESTSUBSTRING_API __declspec(dllimport)
#endif // LONGESTSUBSTRING_EXPORTS



#include<iostream>
#include<unordered_set>

class LONGESTSUBSTRING_API Solution {
public:
	int lengthOfLongestSubstring(std::string s);
};