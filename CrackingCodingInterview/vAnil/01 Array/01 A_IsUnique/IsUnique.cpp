#include <iostream>

using namespace std;

unsigned long bitVector = 0;

void setBit(char ch)
{
	bitVector |= (1UL << (ch - 1));
}

int getBit(char ch)
{
	return bitVector & (1UL << (ch - 1));
}

bool IsUnique(const char *str, int length)
{
	bool result = true;

	for (int i = 0; i < length && str[i] != '\0'; i++)
	{
		if (getBit(str[i]))
		{
			
			result = false;
			break;
		}
		else 
		{
			setBit(str[i]);
		}
	}

	
	return result;
}

int main(int argc, char *argv[])
{
	char str[] = "ASDFGHsdfsdfsdfaa";

	bool result  = IsUnique(str, sizeof(str));

	cout << "string is:" << str;
	if (result)
	{
		cout << "\nUnique \n";
	}
	else
	{
		cout << "\nNot Unique \n";
	}


	return 0;
}