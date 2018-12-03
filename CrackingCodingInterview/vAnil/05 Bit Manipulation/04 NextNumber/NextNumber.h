#pragma once
#ifndef  _N_H_
#define __FLIPBITTOWIN_H_

#include <iostream>

#ifdef MY04NEXTNUMBER_EXPORTS
#define MY04NEXTNUMBER_API __declspec(dllexport)
#else
#define MY04NEXTNUMBER_API __declspec(dllimport)
#endif

MY04NEXTNUMBER_API unsigned NextBigger(unsigned num);
MY04NEXTNUMBER_API unsigned NextSmaller(unsigned num);



#endif // ! __FLIPBITTOWIN_H_
