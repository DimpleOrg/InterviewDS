#pragma once
#ifndef __STRING_PERMUTATION_H_
#define __STRING_PERMUTATION_H_
#include <vector>
#include <string>
#include <iostream>

#ifdef STRINGPERMUTATION_EXPORTS
#define STRINGPERMUTATION_API __declspec(dllexport)
#else
#define STRINGPERMUTATION_API __declspec(dllimport)
#endif



STRINGPERMUTATION_API std::vector<std::string> getStringPermutations(std::string const &str);

#endif//__STRING_PERMUTATION_H_