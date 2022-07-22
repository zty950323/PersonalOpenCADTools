///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include "basic_singleton_pattern_ctests.h"

#include <QtCore/QDebug>

TZ_NAMESPACE_BEGIN(TzSoftTest)

void TzSingletonTest::testCase_01(void)
{
	TzSoft::TzSingleton::GetInstancePtr()->Test();
	TzSoft::TzSingleton::GetInstance().Test();

	qDebug() << "TzSingletonTest::testCase_01 end!";

	return;
}

TZ_NAMESPACE_END(TzSoftTest)