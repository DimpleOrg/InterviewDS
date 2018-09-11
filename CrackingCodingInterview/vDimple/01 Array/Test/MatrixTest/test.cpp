#include "pch.h"
#include"../../07 MatrixRotation/MatrixRotation.h"

using namespace std;

bool compareMatrix(int **matrix1, int **matrix2, int len);

TEST(Matrix_TEST, TEST1)
{
	int **matrix;
	matrix = new int*[4];
	for (int i = 0; i < 4; i++)
	{
		matrix[i] = new int[4];
	}
	
	int matrixInit[4][4] = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
		{13,14,15,16},
	};

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			matrix[i][j] = matrixInit[i][j];
		}
	}

	//rotateMatrixBy90(matrix,4);
	bool result = RotateMatrixBy90DegreeV2(matrix, 4);

	
	int **rotatedMatrix;
	rotatedMatrix = new int*[4];
	for (int i = 0; i < 4; i++)
	{
		rotatedMatrix[i] = new int[4];
	}

	int rotatedMatrixInit[4][4] = {
		{ 13,9,5,1 },
	{ 14,10,6,2 },
	{ 15,11,7,3 },
	{ 16,12,8,4 },
	};

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			rotatedMatrix[i][j] = rotatedMatrixInit[i][j];
		}
	}


	EXPECT_EQ(true, result);
	int len = 4;
	EXPECT_EQ(true, compareMatrix(matrix, rotatedMatrix,len));

}

TEST(Matrix_TEST, TEST2)
{
	int **matrix;
	matrix = new int*[4];
	for (int i = 0; i < 4; i++)
	{
		matrix[i] = new int[4];
	}

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

	/*rotateMatrixBy90(matrix, 4);
	rotateMatrixBy90(matrix, 4);
	rotateMatrixBy90(matrix, 4);
	rotateMatrixBy90(matrix, 4);*/

	bool result = RotateMatrixBy90DegreeV2(matrix, 4);
	 result = RotateMatrixBy90DegreeV2(matrix, 4);
	 result = RotateMatrixBy90DegreeV2(matrix, 4);
	 result = RotateMatrixBy90DegreeV2(matrix, 4);

	int **rotatedMatrix;
	rotatedMatrix = new int*[4];
	for (int i = 0; i < 4; i++)
	{
		rotatedMatrix[i] = new int[4];
	}

	int rotatedMatrixInit[4][4] = {
		{ 1,2,3,4 },
	{ 5,6,7,8 },
	{ 9,10,11,12 },
	{ 13,14,15,16 },
	};

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			rotatedMatrix[i][j] = rotatedMatrixInit[i][j];
		}
	}

	EXPECT_EQ(true, result);
	int len = 4;
	EXPECT_EQ(true, compareMatrix(matrix, rotatedMatrix, len));

	
}

TEST(Matrix_TEST, TEST3)
{
	int **matrix;
	matrix = new int*[5];
	for (int i = 0; i < 5; i++)
	{
		matrix[i] = new int[5];
	}

	int matrixInit[5][5] = {
		{ 1,2,3,4,5 },
	{ 6,7,8,9,10 },
	{ 11,12,13,14,15 },
	{ 16,17,18,19,20},
	{21,22,23,24,25}
	};

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			matrix[i][j] = matrixInit[i][j];
		}
	}

	//rotateMatrixBy90(matrix,4);
	bool result = RotateMatrixBy90DegreeV2(matrix, 5);

	int **rotatedMatrix;
	rotatedMatrix = new int*[5];
	for (int i = 0; i < 5; i++)
	{
		rotatedMatrix[i] = new int[5];
	}

	int rotatedMatrixInit[5][5] = {
		{ 21,16,11,6,1 },
	{ 22,17,12,7,2 },
	{ 23,18,13,8,3 },
	{ 24,19,14,9,4 },
	{ 25,20,15,10,5 }
	};

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			rotatedMatrix[i][j] = rotatedMatrixInit[i][j];
		}
	}
	
	int len = 5;
	EXPECT_EQ(true, result);

	EXPECT_EQ(true, compareMatrix(matrix, rotatedMatrix, len));

}

bool compareMatrix(int **matrix1, int **matrix2, int len)
{
	bool res = true;
	for (int i=0;i<len;i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (matrix1[i][j] != matrix2[i][j])
			{
				res = false;
				break;
			}
		}
	}
	return res;
}