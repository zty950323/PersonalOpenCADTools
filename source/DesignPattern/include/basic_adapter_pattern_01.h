///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#ifndef _BASIC_ADAPTER_PATTERN_H_H_
#define _BASIC_ADAPTER_PATTERN_H_H_

#include "zsofts_compiler_specific.h"

TZ_NAMESPACE_BEGIN(TzSoft)

// ��Ҫ�� Adapt ����
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
// �뱻 Adapt �����ṩ�����ݽӿڵ���
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

// ���� Adapt ����,���þۺ�ԭ�нӿ���ķ�ʽ
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