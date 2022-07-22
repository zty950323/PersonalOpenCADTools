///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#ifndef _BASIC_FACTORY_PATTERN_H_H_
#define _BASIC_FACTORY_PATTERN_H_H_

#include "zsofts_compiler_specific.h"

TZ_NAMESPACE_BEGIN(TzSoft)

class TzFactoryPatternProduct
{
public:
	TzFactoryPatternProduct() 
	{

	}
	virtual ~TzFactoryPatternProduct()
	{

	}
};

class TzFactoryPattrenConcreateProduct : public TzFactoryPatternProduct
{
public:
	TzFactoryPattrenConcreateProduct();
	virtual ~TzFactoryPattrenConcreateProduct();

};

class TzFactoryPattrenCreator
{
public:
	TzFactoryPattrenCreator()
	{

	}
	virtual ~TzFactoryPattrenCreator()
	{

	}

	void anOperatrion();

protected:
	virtual TzFactoryPatternProduct* FactoryMeghod() = 0;
};

class TzFactoryPattrenConcreateCreator : public TzFactoryPattrenCreator
{
public:
	TzFactoryPattrenConcreateCreator();
	virtual ~TzFactoryPattrenConcreateCreator();

protected:
	virtual TzFactoryPatternProduct* FactoryMeghod();
};

TZ_NAMESPACE_END(TzSoft)

#endif