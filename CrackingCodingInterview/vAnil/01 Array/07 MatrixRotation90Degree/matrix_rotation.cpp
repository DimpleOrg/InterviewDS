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


int **matrix;
int len;

inline int* top(int layer, int index)
{
	if (index >= len || layer > len / 2)
	{
		throw;
	}

	int rIndex = 0;
	int cIndex = 0;

	rIndex = layer;
	cIndex = layer + index;

	return &matrix[rIndex][cIndex];
}

inline int* left(int layer, int index)
{
	if (index >= len || layer > len / 2)
	{
		throw;
	}

	int rIndex = 0;
	int cIndex = 0;

	rIndex = len-1-layer-index;
	cIndex = layer;


	return &matrix[rIndex][cIndex];
}

inline int* right(int layer, int index)
{
	if (index >= len || layer > len / 2)
	{
		throw;
	}

	int rIndex = 0;
	int cIndex = 0;

	rIndex = layer + index;
	cIndex = len - 1 - layer;


	return &matrix[rIndex][cIndex];
}


inline int* bottom(int layer, int index)
{
	if (index >= len || layer > len / 2)
	{
		throw;
	}

	int rIndex = 0;
	int cIndex = 0;

	rIndex = len - 1 - layer;
	cIndex = len - 1 - layer - index;


	return &matrix[rIndex][cIndex];
}




__declspec(dllexport) bool RotateMatrixBy90DegreeV2(int **matrix, int l)
{
	if (matrix == nullptr)
		return false;

	::matrix = matrix;
	len = l;

	for (int i = 0; i < l / 2; i++)
	{
		int layer = i;
		int k = 0;
		for (int j = i; j < l -1 - layer; j++)
		{
			int temp = *top(layer, k);
			*top(layer, k) = *left(layer, k);
			*left(layer, k) = *bottom(layer, k);
			*bottom(layer, k) = *right(layer, k);
			*right(layer, k) = temp;
			k++;
		}
	}

	return true;
}

