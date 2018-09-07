#include"MatrixRotation.h"

using namespace std;
/*int main()
{
	int **matrix;
	matrix = new int*[4];
	for (int i = 0; i < 4; i++)
	{
		matrix[i] = new int[4];
	}
	//matrix[0] = { 1,2,3,4 };


	int matrixInit[4][4] = {
		{ 1,2,3,4 },
	{ 5,6,7,8 },
	{ 9,10,11,12 },
	{ 13,14,15,16 },
	};

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			matrix[i][j] = matrixInit[i][j];
		}
	}

	rotateMatrixBy90(matrix, 4);
	return 0;
}*/

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