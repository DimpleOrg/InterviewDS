#include <iostream>
#include <string>

using namespace std;

void convertToURL(int);
void moveElements(int, int);

static string str = "Mr John Smith    ";

int main()
{
	try
	{
		cout << "\n" << str << "\n";
		convertToURL(13);
		cout << "\n" << str << "\n";
	}
	catch (...)
	{
		cout << "\nException thrown\n";
	}

	return 0;
}

void convertToURL(int trueStrLen)
{
	for (int i = trueStrLen - 1; i >= 0; i--)
	{
		if (str[i] == ' ')
		{
			moveElements(i + 1, trueStrLen);
			str[i] = '%';
			str[i + 1] = '2';
			str[i + 2] = '0';
			trueStrLen += 2;

		}
	}
}

void moveElements(int pos, int trueStrLen)
{
	for (int i = trueStrLen - 1; i >= pos; i--)
	{
		str[i + 2] = str[i];
	}
}