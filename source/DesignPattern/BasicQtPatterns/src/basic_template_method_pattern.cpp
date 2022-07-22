///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include "basic_template_method_pattern.h"

#include <QtCore/QDebug>

TZ_NAMESPACE_BEGIN(TzSoft)

void TzAbstractClass::templateMethod()
{
	primitiveOperation1();
	primitiveOperation2();
}

void TzConcreateClass::primitiveOperation1()
{
	qDebug() << "PrimitiveOperation1 by ConcreateClass";
}

void TzConcreateClass::primitiveOperation2()
{
	qDebug() << "PrimitiveOperation2 by ConcreateClass";
}

TZ_NAMESPACE_END(TzSoft)