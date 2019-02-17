//Implement atoi which converts a string to an integer.
//The function first discards as many whitespace characters as necessary until the first non - whitespace character is found.Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
//The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
//If the first sequence of non - whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
//If no valid conversion could be performed, a zero value is returned.
//Note:
//Only the space character ' ' is considered as whitespace character.
//Assume we are dealing with an environment which could only store integers within the 32 - bit signed integer range : [−231, 231 − 1].If the numerical value is out of the range of representable values, INT_MAX(231 − 1) or INT_MIN(−231) is returned.
//Example 1 :
//	Input : "42"
//	Output : 42
//Example 2 :
//	Input : "   -42"
//	Output : -42
//Example 3 :
//	Input : "4193 with words"
//	Output : 4193
//Example 4 :
//	Input : "words and 987"
//	Output : 0
//	Explanation : The first non - whitespace character is 'w', which is not a numerical
//Example 5 :
//	Input : "-91283472332"
//	Output : -2147483648
//	Explanation : The number "-91283472332" is out of the range of a 32 - bit signed integer.
//	Thefore INT_MIN(−231) is returned.*/


#include<iostream>
#include<string>
#include<vector>
#include<math.h>

int getchartoint(char ch)
{
	return (ch - '0');
}

int Myatoi(std::string str)
{
	std::vector<int> vec;
	int res = 0;
	int start = 0;
	bool flag = false;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] != ' ')
		{
			if (isdigit(str[i]))
			{
				start = i;
				do
				{
					flag = true;
					vec.push_back(getchartoint(str[i]));
					i++;
				} while (isdigit(str[i]));
			}
			else
			{
				if (str[i] != '+' && str[i] != '-')
				{
					res = 0;
					flag = true;
				}
			}
			
		}
		if(flag)
			break;
	}
	if (!vec.empty())
	{
		int index = 0;
		for (int i = vec.size() - 1; i >= 0; i--)
		{
			if ((res + (vec[index] * pow(10, i))) < 0)
			{
				res = INT32_MAX;
				break;
			}
			else
			{
				res = res + (vec[index] * pow(10, i));
				index++;
			}	
		}
	}
	else
	{
		res = 0;
	}

	if ((start - 1 >= 0) && str[start - 1] == '-')
	{
		if (res == INT32_MAX)
			res = INT32_MIN;
		else
			res = -res;	
	}
		
	return res;
}

int main()
{
	int res = Myatoi("42");
	int res1 = Myatoi("-42");
	int res2 = Myatoi("4193 with words");
	int res3 = Myatoi("words and 987");
	int res4 = Myatoi("    123   456");
	int res5 = Myatoi("   012345678909876543210jh65hjjh");
	int res6 = Myatoi("   -12345678909876543210jh65hjjh");
	int res7 = Myatoi("   -2147483648");
	int res8 = Myatoi("   -2147483647");			//only this case not working
	int res9 = Myatoi("   dgf-123456hjjh");
	int max= INT32_MAX;
	int min = INT32_MIN;
	return 0;
}