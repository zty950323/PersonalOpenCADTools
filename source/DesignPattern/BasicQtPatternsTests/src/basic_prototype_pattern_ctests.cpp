///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include "basic_prototype_pattern_ctests.h"

#include <QtCore/QDebug>

TZ_NAMESPACE_BEGIN(TzSoftTest)

void TzPrototypeTest::testCase_01(void)
{
	TzSoft::TzPrototype* pPrototype1 = new TzSoft::TzConcreatePrototype1();
	TzSoft::TzPrototype* pPrototype2 = pPrototype1->Clone();

	TzSoft::TzPrototype* pPrototype3 = new TzSoft::TzConcreatePrototype2();
	TzSoft::TzPrototype* pPrototype4 = pPrototype3->Clone();

	delete pPrototype1;
	pPrototype1 = nullptr;
	delete pPrototype2;
	pPrototype2 = nullptr;
	delete pPrototype3;
	pPrototype3 = nullptr;
	delete pPrototype4;
	pPrototype4 = nullptr;

	qDebug() << "TzPrototypeTest::testCase_01 end!";

	return;
}

TZ_NAMESPACE_END(TzSoftTest)