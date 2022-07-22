///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include "basic_abstract_factory_pattern_ctests.h"

#include <QtCore/QDebug>

TZ_NAMESPACE_BEGIN(TzSoftTest)

void TzAbstractFactoryTest::testCase_01(void)
{
	// 生产产品 A 的第一种实现
	TzSoft::TzConcreateFactory1* pFactory1 = new TzSoft::TzConcreateFactory1;
	TzSoft::TzAbstractProductA* pProductA = pFactory1->CreateProductA();
	// 生产产品 B 的第二种实现
	TzSoft::TzConcreateFactory2* pFactory2 = new TzSoft::TzConcreateFactory2;
	TzSoft::TzAbstractProductB* pProductB = pFactory2->CreateProductB();
	delete pFactory1;
	pFactory1 = nullptr;
	delete pProductA;
	pProductA = nullptr;
	delete pFactory2;
	pFactory2 = nullptr;
	delete pProductB;
	pProductB = nullptr;

	qDebug() << "TzAbstractFactoryTest::testCase_01 end!";

	return;
}

TZ_NAMESPACE_END(TzSoftTest)