#pragma once

#ifdef MY02AROBOTINGRID_EXPORTS
#define _API __declspec(dllexport)
#else
#define _API __declspec(dllimport)
#endif

_API size_t coutNumWaysV1(int r, int c);
_API size_t coutNumWaysV2(int r, int c);