///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#ifndef _BASIC_DECORATOR_PATTERN_H_H_
#define _BASIC_DECORATOR_PATTERN_H_H_

#include "zsofts_compiler_specific.h"

TZ_NAMESPACE_BEGIN(TzSoft)

// �������,����һ������ӿ�,����Ϊ����ӿڶ�̬�����ְ��. 
class TzDecoratorComponent
{
public:
	TzDecoratorComponent()
	{

	}

	virtual ~TzDecoratorComponent()
	{

	}

	// ���麯��,��������ʵ��
	virtual void operation() = 0;
};

//  �������,ά��һ��ָ�� Component �����ָ��
class TzDecorator : public TzDecoratorComponent
{
public:
	TzDecorator(TzDecoratorComponent* pComponent)
		: m_pComponent(pComponent)
	{

	}

	virtual ~TzDecorator();

protected:
	TzDecoratorComponent* m_pComponent;
};

// ������ Component,�������ʾ��Ҫ������̬���ְ�����
class TzConcreateDecoratorComponent : public TzDecoratorComponent
{
public:
	TzConcreateDecoratorComponent() 
	{
		
	}

	virtual ~TzConcreateDecoratorComponent()
	{

	}

	virtual void operation() override;
};

// ������ Decorator,�������Ϊ ConcreateComponent ��̬���ְ�����
class TzConcreateDecorator : public TzDecorator
{
public:
	TzConcreateDecorator(TzDecoratorComponent* pComponent)
		: TzDecorator(pComponent)
	{

	}

	virtual void operation() override;

private:
	void addedBehavior();
};

TZ_NAMESPACE_END(TzSoft)

#endif