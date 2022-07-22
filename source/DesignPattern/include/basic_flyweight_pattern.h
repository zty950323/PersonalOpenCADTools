///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#ifndef _BASIC_FLYWEIGHT_PATTERN_H_H_
#define _BASIC_FLYWEIGHT_PATTERN_H_H_

#include "zsofts_compiler_specific.h"

#include <string>
#include <list>

TZ_NAMESPACE_BEGIN(TzSoft)

using STATE = std::string;

class TzFlyweight
{
public:
	virtual ~TzFlyweight()
	{

	}

	STATE getIntrinsicState();
	virtual void operation(STATE& extrinsicState) = 0;

protected:
	TzFlyweight(const STATE& state)
		: m_state(state)
	{

	}

private:
	STATE m_state;
};

class TzFlyweightFacytory
{
public:
	TzFlyweightFacytory()
	{

	}

	~TzFlyweightFacytory();

	TzFlyweight* getFlyweight(const STATE& key);

private:
	std::list<TzFlyweight*> m_listFlyweight;
};

class TzConcreateFlyweight : public TzFlyweight
{
public:
	TzConcreateFlyweight(const STATE& state)
		: TzFlyweight(state)
	{

	}

	virtual ~TzConcreateFlyweight()
	{
		
	}

	virtual void operation(STATE& extrinsicState) override;
};

TZ_NAMESPACE_END(TzSoft)

#endif