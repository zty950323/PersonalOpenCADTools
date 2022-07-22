///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#ifndef _BASIC_STRATEGY_PATTERN_H_H_
#define _BASIC_STRATEGY_PATTERN_H_H_

#include "zsofts_compiler_specific.h"

TZ_NAMESPACE_BEGIN(TzSoft)

class TzStrategy;

class TzContext
{
public:
	TzContext(TzStrategy* pStrategy);
	~TzContext();

	void contextInterface();

private:
	TzStrategy* m_pStrategy;
};

class TzStrategy
{
public:
	virtual ~TzStrategy()
	{

	}

	virtual void algorithmInterface() = 0;
};

class TzConcreateStrategyA : public TzStrategy
{
public:
	virtual ~TzConcreateStrategyA()
	{

	}

	virtual void algorithmInterface() override;
};

TZ_NAMESPACE_END(TzSoft)

#endif