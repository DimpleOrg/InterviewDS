#include<math.h>

void swap(int*, int*);
void heapify(int arr[], int n, int root);

__declspec(dllexport) void heapSort(int arr[], int n)
{
	int heightOfTree = n/2;
	for (int i = heightOfTree; i >= 0; i--)
	{
		heapify(arr, n, i);
	}
	for (int j = n - 1; j > 0; j--)
	{
		swap(&arr[0], &arr[j]);
		heapify(arr, j, 0);
	}
}

void heapify(int arr[], int n, int root)
{
	int largest = root;
	int lc = (2 * root) + 1;
	int rc = (2 * root) + 2;
	if (lc<n && arr[lc]>arr[largest])
		largest = lc;

	if (rc<n && arr[rc]>arr[largest])
		largest = rc;

	if (largest != root)
	{
		swap(&arr[largest], &arr[root]);
		heapify(arr, n, largest);
	}

}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}



//*****************Heap Sort Revision***************

void BuildMaxHeap(int arr[], int len);
void Maxheapify(int arr[], int index, int len);
void sswap(int &a, int&b);

__declspec(dllexport) void heapSortRev(int arr[], int arrLen)
{
	int len = arrLen - 1;
	BuildMaxHeap(arr, len);
	
	while(len > 0)
	{
		sswap(arr[0], arr[len]);
		--len;
		Maxheapify(arr, 0, len);
	}
}

void BuildMaxHeap(int arr[], int len)
{
	for (int i = len / 2; i >= 0; i--)
	{
		Maxheapify(arr, i, len);
	}
}

void Maxheapify(int arr[], int index, int len)
{
	int lc = 2 * index + 1;
	int rc = 2 * index + 2;
	int max = index;
	
	if (lc <= len && arr[max] < arr[lc])
		max = lc;

	if (rc <= len && arr[max] < arr[rc])
		max = rc;

	if (arr[max] == arr[index])
		return;
	else
	{
		sswap(arr[max], arr[index]);
		Maxheapify(arr, max, len);
	}
}

void sswap(int& a, int& b)
{
	size_t temp = a;
	a = b;
	b = temp;
}