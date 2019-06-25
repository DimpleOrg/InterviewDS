void swap(int*, int*);

__declspec(dllexport) void selectionSort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int minI = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[minI])
				minI = j;
		}
		swap(&arr[minI], &arr[i]);
	}
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}