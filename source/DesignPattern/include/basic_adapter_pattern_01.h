///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#ifndef _BASIC_ADAPTER_PATTERN_H_H_
#define _BASIC_ADAPTER_PATTERN_H_H_

#include "zsofts_compiler_specific.h"

TZ_NAMESPACE_BEGIN(TzSoft)

// 需要被 Adapt 的类
class TzTarget
{
public:
	TzTarget()
	{

	}
	virtual ~TzTarget()
	{

	}

	virtual void request() = 0;
};
// 与被 Adapt 对象提供不兼容接口的类
class TzAdaptee
{
public:
	TzAdaptee()
	{

	}

	~TzAdaptee()
	{

	}

	void specialRequest();
};

// 进行 Adapt 的类,采用聚合原有接口类的方式
class TzAdapter : public TzTarget
{
public:
	TzAdapter(TzAdaptee* pAdaptee);
	virtual ~TzAdapter();
	virtual void request() override;
private:
	TzAdaptee* m_pAdptee = { nullptr };
};

TZ_NAMESPACE_END(TzSoft)

#endif