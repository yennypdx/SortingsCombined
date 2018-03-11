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
	SortResult(string inName, int inCArrayTime, int inVArrayTime, int inMArrayTime);
	~SortResult();
public:
	void setName(string inName);
	void setCArrayTime(int inCArrayTime);
	void setVArrayTime(int inVArrayTime);
	void setMArrayTime(int inMArrayTime);
public:
	string getName();
	int getCArrayTime();
	int getVArrayTime();
	int getMArrayTime();

private:
	string m_Name;
	int m_CArrayTime;
	int m_VArrayTime;
	int m_MArrayTime;
	void initTime(int inCArrayTime, int inVArrayTime, int inMArrayTime);
};

inline SortResult::SortResult()
{
	m_CArrayTime = 0;
	m_VArrayTime = 0;
	m_MArrayTime = 0;

	initTime(m_CArrayTime, m_VArrayTime, m_MArrayTime);
}

inline SortResult::SortResult(string inName, int inCArrayTime, int inVArrayTime, int inMArrayTime)
{
	initTime(inCArrayTime, inVArrayTime, inMArrayTime);
}

inline SortResult::~SortResult()
{}

inline void SortResult::setCArrayTime(int inCArrayTime)
{
	m_CArrayTime = inCArrayTime;
}

inline void SortResult::setVArrayTime(int inVArrayTime)
{
	m_VArrayTime = inVArrayTime;
}

inline void SortResult::setMArrayTime(int inMArrayTime)
{
	m_MArrayTime = inMArrayTime;
}

inline void SortResult::setName(string inName)
{
	m_Name = inName;
}

inline int SortResult::getCArrayTime()
{
	return m_CArrayTime;
}

inline int SortResult::getVArrayTime()
{
	return m_VArrayTime;
}

inline int SortResult::getMArrayTime()
{
	return m_MArrayTime;
}

inline string SortResult::getName()
{
	return m_Name;
}

inline void SortResult::initTime(int inCArrayTime, int inVArrayTime,int inMArrayTime)
{
	m_CArrayTime = inCArrayTime;
	m_VArrayTime = inVArrayTime;
	m_MArrayTime = inMArrayTime;
}

#endif