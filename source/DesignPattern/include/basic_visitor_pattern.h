///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#ifndef _BASIC_VISITOR_PATTERN_H_H_
#define _BASIC_VISITOR_PATTERN_H_H_

#include "zsofts_compiler_specific.h"

TZ_NAMESPACE_BEGIN(TzSoft)

class TzVisitor;

class TzVisitorElement
{
public:
	virtual ~TzVisitorElement()
	{

	}

	virtual void accept(TzVisitor& rVisitor) = 0;

protected:
	TzVisitorElement()
	{

	}
};

class TzConcreateElementA : public TzVisitorElement
{
public:
	virtual ~TzConcreateElementA()
	{

	}

	virtual void accept(TzVisitor& rVisitor);
};

class TzConcreateElementB : public TzVisitorElement
{
public:
	virtual ~TzConcreateElementB()
	{

	}

	virtual void accept(TzVisitor& rVisitor);
};

class TzVisitor
{
public:
	virtual ~TzVisitor()
	{

	}

	virtual void visitConcreateElementA(TzConcreateElementA* pConcreateElementA) = 0;
	virtual void visitConcreateElementB(TzConcreateElementB* pConcreateElementB) = 0;

protected:
	TzVisitor()
	{

	}
};

class TzConcreateVisitorA : public TzVisitor
{
public:
	virtual ~TzConcreateVisitorA()
	{

	}

	virtual void visitConcreateElementA(TzConcreateElementA* pConcreateElementA) override;
	virtual void visitConcreateElementB(TzConcreateElementB* pConcreateElementB) override;
};

class TzConcreateVisitorB : public TzVisitor
{
public:
	virtual ~TzConcreateVisitorB()
	{

	}

	virtual void visitConcreateElementA(TzConcreateElementA* pConcreateElementA) override;
	virtual void visitConcreateElementB(TzConcreateElementB* pConcreateElementB) override;
};

TZ_NAMESPACE_END(TzSoft)

#endif