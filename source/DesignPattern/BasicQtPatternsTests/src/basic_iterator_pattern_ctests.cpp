///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include "basic_iterator_pattern_ctests.h"

#include <QtCore/QDebug>

TZ_NAMESPACE_BEGIN(TzSoftTest)

void TzIteratorTest::testCase_01(void)
{
	TzSoft::TzAggregate* pAggregate = new TzSoft::TzConcreateAggregate(4);
	TzSoft::TzIterater* pIterator = new TzSoft::TzConcreateIterater(pAggregate);

	for (; false == pIterator->isDone();  pIterator->next())
	{
		qDebug() << pIterator->currentItem();
	}

	qDebug() << "TzIteratorTest::testCase_01 end!";

	return;
}

TZ_NAMESPACE_END(TzSoftTest)