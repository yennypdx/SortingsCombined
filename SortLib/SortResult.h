#pragma once
#ifndef SORTRESULT_H
#define SORTRESULT_H

#include <Windows.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
using namespace std;

class SortResult
{
public:
	SortResult();
	SortResult(string inName, int inVArrayTime, int inCArrayTime, int inMArrayTime);
	~SortResult();
public:
	void setName(string inName);
	void setVArrayTime(int inVArrayTime);
	void setCArrayTime(int inCArrayTime);
	void setMArrayTime(int inMArrayTime);
public:
	string getName();
	int getVArrayTime();
	int getCArrayTime();
	int getMArrayTime();

private:
	string mName;
	int mVArrayTime;
	int mCArrayTime;
	int mMArrayTime;
	void initTime(int inVArrayTime, int inCArrayTime, int inMArrayTime);
};

inline SortResult::SortResult()
{
	mVArrayTime = 0;
	mCArrayTime = 0;
	mMArrayTime = 0;

	initTime(mVArrayTime, mCArrayTime, mMArrayTime);
}

inline SortResult::SortResult(string inName, int inVArrayTime, int inCArrayTime, int inMArrayTime)
{
	initTime(inVArrayTime, inCArrayTime, inMArrayTime);
}

inline SortResult::~SortResult()
{}

inline void SortResult::setVArrayTime(int inVArrayTime)
{
	mVArrayTime = inVArrayTime;
}
inline void SortResult::setCArrayTime(int inCArrayTime)
{
	mCArrayTime = inCArrayTime;
}
inline void SortResult::setMArrayTime(int inMArrayTime)
{
	mMArrayTime = inMArrayTime;
}

inline void SortResult::setName(string inName)
{
	mName = inName;
}

inline int SortResult::getVArrayTime()
{
	return mVArrayTime;
}
inline int SortResult::getCArrayTime()
{
	return mCArrayTime;
}
inline int SortResult::getMArrayTime()
{
	return mMArrayTime;
}

inline string SortResult::getName()
{
	return mName;
}

inline void SortResult::initTime(int inVArrayTime, int inCArrayTime, int inMArrayTime)
{
	mVArrayTime = inVArrayTime;
	mCArrayTime = inCArrayTime;
	mMArrayTime = inMArrayTime;
}

#endif