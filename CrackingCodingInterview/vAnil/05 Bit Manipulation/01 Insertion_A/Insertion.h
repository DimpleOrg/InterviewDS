#pragma once
#ifndef  __INSERTION_H_
#define __INSERTION_H_

#include <iostream>

#ifdef MY01INSERTIONA_EXPORTS
#define MY01INSERTIONA_API __declspec(dllexport)
#else
#define MY01INSERTIONA_API __declspec(dllimport)
#endif

MY01INSERTIONA_API int Insert_M_into_N(int N, int M, int i, int j);



#endif // ! __INSERTION_H_
