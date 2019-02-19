#pragma once
#ifndef  __DIFFBITS_H_
#define __DIFFBITS_H_

#include <iostream>

#ifdef MY06COUNTDIFFERENTBITS_EXPORTS
#define  MY06COUNTDIFFERENTBITS_API __declspec(dllexport)
#else
#define MY06COUNTDIFFERENTBITS_API __declspec(dllimport)
#endif

MY06COUNTDIFFERENTBITS_API unsigned CountDifferentBits(size_t x, size_t y);



#endif // ! __DIFFBITS_H_

