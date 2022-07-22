///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include "basic_bridge_pattern.h"

#include <QtCore/QDebug>

TZ_NAMESPACE_BEGIN(TzSoft)

TzAbstraction::TzAbstraction(TzAbstractionImpl* pImplementor)
	: m_pImplementor(pImplementor)
{

}

TzAbstraction::~TzAbstraction()
{
	delete m_pImplementor;
	m_pImplementor = nullptr;
}

void TzAbstraction::operation()
{
	m_pImplementor->operationImpl();
}

void TzConcreateImplementorA::operationImpl()
{
	qDebug() << "Implementation by ConcreateImplementorA";
}

void TzConcreateImplementorB::operationImpl()
{
	qDebug() << "Implementation by ConcreateImplementorB";
}

TZ_NAMESPACE_END(TzSoft)