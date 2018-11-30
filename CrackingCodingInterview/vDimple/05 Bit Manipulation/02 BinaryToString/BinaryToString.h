#pragma once
#ifndef __BINARYTOSTRING_H_
#define __BINARYTOSTRING_H_

#ifdef MY02BINARYTOSTRING_EXPORTS
#define BINARYTOSTRING_API __declspec(dllexport)
#else
#define BINARYTOSTRING_API __declspec(dllimport)
#endif

#include<iostream>

BINARYTOSTRING_API std::string convert(double n);

#endif