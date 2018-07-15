

void merge(int arr[], int l, int m, int r);

__declspec(dllexport) void mergeSort(int arr[], int l, int r)
{
	int len = r - l + 1;
	if (len == 1)
	{
		return;
	}
	else
	{
		int m = (len) / 2;
		mergeSort(arr, l, l+m-1);
		mergeSort(arr, l+m, r);
		merge(arr, l, l+m-1, r);
	}
}

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	// Create temp arrays
	int *left = new int[n1]; 
	int *rt = new int[n2];

	// copy data to temp arrays
	for (i = 0; i < n1; i++)
	{
		left[i] = arr[l + i];
	}

	for (j = 0; j < n2; j++)
	{
		rt[j]=arr[m+1+j];
	}

	i = 0; j = 0; k = l;

	while (i < n1 && j < n2)
	{
		if (left[i] <= rt[j])
		{
			arr[k] = left[i];
			i++;
			k++;
		}
		else
		{
			arr[k] = rt[j];
			j++;
			k++;
		}
	}

	while (i < n1)
	{
		arr[k] = left[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arr[k] = rt[j];
		k++;
		j++;
	}

	delete[] left;
	delete[] rt;
}
