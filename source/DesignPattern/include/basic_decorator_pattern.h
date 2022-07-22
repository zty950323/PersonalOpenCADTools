///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#ifndef _BASIC_DECORATOR_PATTERN_H_H_
#define _BASIC_DECORATOR_PATTERN_H_H_

#include "zsofts_compiler_specific.h"

TZ_NAMESPACE_BEGIN(TzSoft)

// 抽象基类,定义一个对象接口,可以为这个接口动态的添加职责. 
class TzDecoratorComponent
{
public:
	TzDecoratorComponent()
	{

	}

	virtual ~TzDecoratorComponent()
	{

	}

	// 纯虚函数,由派生类实现
	virtual void operation() = 0;
};

//  抽象基类,维护一个指向 Component 对象的指针
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

// 派生自 Component,在这里表示需要给它动态添加职责的类
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

// 派生自 Decorator,这里代表为 ConcreateComponent 动态添加职责的类
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