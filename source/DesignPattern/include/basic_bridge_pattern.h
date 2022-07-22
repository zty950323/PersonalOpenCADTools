///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#ifndef  BASIC_BRIDGE_H_H_
#define BASIC_BRIDGE_H_H_

#include "zsofts_compiler_specific.h"

TZ_NAMESPACE_BEGIN(TzSoft)

class TzAbstractionImpl;

class TzAbstraction
{
public:
	TzAbstraction(TzAbstractionImpl* pImplementor);
	virtual ~TzAbstraction();
	void operation();

protected:
	TzAbstractionImpl* m_pImplementor = { nullptr };
};

// 为实现 Abstraction 定义的抽象基类,定义了实现的接口函数
class TzAbstractionImpl
{
public:
	TzAbstractionImpl()
	{

	}

	virtual ~TzAbstractionImpl()
	{

	}

	virtual void operationImpl() = 0;
};

// 继承自 Implementor,是 Implementor 的不同实现之一 
class TzConcreateImplementorA : public TzAbstractionImpl
{
public:
	TzConcreateImplementorA()
	{

	}

	virtual ~TzConcreateImplementorA()
	{

	}

	virtual void operationImpl() override;
};

// 继承自 Implementor,是 Implementor 的不同实现之一 
class TzConcreateImplementorB : public TzAbstractionImpl
{
public:
	TzConcreateImplementorB()
	{

	}

	virtual ~TzConcreateImplementorB()
	{

	}

	virtual void operationImpl() override;
};

TZ_NAMESPACE_END(TzSoft)

#endif