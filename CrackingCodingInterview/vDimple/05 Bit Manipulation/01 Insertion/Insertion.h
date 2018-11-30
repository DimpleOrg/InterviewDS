#pragma once
#ifndef __INSERTION_H_
#define __INSERTION_H_

#ifdef MY01INSERTION_EXPORTS
#define INSERTION_API __declspec(dllexport)
#else
#define INSERTION_API __declspec(dllimport)
#endif

#include<iostream>

INSERTION_API int bitInsertion(int, int, int const, int const);
int clearBits( int const, int const);
void printBinary(unsigned int num);

#endif
