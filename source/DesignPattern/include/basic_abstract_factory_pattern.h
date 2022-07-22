///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#ifndef _BASIC_ABSTRACT_FACTORY_PATTERN_H_H_
#define _BASIC_ABSTRACT_FACTORY_PATTERN_H_H_

#include "zsofts_compiler_specific.h"

TZ_NAMESPACE_BEGIN(TzSoft)

// ������� AbstractProductA,�����Ʒ A �ĳ���

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

// ������ ConcreateProductA1,�̳��� AbstractProductA,�����Ʒ A �ĵ�һ��ʵ��

class TzConcreateProductA1 : public TzAbstractProductA
{
public:
	TzConcreateProductA1();
	virtual ~TzConcreateProductA1();
};

// ������ ConcreateProductA2,�̳��� AbstractProductA,�����Ʒ A �ĵڶ���ʵ��
class TzConcreateProductA2
	: public TzAbstractProductA
{
public:
	TzConcreateProductA2();
	virtual ~TzConcreateProductA2();
};

// ������� AbstractProductB,�����Ʒ B �ĳ���

class TzAbstractProductB
{
public:
	TzAbstractProductB() {}
	virtual ~TzAbstractProductB() {};
};

// ������ ConcreateProductB1,�̳��� AbstractProductB,�����Ʒ B �ĵ�һ��ʵ��
class TzConcreateProductB1
	: public TzAbstractProductB
{
public:
	TzConcreateProductB1();
	virtual ~TzConcreateProductB1();
};

// ������ ConcreateProductB2,�̳��� AbstractProductB,�����Ʒ B �ĵڶ���ʵ��
class TzConcreateProductB2
	: public TzAbstractProductB
{
public:
	TzConcreateProductB2();
	virtual ~TzConcreateProductB2();
};

// ������� AbstractFactory,�����ĳ�����,������Ʒ A �Ͳ�Ʒ B 
class TzAbstractFactory
{
public:
	TzAbstractFactory() {}
	virtual ~TzAbstractFactory() {}
	virtual TzAbstractProductA* CreateProductA() = 0;
	virtual TzAbstractProductB* CreateProductB() = 0;
};

// ������ ConcreateFactory1,�̳��� AbstractFactory 
// ������Ʒ A �Ͳ�Ʒ B �ĵ�һ��ʵ��
class TzConcreateFactory1
	: public TzAbstractFactory
{
public:
	TzConcreateFactory1();
	virtual ~TzConcreateFactory1();
	virtual TzAbstractProductA* CreateProductA();
	virtual TzAbstractProductB* CreateProductB();
};
// ������ ConcreateFactory2,�̳��� AbstractFactory 
// ������Ʒ A �Ͳ�Ʒ B �ĵڶ���ʵ��
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