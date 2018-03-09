#pragma once
#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <vector>
#include "Exception.h"
#include "Array.h"
#include "ISort.h"
using namespace std;

template <typename T>
class Array;

template<class T>
class BubbleSort : public ISort<T>
{
public:
	BubbleSort(vector<T> *values, int inNum);
	~BubbleSort();

private:
	int SortVArray(vector<T> *inVArray);
	int SortCArray(T** inCArray);
	int SortMArray(Array<T> *inMArray);
};

template<typename T>
inline BubbleSort<T>::BubbleSort(vector<T> *inValues, int inSize)
{
	if (inSize > 0) {
		ISort<T>::init(inValues, inSize, "BUBBLESORT");
	}
	else {
		runtime_error("Exception caught: Size must be greater than 0.");
	}
}

template<typename T>
inline BubbleSort<T>::~BubbleSort()
{}

template<typename T>
inline int BubbleSort<T>::SortVArray(vector<T> *inVArray)
{
	int startTime = GetTickCount();
	int vSize = inVArray->size();

	for (int i = 0; i < vSize; i++) {
		for (int j = 0; j < (vSize - 1); j++) {
			if ((*inVArray)[j] >(*inVArray)[j + 1]) {
				T temp = (*inVArray)[j];
				(*inVArray)[j] = (*inVArray)[j + 1];
				(*inVArray)[j + 1] = temp;
			}
		}
	}
	return (GetTickCount() - startTime);
}

template<typename T>
inline int BubbleSort<T>::SortCArray(T** inCArray)
{
	int startTime = GetTickCount();
	int cSize = sizeof(inCArray);

	for (int i = 1; i < cSize; i++) {
		for (int j = 0; j < (cSize - 1); j++) {
			if ((*inCArray)[j] >(*inCArray)[j + 1]) {
				T temp = (*inCArray)[j];

				(*inCArray)[j] = (*inCArray)[j + 1];
				(*inCArray)[j + 1] = temp;
			}
		}
	}
	return (GetTickCount() - startTime);
}

template<typename T>
inline int BubbleSort<T>::SortMArray(Array<T> *inMArray)
{
	int startTime = GetTickCount();
	int mSize = inMArray->getLength();

	for (int i = 1; i < mSize; i++) {
		for (int j = 0; j < (mSize - 1); j++) {
			if ((*inMArray)[j] >(*inMArray)[j + 1]) {
				T temp = (*inMArray)[j];

				(*inMArray)[j] = (*inMArray)[j + 1];
				(*inMArray)[j + 1] = temp;
			}
		}
	}
	return (GetTickCount() - startTime);
}

#endif