///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include "basic_template_method_pattern_ctests.h"

#include <QtCore/QDebug>

TZ_NAMESPACE_BEGIN(TzSoftTest)

void TzTemplateMethodTest::testCase_01(void)
{
	TzSoft::TzAbstractClass* pConcreateClass = new TzSoft::TzConcreateClass();
	pConcreateClass->templateMethod();

	delete pConcreateClass;
	pConcreateClass = nullptr;

	qDebug() << "TzAbstractFactoryTest::testCase_01 end!";

	return;
}

TZ_NAMESPACE_END(TzSoftTest)