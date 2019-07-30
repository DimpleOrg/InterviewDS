#include "robotheader.h"
#include <vector>


bool IsDefectiveCell(std::unordered_multimap<int, int> dlist, int r, int c)
{
	typedef std::unordered_multimap<int, int>::iterator ITER;

	std::pair<ITER, ITER> res = dlist.equal_range(r);

	for (ITER it = res.first; it != res.second; it++)
	{
		if (c == it->second)
		{
			return true;
		}
	}

	return false;
}

size_t ans1 = 0;
void coutNumWayshV1(const int R, const int C, int r, int c, std::unordered_multimap<int, int> dlist)
{
	if (r >= R || c >= C)
	{
		return;
	}
	else if (IsDefectiveCell(dlist, r, c))
	{
		return;
	}
	else if (r == R - 1 && c == C - 1)
	{
		ans1++;
	}
	

	if (r < R)
		coutNumWayshV1(R, C, r + 1, c, dlist);

	if (c < C)
		coutNumWayshV1(R, C, r, c + 1, dlist);
}

_API size_t coutNumWaysV1(int r, int c, std::unordered_multimap<int, int> dlist)
{
	coutNumWayshV1(r, c, 0, 0, dlist);
	return ans1;
}


int coutNumWayshV2(std::vector<std::vector<int>> &mp, const int r, const int c)
{

	if (r < 0 || c < 0)
		return 0;

	if (mp[r][c] == -1)
	{
		return 0;
	}

	if (mp[r][c] != 0)
		return mp[r][c];

	if (r == 0 && c == 0)
	{
		return 1;
	}
	else if (r == 0 && c == 1)
	{
		return 1;
	}
	else if (c == 0 && r == 1)
	{
		return 1;
	}
	
	int w = coutNumWayshV2(mp, r - 1, c) + coutNumWayshV2(mp, r, c - 1);
	mp[r][c] = w;

	return w;
}

_API size_t coutNumWaysV2(int r, int c, std::unordered_multimap<int, int> dlist)
{
	std::vector<std::vector<int>> mp(r, std::vector<int>(c, 0));

	for (auto iter = dlist.begin(); iter != dlist.end(); iter++)
	{
		mp[iter->first][iter->second] = -1;
	}

	coutNumWayshV2(mp, r-1, c-1);
	return mp[r - 1][c - 1];
}





int  getPathHelper(std::vector<std::vector<int>> &mp, const int r, const int c, std::vector<std::pair<int, int>>& ans)
{
	if (r == 0 && c == 0)
	{
		return 0;
	}
	else if (r < 0 || c < 0 || mp[r][c] == -1)
	{
		return 1;
	}

	ans.push_back({ r - 1,c });
	
	int ret = getPathHelper(mp, r - 1, c, ans);
	if (ret == 1)
	{
		if (r > 0 && c >= 0)
			mp[r - 1][c] = -1;
		ans.pop_back();
	}
	else if (ret == 0)
		return 0;
	ans.push_back({ r, c - 1 });
	ret = getPathHelper(mp, r, c - 1, ans);
	if (ret == 1)
	{
		if (r >= 0 && c > 0)
			mp[r][c-1] = -1;

		ans.pop_back();
	}
	else if (ret == 0)
		return 0;
	return 1;
}

_API std::vector<std::pair<int, int>> getPath(int r, int c, std::unordered_multimap<int, int> dlist)
{
	std::vector<std::vector<int>> mp(r, std::vector<int>(c, 0));

	std::vector<std::pair<int, int>> ans;

	for (auto iter = dlist.begin(); iter != dlist.end(); iter++)
	{
		mp[iter->first][iter->second] = -1;
	}

	ans.push_back({ r - 1, c - 1 });
	int ret = getPathHelper(mp, r - 1, c - 1, ans);

	if (ret != 0)
		ans.clear();

	std::reverse(ans.begin(), ans.end());

	return ans;
}
