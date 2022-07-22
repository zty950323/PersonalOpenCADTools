///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include "basic_abstract_factory_pattern.h"

#include <QtCore/QDebug>

TZ_NAMESPACE_BEGIN(TzSoft)

TzConcreateProductA1::TzConcreateProductA1()
{
	qDebug() << " construction of ConcreateProductA1";
}

TzConcreateProductA1::~TzConcreateProductA1()
{
	qDebug() << " destruction of ConcreateProductA1";
}

TzConcreateProductA2::TzConcreateProductA2()
{
	qDebug() << " construction of ConcreateProductA2";
}

TzConcreateProductA2::~TzConcreateProductA2()
{
	qDebug() << " destruction of ConcreateProductA2";
}

TzConcreateProductB1::TzConcreateProductB1()
{
	qDebug() << " construction of ConcreateProductB1";
}

TzConcreateProductB1::~TzConcreateProductB1()
{
	qDebug() << " destruction of ConcreateProductB1";
}

TzConcreateProductB2::TzConcreateProductB2()
{
	qDebug() << " construction of ConcreateProductB2";
}

TzConcreateProductB2::~TzConcreateProductB2()
{
	qDebug() << " destruction of ConcreateProductB2";
}

TzConcreateFactory1::TzConcreateFactory1()
{
	qDebug() << " construction of ConcreateFactory1";
}

TzConcreateFactory1::~TzConcreateFactory1()
{
	qDebug() << " destruction of ConcreateFactory1";
}

TzAbstractProductA* TzConcreateFactory1::CreateProductA()
{
	return new TzConcreateProductA1();
}

TzAbstractProductB* TzConcreateFactory1::CreateProductB()
{
	return new TzConcreateProductB1();
}

TzConcreateFactory2::TzConcreateFactory2()
{
	qDebug() << " construction of ConcreateFactory2";
}

TzConcreateFactory2::~TzConcreateFactory2()
{
	qDebug() << " destruction of ConcreateFactory1";
}

TzAbstractProductA* TzConcreateFactory2::CreateProductA()
{
	return new TzConcreateProductA2();
}

TzAbstractProductB* TzConcreateFactory2::CreateProductB()
{
	return new TzConcreateProductB2();
}

TZ_NAMESPACE_END(TzSoft)