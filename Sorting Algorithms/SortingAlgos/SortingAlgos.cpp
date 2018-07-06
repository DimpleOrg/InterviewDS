#include "SortingAlgos.h"
// SortingAlgos.cpp : Defines the entry point for the console application.
//


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
				if (pElemArray[j] > pElemArray[j+1])
				{
					int temp = pElemArray[j];
					pElemArray[j] = pElemArray[j+1];
					pElemArray[j+1] = temp;
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

	void MergeSort::Sort()
	{



	}

}