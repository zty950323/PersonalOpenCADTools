///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include "basic_builder_pattern_ctests.h"

#include <QtCore/QDebug>

TZ_NAMESPACE_BEGIN(TzSoftTest)

void TzBuilderTest::testCase_01(void)
{
	TzSoft::TzBuilder* pBuilder1 = new TzSoft::TzConcreateBuilder1;
	TzSoft::TzDirector* pDirector1 = new TzSoft::TzDirector(pBuilder1);
	pDirector1->Construct();

	TzSoft::TzBuilder* pBuilder2 = new TzSoft::TzConcreateBuilder2;
	TzSoft::TzDirector* pDirector2 = new TzSoft::TzDirector(pBuilder2);
	pDirector2->Construct();

	delete pDirector1;
	pDirector1 = nullptr;
	delete pDirector2;
	pDirector2 = nullptr;

	qDebug() << "TzBuilderTest::testCase_01 end!";

	return;
}

TZ_NAMESPACE_END(TzSoftTest)