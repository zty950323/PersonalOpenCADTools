///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include "basic_chain_of_responsibility_pattern_ctests.h"

#include <QtCore/QDebug>

TZ_NAMESPACE_BEGIN(TzSoftTest)

void TzChainOfResponsibilityTest::testCase_01(void)
{
	TzSoft::TzHandler* p1 = new TzSoft::TzConcreateHandler1();
	TzSoft::TzHandler* p2 = new TzSoft::TzConcreateHandler2(p1);

	p2->handleRequest();

	delete p2;
	p2 = nullptr;

	qDebug() << "TzChainOfResponsibilityTest::testCase_01 end!";

	return;
}

TZ_NAMESPACE_END(TzSoftTest)