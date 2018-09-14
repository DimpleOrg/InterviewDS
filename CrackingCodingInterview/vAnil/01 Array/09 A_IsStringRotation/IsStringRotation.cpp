#include"IsStringRotation.h"

bool isStringRotation(string origString, string rotatedString)
{
	if (origString.length() != rotatedString.length())
		return false;
	if (origString == "")
		return true;

	string newString = origString + origString;
	bool res = isSubstring(newString, rotatedString);
	return res;
}

bool isSubstring(string newString, string rotatedString)
{
	return newString.find(rotatedString);
}