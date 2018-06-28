// BubbleSort.cpp : Defines the entry point for the console application.

#include<iostream>
#include<conio.h>

using namespace std;

void swap(int *arr1, int *arr2);
void print(int arr[]);

void main()
{
	int arr[10] = { 15,3,12,10,1,9,6,11,5,4 };
	bool swapped;
	for (int i = 0; i < 9; i++)
	{
		swapped = false;
		for (int j = 0; j < 9 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
				swapped = true;
			}
		}
		if (swapped == false) 
			break;
	}
	print(arr);
}

void swap(int *arr1, int *arr2)
{
	int temp = 0;
	temp = *arr1;
	*arr1 = *arr2;
	*arr2 = temp;
}

void print(int arr[])
{
	for (int i = 0; i < 9;i++)
	{
		cout << arr[i];
		cout << endl;
	}
}