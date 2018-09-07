#include"ZeroMatrix.h"

using namespace std;

void zeroMatrix(int row, int col, int **matrix)
{
	bool rowHasZero = false;
	bool colHasZero = false;
	
	//check if row 0 has 0
	for (int j = 0; j < col; j++)
	{
		if (matrix[0][j] == 0)
			rowHasZero = true;
	}

	//check if col 0 has 0
	for (int i = 0; i < row; i++)
	{
		if (matrix[i][0] == 0)
			colHasZero = true;
	}

	for (int i = 1; i < row; i++)
	{
		for (int j = 1; j < col; j++)
		{
			if (matrix[i][j] == 0)
			{
				matrix[0][j] = 0;
				matrix[i][0] = 0;
			}
		}
	}

	for (int j = 0; j < col; j++)
	{
		if (matrix[0][j] == 0)
		{
			makeColZero(matrix, j, row, col);
		}
	}

	for (int i = 0; i < row; i++)
	{
		if (matrix[i][0] == 0)
			makeRowZero(matrix, i, row, col);
	}

	if (rowHasZero == true)
	{
		for (int j= 0; j < col; j++)
		{
			matrix[0][j] = 0;
		}
	}
	if (colHasZero == true)
	{
		for (int i = 0; i < row; i++)
		{
			matrix[i][0] = 0;
		}
	}
}
void makeRowZero(int **matrix, int i, int row, int col)
{
	for (int k = 0; k < col; k++)
	{
		matrix[i][k] = 0;
	}
}
void makeColZero(int **matrix, int j, int row, int col)
{
	for (int k = 0; k < row; k++)
	{
		matrix[k][j] = 0;
	}
}