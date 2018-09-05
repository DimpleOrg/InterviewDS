#include "matrix_rotation.h"

inline void swap(int &i, int &j)
{
	int k = i;
	i = j;
	j = k;
}

bool RotateMatrixby90Degree(int **matrix, int l)
{
	try {
		//Invert the row-column
		if (matrix == nullptr || l < 1)
			return false;

		for (int i = 0; i < l; i++)
		{
			for (int j = i; j < l; j++)
			{
				swap(matrix[i][j], matrix[j][i]);
			}
		}

		int half_len = l / 2;
		// exchange column
		for (int i = 0; i < half_len; i++)
		{
			for (int j = 0; j < l; j++)
			{
				swap(matrix[j][i], matrix[j][l - i - 1]);
			}
		}
	}
	catch (...)
	{
		return false;
	}

	return true;
}