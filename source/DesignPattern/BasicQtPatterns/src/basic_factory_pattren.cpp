///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include "basic_factory_pattern.h"

#include <QtCore/QDebug>

TZ_NAMESPACE_BEGIN(TzSoft)

TzFactoryPattrenConcreateProduct::TzFactoryPattrenConcreateProduct()
{
	qDebug() << " construction of  ConcreateProduct";
}

TzFactoryPattrenConcreateProduct::~TzFactoryPattrenConcreateProduct()
{
	qDebug() << " construction of  ConcreateProduct";
}

void TzFactoryPattrenCreator::anOperatrion()
{
	TzFactoryPatternProduct* p = FactoryMeghod();

	qDebug() << " an operation of product";
}

TzFactoryPattrenConcreateCreator::TzFactoryPattrenConcreateCreator()
{
	qDebug() << " construction of  ConcreateCreator";
}

TzFactoryPattrenConcreateCreator::~TzFactoryPattrenConcreateCreator()
{
	qDebug() << " destruction of  ConcreateCreator";
}

TzFactoryPatternProduct* TzFactoryPattrenConcreateCreator::FactoryMeghod()
{
	return new TzFactoryPattrenConcreateProduct();
}

TZ_NAMESPACE_END(TzSoft)