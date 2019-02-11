#include "MultiplyBigNumbers.h"

using namespace std;

string MultiplyString(string num1, string num2)
{
	vector<string> vecOfStr;
	string suffix = "";

	for (size_t len = num2.length(); len > 0; len--)
	{
		vecOfStr.push_back(MultiplyStringToChar(num1, num2[len - 1]) + suffix);
		suffix += "0";
	}

	return AddStringsOfVector(vecOfStr);
}

string MultiplyStringToChar(string num, char ch)
{
	unsigned int m = ch - '0';
	string result = "";
	unsigned int carry = 0;

	for (size_t len = num.length(); len > 0; len--)
	{
		unsigned int temp = (m * (num[len - 1] - '0')) + carry;

		if (temp < 9)
		{
			carry = 0;
			result = static_cast<char>(temp + '0') + result;
		}
		else
		{
			carry = temp / 10;
			result = static_cast<char>((temp % 10) + '0') + result;
		}
	}

	while (carry != 0)
	{
		result = static_cast<char>((carry % 10) + '0') + result;
		carry /= 10;
	}

	return result;
}

string AddStringsOfVector(vector<string> vecOfStr)
{
	string result = "";
	size_t carry = 0;
	size_t sum = 0;

	for (size_t len = 0; len < vecOfStr.back().length(); len++)
	{
		sum = 0;
		for (size_t vlen = vecOfStr.size(); vlen > 0; vlen--)
		{
			if (vecOfStr[vlen - 1].size() > len)
			{
				sum = sum + (vecOfStr[vlen - 1][vecOfStr[vlen - 1].size() - 1 - len] - '0');
			}
		}

		sum = sum + carry;

		if (sum < 9)
		{
			carry = 0;
			result = static_cast<char>(sum + '0') + result;
		}
		else
		{
			carry = sum / 10;
			result = static_cast<char>((sum % 10) + '0') + result;
		}
	}

	while (carry != 0)
	{
		result = static_cast<char>((carry % 10) + '0') + result;
		carry /= 10;
	}

	return result;
}

string multiply(string num1, string num2) {
	string sum(num1.size() + num2.size(), '0');

	for (int i = num1.size() - 1; 0 <= i; --i) {
		int carry = 0;
		for (int j = num2.size() - 1; 0 <= j; --j) {
			int tmp = (sum[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
			sum[i + j + 1] = tmp % 10 + '0';
			carry = tmp / 10;
		}
		sum[i] += carry;
	}

	size_t startpos = sum.find_first_not_of("0");
	if (string::npos != startpos) {
		return sum.substr(startpos);
	}
	return "0";
}
