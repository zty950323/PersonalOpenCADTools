///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include "basic_bridge_pattern_ctests.h"

#include <QtCore/QDebug>

TZ_NAMESPACE_BEGIN(TzSoftTest)

void TzBridgeTest::testCase_01(void)
{
	TzSoft::TzConcreateImplementorA* pImplA = new TzSoft::TzConcreateImplementorA();
	TzSoft::TzAbstraction* pAbstractions1 = new TzSoft::TzAbstraction(pImplA);
	pAbstractions1->operation();

	TzSoft::TzConcreateImplementorB* pImplB = new TzSoft::TzConcreateImplementorB();
	TzSoft::TzAbstraction* pAbstractions2 = new TzSoft::TzAbstraction(pImplB);
	pAbstractions2->operation();

	delete pAbstractions1;
	pAbstractions1 = nullptr;
	delete pAbstractions2;
	pAbstractions2 = nullptr;

	qDebug() << "TzAbstractFactoryTest::testCase_01 end!";

	return;
}

TZ_NAMESPACE_END(TzSoftTest)