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
	// ��ʼ��һ�� Component ����
	TzSoft::TzDecoratorComponent* pComponent = new TzSoft::TzConcreateDecoratorComponent();

	// ������� Component ����ȥ��ʼ��һ�� Decorator ����, 
	// �����Ϳ���Ϊ��� Component ����̬���ְ��
	TzSoft::TzDecorator* pDecorator = new TzSoft::TzConcreateDecorator(pComponent);
	pDecorator->operation();

	delete pDecorator;
	pDecorator = nullptr;

	qDebug() << "TzDecoratorTest::testCase_01 end!";

	return;
}

TZ_NAMESPACE_END(TzSoftTest)