#pragma once

#ifdef MY01ATRIPLESTEP_EXPORTS
#define _API __declspec(dllexport)
#else
#define _API __declspec(dllimport)
#endif

_API size_t CountStairCaseHopMethods(size_t numOfStairs);
_API size_t CountStairCaseHopMethodsDP(size_t numOfStairs);