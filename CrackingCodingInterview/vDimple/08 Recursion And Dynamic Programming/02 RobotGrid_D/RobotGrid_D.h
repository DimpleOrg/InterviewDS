#pragma once
#ifndef __ROBOTGRID_H
#define __ROBOTGRID_H

#ifdef MY02ROBOTGRIDD_EXPORTS 
#define MY02ROBOTGRIDD_API __declspec(dllexport) 
#else 
#define MY02ROBOTGRIDD_API __declspec(dllimport) 
#endif 

#include<iostream>
#include<vector>
#include<unordered_set>

struct point
{
	int x;
	int y;
};

std::unordered_set<point> invalidCells = { {0,1}, {2,2}, {3,0} };

bool isInvalidCell(int r, int c)
{
	return (invalidCells.find({ r, c }) != invalidCells.end());
}

void findPath(int r, int c, int R, int C, std::vector<point>& path, std::vector<std::vector<point>>& res)
{
	if (isInvalidCell(r, c))
		return;

	if (r > R || c > C)
		return;

	path.push_back({ r,c });

	if ((r == R) && (c == C))
		res.push_back(path);

	if ((r == R) && (c < C))
	{
		findPath(r, c + 1, R, C, path, res);
		path.pop_back();
	}

	if ((c == C) && (r < R))
	{
		findPath(r+1, c, R, C, path, res);
		path.pop_back();
	}

	findPath(r, c + 1, R, C, path, res);
	findPath(r + 1, c, R, C, path, res);

	path.pop_back();
}

MY02ROBOTGRIDD_API std::vector<std::vector<point>> findPath(int R, int C)
{
	std::vector<point> path;
	std::vector<std::vector<point>> res;
	findPath(0, 0, R, C, path, res);
	return res;
}

#endif // __ROBOTGRID_H
