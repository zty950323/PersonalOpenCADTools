///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include "basic_adapter_pattern_ctests.h"

#include <QtCore/QDebug>

TZ_NAMESPACE_BEGIN(TzSoftTest)

void TzAdapter01Test::testCase_01(void)
{
	TzSoft::TzAdaptee* pAdaptee = new TzSoft::TzAdaptee;
	TzSoft::TzTarget* pTarget = new TzSoft::TzAdapter(pAdaptee);

	pTarget->request();

	delete pTarget;
	pTarget = nullptr;

	qDebug() << "TzAdapter01Test::testCase_01 end!";

	return;
}

TZ_NAMESPACE_END(TzSoftTest)