#include "pch.h"
#include "../../06 A_CompressString/CompressString.h"
#include "../../07 MatrixRotation90Degree/matrix_rotation.h"
#include "../../08 ZeroMatrix/ZeroMatrix.h"
using namespace std;


TEST(COMPRESS_STRING_TEST, TEST1)
{
	string origstr = "aabbccdddd";
	string compressStr;

	compressStr = CompressString(origstr);

	EXPECT_EQ("a2b2c2d4", compressStr);
}



TEST(COMPRESS_STRING_TEST, TEST2)
{
	string origstr = "abcd";
	string compressStr;

	compressStr = CompressString(origstr);

	EXPECT_EQ("abcd", compressStr);
}


TEST(COMPRESS_STRING_TEST, TEST3)
{
	string origstr = "";
	string compressStr;

	compressStr = CompressString(origstr);

	EXPECT_EQ("", compressStr);
}


bool IsMatrixEqual(int **mat1, int mat2[][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (mat1[i][j] != mat2[i][j])
			{
				return false;
			}
		}
	}

	return true;
}

TEST(MATRIX_ROTATION_TEST, TEST1)
{
	int InitMat[4][4] = 
	{
		{1,2,3,4},
	{5,6,7,8},
	{9,10,11,12},
	{13,14,15,16}
	};

	int **mat1 = new int*[4];

	for (int i = 0; i < 4; i++)
		mat1[i] = new int[4];

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			mat1[i][j] = InitMat[i][j];
		}
	}

	int mat2[4][4] = {
		{13,9,5,1},
	{14,10,6,2},
	{15,11,7,3},
	{16,12,8,4}
	};

	bool result = RotateMatrixby90Degree(mat1, 4);

	EXPECT_EQ(true, result);

	EXPECT_EQ(true, IsMatrixEqual(mat1, mat2));
}

TEST(MATRIX_ROTATION_TEST, TEST2)
{
	bool result = RotateMatrixby90Degree(nullptr, 4);

	EXPECT_EQ(false, result);

}

TEST(MATRIX_ROTATION_TEST, TEST3)
{
	int InitMat[4][4] =
	{
		{1,2,3,4},
	{5,6,7,8},
	{9,10,11,12},
	{13,14,15,16}
	};

	int **mat1 = new int*[4];

	for (int i = 0; i < 4; i++)
		mat1[i] = new int[4];

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			mat1[i][j] = InitMat[i][j];
		}
	}

	bool result = RotateMatrixby90Degree(mat1, -1);

	EXPECT_EQ(false, result);

}

TEST(MATRIX_ROTATION_TEST, TEST4)
{
	int InitMat[4][4] =
	{
		{1,2,3,4},
	{5,6,7,8},
	{9,10,11,12},
	{13,14,15,16}
	};

	int **mat1 = new int*[4];

	for (int i = 0; i < 4; i++)
		mat1[i] = new int[4];

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			mat1[i][j] = InitMat[i][j];
		}
	}


	bool result = RotateMatrixby90Degree(mat1, 4);
	result = RotateMatrixby90Degree(mat1, 4);
	result = RotateMatrixby90Degree(mat1, 4);
	result = RotateMatrixby90Degree(mat1, 4);


	EXPECT_EQ(true, IsMatrixEqual(mat1, InitMat));

}
TEST(ZERO_MATRIX_TEST, TEST1)
{
	int InitMat[4][4] =
	{
	{1,2,3,4},
	{5,0,7,8},
	{9,10,0,12},
	{13,14,15,16}
	};

	int **mat1 = new int*[4];

	for (int i = 0; i < 4; i++)
		mat1[i] = new int[4];

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			mat1[i][j] = InitMat[i][j];
		}
	}

	int ResultMatrix[4][4] =
	{
	{1,0,0,4},
	{0,0,0,0},
	{0,0,0,0},
	{13,0,0,16}
	};

	ZeroMatrix(mat1, 4, 4);


	EXPECT_EQ(true, IsMatrixEqual(mat1, ResultMatrix));

}

TEST(ZERO_MATRIX_TEST, TEST2)
{
	int InitMat[4][4] =
	{
	{1,2,3,4},
	{5,0,7,8},
	{9,10,0,12},
	{13,14,15,16}
	};

	int **mat1 = new int*[4];

	for (int i = 0; i < 4; i++)
		mat1[i] = new int[4];

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			mat1[i][j] = InitMat[i][j];
		}
	}

	int ResultMatrix[4][4] =
	{
	{1,0,0,4},
	{0,0,0,0},
	{0,0,0,0},
	{13,0,0,16}
	};

	ZeroMatrixV3(mat1, 4, 4);
	

	EXPECT_EQ(true, IsMatrixEqual(mat1, ResultMatrix));

}
