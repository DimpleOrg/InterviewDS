#pragma once
#ifndef __FLIPBITTOWIN_H
#define __FLIPBITTOWIN_H

#include<iostream>

#ifdef MY03FLIPBITTOWIN_EXPORTS
#define FLIPBITTOWIN_API __declspec(dllexport)
#else
#define FLIPBITTOWIN_API _declspec(dllimport)
#endif

FLIPBITTOWIN_API size_t longestSeq(size_t n);

#endif