///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#ifndef _BASIC_ABSTRACT_FACTORY_PATTERN_H_H_
#define _BASIC_ABSTRACT_FACTORY_PATTERN_H_H_

#include "zsofts_compiler_specific.h"

TZ_NAMESPACE_BEGIN(TzSoft)

using DATA = int;

class TzIterater;

// �����ĳ������
class TzAggregate
{
public:
	virtual ~TzAggregate()
	{

	}

	virtual TzIterater* createIterater(TzAggregate* pAggregate) = 0;
	virtual int getSize() = 0;
	virtual DATA getItem(int nIndex) = 0;
};

// �������ĳ������
class TzIterater
{
public:
	~TzIterater()
	{

	}

	virtual void first() = 0;
	virtual void next() = 0;
	virtual bool isDone() = 0;
	virtual DATA currentItem() = 0;
};

// һ������������࣬����ʹ�������ʾ
class TzConcreateAggregate : public TzAggregate
{
public:
	TzConcreateAggregate(int nSize);
	virtual ~TzConcreateAggregate();

	virtual TzIterater* createIterater(TzAggregate* pAggregate);
	virtual int getSize();
	virtual DATA getItem(int nIndex);

private:
	int m_nSize = { 0 };
	DATA* m_pData = { nullptr };
};

// ���� TzConcreateAggregate ������ĵ�������
class TzConcreateIterater : public TzIterater
{
public:
	TzConcreateIterater(TzAggregate* pAggregate);
	virtual ~TzConcreateIterater()
	{

	}

	virtual void first() override;
	virtual void next() override;
	virtual bool isDone() override;
	virtual DATA currentItem() override;

private:
	TzAggregate* m_pConcreateAggregate = { nullptr };
	int m_nIndex = 0;
};

TZ_NAMESPACE_END(TzSoft)

#endif