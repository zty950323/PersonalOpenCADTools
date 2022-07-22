///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include "basic_visitor_pattern.h"

#include <QtCore/QDebug>

TZ_NAMESPACE_BEGIN(TzSoft)

void TzConcreateElementA::accept(TzVisitor& rVisitor)
{
	rVisitor.visitConcreateElementA(this);
}

void TzConcreateElementB::accept(TzVisitor& rVisitor)
{
	rVisitor.visitConcreateElementB(this);
}

void TzConcreateVisitorA::visitConcreateElementA(TzConcreateElementA* pConcreateElementA)
{
	qDebug() << "VisitConcreateElementA By ConcreateVisitorA";
}

void TzConcreateVisitorA::visitConcreateElementB(TzConcreateElementB* pConcreateElementB)
{
	qDebug() << "VisitConcreateElementB By ConcreateVisitorA";
}

void TzConcreateVisitorB::visitConcreateElementA(TzConcreateElementA* pConcreateElementA)
{
	qDebug() << "VisitConcreateElementA By ConcreateVisitorB";
}

void TzConcreateVisitorB::visitConcreateElementB(TzConcreateElementB* pConcreateElementB)
{
	qDebug() << "VisitConcreateElementB By ConcreateVisitorB";
}

TZ_NAMESPACE_END(TzSoft)