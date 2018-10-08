#pragma once
#ifndef __NUMBER_OF_LINES_TO_WRITE_STRING_H_
#define __NUMBER_OF_LINES_TO_WRITE_STRING_H_
#include <vector>
#include <string>
#include <iostream>

#ifdef NUMBEROFLINESTOWRITESTRING_EXPORTS
#define NUMBEROFLINESTOWRITESTRING_API __declspec(dllexport)
#else
#define NUMBEROFLINESTOWRITESTRING_API __declspec(dllimport)
#endif



NUMBEROFLINESTOWRITESTRING_API std::vector<size_t> numberOfLines(const std::vector<size_t>& widths, const std::string &s, size_t lineLen = 100);

#endif