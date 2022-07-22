///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include "basic_flyweight_pattern_ctests.h"

#include <QtCore/QDebug>

TZ_NAMESPACE_BEGIN(TzSoftTest)

void TzFlyweightTest::testCase_01(void)
{
	TzSoft::TzFlyweightFacytory flyweightFactory;
	flyweightFactory.getFlyweight("Hello ");
	flyweightFactory.getFlyweight("World ");
	flyweightFactory.getFlyweight("This is a flyweight pattern, I am Tom Zhao.");

	qDebug() << "TzFlyweightTest::testCase_01 end!";

	return;
}

TZ_NAMESPACE_END(TzSoftTest)