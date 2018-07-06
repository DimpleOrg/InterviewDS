// Test.cpp : Defines the entry point for the console application.
//

#include"Test.h"

#define ARRAY_SIZE 10

void bubbleSort(int arr[]);
void insertionSort(int arr[]);
void print(int arr[]);
using namespace SORT;

void TestSortingAlgos() {
	BubbleSort testBObj;
	int arrB[ARRAY_SIZE] = { 15,3,12,10,1,9,6,11,5,4 };

	testBObj.LoadData(arrB, ARRAY_SIZE);
	testBObj.Print();
	testBObj.Sort();

	cout << "Bubble Sort Output:";
	testBObj.Print();


	InsertionSort testIObj;
	int arrI[ARRAY_SIZE] = { 15,3,12,10,1,9,6,11,5,4 };

	testIObj.LoadData(arrI, ARRAY_SIZE);
	testIObj.Print();
	testIObj.Sort();

	cout << "Insertion Sort Output:";
	testIObj.Print();
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