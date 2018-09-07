#include "pch.h"
#include<fstream>

#include"../../07 MatrixRotation/MatrixRotation.h"

using namespace std;

bool compareMatrix(int **matrix1, int matrix2[][4]);

TEST(Matrix_TEST, TEST1)
{
	ofstream myfile;	myfile.open("example.txt");	myfile << "Writing this to a file.\n";	//myfile.close();

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

	rotateMatrixBy90(matrix,4);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			myfile << matrix[i][j] << "   ";
		}
		myfile << "\n";
	}
	int rotatedMatrix[4][4] = {
		{ 13,9,5,1 },
		{ 14,10,6,2 },
		{ 15,11,7,3 },
		{ 16,12,8,4 },
	};

	EXPECT_EQ(true, compareMatrix(matrix, rotatedMatrix));

	myfile.close();
}

TEST(Matrix_TEST, TEST2)
{
	ofstream myfile;	myfile.open("example.txt");	myfile << "Writing this to a file.\n";	//myfile.close();

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

	rotateMatrixBy90(matrix, 4);
	rotateMatrixBy90(matrix, 4);
	rotateMatrixBy90(matrix, 4);
	rotateMatrixBy90(matrix, 4);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			myfile << matrix[i][j] << "   ";
		}
		myfile << "\n";
	}
	int rotatedMatrix[4][4] = {
		{ 1,2,3,4 },
	{ 5,6,7,8 },
	{ 9,10,11,12 },
	{ 13,14,15,16 },
	};

	EXPECT_EQ(true, compareMatrix(matrix, rotatedMatrix));

	myfile.close();
}

bool compareMatrix(int **matrix1, int matrix2[][4])
{
	bool res = true;
	for (int i=0;i<4;i++)
	{
		for (int j = 0; j < 4; j++)
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