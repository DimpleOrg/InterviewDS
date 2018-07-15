// BubbleSort.cpp : Defines the entry point for the console application.

//#include<header>

 void swap(int *arr1, int *arr2);


// __declspec(dllexport) void bubbleSort(int arr[])
 void bubbleSort(int arr[])
{
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
}

void swap(int *arr1, int *arr2)
{
	int temp = 0;
	temp = *arr1;
	*arr1 = *arr2;
	*arr2 = temp;
}

