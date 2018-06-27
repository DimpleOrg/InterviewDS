// BubbleSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

//Adding project for bubble sorting
//Add code for bubble sort here

void swap(int *arr1, int *arr2);

int main()
{

	std::cout << "Bubble Sorting";
	//int n = 0;
	//cout << "Enter the number of elements in array";
	//cin >> n;
	int arr[10] = { 3, 6,2,8,5,10,1,12,9,11 };
	bool swapped = false;
	for (int i = 0; i < 10; i++)
	{
		swapped = false;

		for (int j = 0; j < 10 - i; j++)
		{
			if (i > j)
			{
				swap(arr[j], arr[j + 1]);
				swapped = true;
			}
		}
		if (swapped == true) break;
	}
	return 0;
}


void swap(int *arr1, int *arr2)
{
	int temp = 0;
	temp = *arr1;
	*arr1 = *arr2;
	*arr2 = temp;
}

