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

// Ϊʵ�� Abstraction ����ĳ������,������ʵ�ֵĽӿں���
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

// �̳��� Implementor,�� Implementor �Ĳ�ͬʵ��֮һ 
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

// �̳��� Implementor,�� Implementor �Ĳ�ͬʵ��֮һ 
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