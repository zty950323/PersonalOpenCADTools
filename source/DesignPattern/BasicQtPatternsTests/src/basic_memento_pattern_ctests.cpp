///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include "basic_memento_pattern_ctests.h"

#include <QtCore/QDebug>

TZ_NAMESPACE_BEGIN(TzSoftTest)

void TzMementoTest::testCase_01(void)
{
	// ����һ��ԭ����
	TzSoft::TzOriginator* pOriginator = new TzSoft::TzOriginator("old state");
	pOriginator->printState();
	// ����һ������¼������ԭ������״̬
	TzSoft::TzMemento* pMemento = pOriginator->createMemento();

	// ����ԭ������״̬
	pOriginator->setState("new state");
	pOriginator->printState();
	// ͨ������¼��ԭ������״̬��ԭ��֮ǰ��״̬
	pOriginator->restoreState(pMemento);
	pOriginator->printState();
	delete pOriginator;
	delete pMemento;
	qDebug() << "TzMementoTest::testCase_01 end!";

	return;
}

TZ_NAMESPACE_END(TzSoftTest)