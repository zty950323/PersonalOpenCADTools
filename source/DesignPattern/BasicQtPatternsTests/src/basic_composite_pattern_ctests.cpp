///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include "basic_composite_pattern_ctests.h"

#include <QtCore/QDebug>

TZ_NAMESPACE_BEGIN(TzSoftTest)

void TzCompositeTest::testCase_01(void)
{
	TzSoft::TzLeaf* pLeaf1 = new TzSoft::TzLeaf();
	TzSoft::TzLeaf* pLeaf2 = new TzSoft::TzLeaf();

	TzSoft::TzComposite* pComposite = new TzSoft::TzComposite;
	pComposite->add(pLeaf1);
	pComposite->add(pLeaf2);
	pComposite->operation();
	pComposite->getChild(2)->operation();

	delete pComposite;
	pComposite = nullptr;

	qDebug() << "TzCompositeTest::testCase_01 end!";

	return;
}

TZ_NAMESPACE_END(TzSoftTest)