#pragma once
#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <vector>
#include <Windows.h>
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
public:
	void setArrSize(int inNum) { arrSize = inNum; }

private:
	int arrSize;
	int SortCArray(T* inCArray);
	int SortVArray(vector<T> *inVArray);
	int SortMArray(Array<T> *inMArray);
};

template<typename T>
inline BubbleSort<T>::BubbleSort(vector<T> * inValues, int inSize)
{
	if (inSize > 0) {
		ISort<T>::init(inValues, inSize, "BUBBLESORT");
		setArrSize(inSize);
	}
	else {
		runtime_error("Exception caught: Size must be greater than 0.");
	}
}

template<typename T>
inline BubbleSort<T>::~BubbleSort()
{}

template<typename T>
inline int BubbleSort<T>::SortCArray(T * inCArray)
{
	int startTime = GetTickCount();

	for (int i = 1; i < arrSize; i++) {
		for (int j = 0; j < arrSize - i; j++) {
			if (inCArray[j] > inCArray[j + 1]) {
				//swap
				T temp = inCArray[j];
				inCArray[j] = inCArray[j + 1];
				inCArray[j + 1] = temp;

			}
		}
	}
	return (GetTickCount() - startTime);
}

template<typename T>
inline int BubbleSort<T>::SortVArray(vector<T> * inVArray)
{
	int startTime = GetTickCount();

	for (int i = 1; i < arrSize; i++) {
		for (int j = 0; j < arrSize - i; j++) {
			if ((*inVArray)[j] > (*inVArray)[j + 1]) {
				//swap
				T temp = (*inVArray)[j];
				(*inVArray)[j] = (*inVArray)[j + 1];
				(*inVArray)[j + 1] = temp;

			}
		}
	}
	return (GetTickCount() - startTime);
}



template<typename T>
inline int BubbleSort<T>::SortMArray(Array<T>* inMArray)
{
	int startTime = GetTickCount();
	int mSize = inMArray->getLength();

	for (int i = 1; i < arrSize; i++) {
		for (int j = 0; j < arrSize - i; j++) {
			if ((*inMArray)[j] >(*inMArray)[j + 1]) {
				//swap
				T temp = (*inMArray)[j];
				(*inMArray)[j] = (*inMArray)[j + 1];
				(*inMArray)[j + 1] = temp;

			}
		}
	}
	return (GetTickCount() - startTime);
}

#endif