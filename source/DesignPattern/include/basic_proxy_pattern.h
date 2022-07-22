///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#ifndef _BASIC_PROXY_PATTERN_H_H_
#define _BASIC_PROXY_PATTERN_H_H_

#include "zsofts_compiler_specific.h"

TZ_NAMESPACE_BEGIN(TzSoft)

// 定义了 Proxy 和 RealSubject 的公有接口, 
// 这样就可以在任何需要使用到 RealSubject 的地方都使用 Proxy.
class TzSubject
{
public:
	TzSubject()
	{

	}

	virtual ~TzSubject()
	{

	}

	virtual void request() = 0;
};

// 真正使用的实体
class TzRealSubject : public TzSubject
{
public:
	TzRealSubject();
	virtual ~TzRealSubject();

	virtual void request() override;
};

// 代理类,含有一个指向 RealSubject 对象的指针
class TzProxy : public TzSubject
{
public:
	TzProxy();
	virtual ~TzProxy();

	virtual void request() override;

private:
	TzRealSubject* m_pRealSubject = { nullptr };
};

TZ_NAMESPACE_END(TzSoft)

#endif