///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include "basic_prototype_pattern.h"

#include <QtCore/QDebug>

TZ_NAMESPACE_BEGIN(TzSoft)

TzConcreatePrototype1::TzConcreatePrototype1()
{
	qDebug() << "construction of ConcreatePrototype1";
}

TzConcreatePrototype1::TzConcreatePrototype1(const TzConcreatePrototype1&)
{
	qDebug() << "copy construction of ConcreatePrototype1";
}

TzConcreatePrototype1::~TzConcreatePrototype1()
{
	qDebug() << "destruction of ConcreatePrototype1";
}

TzPrototype* TzConcreatePrototype1::Clone()
{
	return new TzConcreatePrototype1(*this);
}

/// <summary>
/// 
/// </summary>

TzConcreatePrototype2::TzConcreatePrototype2()
{
	qDebug() << "copy construction of ConcreatePrototype2";
}

TzConcreatePrototype2::TzConcreatePrototype2(const TzConcreatePrototype2&)
{
	qDebug() << "copy construction of ConcreatePrototype2";
}

TzConcreatePrototype2::~TzConcreatePrototype2()
{
	qDebug() << "destruction of ConcreatePrototype2";
}

TzPrototype* TzConcreatePrototype2::Clone()
{
	return new TzConcreatePrototype2(*this);
}

TZ_NAMESPACE_END(TzSoft)