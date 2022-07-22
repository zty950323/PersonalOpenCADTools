///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include "basic_proxy_pattern_ctests.h"

#include <QtCore/QDebug>

TZ_NAMESPACE_BEGIN(TzSoftTest)

void TzProxyTest::testCase_01(void)
{
	TzSoft::TzSubject* pProxy = new TzSoft::TzProxy();
	pProxy->request();

	delete pProxy;
	pProxy = nullptr;

	qDebug() << "TzProxyTest::testCase_01 end!";

	return;
}

TZ_NAMESPACE_END(TzSoftTest)