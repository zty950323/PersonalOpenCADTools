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
	// 创建一个原发器
	TzSoft::TzOriginator* pOriginator = new TzSoft::TzOriginator("old state");
	pOriginator->printState();
	// 创建一个备忘录存放这个原发器的状态
	TzSoft::TzMemento* pMemento = pOriginator->createMemento();

	// 更改原发器的状态
	pOriginator->setState("new state");
	pOriginator->printState();
	// 通过备忘录把原发器的状态还原到之前的状态
	pOriginator->restoreState(pMemento);
	pOriginator->printState();
	delete pOriginator;
	delete pMemento;
	qDebug() << "TzMementoTest::testCase_01 end!";

	return;
}

TZ_NAMESPACE_END(TzSoftTest)