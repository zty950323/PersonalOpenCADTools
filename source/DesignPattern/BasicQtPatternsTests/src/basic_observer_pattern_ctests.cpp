///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include "basic_observer_pattern_ctests.h"

#include <QtCore/QDebug>

TZ_NAMESPACE_BEGIN(TzSoftTest)

void TzObserverTest::testCase_01(void)
{
	TzSoft::TzObserver* p1 = new TzSoft::TzConcreateObserver();
	TzSoft::TzObserver* p2 = new TzSoft::TzConcreateObserver();

	TzSoft::TzObserverSubject* p = new TzSoft::TzConcreateSubject();

	p->attach(p1);
	p->attach(p2);
	p->setState(4);
	p->notify();

	p->detach(p1);
	p->setState(10);
	p->notify();

	delete p;
	p = nullptr;

	qDebug() << "TzObserverTest::testCase_01 end!";

	return;
}

TZ_NAMESPACE_END(TzSoftTest)