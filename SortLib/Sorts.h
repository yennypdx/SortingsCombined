#pragma once
#ifndef SORTS_H
#define SORTS_H

#include <iostream>
#include <fstream>
#include <vector>
#include "Exception.h"
#include "Array.h"
#include "BubbleSort.h"
#include "FlaggedSort.h"
#include "HeapSort.h"
#include "InsertSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "SelectSort.h"
#include "ShellSort.h"
using namespace std;

template <typename T>
class BubbleSort;

template <typename T>
class FlaggedSort;

template <typename T>
class HeapSort;

template <typename T>
class InsertSort;

template <typename T>
class MergeSort;

template <typename T>
class QuickSort;

template <typename T>
class SelectSort;

template <typename T>
class ShellSort;

template <typename T>
class Array;

template<class T>
class Sorts
{
public:
	Sorts() {}
	~Sorts();
public:
	void RunSorts(int inSize);

private:
	vector<T> values;
	void initNumToSort(int inSize);
	void writeToFile(vector<SortResult> inResults);
};

template<typename T>
inline Sorts<T>::~Sorts()
{
	vector<T>().swap(values);
}

template<typename T>
inline void Sorts<T>::RunSorts(int inSize)
{
	initNumToSort(inSize);
	vector<SortResult> results;
	vector<ISort<T>*> algorithms;
	
	algorithms.push_back(new BubbleSort<T>(&values, inSize));
	algorithms.push_back(new FlaggedSort<T>(&values, inSize));
	algorithms.push_back(new HeapSort<T>(&values, inSize));
	algorithms.push_back(new InsertSort<T>(&values, inSize));
	algorithms.push_back(new MergeSort<T>(&values, inSize));
	algorithms.push_back(new QuickSort<T>(&values, inSize));
	algorithms.push_back(new SelectSort<T>(&values, inSize));
	algorithms.push_back(new ShellSort<T>(&values, inSize));

	int it = 0;
	for (auto &algorithm : algorithms) {
		results.push_back(algorithm->Sort());

		cout << "SORTING TYPE : " << results[it].getName() << endl;
		cout << "via C-Array	: " << results[it].getCArrayTime() << endl;
		cout << "via V-Array	: " << results[it].getVArrayTime() << endl;
		cout << "via MY-ARRAY	: " << results[it].getMArrayTime() << endl << endl;

		it++;
		delete algorithm;
	}
	writeToFile(results);
}

template<typename T>
inline void Sorts<T>::initNumToSort(int inSize)
{
	srand(1);
	for (int i = 0; i < inSize; i++) {
		int number = (rand() % 100000);
		values.push_back(number);
	}
}

template<class T>
inline void Sorts<T>::writeToFile(vector<SortResult> inResults)
{
	ofstream myFile;
	myFile.open("sortsresult.txt");
	int restSize = inResults.size();

	for (int i = 0; i < restSize; i++) {
		myFile << "Sorting Type: " <<  inResults[i].getName() << endl;
		myFile << "CARRAY : " << to_string(inResults[i].getCArrayTime()) << endl;
		myFile << "VARRAY : " << to_string(inResults[i].getVArrayTime()) << endl;
		myFile << "MYARRAY : " << to_string(inResults[i].getMArrayTime()) << endl << endl;
	}
	myFile.close();
}

#endif