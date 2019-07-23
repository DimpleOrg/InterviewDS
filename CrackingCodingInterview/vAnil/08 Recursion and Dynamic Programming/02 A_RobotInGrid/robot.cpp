#include "robotheader.h"
#include <vector>

size_t ans1 = 0;
void coutNumWayshV1(const int R, const int C, int r, int c)
{
	if (r >= R || c >= C)
	{
		return;
	}
	else if (r == R - 1 && c == C - 1)
	{
		ans1++;
	}

	if (r < R)
		coutNumWayshV1(R, C, r + 1, c);

	if (c < C)
		coutNumWayshV1(R, C, r, c + 1);
}

_API size_t coutNumWaysV1(int r, int c)
{
	coutNumWayshV1(r, c, 0, 0);
	return ans1;
}


int coutNumWayshV2(std::vector<std::vector<int>> &mp, const int r, const int c)
{
	if (mp[r][c] != 0)
	{
		return mp[r][c];
	}

	if (r == 0 || c == 0)
	{
		return 1;
	}
	else if (r < 0 || c < 0)
	{
		return 0;
	}

	int w = coutNumWayshV2(mp, r - 1, c) + coutNumWayshV2(mp, r, c - 1);
	mp[r][c] = w;

	return w;
}

_API size_t coutNumWaysV2(int r, int c)
{
	std::vector<std::vector<int>> mp(r, std::vector<int>(c, 0));

	coutNumWayshV2(mp, r-1, c-1);

	return mp[r - 1][c - 1];
}