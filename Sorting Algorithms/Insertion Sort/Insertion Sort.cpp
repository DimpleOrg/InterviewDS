// Insertion Sort.cpp : Defines the entry point for the console application.
//

#include"stdafx.h"
#include<iostream>

void insert(int i, int j, int arr[]);


__declspec(dllexport) void insertionSort(int arr[])
{
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 0; j < i;j++)
		{
			if (arr[i] > arr[j])
			{
				insert(i, j, arr);
			}
		}
	}
 // return 0;
}

void insert(int i, int j, int arr[])
{
	int storei = arr[i];
	int k = i;
	while (k - 1 >= j)
	{
		arr[k] = arr[k - 1];
		k--;
	}
	arr[j] = storei;
}
