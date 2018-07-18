#pragma once

#ifndef __SORTING_ALGOS_H
#define __SORTING_ALGOS_H

#include <iostream>

namespace SORT
{

	#define DllExport   __declspec( dllexport )  


	class DllExport SortingAlgos
	{
	public:
		virtual void Sort () = 0;

		SortingAlgos(): nElem(0), pElemArray(nullptr){}
		SortingAlgos(int size);
		~SortingAlgos();

		
		SortingAlgos(const SortingAlgos& other);
	//	SortingAlgos& operator=(const SortingAlgos& other);

		SortingAlgos(SortingAlgos&& other);
	//	SortingAlgos& operator=(SortingAlgos&& other);

		void LoadData(const int intArr[], int len);
		void Clear();

		void Print();

		void AllocateArray(int size);
	protected:
		int nElem = 0;
		int *pElemArray = nullptr;
	};


	class DllExport BubbleSort : public SortingAlgos {
	public:
		void Sort();
	};

	class DllExport InsertionSort : public SortingAlgos {
	public:
		void Sort();
	};

	class DllExport MergeSort : public SortingAlgos {
	public:
		void Sort();
	private:
		void MergeSortAlgo(int A[], int s, int e);
		void MergeSortedArray(int A[], int s, int m, int e);
	};

	class DllExport QuickSort : public SortingAlgos {
	public:
		void Sort();
	private:
		void Quick_Sort(int start, int end);
		void SwapElement(int id1, int id2);
	};
}



#endif // __SORTING_ALGOS_H

