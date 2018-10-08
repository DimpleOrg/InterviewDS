#pragma once
#ifndef STRING_PERMUTATION_H
#define STRING_PERMUTATION_H
#include<iostream>
#include<vector>
#include<string>

#ifdef STRINGPERMUTATIONSD_EXPORTS
#define STRINGPERMUTATIONSD_API __declspec(dllexport)
#else
#define STRINGPERMUTATIONSD_API __declspec(dllimport)
#endif

STRINGPERMUTATIONSD_API std::vector<std::string> getStringPermutations(std::string const& str);

#endif	//STRING_PERMUTATION_H