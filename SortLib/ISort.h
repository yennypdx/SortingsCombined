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
	void displayArrays(T** inCArray);
	void displayArrays(Array<T> *inMArray);
	void init(vector<T> *inValues, int inNum, string inName);
protected:
	virtual int SortVArray(vector<T> *inVArray) = 0;
	virtual int SortCArray(T** inCArray) = 0;
	virtual int SortMArray(Array<T> *inMArray) = 0;
protected:
	int aSize;
	T** cArray;
	string mName = "default";
	vector<T> oArray;
	vector<T> vArray;
	Array<T> mArray;
};

template <typename T>
inline SortResult ISort<T>::Sort()
{
	revertArrays();
	SortResult tempResults = SortResult();

	tempResults.setName(mName);
	tempResults.setVArrayTime(SortVArray(&vArray));
	tempResults.setCArrayTime(SortCArray(cArray));
	tempResults.setMArrayTime(SortMArray(&mArray));

	return tempResults;
}

template <typename T>
inline ISort<T>::~ISort()
{
	vector<T>().swap(oArray);
	vector<T>().swap(vArray);
	delete[](*cArray);
	delete cArray;
	cArray = NULL;
	mArray = NULL;
}

template <typename T>
inline void ISort<T>::revertArrays()
{
	for (int i = 0; i < (aSize - 1); i++) {
		vArray[i] = oArray[i];
		(*cArray)[i] = oArray[i];
		mArray[i] = oArray[i];
	}
}

template <typename T>
inline void ISort<T>::init(vector<T>* inValues, int inNum, string inName)
{
	cArray = new T*;
	(*cArray) = new T[inNum];
	mArray = Array<T>(inNum);
	mName = inName;

	for (int i = 0; i < inNum; i++) {
		vArray.push_back((*inValues)[i]);
		oArray.push_back((*inValues)[i]);
		(*cArray)[i] = (*inValues)[i];
		mArray[i] = (*inValues)[i];
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
inline void ISort<T>::displayArrays(T** inCArray)
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