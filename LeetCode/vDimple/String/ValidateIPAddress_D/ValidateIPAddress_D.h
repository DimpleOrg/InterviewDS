#pragma once
#ifdef VALIDATEIPADDRESSD_EXPORTS
#define VALIDATEIPADDRESSD_API __declspec(dllexport)
#else
#define VALIDATEIPADDRESSD_API __declspec(dllimport)
#endif // VALIDATEIPADDRESSD_EXPORTS

#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

VALIDATEIPADDRESSD_API string validIPAddress(string IP);
bool isIPV4(string str);