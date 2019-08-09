#pragma once
#ifndef __GROUPANAGRAMS_H
#define __GROUPANAGRAMS_H

#ifdef MY02GROUPANAGRAMSD_EXPORTS
#define GROUPANAGRAMS_API __declspec(dllexport)
#else
#define GROUPANAGRAMS_API__declspec(dllimport)
#endif // MY02GROUPANAGRAMSD_EXPORTS

#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<map>
#include<functional>

std::unordered_map<char, int>& getMap(std::string str);
GROUPANAGRAMS_API void groupAnagrams(std::vector<std::string>);

#endif