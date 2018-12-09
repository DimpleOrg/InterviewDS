#pragma once
#ifndef  __DECIMAL_FRACTION_TO_STR_H_
#define __DECIMAL_FRACTION_TO_STR_H_

#include <iostream>
#include <string>

#ifdef MY02DECIMALFRACTIONTOBINARY_EXPORTS
#define MY02DECIMALFRACTIONTOBINARY_API __declspec(dllexport)
#else
#define MY02DECIMALFRACTIONTOBINARY_API __declspec(dllimport)
#endif

MY02DECIMALFRACTIONTOBINARY_API std::string DecimalFractionToString(double decimalFraction);



#endif // ! __DECIMAL_FRACTION_TO_STR_H_
