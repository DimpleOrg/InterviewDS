#include "ZeroMatrix.h"

#include<vector>
#include <tuple>

using namespace std;

__declspec(dllexport)  void ZeroMatrix(int **matrix, int row, int column)
{
	vector<tuple<int, int>> v;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (matrix[i][j] == 0)
			{
				v.push_back(make_tuple(i, j));
			}
		}
	}

	for (auto val : v)
	{
		int r = get<0>(val);
		int c = get<1>(val);


		for (int i = 0; i < column; i++)
			matrix[r][i] = 0;

		for (int i = 0; i < row; i++)
			matrix[i][c] = 0;
	}

}

inline void MakeRowColumnZero(int **matrix, int row, int column, int rIndex, int cIndex)
{
	for (int i = 0; i < column; i++)
		matrix[rIndex][i] = 0;

	for (int i = 0; i < row; i++)
		matrix[i][cIndex] = 0;
}

__declspec(dllexport)  void ZeroMatrixV3(int **matrix, int row, int column)
{
	bool rowhaszero = false;
	bool columnhaszero = false;

	for (int i = 0; i < row; i++)
	{
		if (matrix[0][i] == 0)
		{
			columnhaszero = true;
			break;
		}
	}

	for (int i = 0; i < column; i++)
	{
		if (matrix[i][0] == 0)
		{
			rowhaszero = true;
			break;
		}
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if( (matrix[i][j]) == 0)
			{
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}
	}

	for (int i = 0; i < row; i++)
	{
		if (matrix[0][i] == 0)
		{
			for (int j = 0; j < column; j++)
			{
				matrix[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < column; i++)
	{
		if (matrix[i][0] == 0)
		{
			for (int j = 0; j < row; j++)
			{
				matrix[j][i] = 0;
			}
		}
	}

	if (rowhaszero)
	{
		for (int i=0;i < column; i++)
		{
			matrix[0][i] = 0;
		}
	}

	if (columnhaszero)
	{
		for (int i = 0; i < row; i++)
		{
			matrix[i][0] = 0;
		}
	}
}