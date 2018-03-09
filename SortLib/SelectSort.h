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
	SelectSort(vector<T> *inValues, int inNum);;
	~SelectSort();

private:
	int SortVArray(vector<T> *inVArray);
	int SortCArray(T** inCArray);
	int SortMArray(Array<T> *inMArray);
};

template<typename T>
inline SelectSort<T>::SelectSort(vector<T> *inValues, int inSize)
{
	if (inSize > 0) {
		ISort<T>::init(inValues, inSize, "SELECTSORT");
	}
	else {
		runtime_error("Exception caught: Size must be greater than 0.");
	}
}

template<typename T>
inline SelectSort<T>::~SelectSort()
{}

template<typename T>
inline int SelectSort<T>::SortVArray(vector<T> *inVArray)
{
	int startTime = GetTickCount();
	int i, j, min_idx;
	int vSize = inVArray->size();

	for (i = 0; i < (vSize - 1); i++) {
		min_idx = i;
		for (j = i + 1; j < vSize; j++) {
			if ((*inVArray)[j] < (*inVArray)[min_idx]) {
				min_idx = j;
			}
		}
		swap((*inVArray)[min_idx], (*inVArray)[i]);
	}
	return (GetTickCount() - startTime);
}

template<typename T>
inline int SelectSort<T>::SortCArray(T** inCArray)
{
	int startTime = GetTickCount();
	int i, j, min_idx;
	int cSize = sizeof(inCArray);

	for (i = 0; i < (cSize - 1); i++) {
		min_idx = i;
		for (j = i + 1; j < cSize; j++) {
			if ((*inCArray)[j] < (*inCArray)[min_idx]) {
				min_idx = j;
			}
		}
		swap((*inCArray)[min_idx], (*inCArray)[i]);
	}
	return (GetTickCount() - startTime);
}

template<typename T>
inline int SelectSort<T>::SortMArray(Array<T> *inMArray)
{
	int startTime = GetTickCount();
	int i, j, min_idx;
	int mSize = inMArray->getLength();

	for (i = 0; i < (mSize - 1); i++) {
		min_idx = i;
		for (j = i + 1; j < mSize; j++) {
			if ((*inMArray)[j] < (*inMArray)[min_idx]) {
				min_idx = j;
			}
		}
		swap((*inMArray)[min_idx], (*inMArray)[i]);
	}
	return (GetTickCount() - startTime);
}

#endif