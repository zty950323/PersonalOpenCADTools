///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include "basic_factory_pattern_ctests.h"

#include <QtCore/QDebug>

TZ_NAMESPACE_BEGIN(TzSoftTest)

void TzFactoryTest::testCase_01(void)
{
	TzSoft::TzFactoryPattrenCreator* p = new TzSoft::TzFactoryPattrenConcreateCreator();
	p->anOperatrion();

	delete p;
	p = nullptr;

	qDebug() << "TzFactoryTest::testCase_01 end!";

	return;
}

TZ_NAMESPACE_END(TzSoftTest)