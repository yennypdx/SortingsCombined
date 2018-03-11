#pragma once
#ifndef ISORT_H
#define ISORT_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include "Array.h"
#include "SortResult.h"
using namespace std;

template<class T>
class ISort
{
public:
	SortResult Sort();
	~ISort();

protected:
	void revertArrays();
	void displayHeader(string inHeader);
	void displayAllArrays();
	void displayArrays(vector<T> *inVArray);
	void displayArrays(T* inCArray);
	void displayArrays(Array<T> *inMArray);
	void init(vector<T> *inValues, int inNum, string inName);
protected:
	virtual int SortVArray(vector<T> *inVArray) = 0;
	virtual int SortCArray(T* inCArray) = 0;
	virtual int SortMArray(Array<T> *inMArray) = 0;
protected:
	int aSize;
	string mName = "default";
protected:
	T * c_Array;
	vector<T> orig_CopyArray;
	vector<T> vec_Array;
	Array<T> my_Array;
};

template <typename T>
inline SortResult ISort<T>::Sort()
{
	revertArrays();
	SortResult tempResults = SortResult();

	tempResults.setName(mName);
	tempResults.setCArrayTime(SortCArray(& (*c_Array)));
	tempResults.setVArrayTime(SortVArray(&vec_Array));
	tempResults.setMArrayTime(SortMArray(&my_Array));

	return tempResults;
}

template <typename T>
inline ISort<T>::~ISort()
{
	vector<T>().swap(orig_CopyArray);
	vector<T>().swap(vec_Array);
	delete c_Array;
	c_Array = nullptr;
}

template <typename T>
inline void ISort<T>::revertArrays()
{
	for (int i = 0; i < (aSize - 1); i++) {
		c_Array[i] = orig_CopyArray[i];
		vec_Array[i] = orig_CopyArray[i];
		my_Array[i] = orig_CopyArray[i];
	}
}

template <typename T>
inline void ISort<T>::init(vector<T>* inValues, int inNum, string inName)
{
	c_Array = new T[inNum];
	my_Array = Array<T>(inNum);
	mName = inName;

	for (int i = 0; i < inNum; i++) {
		orig_CopyArray.push_back((*inValues)[i]);

		c_Array[i] = (*inValues)[i];
		vec_Array.push_back((*inValues)[i]);
		my_Array[i] = (*inValues)[i];
	}
}

template <typename T>
inline void ISort<T>::displayHeader(string inHeader)
{
	cout << endl;
	cout << "*****************************" << endl;
	cout << ">>>> " << inHeader << " <<<<" << endl;
	cout << endl;
}

template <typename T>
inline void ISort<T>::displayAllArrays()
{
	displayArrays(&vArray);
	displayArrays(cArray);
	displayArrays(&mArray);
}

template <typename T>
inline void ISort<T>::displayArrays(vector<T>* inVArray)
{
	for (int i = 0; i < aSize; i++)
	{
		cout << "VECTOR : " << vArray[i] << endl;
	}
}

template <typename T>
inline void ISort<T>::displayArrays(T* inCArray)
{
	for (int i = 0; i < aSize; i++)
	{
		cout << "CARRAY : " << (*inCArray)[i] << endl;
	}
}

template <typename T>
inline void ISort<T>::displayArrays(Array<T>* inMArray)
{
	for (int i = 0; i < aSize; i++)
	{
		cout << "MARRAY : " << mArray[i] << endl;
	}
}

#endif