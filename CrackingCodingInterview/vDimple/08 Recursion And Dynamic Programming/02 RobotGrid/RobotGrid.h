#pragma once
#pragma once
#ifndef __ROBOTGRID_H
#define __ROBOTGRID_H

#ifdef MY02ROBOTGRID_EXPORTS 
#define MY02ROBOTGRID_API __declspec(dllexport) 
#else 
#define MY02ROBOTGRID_API __declspec(dllimport) 
#endif 

#include<iostream>
#include<vector>
#include<unordered_set>
#include<set>

struct point
{
	int x;
	int y;

	bool operator <(const point& pt) const
	{
		return (x < pt.x) || ((!(pt.x < x)) && (y < pt.y));
	}
};

std::set<point> invalidCells = { {0,1}, {2,2}, {0,3} };

MY02ROBOTGRID_API std::vector<std::vector<point>> findPath(int R, int C);

MY02ROBOTGRID_API std::vector<point> findPathDP(std::vector<std::vector<int>>& matrix, int R, int C);
int findPathDP(std::vector<std::vector<int>>& matrix, int r, int c, int R, int C, std::vector<point>& res);

#endif // __ROBOTGRID_H
