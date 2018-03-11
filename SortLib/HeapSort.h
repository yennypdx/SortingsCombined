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

private:
	int SortVArray(vector<T> *inVArray);
	void heapify(vector<T> *inVArray, int num1, int num2);
private:
	int SortCArray(T* inCArray);
	void heapify(T* inCArray, int num1, int num2);
private:
	int SortMArray(Array<T> *inMArray);
	void heapify(Array<T> *inMArray, int num1, int num2);
};

template<typename T>
inline HeapSort<T>::HeapSort(vector<T> *inValues, int inSize)
{
	if (inSize > 0) {
		ISort<T>::init(inValues, inSize, "HEAPSORT");
	}
	else {
		runtime_error("Exception caught: Size must be greater than 0.");
	}
}

template<typename T>
inline HeapSort<T>::~HeapSort()
{}

template<typename T>
inline int HeapSort<T>::SortVArray(vector<T> *inVArray)
{
	int startTime = GetTickCount();
	int vSize = inVArray->size();

	for (int i = ((vSize / 2) - 1); i >= 0; i--) {
		heapify(inVArray, vSize, i);
	}

	for (int i = (vSize - 1); i >= 0; i--) {
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
inline int HeapSort<T>::SortCArray(T* inCArray)
{
	int startTime = GetTickCount();
	int cSize = sizeof(inCArray);

	for (int i = ((cSize / 2) - 1); i >= 0; i--) {
		heapify(inCArray, cSize, i);
	}

	for (int i = (cSize - 1); i >= 0; i--) {
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
inline int HeapSort<T>::SortMArray(Array<T> *inMArray)
{
	int startTime = GetTickCount();
	int mSize = inMArray->getLength();

	for (int i = ((mSize / 2) - 1); i >= 0; i--) {
		heapify(inMArray, mSize, i);
	}

	for (int i = (mSize - 1); i >= 0; i--) {
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