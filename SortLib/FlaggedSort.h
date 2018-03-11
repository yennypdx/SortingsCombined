#pragma once
#ifndef FLAGGEDSORT_H
#define FLAGGEDSORT_H

#include <vector>
#include "Exception.h"
#include "Array.h"
#include "ISort.h"
using namespace std;

template <typename T>
class Array;

template<class T>
class FlaggedSort : public ISort<T>
{
public:
	FlaggedSort(vector<T> *inValues, int inNum);
	~FlaggedSort();

private:
	int SortVArray(vector<T> *inVArray);
	int SortCArray(T* inCArray);
	int SortMArray(Array<T> *inMArray);
};

template<typename T>
inline FlaggedSort<T>::FlaggedSort(vector<T> *inValues, int inSize)
{
	if (inSize > 0) {
		ISort<T>::init(inValues, inSize, "FLAGGEDSORT");
	}
	else {
		runtime_error("Exception caught: Size must be greater than 0.");
	}
}

template<typename T>
inline FlaggedSort<T>::~FlaggedSort()
{}

template<typename T>
inline int FlaggedSort<T>::SortVArray(vector<T> *inVArray)
{
	int startTime = GetTickCount();
	int vSize = inVArray->size();

	for (int i = 1; i < vSize; i++) {
		bool isSorted = true;
		for (int j = 0; j < (vSize - 1); j++) {
			if ((*inVArray)[j] >(*inVArray)[j + 1]) {
				T temp = (*inVArray)[j];
				(*inVArray)[j] = (*inVArray)[j + 1];
				(*inVArray)[j + 1] = temp;
				isSorted = false;
			}
		}
		if (isSorted) {
			continue;
		}
	}
	return (GetTickCount() - startTime);
}

template<typename T>
inline int FlaggedSort<T>::SortCArray(T* inCArray)
{
	int startTime = GetTickCount();
	int cSize = sizeof(inCArray);

	for (int i = 1; i < cSize; i++) {
		bool isSorted = true;
		for (int j = 0; j < ((cSize - 1) - i); j++) {
			if (inCArray[j] > inCArray[j + 1]) {
				T temp = inCArray[j];
				inCArray[j] = inCArray[j + 1];
				inCArray[j + 1] = temp;
				isSorted = false;
			}
		}

		if (isSorted) {
			continue;
		}
	}
	return (GetTickCount() - startTime);
}

template<typename T>
inline int FlaggedSort<T>::SortMArray(Array<T> *inMArray)
{
	int startTime = GetTickCount();
	int mSize = inMArray->getLength();

	for (int i = 1; i < (mSize - 1); i++) {
		bool isSorted = true;
		for (int j = 0; j < ((mSize - 1) - i); j++) {
			if ((*inMArray)[j] >(*inMArray)[j + 1]) {
				T temp = (*inMArray)[j];
				(*inMArray)[j] = (*inMArray)[j + 1];
				(*inMArray)[j + 1] = temp;
				isSorted = false;
			}
		}

		if (isSorted) {
			continue;
		}
	}
	return (GetTickCount() - startTime);
}

#endif