///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include "basic_state_pattern_ctests.h"

#include <QtCore/QDebug>

TZ_NAMESPACE_BEGIN(TzSoftTest)

void TzStateTest::testCase_01(void)
{
	TzSoft::TzState* pState = new TzSoft::TzConcreateStateA();
	TzSoft::TzStateContext* pContext = new TzSoft::TzStateContext(pState);

	for (int i = 0; i < 3; ++i)
	{
		pContext->request();
	}

	delete pContext;
	pContext = nullptr;

	qDebug() << "TzAbstractFactoryTest::testCase_01 end!";

	return;
}

TZ_NAMESPACE_END(TzSoftTest)