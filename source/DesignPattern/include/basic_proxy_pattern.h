///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#ifndef _BASIC_PROXY_PATTERN_H_H_
#define _BASIC_PROXY_PATTERN_H_H_

#include "zsofts_compiler_specific.h"

TZ_NAMESPACE_BEGIN(TzSoft)

// ������ Proxy �� RealSubject �Ĺ��нӿ�, 
// �����Ϳ������κ���Ҫʹ�õ� RealSubject �ĵط���ʹ�� Proxy.
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

// ����ʹ�õ�ʵ��
class TzRealSubject : public TzSubject
{
public:
	TzRealSubject();
	virtual ~TzRealSubject();

	virtual void request() override;
};

// ������,����һ��ָ�� RealSubject �����ָ��
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