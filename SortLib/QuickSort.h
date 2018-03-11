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
	int SortCArray(T *inCArray);
	void quickSortReq(T *inCArray, int low, int high);
	int partition(T *inCArray, int low, int high);
private:
	int SortMArray(Array<T> *inMArray);
	void quickSortReq(Array<T> *inMArray, int left, int right);
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
inline void QuickSort<T>::quickSortReq(vector<T> *inVArray, int left, int right)
{
	if (left < right) {
		int pi = partition(inVArray, left, right);

		quickSortReq(inVArray, left, pi - 1);
		quickSortReq(inVArray, pi + 1, right);
	}
}

template<typename T>
inline int QuickSort<T>::partition(vector<T> *inVArray, int left, int right)
{
	T pivot = (*inVArray)[left];
	int l = left + 1;
	int r = right;

	while (l < r) {
		while (l < right && (*inVArray)[l] < pivot) {
			l++;
		}
		while (r > left && (*inVArray)[r] >= pivot) {
			r--;
		}
			
		if (l < r) {
			int temp = (*inVArray)[l];
			(*inVArray)[l] = (*inVArray)[r];
			(*inVArray)[r] = temp;
		}
	}
	(*inVArray)[left] = (*inVArray)[r];
	(*inVArray)[r] = pivot;
	return r;
}

template<typename T>
inline int QuickSort<T>::SortCArray(T * inCArray)
{
	int startTime = GetTickCount();
	int cSize = sizeof(inCArray);

	quickSortReq(inCArray, 0, cSize - 1);

	return (GetTickCount() - startTime);
}

template<typename T>
inline void QuickSort<T>::quickSortReq(T * inCArray, int left, int right)
{
	if (left < right) {
		int pi = partition(inCArray, left, right);

		quickSortReq(inCArray, left, pi - 1);
		quickSortReq(inCArray, pi + 1, right);
	}
}

template<typename T>
inline int QuickSort<T>::partition(T * inCArray, int left, int right)
{
	T pivot = inCArray[left];
	int l = left + 1;
	int r = right;

	while (l < r) {
		while (l < right && inCArray[l] < pivot) l++;
		while (r > left && inCArray[r] >= pivot) r--;
		if (l < r) {
			int temp = inCArray[l];
			inCArray[l] = inCArray[r];
			inCArray[r] = temp;
		}
	}
	inCArray[left] = inCArray[r];
	inCArray[r] = pivot;
	return r;
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
inline void QuickSort<T>::quickSortReq(Array<T> *inMArray, int left, int right)
{
	if (left < right) {
		int pi = partition(inMArray, left, right);

		quickSortReq(inMArray, left, pi - 1);
		quickSortReq(inMArray, pi + 1, right);
	}
}

template<typename T>
inline int QuickSort<T>::partition(Array<T> *inMArray, int left, int right)
{
	T pivot = (*inMArray)[left];
	int l = left + 1;
	int r = right;

	while (l < r) {
		while (l < right && (*inMArray)[l] < pivot) l++;
		while (r > left && (*inMArray)[r] >= pivot) r--;
		if (l < r) {
			int temp = (*inMArray)[l];
			(*inMArray)[l] = (*inMArray)[r];
			(*inMArray)[r] = temp;
		}
	}
	(*inMArray)[left] = (*inMArray)[r];
	(*inMArray)[r] = pivot;
	return r;
}

#endif
