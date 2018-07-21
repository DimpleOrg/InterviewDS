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