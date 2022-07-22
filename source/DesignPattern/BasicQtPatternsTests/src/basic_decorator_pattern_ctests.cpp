///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include "basic_decorator_pattern_ctests.h"

#include <QtCore/QDebug>

TZ_NAMESPACE_BEGIN(TzSoftTest)

void TzDecoratorTest::testCase_01(void)
{
	// 初始化一个 Component 对象
	TzSoft::TzDecoratorComponent* pComponent = new TzSoft::TzConcreateDecoratorComponent();

	// 采用这个 Component 对象去初始化一个 Decorator 对象, 
	// 这样就可以为这个 Component 对象动态添加职责
	TzSoft::TzDecorator* pDecorator = new TzSoft::TzConcreateDecorator(pComponent);
	pDecorator->operation();

	delete pDecorator;
	pDecorator = nullptr;

	qDebug() << "TzDecoratorTest::testCase_01 end!";

	return;
}

TZ_NAMESPACE_END(TzSoftTest)