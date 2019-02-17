//Given two non - negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
//Example 1:
//Input: num1 = "2", num2 = "3"
//	Output : "6"

#include<iostream>
#include<string>
#include<vector>

std::string addIntStrings(std::string str1, std::string str2)
{
	std::string res = "";
	int product = 0;
	int carry = 0;
	int loop = 0;
	std::vector<std::string> vec;
	for (int i = str1.length() - 1; i >= 0; i--)
	{
		for (int j = str2.length() - 1; j >= 0; j--)
		{
			int product = (static_cast<int>(str2[j] - '0') * static_cast<int>(str1[i] - '0')) + carry;
			if (product > 9)
			{
				carry = product / 10;
				product = product % 10;
			}
			else
				carry = 0;
			res = static_cast<char>(product +'0') + res;
		}
		if(carry>0)
			res = static_cast<char>(carry + '0') + res;

		for (int k = 0; k<loop ;k++)
		{
			res = res + '0';
		}
		vec.push_back(res);
		res = "";
		carry = 0;

		loop++;
	}

	int sum = 0;
	carry = 0;
	int offset = 1;
	std::string finalStr = "";
	for (int i = 0; i < vec.back().size(); i++)
	{
		sum = 0;
		for (auto each : vec)
		{
			if ((each.size() >= offset) )
			{
				sum = sum + static_cast<int>(each[each.size() - offset] - '0');
			}
		}
		sum += carry;

		if (sum > 9)
		{
			carry = sum / 10;
			sum = sum % 10;
		}
		else
			carry = 0;

		finalStr = static_cast<char>(sum + '0') + finalStr;
		
		offset++;
	}
	if (carry > 0)
	{
		if (carry > 9)
		{
			do
			{
				finalStr = static_cast<char>((carry%10) + '0') + finalStr;
				carry = carry / 10;
			} while (carry != 0);
		}
		else
		{
			finalStr = static_cast<char>((carry % 10) + '0') + finalStr;
		}
	}

	return finalStr;
}

int main()
{
	std::string res = addIntStrings("1257", "1399");
	std::string res1 = addIntStrings("9999", "9999");
	std::string res2 = addIntStrings("12575645634245356578", "138765432344");
	return 0;
}