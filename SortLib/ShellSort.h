#pragma once
#ifndef SHELLSORT_H
#define SHELLSORT_H

#include <vector>
#include "Exception.h"
#include "Array.h"
#include "ISort.h"
using namespace std;

template <typename T>
class Array;

template<class T>
class ShellSort : public ISort<T>
{
public:
	ShellSort(vector<T> *inValues, int inNum);
	~ShellSort();
public:
	void setArrSize(int inNum) { arrSize = inNum; }

private:
	int arrSize;
	int SortVArray(vector<T> * inVArray);
	int SortCArray(T * inCArray);
	int SortMArray(Array<T> * inMArray);
};

template<typename T>
inline ShellSort<T>::ShellSort(vector<T> * inValues, int inSize)
{
	if (inSize > 0) {
		ISort<T>::init(inValues, inSize, "SHELLSORT");
		setArrSize(inSize);
	}
	else {
		runtime_error("Exception caught: Size must be greater than 0.");
	}
}

template<typename T>
inline ShellSort<T>::~ShellSort()
{}

template<typename T>
inline int ShellSort<T>::SortVArray(vector<T> * inVArray)
{
	int startTime = GetTickCount();
	int gap;

	for (gap = arrSize / 2; gap > 0; gap /= 2)	{
		for (int i = gap; i < arrSize; i++) {
			T temp = (*inVArray)[i];
			int j;

			for (j = i; j >= gap && temp < (*inVArray)[j - gap]; j -= gap) {
				(*inVArray)[j] = (*inVArray)[j - gap];
			}
			(*inVArray)[j] = temp;
		}
	}
	return (GetTickCount() - startTime);
}

template<typename T>
inline int ShellSort<T>::SortCArray(T * inCArray)
{
	int startTime = GetTickCount();
	int gap;

	for (gap = arrSize / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < arrSize; i++) {
			T temp = inCArray[i];
			int j;

			for (j = i; j >= gap && temp < inCArray[j - gap]; j -= gap) {
				inCArray[j] = inCArray[j - gap];
			}
			inCArray[j] = temp;
		}
	}
	return (GetTickCount() - startTime);
}

template<typename T>
inline int ShellSort<T>::SortMArray(Array<T> * inMArray)
{
	int startTime = GetTickCount();
	int gap;

	for (gap = arrSize / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < arrSize; i++) {
			T temp = (*inMArray)[i];
			int j;

			for (j = i; j >= gap && temp < (*inMArray)[j - gap]; j -= gap) {
				(*inMArray)[j] = (*inMArray)[j - gap];
			}
			(*inMArray)[j] = temp;
		}
	}
	return (GetTickCount() - startTime);
}

#endif
