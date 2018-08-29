#include <iostream>
#include <string>

using namespace std;

bool CheckOneEditAway(string orig, string edited)
{
	size_t olen = orig.length();
	size_t elen = edited.length();
	
	if (olen > elen && olen - elen > 1)
	{
		return false;
	}
	else if (elen > olen && elen - olen > 1)
	{
		return false;
	}

	if (olen > elen)
		{
			size_t mismatchCount = 0;
			for (size_t i = 0,j=0; i < olen; i++)
			{
				if (orig[i] != edited[j])
				{
					mismatchCount++;
				}
				else
				{
					j++;
				}
			}

			if (mismatchCount > 1)
				return false;
		}
		else if (elen > olen)
		{
			size_t mismatchCount = 0;
			for (size_t i = 0, j = 0; i < elen; i++)
			{
				if (edited[i] != orig[j])
				{
					mismatchCount++;
				}
				else
				{
					j++;
				}
			}

			if (mismatchCount > 1)
				return false;
		}
		else
		{
			size_t mismatchCount = 0;
			for (size_t i = 0, j = 0; i < elen; i++)
			{
				if (edited[i] != orig[i])
				{
					mismatchCount++;
				}
			}

			if (mismatchCount > 1)
				return false;
		}


	return true;
}


int main()
{
	string orig = "pale";
	string edited = "bake";

	cout << CheckOneEditAway(orig, edited);

	return 0;
}