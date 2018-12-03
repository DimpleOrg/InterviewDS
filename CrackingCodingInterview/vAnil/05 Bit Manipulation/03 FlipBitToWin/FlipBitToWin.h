#pragma once
#ifndef  __FLIPBITTOWIN_H_
#define __FLIPBITTOWIN_H_

#include <iostream>

#ifdef MY03FLIPBITTOWIN_EXPORTS
#define MY03FLIPBITTOWIN_API __declspec(dllexport)
#else
#define MY03FLIPBITTOWIN_API __declspec(dllimport)
#endif

MY03FLIPBITTOWIN_API int Longest1Sequence(unsigned num);



#endif // ! __FLIPBITTOWIN_H_