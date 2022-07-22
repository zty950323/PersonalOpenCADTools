///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#ifndef _BASIC_TEMPLATE_METHOD_PATTERN_H_H_
#define _BASIC_TEMPLATE_METHOD_PATTERN_H_H_

#include "zsofts_compiler_specific.h"

TZ_NAMESPACE_BEGIN(TzSoft)

// 抽象基类，定义算法轮廓
class TzAbstractClass
{
public:
	TzAbstractClass()
	{

	}

	virtual ~TzAbstractClass() 
	{

	}

	// 这个函数中定义了算法的轮廓
	void templateMethod();

protected:
	// 纯虚函数，由派生类实现之
	virtual void primitiveOperation1() = 0;
	virtual void primitiveOperation2() = 0;
};

// 继承自TzAbstractClass， 实现对应的算法
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