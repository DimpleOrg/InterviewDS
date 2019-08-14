#pragma once
#ifndef __GROUPANAGRAMS_H
#define __GROUPANAGRAMS_H

#ifdef MY02GROUPANAGRAMSD_EXPORTS
#define _GROUPANAGRAMS_API __declspec(dllexport)
#else
#define _GROUPANAGRAMS_API __declspec(dllimport)
#endif // MY02GROUPANAGRAMSD_EXPORTS

#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>

_GROUPANAGRAMS_API void groupAnagrams(std::vector<std::string>& vec);

#endif