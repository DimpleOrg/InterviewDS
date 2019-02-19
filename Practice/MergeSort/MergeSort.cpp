#include<iostream>

template<typename T>
void merge(T arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	std::unique_ptr<T[]> left = std::make_unique<T[]>(n1);
	std::unique_ptr<T[]> right = std::make_unique<T[]>(n2);
	
	for (i = 0; i < n1; i++)
		left.get()[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		right.get()[j] = arr[m + 1 + j];
	
	i = 0, j = 0, k = l;
	while (i < n1 && j < n2)
	{
		if (left.get()[i] < right.get()[j])
		{
			arr[k] = left.get()[i];
			i++;
		}
		else
		{
			arr[k] = right.get()[j];
			j++;
		}
		k++;
	}
	
	while (i < n1)
	{
		arr[k] = left.get()[i];
		i++; k++;
	}

	while (j < n2)
	{
		arr[k] = right.get()[j];
		j++; k++;
	}
}

template<typename T>
void mergesort(T arr[], int l, int r)
{
	if (l < r)
	{
		int m = (l+r) / 2;
		mergesort<int>(arr, l, m);
		mergesort<int>(arr, m+1, r);
		merge<int>(arr, l, m , r);
	}
}

int main()
{
	int arr[] = { 12,12,11,13,5,6,7 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);
	mergesort<int>(arr, 0, (arr_size-1));
}
