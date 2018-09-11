#include "pch.h"
#include<fstream>
#include"../../06 CompressString/CompressString.h"
#include"../../08 ZeroMatrix/ZeroMatrix.h"
#include"../../09 IsStringRotation/IsStringRoation.h"

using namespace std;

bool compareMatrix(int **matrix1, int matrix2[][4]);

TEST(Is_String_Rotation, TEST1)
{
	string origstr = "erbottlewat";
	string rotatedString = "waterbottle";

	bool res = isStringRotation(origstr, rotatedString);

	EXPECT_EQ(true, res);
}

TEST(ZeroMatrix, TEST1)
{
	ofstream myfile;
	myfile.open("example.txt");
	myfile << "Writing this to a file.\n";

	int **matrix;
	int row = 4, col = 4;
	matrix = new int*[4];
	for (int i = 0; i < 4; i++)
	{
		matrix[i] = new int[4];
	}
	
	int matrixInit[4][4] = {
		{ 1,0,3,4 },
		{ 5,6,7,8 },
		{ 9,10,0,12 },
		{ 13,14,15,16 },
	};

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			matrix[i][j] = matrixInit[i][j];
		}
	}

	zeroMatrix(row, col, matrix);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			myfile << matrix[i][j] << "   ";
		}
		myfile << "\n";
	}

	int zeroMatrix[4][4] = {
		{ 0,0,0,0 },
		{ 5,0,0,8 },
		{ 0,0,0,0 },
		{ 13,0,0,16 },
	};

	EXPECT_EQ(true, compareMatrix(matrix, zeroMatrix));
	myfile.close();
}

bool compareMatrix(int **matrix1, int matrix2[][4])
{
	bool res = true;
	for (int i = 0; i<4; i++)
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

TEST(COMPRESS_STRING_TEST, TEST1)
{
	string origstr = "aabbccdddd";
	string compressStr;

	compressStr = compressString(origstr);

	EXPECT_EQ("a2b2c2d4", compressStr);
}



TEST(COMPRESS_STRING_TEST, TEST2)
{
	string origstr = "abcd";
	string compressStr;

	compressStr = compressString(origstr);

	EXPECT_EQ("abcd", compressStr);
}


TEST(COMPRESS_STRING_TEST, TEST3)
{
	string origstr = "";
	string compressStr;

	compressStr = compressString(origstr);

	EXPECT_EQ("", compressStr);
}

TEST(COMPRESS_STRING_TEST, TEST4)
{
	string origstr = "aBBBBBBd";
	string compressStr;

	compressStr = compressString(origstr);

	EXPECT_EQ("a1B6d1", compressStr);
}
