#pragma once
#ifdef MY01ASORTEDMERGE_EXPORTS
#define _API __declspec(dllexport)
#else
#define _API __declspec(dllimport)
#endif


_API void mergeArray(int arr1[], int len1, int arr2[], int len2);