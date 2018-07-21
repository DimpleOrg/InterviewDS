#include "SortingAlgos.h"
namespace SORT
{
	SortingAlgos::SortingAlgos(int size)
	{
		AllocateArray(size);
	}


	void SortingAlgos::AllocateArray(int size)
	{
		if (size < 1)
		{
			throw std::length_error("Invalid Lenght of Array");
		}
		else
		{
			Clear(); // clear the previos data before loading new data

			nElem = size;
			pElemArray = new int[nElem];
		}
	}

	void SortingAlgos::SwapElement(int id1, int id2)
	{
		int temp = pElemArray[id1];
		pElemArray[id1] = pElemArray[id2];
		pElemArray[id2] = temp;

	}


	SortingAlgos::~SortingAlgos()
	{
		Clear();
	}

	SortingAlgos::SortingAlgos(const SortingAlgos & other)
	{

	}

	/*SortingAlgos &  SortingAlgos::operator=(const SortingAlgos & other)
	{

	}

	SortingAlgos & SortingAlgos::operator=(SortingAlgos && other)
	{
	// TODO: insert return statement here
	return other;
	}
	*/
	SortingAlgos::SortingAlgos(SortingAlgos && other)
	{
	}



	void SortingAlgos::LoadData(const int intArr[], int len)
	{
		if (len < 1)
		{
			throw std::length_error("Invalid Array Length");
		}
		else {
			AllocateArray(len);

			for (int i = 0; i < len; i++)
			{
				pElemArray[i] = intArr[i];
			}
		}
	}

	void SortingAlgos::Clear()
	{
		if (pElemArray != nullptr)
		{
			delete[] pElemArray;
		}

		nElem = 0;
		pElemArray = nullptr;
	}

	void SortingAlgos::Print()
	{
		std::cout << std::endl;

		for (int i = 0; i < nElem; i++) {
			std::cout << pElemArray[i] << " ";
		}

		std::cout << std::endl;
	}


	void BubbleSort::Sort()
	{
		for (int i = 0; i < nElem - 1; i++)
		{
			for (int j = 0; j < nElem - i - 1; j++) {
				if (pElemArray[j] > pElemArray[j + 1])
				{
					int temp = pElemArray[j];
					pElemArray[j] = pElemArray[j + 1];
					pElemArray[j + 1] = temp;
				}
			}
		}
	}

	void InsertionSort::Sort()
	{
		for (int i = 1; i < nElem; i++)
		{
			int var = pElemArray[i];
			int j;
			for (j = i - 1; j >= 0; j--)
			{
				if (var < pElemArray[j])
				{
					pElemArray[j + 1] = pElemArray[j];
				}
				else
				{
					break;
				}
			}
			pElemArray[j + 1] = var;
		}
	}

	void MergeSort::MergeSortAlgo(int A[], int s, int e)
	{
		int len = e - s + 1;
		if (len == 1) {
			return;
		}
		else
		{
			int m = len / 2;

			MergeSortAlgo(A, s, s + m - 1);
			MergeSortAlgo(A, s + m, e);

			MergeSortedArray(A, s, s + m - 1, e);
		}

	}

	void MergeSort::MergeSortedArray(int A[], int s, int m, int e)
	{
		int len = e - s + 1;
		int *B = new int[len];

		int i, j;
		i = s;
		j = m + 1;

		for (int k = 0; k < len; k++)
		{
			if ((i <= m && A[i] < A[j]) || j > e)
			{
				B[k] = A[i++];
			}
			else if (j <= e)
			{
				B[k] = A[j++];
			}
			else
			{
				std::cout << "Error";
			}
		}

		for (int k = 0; k < len; k++)
		{
			A[s] = B[k];
			s++;
		}


		delete[]B;
	}

	void MergeSort::Sort()
	{
		MergeSortAlgo(pElemArray, 0, nElem - 1);
	}


	void QuickSort::Sort()
	{
		Quick_Sort(0, nElem - 1);
	}


	void QuickSort::Quick_Sort(int start, int end)
	{
		if (end > start)
		{
			int counter = start;
			int pivot = pElemArray[end];

			for (int j = start; j < end; j++) {
				if (j == counter) {
					if (pElemArray[counter] <= pivot)
					{
						counter++;
					}
				}
				else if (j > counter)
				{
					if (pElemArray[j] < pivot) {
						SwapElement(j, counter);
						counter++;
					}
				}
			}

			SwapElement(counter, end);
			Quick_Sort(start, counter - 1);
			Quick_Sort(counter + 1, end);
		}
	}

	void SelectionSort::Sort()
	{
		for (int i = 0; i < nElem -1; i++)
		{
			int maxIndex = 0;

			int j = 0;
			for (; j < nElem - i; j++)
			{
				if (pElemArray[maxIndex] < pElemArray[j]) {
					maxIndex = j;
				}
			}

			SwapElement(j - 1, maxIndex);			
		}
	}


	void HeapSort::BuildMaxHeap()
	{
		int i = tracklen / 2 - 1;
		for (; i >= 0; i--) {
			MaxHeapify(i);
		}

	}

	void HeapSort::MaxHeapify(int index)
	{
		int l = leftChild(index);
		int r = rightChild(index);

		if (l >= tracklen) {
			return;
		}

		int max = index;

		if (l < tracklen && pElemArray[l] > pElemArray[index]) {
			max = l;
		}

		if (r < tracklen && pElemArray[r] > pElemArray[max]) {
			max = r;
		}

		if (max == index)
			return;

		SwapElement(index, max);

		MaxHeapify(max);

	}

	void HeapSort::Sort()
	{
		tracklen = nElem;
		BuildMaxHeap();

		for (int i = 0; i < nElem - 1; i++)
		{
			SwapElement(0, tracklen - 1);
			tracklen--;
			

			MaxHeapify(0);
		}
	}

	int HeapSort::parent(int index)
	{
		return (index - 1) / 2;
	}

	int HeapSort::leftChild(int index)
	{

		return (2*index) + 1;
	}

	int HeapSort::rightChild(int index)
	{
		return (2 * index) + 2;
	}

}

