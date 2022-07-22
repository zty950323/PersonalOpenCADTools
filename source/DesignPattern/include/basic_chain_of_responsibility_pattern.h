///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#ifndef _BASIC_CHAIN_OF_RESPONSIBILITY_PATTERN_H_H_
#define _BASIC_CHAIN_OF_RESPONSIBILITY_PATTERN_H_H_

#include "zsofts_compiler_specific.h"

TZ_NAMESPACE_BEGIN(TzSoft)

// ������࣬ ����һ����������Ľӿ�
class TzHandler 
{
public:
	TzHandler(TzHandler* pSuccessor = nullptr);
	virtual ~TzHandler();

	// ���麯���� ��������ʵ��
	virtual void handleRequest() = 0;

protected:
	TzHandler* m_pSuccessor;
};

class TzConcreateHandler1 : public TzHandler
{
public:
	TzConcreateHandler1(TzHandler* pSuccessor = nullptr)
		: TzHandler(pSuccessor)
	{

	}

	virtual ~TzConcreateHandler1()
	{

	}

	virtual void handleRequest() override;
};

class TzConcreateHandler2 : public TzHandler
{
public:
	TzConcreateHandler2(TzHandler* pSuccessor = nullptr)
		: TzHandler(pSuccessor)
	{

	}

	virtual ~TzConcreateHandler2()
	{

	}

	virtual void handleRequest() override;
};

TZ_NAMESPACE_END(TzSoft)

#endif