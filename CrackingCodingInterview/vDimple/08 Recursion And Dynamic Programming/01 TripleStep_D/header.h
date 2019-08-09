// header.h : include file for standard system include files,
// or project specific include files
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files
#include <windows.h>



// reference additional headers your program requires here


#pragma once
#ifndef __TRIPLESTEPD_H
#define __TRIPLESTEPD_H

#ifdef MY01TRIPLESTEPD_EXPORTS 
#define TRIPLESTEP_API __declspec(dllexport) 
#else 
#define TRIPLESTEP_API __declspec(dllimport) 
#endif 

#include<iostream>
#include<unordered_map>
#include<vector>

class TripleStep
{
private:
	size_t numberOfPossibleWays = 0;
	int reqdSum = 0;
	std::unordered_map<int, int> umap;

public:
	TripleStep(int sum = 0) : reqdSum(sum) {}

	TRIPLESTEP_API void possibleWays(int curr_sum)
	{
		if (curr_sum > reqdSum)
			return;

		if (curr_sum == reqdSum)
			++numberOfPossibleWays;

		possibleWays(curr_sum + 1);
		possibleWays(curr_sum + 2);
		possibleWays(curr_sum + 3);
	}

	TRIPLESTEP_API size_t possibleWays()
	{
		if (reqdSum > 1)
			possibleWays(1);
		if (reqdSum > 2)
			possibleWays(2);
		if (reqdSum > 3)
			possibleWays(3);

		return numberOfPossibleWays;
	}

	/*==================================================*/

	TRIPLESTEP_API size_t possibleWaysDP(int n, std::vector<int>& memo)
	{
		if (n < 0)
			return 0;
		
		else if (n == 0)
			return 1;
		
		else if (memo[n] > -1)
			return memo[n];
		
		else
			memo[n] = possibleWaysDP(n-1, memo) + possibleWaysDP(n-2, memo) + possibleWaysDP(n-3, memo);

		return memo[n];
	}

	TRIPLESTEP_API size_t possibleWaysDP(int n)
	{
		std::vector<int> memo;
		memo.assign(n + 1, -1);
		
		return possibleWaysDP(n, memo);
	}
};

#endif __TRIPLESTEPD_H