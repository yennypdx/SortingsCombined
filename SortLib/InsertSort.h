#pragma once
#ifndef INSERTSORT_H
#define INSERTSORT_H

#include <vector>
#include "Exception.h"
#include "Array.h"
#include "ISort.h"
using namespace std;

template <typename T>
class Array;

template<class T>
class InsertSort : public ISort<T>
{
public:
	InsertSort(vector<T> *inValues, int inNum);
	~InsertSort();

private:
	int SortVArray(vector<T> *inVArray);
	int SortCArray(T **inCArray);
	int SortMArray(Array<T> *inMArray);
};

template<typename T>
inline InsertSort<T>::InsertSort(vector<T> *inValues, int inSize)
{
	if (inSize > 0) {
		ISort<T>::init(inValues, inSize, "INSERTSORT");
	}
	else {
		runtime_error("Exception caught: Size must be greater than 0.");
	}
}

template<typename T>
inline InsertSort<T>::~InsertSort()
{}

template<typename T>
inline int InsertSort<T>::SortVArray(vector<T> *inVArray)
{
	int startTime = GetTickCount();
	int vSize = inVArray->size();
	int i, j;
	T key;

	for (i = 1; i < vSize; i++)
	{
		key = (*inVArray)[i];
		j = i - 1;

		while (j >= 0 && (*inVArray)[j] > key)
		{
			(*inVArray)[j + 1] = (*inVArray)[j];
			j = j - 1;
		}
		(*inVArray)[j + 1] = key;
	}
	return (GetTickCount() - startTime);
}

template<typename T>
inline int InsertSort<T>::SortCArray(T** inCArray)
{
	int startTime = GetTickCount();
	int cSize = sizeof(inCArray);
	int i, j;
	T key;

	for (i = 1; i < cSize; i++)	{
		key = (*inCArray)[i];
		j = i - 1;

		while (j >= 0 && (*inCArray)[j] > key) {
			(*inCArray)[j + 1] = (*inCArray)[j];
			j = j - 1;
		}
		(*inCArray)[j + 1] = key;
	}
	return (GetTickCount() - startTime);
}

template<typename T>
inline int InsertSort<T>::SortMArray(Array<T> *inMArray)
{
	int startTime = GetTickCount();
	int mSize = inMArray->getLength();
	T key;
	int i, j;

	for (i = 1; i < mSize; i++) {
		key = (*inMArray)[i];
		j = i - 1;

		while (j >= 0 && (*inMArray)[j] > key)	 {
			(*inMArray)[j + 1] = (*inMArray)[j];
			j = j - 1;
		}
		(*inMArray)[j + 1] = key;
	}
	return (GetTickCount() - startTime);
}
#endif
