#include<cstdlib>

int rPartition(int arr[], int low, int high);
int randomPartition(int arr[], int low, int high);

void swap(int*, int*);
void rpSwap(int&, int&);

int partition(int qarr[], int low, int high);

__declspec(dllexport) void quickSort(int qarr[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(qarr, low, high);

		quickSort(qarr, low, pi - 1);
		quickSort(qarr, pi + 1, high);
	}
}

int partition(int qarr[], int low, int high)
{
	int pi = qarr[high];
	int i = low - 1;
	for (int j = low; j <= high - 1; j++)
	{
		if (qarr[j] <= pi)
		{
			i++;
			swap(&qarr[i], &qarr[j]);
		}
	}
	swap(&qarr[i + 1], &qarr[high]);
	return i + 1;
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

//--------------------------------Randomized Quick Sort-------------------------------------------

__declspec(dllexport) void randomizedQuickSort(int qarr[], int low, int high)
{
	try 
	{
		if (low < high)
		{
			int pi = randomPartition(qarr, low, high);
			randomizedQuickSort(qarr, low, pi-1);
			randomizedQuickSort(qarr, pi + 1, high);
		}
	}
		catch(...)
		{
			throw "Some exception thrown";
		}
}

int randomPartition(int arr[], int low, int high)
{
	int rn = rand();
	rn = low + (rn % (high - low + 1));
	rpSwap(arr[high], arr[rn]);
	int pi = rPartition(arr, low, high);
	return pi;
}

int rPartition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = low - 1;
	for (int j = low; j < high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			++i;
			rpSwap(arr[i], arr[j]);
		}
	}
	rpSwap(arr[high], arr[i + 1]);
	return arr[i + 1];
}

void rpSwap(int &a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}