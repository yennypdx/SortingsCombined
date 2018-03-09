#pragma once
#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>
#include "Exception.h"
#include "Array.h"
#include "ISort.h"
using namespace std;

template <typename T>
class Array;

template<class T>
class MergeSort : public ISort<T>
{
public:
	MergeSort(vector<T> *inValues, int inNum);
	~MergeSort();

private:
	int SortVArray(vector<T> *inVArray);
	void mergeSortRec(vector<T> *inVArray, int left, int right);
	void merge(vector<T> *inVArray, int left, int mer, int right);
private:
	int SortCArray(T **inCArray);
	void mergeSortRec(T **inCArray, int left, int right);
	void merge(T **inCArray, int left, int mer, int right);
private:
	int SortMArray(Array<T> *inMArray);
	void mergeSortRec(Array<T> *inMArray, int left, int right);
	void merge(Array<T> *inMArray, int left, int mer, int right);
};

template<typename T>
inline MergeSort<T>::MergeSort(vector<T> *inValues, int inSize)
{
	if (inSize > 0) {
		ISort<T>::init(inValues, inSize, "MERGESORT");
	}
	else {
		runtime_error("Exception caught: Size must be greater than 0.");
	}
}

template<typename T>
inline MergeSort<T>::~MergeSort()
{}

template<typename T>
inline int MergeSort<T>::SortVArray(vector<T> *inVArray)
{
	int startTime = GetTickCount();
	int vSize = inVArray->size();

	mergeSortRec(inVArray, 0, (vSize - 1));

	return (GetTickCount() - startTime);
}

template<typename T>
inline void MergeSort<T>::mergeSortRec(vector<T> *inVArray, int left, int right)
{
	if (left < right) {
		int mer = left + (right - left) / 2;

		mergeSortRec(inVArray, left, mer);
		mergeSortRec(inVArray, mer + 1, right);

		merge(inVArray, left, mer, right);
	}
}

template<typename T>
inline void MergeSort<T>::merge(vector<T> *inVArray, int left, int mer, int right)
{
	int i, j, k;
	int n1 = mer - left + 1;
	int n2 = right - mer;

	int* Left = new int[n1];
	int* Right = new int[n2];

	for (i = 0; i < n1; i++) {
		Left[i] = (*inVArray)[left + i];
	}
	
	for (j = 0; j < n2; j++) {
		Right[j] = (*inVArray)[mer + 1 + j];
	}
	
	i = 0;
	j = 0;
	k = left;
	while (i < n1 && j < n2)
	{
		if (Left[i] <= Right[j]) {
			(*inVArray)[k] = Left[i];
			i++;
		}
		else {
			(*inVArray)[k] = Right[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		(*inVArray)[k] = Left[i];
		i++;
		k++;
	}

	while (j < n2) {
		(*inVArray)[k] = Right[j];
		j++;
		k++;
	}

	delete[] Left;
	delete[] Right;
}

template<typename T>
inline int MergeSort<T>::SortCArray(T** inCArray)
{
	int startTime = GetTickCount();
	int cSize = sizeof(inCArray);

	mergeSortRec(inCArray, 0, (cSize - 1));

	return (GetTickCount() - startTime);
}

template<typename T>
inline void MergeSort<T>::mergeSortRec(T **inCArray, int left, int right)
{
	if (left < right) {
		int mer = left + (right - left) / 2;

		mergeSortRec(inCArray, left, mer);
		mergeSortRec(inCArray, mer + 1, right);

		merge(inCArray, left, mer, right);
	}
}

template<typename T>
inline void MergeSort<T>::merge(T **inCArray, int left, int mer, int right)
{
	int i, j, k;
	int n1 = mer - left + 1;
	int n2 = right - mer;

	int* Left = new int[n1];
	int* Right = new int[n2];

	for (i = 0; i < n1; i++) {
		Left[i] = (*inCArray)[left + i];
	}
		
	for (j = 0; j < n2; j++) {
		Right[j] = (*inCArray)[mer + 1 + j];
	}
	
	i = 0;
	j = 0;
	k = left;
	while (i < n1 && j < n2)	{
		if (Left[i] <= Right[j]) {
			(*inCArray)[k] = Left[i];
			i++;
		}
		else {
			(*inCArray)[k] = Right[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		(*inCArray)[k] = Left[i];
		i++;
		k++;
	}

	while (j < n2) {
		(*inCArray)[k] = Right[j];
		j++;
		k++;
	}

	delete[] Left;
	delete[] Right;
}

template<typename T>
inline int MergeSort<T>::SortMArray(Array<T> *inMArray)
{
	int startTime = GetTickCount();
	int mSize = inMArray->getLength();

	mergeSortRec(inMArray, 0, (mSize - 1));

	return (GetTickCount() - startTime);
}

template<typename T>
inline void MergeSort<T>::mergeSortRec(Array<T> *inMArray, int left, int right)
{
	if (left < right) {
		int mer = left + (right - left) / 2;

		mergeSortRec(inMArray, left, mer);
		mergeSortRec(inMArray, mer + 1, right);

		merge(inMArray, left, mer, right);
	}
}

template<typename T>
inline void MergeSort<T>::merge(Array<T> *inMArray, int left, int mer, int right)
{
	int i, j, k;
	int n1 = mer - left + 1;
	int n2 = right - mer;

	int* Left = new int[n1];
	int* Right = new int[n2];

	for (i = 0; i < n1; i++) {
		Left[i] = (*inMArray)[left + i];
	}
		
	for (j = 0; j < n2; j++) {
		Right[j] = (*inMArray)[mer + 1 + j];
	}
		
	i = 0;
	j = 0;
	k = left;
	while (i < n1 && j < n2) {
		if (Left[i] <= Right[j]) {
			(*inMArray)[k] = Left[i];
			i++;
		}
		else {
			(*inMArray)[k] = Right[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		(*inMArray)[k] = Left[i];
		i++;
		k++;
	}

	while (j < n2) {
		(*inMArray)[k] = Right[j];
		j++;
		k++;
	}

	delete[] Left;
	delete[] Right;
}

#endif