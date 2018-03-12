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
public:
	void setArrSize(int inNum) { arrSize = inNum; }

private:
	int arrSize;
private:
	int SortVArray(vector<T> *inVArray);
	void mergeSortReq(vector<T> *inVArray, int left, int right);
	void merge(vector<T> *inVArray, int left, int mer, int right);
private:
	int SortCArray(T * inCArray);
	void mergeSortReq(T * inCArray, int left, int right);
	void merge(T * inCArray, int left, int mer, int right);
private:
	int SortMArray(Array<T> *inMArray);
	void mergeSortReq(Array<T> *inMArray, int left, int right);
	void merge(Array<T> *inMArray, int left, int mer, int right);
};

template<typename T>
inline MergeSort<T>::MergeSort(vector<T> *inValues, int inSize)
{
	if (inSize > 0) {
		ISort<T>::init(inValues, inSize, "MERGESORT");
		setArrSize(inSize);
	}
	else {
		runtime_error("Exception caught: Size must be greater than 0.");
	}
}

template<typename T>
inline MergeSort<T>::~MergeSort()
{}

template<typename T>
inline int MergeSort<T>::SortVArray(vector<T> * inVArray)
{
	int startTime = GetTickCount();

	mergeSortReq(inVArray, 0, (arrSize - 1));

	return (GetTickCount() - startTime);
}

template<typename T>
inline void MergeSort<T>::mergeSortReq(vector<T> * inVArray, int left, int right)
{
	if (left < right) {
		int mid = (left + right) / 2;

		mergeSortReq(inVArray, left, mid);
		mergeSortReq(inVArray, mid + 1, right);

		merge(inVArray, left, mid, right);
	}
}

template<typename T>
inline void MergeSort<T>::merge(vector<T> * inVArray, int left, int mid, int right)
{
	int i, j, k;
	int n1 = mid - left + 1;
	int n2 = right - mid;

	int* Left = new int[n1];
	int* Right = new int[n2];

	for (i = 0; i < n1; i++) {
		Left[i] = (*inVArray)[left + i];
	}
	
	for (j = 0; j < n2; j++) {
		Right[j] = (*inVArray)[mid + 1 + j];
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
inline int MergeSort<T>::SortCArray(T* inCArray)
{
	int startTime = GetTickCount();

	mergeSortReq(inCArray, 0, (arrSize - 1));

	return (GetTickCount() - startTime);
}

template<typename T>
inline void MergeSort<T>::mergeSortReq(T *inCArray, int left, int right)
{
	if (left < right) {
		int mid = (left + right) / 2;

		mergeSortReq(inCArray, left, mid);
		mergeSortReq(inCArray, mid + 1, right);

		merge(inCArray, left, mid, right);
	}
}

template<typename T>
inline void MergeSort<T>::merge(T  *inCArray, int left, int mid, int right)
{
	int i, j, k;
	int n1 = mid - left + 1;
	int n2 = right - mid;

	int* Left = new int[n1];
	int* Right = new int[n2];

	for (i = 0; i < n1; i++) {
		Left[i] = inCArray[left + i];
	}
		
	for (j = 0; j < n2; j++) {
		Right[j] = inCArray[mid + 1 + j];
	}
	
	i = 0;
	j = 0;
	k = left;
	while (i < n1 && j < n2)	{
		if (Left[i] <= Right[j]) {
			inCArray[k] = Left[i];
			i++;
		}
		else {
			inCArray[k] = Right[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		inCArray[k] = Left[i];
		i++;
		k++;
	}

	while (j < n2) {
		inCArray[k] = Right[j];
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

	mergeSortReq(inMArray, 0, (arrSize - 1));

	return (GetTickCount() - startTime);
}

template<typename T>
inline void MergeSort<T>::mergeSortReq(Array<T> *inMArray, int left, int right)
{
	if (left < right) {
		int mid = (left + right) / 2;

		mergeSortReq(inMArray, left, mid);
		mergeSortReq(inMArray, mid + 1, right);

		merge(inMArray, left, mid, right);
	}
}

template<typename T>
inline void MergeSort<T>::merge(Array<T> *inMArray, int left, int mid, int right)
{
	int i, j, k;
	int n1 = mid - left + 1;
	int n2 = right - mid;

	int* Left = new int[n1];
	int* Right = new int[n2];

	for (i = 0; i < n1; i++) {
		Left[i] = (*inMArray)[left + i];
	}
		
	for (j = 0; j < n2; j++) {
		Right[j] = (*inMArray)[mid + 1 + j];
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