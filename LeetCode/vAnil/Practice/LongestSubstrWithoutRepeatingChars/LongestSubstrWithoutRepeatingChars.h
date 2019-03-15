#pragma once

#include <iostream>
#include <string>

#ifdef LONGESTSUBSTRWITHOUTREPEATINGCHARS_EXPORTS
#define LONGESTSUBSTRWITHOUTREPEATINGCHARS_API __declspec(dllexport)
#else
#define LONGESTSUBSTRWITHOUTREPEATINGCHARS_API __declspec(dllimport)
#endif

LONGESTSUBSTRWITHOUTREPEATINGCHARS_API std::size_t LongestSubstrWithoutRepeatingChars(const std::string &str);
