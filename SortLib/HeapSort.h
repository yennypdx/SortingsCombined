#pragma once
#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <vector>
#include "Exception.h"
#include "Array.h"
#include "ISort.h"
using namespace std;

template <typename T>
class Array;

template<class T>
class HeapSort : public ISort<T>
{
public:
	HeapSort(vector<T> *inValues, int inNum);
	~HeapSort();
public:
	void setArrSize(int inNum) { arrSize = inNum; }

private:
	int arrSize;
private:
	int SortCArray(T* inCArray);
	void heapify(T* inCArray, int num1, int num2);
private:
	int SortVArray(vector<T> *inVArray);
	void heapify(vector<T> *inVArray, int num1, int num2);
private:
	int SortMArray(Array<T> *inMArray);
	void heapify(Array<T> *inMArray, int num1, int num2);
};

template<typename T>
inline HeapSort<T>::HeapSort(vector<T> *inValues, int inSize)
{
	if (inSize > 0) {
		ISort<T>::init(inValues, inSize, "HEAPSORT");
		setArrSize(inSize);
	}
	else {
		runtime_error("Exception caught: Size must be greater than 0.");
	}
}

template<typename T>
inline HeapSort<T>::~HeapSort()
{}

template<typename T>
inline int HeapSort<T>::SortCArray(T* inCArray)
{
	int startTime = GetTickCount();

	for (int i = ((arrSize / 2) - 1); i >= 0; i--) {
		heapify(inCArray, arrSize, i);
	}

	for (int i = (arrSize - 1); i >= 0; i--) {
		swap(inCArray[0], inCArray[i]);
		heapify(inCArray, i, 0);
	}
	return (GetTickCount() - startTime);
}

template<typename T>
inline void HeapSort<T>::heapify(T* inCArray, int num1, int num2)
{
	int largest = num2;
	int left = (2 * num2) + 1;
	int right = (2 * num2) + 2;

	if ((left < num1) && (inCArray[left] > inCArray[largest])) {
		largest = left;
	}

	if ((right < num1) && (inCArray[right] > inCArray[largest])) {
		largest = right;
	}

	if (largest != num2) {
		swap(inCArray[num2], inCArray[largest]);
		heapify(inCArray, num1, largest);
	}
}

template<typename T>
inline int HeapSort<T>::SortVArray(vector<T> *inVArray)
{
	int startTime = GetTickCount();

	for (int i = ((arrSize / 2) - 1); i >= 0; i--) {
		heapify(inVArray, arrSize, i);
	}

	for (int i = (arrSize - 1); i >= 0; i--) {
		swap((*inVArray)[0], (*inVArray)[i]);
		heapify(inVArray, i, 0);
	}
	return (GetTickCount() - startTime);
}

template<typename T>
inline void HeapSort<T>::heapify(vector<T> *inVArray, int num1, int num2)
{
	int largest = num2;
	int left = (2 * num2) + 1;
	int right = (2 * num2) + 2;

	if ((left < num1) && ((*inVArray)[left] >(*inVArray)[largest])) {
		largest = left;
	}

	if ((right < num1) && ((*inVArray)[right] >(*inVArray)[largest])) {
		largest = right;
	}

	if (largest != num2) {
		swap((*inVArray)[num2], (*inVArray)[largest]);
		heapify(inVArray, num1, largest);
	}
}

template<typename T>
inline int HeapSort<T>::SortMArray(Array<T> *inMArray)
{
	int startTime = GetTickCount();

	for (int i = ((arrSize / 2) - 1); i >= 0; i--) {
		heapify(inMArray, arrSize, i);
	}

	for (int i = (arrSize - 1); i >= 0; i--) {
		swap((*inMArray)[0], (*inMArray)[i]);
		heapify(inMArray, i, 0);
	}
	return (GetTickCount() - startTime);
}

template<typename T>
inline void HeapSort<T>::heapify(Array<T> *inMArray, int num1, int num2)
{
	int largest = num2;
	int left = (2 * num2) + 1;
	int right = (2 * num2) + 2;

	if ((left < num1) && ((*inMArray)[left] >(*inMArray)[largest])) {
		largest = left;
	}

	if ((right < num1) && ((*inMArray)[right] >(*inMArray)[largest])) {
		largest = right;
	}

	if (largest != num2) {
		swap((*inMArray)[num2], (*inMArray)[largest]);
		heapify(inMArray, num1, largest);
	}
}

#endif