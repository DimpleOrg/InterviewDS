#pragma once
#include <iostream>
#include <string>


#ifdef PRACTICEQUESTIONS_EXPORTS
#define PRACTICEQUESTIONS_API __declspec(dllexport)
#else
#define PRACTICEQUESTIONS_API __declspec(dllimport)
#endif

PRACTICEQUESTIONS_API std::string validIPAddress(std::string IP);