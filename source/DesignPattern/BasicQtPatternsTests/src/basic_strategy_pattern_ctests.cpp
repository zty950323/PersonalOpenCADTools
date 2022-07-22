///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include "basic_strategy_pattern_ctests.h"

#include <QtCore/QDebug>

TZ_NAMESPACE_BEGIN(TzSoftTest)

void TzStrategyTest::testCase_01(void)
{
	TzSoft::TzStrategy* pStrategy = new TzSoft::TzConcreateStrategyA();
	TzSoft::TzContext* pContext = new TzSoft::TzContext(pStrategy);

	pContext->contextInterface();

	delete pContext;

	qDebug() << "TzAbstractFactoryTest::testCase_01 end!";

	return;
}

TZ_NAMESPACE_END(TzSoftTest)