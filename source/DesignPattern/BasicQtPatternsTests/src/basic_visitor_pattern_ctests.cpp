///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include "basic_visitor_pattern_ctests.h"

#include <QtCore/QDebug>

TZ_NAMESPACE_BEGIN(TzSoftTest)

void TzVisitorTest::testCase_01(void)
{
	TzSoft::TzVisitor* pVisitorA = new TzSoft::TzConcreateVisitorA();
	TzSoft::TzVisitorElement* pElement = new TzSoft::TzConcreateElementA();
	TzSoft::TzVisitor* pVisitorB = new TzSoft::TzConcreateVisitorB();
	TzSoft::TzVisitorElement* pElementB = new TzSoft::TzConcreateElementB();

	pElement->accept(*pVisitorA);
	pElementB->accept(*pVisitorB);

	delete pElementB;
	pElementB = nullptr;
	delete pVisitorB;
	pVisitorB = nullptr;
	delete pElement;
	pElement = nullptr;
	delete pVisitorA;
	pVisitorA = nullptr;

	qDebug() << "TzVisitorTest::testCase_01 end!";

	return;
}

TZ_NAMESPACE_END(TzSoftTest)