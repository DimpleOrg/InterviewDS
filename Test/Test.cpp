// Test.cpp : Defines the entry point for the console application.
//

#include"Test.h"

#define ARRAY_SIZE 10

void bubbleSort(int arr[]);
void insertionSort(int arr[]);
void print(int arr[]);

int main()
{
	int arr[ARRAY_SIZE] = { 15,3,12,10,1,9,6,11,5,4 };
	//insertionSort(arr);
	bubbleSort(arr);
	print(arr);
    return 0;
}

void print(int arr[])
{
	for (int i = 0; i < 9;i++)
	{
		cout << arr[i];
		cout << endl;
	}
}