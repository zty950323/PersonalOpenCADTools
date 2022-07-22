///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include "basic_decorator_pattern.h"

#include <QtCore/QDebug>

TZ_NAMESPACE_BEGIN(TzSoft)

TzDecorator::~TzDecorator()
{
	delete m_pComponent;
	m_pComponent = nullptr;
}

void TzConcreateDecoratorComponent::operation()
{
	qDebug() << "Operation of TzConcreateDecoratorComponent";
}

void TzConcreateDecorator::operation()
{
	m_pComponent->operation();
	addedBehavior();
}

void TzConcreateDecorator::addedBehavior()
{
	qDebug() << "AddedBehavior of TzConcreateDecorator";
}

TZ_NAMESPACE_END(TzSoft)