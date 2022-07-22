///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#ifndef _BASIC_ABSTRACT_FACTORY_PATTERN_H_H_
#define _BASIC_ABSTRACT_FACTORY_PATTERN_H_H_

#include "zsofts_compiler_specific.h"

TZ_NAMESPACE_BEGIN(TzSoft)

// 抽象基类 AbstractProductA,代表产品 A 的抽象

class TzAbstractProductA
{
public:
	TzAbstractProductA()
	{

	}

	virtual ~TzAbstractProductA()
	{

	};
};

// 派生类 ConcreateProductA1,继承自 AbstractProductA,代表产品 A 的第一种实现

class TzConcreateProductA1 : public TzAbstractProductA
{
public:
	TzConcreateProductA1();
	virtual ~TzConcreateProductA1();
};

// 派生类 ConcreateProductA2,继承自 AbstractProductA,代表产品 A 的第二种实现
class TzConcreateProductA2
	: public TzAbstractProductA
{
public:
	TzConcreateProductA2();
	virtual ~TzConcreateProductA2();
};

// 抽象基类 AbstractProductB,代表产品 B 的抽象

class TzAbstractProductB
{
public:
	TzAbstractProductB() {}
	virtual ~TzAbstractProductB() {};
};

// 派生类 ConcreateProductB1,继承自 AbstractProductB,代表产品 B 的第一种实现
class TzConcreateProductB1
	: public TzAbstractProductB
{
public:
	TzConcreateProductB1();
	virtual ~TzConcreateProductB1();
};

// 派生类 ConcreateProductB2,继承自 AbstractProductB,代表产品 B 的第二种实现
class TzConcreateProductB2
	: public TzAbstractProductB
{
public:
	TzConcreateProductB2();
	virtual ~TzConcreateProductB2();
};

// 抽象基类 AbstractFactory,工厂的抽象类,生产产品 A 和产品 B 
class TzAbstractFactory
{
public:
	TzAbstractFactory() {}
	virtual ~TzAbstractFactory() {}
	virtual TzAbstractProductA* CreateProductA() = 0;
	virtual TzAbstractProductB* CreateProductB() = 0;
};

// 派生类 ConcreateFactory1,继承自 AbstractFactory 
// 生产产品 A 和产品 B 的第一种实现
class TzConcreateFactory1
	: public TzAbstractFactory
{
public:
	TzConcreateFactory1();
	virtual ~TzConcreateFactory1();
	virtual TzAbstractProductA* CreateProductA();
	virtual TzAbstractProductB* CreateProductB();
};
// 派生类 ConcreateFactory2,继承自 AbstractFactory 
// 生产产品 A 和产品 B 的第二种实现
class TzConcreateFactory2
	: public TzAbstractFactory
{
public:
	TzConcreateFactory2();
	virtual ~TzConcreateFactory2();
	virtual TzAbstractProductA* CreateProductA();
	virtual TzAbstractProductB* CreateProductB();
};

TZ_NAMESPACE_END(TzSoft)

#endif