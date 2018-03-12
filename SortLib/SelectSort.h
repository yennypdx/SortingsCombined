#pragma once
#ifndef SELECTSORT_H
#define SELECTSORT_H

#include <vector>
#include "Exception.h"
#include "Array.h"
#include "ISort.h"
using namespace std;

template <typename T>
class Array;

template<class T>
class SelectSort : public ISort<T>
{
public:
	SelectSort(vector<T> * inValues, int inNum);;
	~SelectSort();
public:
	void setArrSize(int inNum) { arrSize = inNum; }

private:
	int arrSize;
	int SortCArray(T * inCArray);
	int SortVArray(vector<T> *inVArray);
	int SortMArray(Array<T> *inMArray);
};

template<typename T>
inline SelectSort<T>::SelectSort(vector<T> * inValues, int inSize)
{
	if (inSize > 0) {
		ISort<T>::init(inValues, inSize, "SELECTSORT");
		setArrSize(inSize);
	}
	else {
		runtime_error("Exception caught: Size must be greater than 0.");
	}
}

template<typename T>
inline SelectSort<T>::~SelectSort()
{}

template<typename T>
inline int SelectSort<T>::SortCArray(T * inCArray)
{
	int startTime = GetTickCount();
	int i, j, min_idx;

	for (i = arrSize - 1; i >= 1; i--) {
		min_idx = i;
		for (j = 0; j < i; j++) {
			if (inCArray[j] < inCArray[min_idx]) {
				min_idx = j;
			}
		}
		swap(inCArray[min_idx], inCArray[i]);
	}
	return (GetTickCount() - startTime);
}

template<typename T>
inline int SelectSort<T>::SortVArray(vector<T> * inVArray)
{
	int startTime = GetTickCount();
	int i, j, min_idx;

	for (i = arrSize - 1; i >= 1; i--) {
		min_idx = i;
		for (j = 0; j < i; j++) {
			if ((*inVArray)[j] > (*inVArray)[min_idx]) {
				min_idx = j;
			}
		}
		swap((*inVArray)[min_idx], (*inVArray)[i]);
	}
	return (GetTickCount() - startTime);
}

template<typename T>
inline int SelectSort<T>::SortMArray(Array<T> * inMArray)
{
	int startTime = GetTickCount();
	int i, j, min_idx;

	for (i = arrSize - 1; i >= 1; i--) {
		min_idx = i;
		for (j = 0; j < i; j++) {
			if ((*inMArray)[j] < (*inMArray)[min_idx]) {
				min_idx = j;
			}
		}
		swap((*inMArray)[min_idx], (*inMArray)[i]);
	}
	return (GetTickCount() - startTime);
}

#endif