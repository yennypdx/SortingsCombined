#pragma once
#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>
#include "Exception.h"
#include "Array.h"
#include "ISort.h"
using namespace std;

template <typename T>
class Array;

template<class T>
class QuickSort : public ISort<T>
{
public:
	QuickSort(vector<T> *inValues, int inNum);
	~QuickSort();

private:
	int SortVArray(vector<T> *inVArray);
	void quickSortReq(vector<T> *inVArray, int low, int high);
	int partition(vector<T> *inVArray, int low, int high);
private:
	int SortCArray(T **inCArray);
	void quickSortReq(T **inCArray, int low, int high);
	int partition(T **inCArray, int low, int high);
private:
	int SortMArray(Array<T> *inMArray);
	void quickSortReq(Array<T> *inMArray, int low, int high);
	int partition(Array<T> *inMArray, int low, int high);
};

template<typename T>
inline QuickSort<T>::QuickSort(vector<T> *inValues, int inSize)
{
	if (inSize > 0) {
		ISort<T>::init(inValues, inSize, "QUICKSORT");
	}
	else {
		runtime_error("Exception caught: Size must be greater than 0.");
	}
}

template<typename T>
inline QuickSort<T>::~QuickSort()
{}

template<typename T>
inline int QuickSort<T>::SortVArray(vector<T> *inVArray)
{
	int startTime = GetTickCount();
	int vSize = inVArray->size();

	quickSortReq(inVArray, 0, vSize - 1);

	return (GetTickCount() - startTime);
}

template<typename T>
inline void QuickSort<T>::quickSortReq(vector<T> *inVArray, int low, int high)
{
	if (low < high) {
		int pi = partition(inVArray, low, high);

		quickSortReq(inVArray, low, pi - 1);
		quickSortReq(inVArray, pi + 1, high);
	}
}

template<typename T>
inline int QuickSort<T>::partition(vector<T> *inVArray, int low, int high)
{
	T pivot = (*inVArray)[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) {
		if ((*inVArray)[j] <= pivot) {
			i++;
			swap((*inVArray)[i], (*inVArray)[j]);
		}
	}
	swap((*inVArray)[i + 1], (*inVArray)[high]);
	return (i + 1);
}

template<typename T>
inline int QuickSort<T>::SortCArray(T** inCArray)
{
	int startTime = GetTickCount();
	int cSize = sizeof(inCArray);

	quickSortReq(inCArray, 0, cSize - 1);

	return (GetTickCount() - startTime);
}

template<typename T>
inline void QuickSort<T>::quickSortReq(T **inCArray, int low, int high)
{
	if (low < high) {
		int pi = partition(inCArray, low, high);

		quickSortReq(inCArray, low, pi - 1);
		quickSortReq(inCArray, pi + 1, high);
	}
}

template<typename T>
inline int QuickSort<T>::partition(T **inCArray, int low, int high)
{
	T pivot = (*inCArray)[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) {
		if ((*inCArray)[j] <= pivot) {
			i++;
			swap((*inCArray)[i], (*inCArray)[j]);
		}
	}
	swap((*inCArray)[i + 1], (*inCArray)[high]);
	return (i + 1);
}

template<typename T>
inline int QuickSort<T>::SortMArray(Array<T> *inMArray)
{
	int startTime = GetTickCount();
	int mSize = inMArray->getLength();

	quickSortReq(inMArray, 0, mSize - 1);

	return (GetTickCount() - startTime);
}

template<typename T>
inline void QuickSort<T>::quickSortReq(Array<T> *inMArray, int low, int high)
{
	if (low < high) {
		int pi = partition(inMArray, low, high);

		quickSortReq(inMArray, low, pi - 1);
		quickSortReq(inMArray, pi + 1, high);
	}
}

template<typename T>
inline int QuickSort<T>::partition(Array<T> *inMArray, int low, int high)
{
	T pivot = (*inMArray)[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) {
		if ((*inMArray)[j] <= pivot)	{
			i++;
			swap((*inMArray)[i], (*inMArray)[j]);
		}
	}
	swap((*inMArray)[i + 1], (*inMArray)[high]);
	return (i + 1);
}

#endif
