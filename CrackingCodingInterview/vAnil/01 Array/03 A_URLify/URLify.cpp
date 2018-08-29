#include <iostream>

using namespace std;

void URLify(char *str, uint32_t max_lenght)
{
	uint32_t len = 0;
	uint32_t count_space = 0;

	for (int i = 0; str[i] != '\0' && i < max_lenght; i++)
	{
		if (str[i] == ' ')
			count_space++;

		len = i;
	}

	len++;

	uint32_t extra_lenght = 0;

	extra_lenght = count_space * 2;

	if ((len + extra_lenght) < max_lenght) {

		for (int i = len - 1; i > 0; i--) {
			if (str[i] == ' ')
			{
				for (int j = len; j > i; j--)
				{
					str[j + 2] = str[j];
				}

				str[i] = '\\';
				str[i + 1] = '2';
				str[i + 2] = '0';

					len += 2;
			}
		}
	}
}

int main(int argc, char *argv[])
{
	char str[100] = "Hello World I am Here";

	URLify(str, sizeof(str));

	cout << str;

}