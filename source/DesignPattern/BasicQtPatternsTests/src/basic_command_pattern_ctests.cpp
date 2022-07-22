///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include "basic_command_pattern_ctests.h"

#include <QtCore/QDebug>

TZ_NAMESPACE_BEGIN(TzSoftTest)

void TzCommandTest::testCase_01(void)
{
	TzSoft::TzReceiver* pReceiver = new TzSoft::TzReceiver();
	TzSoft::TzCommand* pCommand = new TzSoft::TzConcreateCommand(pReceiver);
	TzSoft::TzInvoker* pInvoker = new TzSoft::TzInvoker(pCommand);

	pInvoker->invoke();

	delete pInvoker;
	pInvoker = nullptr;

	qDebug() << "TzAbstractFactoryTest::testCase_01 end!";

	return;
}

TZ_NAMESPACE_END(TzSoftTest)