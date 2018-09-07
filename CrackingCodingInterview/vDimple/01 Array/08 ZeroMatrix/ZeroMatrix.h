#pragma once
#include<iostream>
#include<vector>

__declspec(dllexport) void zeroMatrix(int row, int col, int **matrix);
void makeRowZero(int **,int, int, int);
void makeColZero(int **, int, int, int);