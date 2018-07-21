// Test.cpp : Defines the entry point for the console application.
//

#include"Test.h"

#define ARRAY_SIZE 10
#define qSortArrSize 7

void bubbleSort(int arr[]);
void insertionSort(int arr[]);
void mergeSort(int arr[], int l, int r);
void quickSort(int arr[], int low, int high);
void print(int arr[]);
void qprint(int arr[]);

using namespace SORT;

void TestSortingAlgos() {

	try
	{
		BubbleSort testBObj;
		int arrB[ARRAY_SIZE] = { 15,3,12,10,1,9,6,11,5,4 };

		testBObj.LoadData(arrB, ARRAY_SIZE);
		testBObj.Print();
		testBObj.Sort();

		cout << "Bubble Sort Output:";
		testBObj.Print();

		SelectionSort testSObj;
		int arrS[ARRAY_SIZE] = { 15,3,12,10,1,9,6,11,5,4 };

		testSObj.LoadData(arrS, ARRAY_SIZE);
		testSObj.Print();
		testSObj.Sort();

		cout << "Selection Sort Output:";
		testSObj.Print();


		InsertionSort testIObj;
		int arrI[ARRAY_SIZE] = { 15,3,12,10,1,9,6,11,5,4 };

		testIObj.LoadData(arrI, ARRAY_SIZE);
		testIObj.Print();
		testIObj.Sort();

		cout << "Insertion Sort Output:";
		testIObj.Print();


		MergeSort testMObj;

		int arrM[ARRAY_SIZE] = { 15,3,12,10,1,9,6,11,5,4 };

		testMObj.LoadData(arrM, ARRAY_SIZE);
		testMObj.Print();
		testMObj.Sort();

		cout << "Insertion Sort Output:";
		testMObj.Print();


		QuickSort testQObj;

		int arrQ[] = { 15,3,12,10,1,9,6,11,5,4, 12, 8,1, -23, 87,45, 12, 423 };

		testQObj.LoadData(arrQ, sizeof(arrQ)/sizeof(int));
		testQObj.Print();
		testQObj.Sort();

		cout << "Quick Sort Output:";
		testQObj.Print();



		HeapSort testHObj;

		int arrH[] = { 15,3,12,10,1,9,6,11,5,4, 12, 8,1, -23, 87,45, 12, 423 };

		testHObj.LoadData(arrH, sizeof(arrH) / sizeof(int));
		testHObj.Print();
		testHObj.Sort();

		cout << "Heap Sort Output:";
		testHObj.Print();
	}
	catch (const std::exception& E)
	{
		cerr << "Caught exception \"" << E.what() << "\"\n";
	}
	catch (...)
	{
		cerr << "Caught unknown exception";
	}

}


int main()
{
	
	TestSortingAlgos();
	int qarr[qSortArrSize] = { 10, 80, 30, 90, 40, 50, 70 };
	int arr[ARRAY_SIZE] = { 15,3,12,10,1,9,6,11,5,4 };
	//insertionSort(arr);
	//bubbleSort(arr);
	//mergeSort(arr, 0, 9);
	quickSort(qarr, 0, 6);
	qprint(qarr);

    return 0;
}

void print(int arr[])
{
	for (int i = 0; i < 10;i++)
	{
		cout << arr[i];
		cout << endl;
	}
}

void qprint(int qarr[])
{
	for (int i = 0; i <= 6; i++)
	{
		cout << qarr[i];
		cout << endl;
	}
}