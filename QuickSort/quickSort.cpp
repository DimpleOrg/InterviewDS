
void swap(int*, int*);

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