// Test.cpp : Defines the entry point for the console application.
//

#include"Test.h"

#define ARRAY_SIZE 10

void bubbleSort(int arr[]);
void insertionSort(int arr[]);
void print(int arr[]);
using namespace SORT;

void TestSortingAlgos() {
	BubbleSort testObj;
	int arr[ARRAY_SIZE] = { 15,3,12,10,1,9,6,11,5,4 };

	testObj.LoadData(arr, ARRAY_SIZE);
	testObj.Print();
	testObj.Sort();
	testObj.Print();
}


int main()
{
	TestSortingAlgos();
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