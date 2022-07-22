///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include "basic_iterator_pattern.h"

#include <QtCore/QDebug>

TZ_NAMESPACE_BEGIN(TzSoft)

TzConcreateAggregate::TzConcreateAggregate(int nSize)
	: m_pData(nullptr),
	m_nSize(nSize)
{
	m_pData = new DATA[m_nSize];

	for (decltype(nSize) i = 0; i < nSize; ++i)
	{
		m_pData[i] = i;
	}
}

TzConcreateAggregate::~TzConcreateAggregate()
{
	delete[] m_pData;
	m_pData = nullptr;
}

TzIterater* TzConcreateAggregate::createIterater(TzAggregate* pAggregate)
{
	return new TzConcreateIterater(this);
}

int TzConcreateAggregate::getSize()
{
	return m_nSize;
}

DATA TzConcreateAggregate::getItem(int nIndex)
{
	if (nIndex < m_nSize)
	{
		return m_pData[nIndex];
	}
	else
	{
		return -1;
	}
}

TzConcreateIterater::TzConcreateIterater(TzAggregate* pAggregate)
	: m_pConcreateAggregate(pAggregate),
	m_nIndex(0)
{

}

void TzConcreateIterater::first()
{
	m_nIndex = 0;
}

void TzConcreateIterater::next()
{
	if (m_nIndex < m_pConcreateAggregate->getSize())
	{
		++m_nIndex;
	}
}

bool TzConcreateIterater::isDone()
{
	return m_nIndex == m_pConcreateAggregate->getSize();
}

DATA TzConcreateIterater::currentItem()
{
	return m_pConcreateAggregate->getItem(m_nIndex);
}

TZ_NAMESPACE_END(TzSoft)