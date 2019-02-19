// printMatrixInSpiralFormat.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

void printInSpiral(int mat[][5], int start, int col, int row)
{
	for (int i = start; i < col; i++)
	{
		cout << mat[start][i]<<"\t";
	}
	for (int i = start+1; i < row; i++)
	{
		cout << mat[i][col-1]<<"\t";
	}
	for (int i = col-2; i >= start; i--)
	{
		cout << mat[row-1][i] << "\t";
	}
	for (int i = row-2; i >start; i--)
	{
		cout << mat[i][start] << "\t";
	}
}

int main()
{
	int mat[5][5] = { 1, 2, 3, 4,5,
					  6, 7, 8, 9, 10,
					  11, 12,13,14,15,
					  16,17,18,19,20,
					  21,22,23,24,25 };
	
	int row = 5, col = 5, origCol=5;
	int count = 0, start = 0;
	while (count < origCol - 2)
	{
		printInSpiral(mat, start, col, row);
		cout << endl;
		start = start + 1;
		row -= 1;
		col -= 1;
		count++;
	}
}

