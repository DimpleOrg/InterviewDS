#include"MatrixRotation.h"

using namespace std;


void rotateMatrixBy90(int **matrix, int len)
{
	
	
	int templen = len-1;
	for (int i = 0; i < len; i++)
		{
			for (int j = i; j < len; j++)
			{
				swap(matrix[i][j], matrix[j][i]);
			}
		}
	for (int i = 0; i < len/2; i++)
	{
		for (int j = 0; j < len; j++)
		{
			swap(matrix[j][i], matrix[j][templen]);
		}
		templen--;
	}
}

void swap(int &a, int &b)
{
	int temp = 0;
	temp = a;
	a = b;
	b = temp;;
}

//----------------------------------version2-------------------------------------

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
	cIndex = index;

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

	rIndex = len - 1 - index;
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

	rIndex = index;
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
	cIndex = len - 1 - index;


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
		//int k = 0;
		for (int j = i; j < l - 1 - layer; j++)
		{
			int temp = *top(layer, j);
			*top(layer, j) = *left(layer, j);
			*left(layer, j) = *bottom(layer, j);
			*bottom(layer, j) = *right(layer, j);
			*right(layer, j) = temp;
			//k++;
		}
	}

	return true;
}