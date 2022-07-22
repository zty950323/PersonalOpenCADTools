///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#ifndef _BASIC_TEMPLATE_METHOD_PATTERN_H_H_
#define _BASIC_TEMPLATE_METHOD_PATTERN_H_H_

#include "zsofts_compiler_specific.h"

TZ_NAMESPACE_BEGIN(TzSoft)

// ������࣬�����㷨����
class TzAbstractClass
{
public:
	TzAbstractClass()
	{

	}

	virtual ~TzAbstractClass() 
	{

	}

	// ��������ж������㷨������
	void templateMethod();

protected:
	// ���麯������������ʵ��֮
	virtual void primitiveOperation1() = 0;
	virtual void primitiveOperation2() = 0;
};

// �̳���TzAbstractClass�� ʵ�ֶ�Ӧ���㷨
class TzConcreateClass : public TzAbstractClass
{
public:
	TzConcreateClass()
	{

	}

	virtual ~TzConcreateClass()
	{

	}

protected:
	virtual void primitiveOperation1() override;
	virtual void primitiveOperation2() override;
};

TZ_NAMESPACE_END(TzSoft)

#endif