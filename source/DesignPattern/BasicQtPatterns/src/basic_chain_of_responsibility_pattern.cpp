///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include "basic_chain_of_responsibility_pattern.h"
#include "tzsofts_debug_utils.h"

#include <QtCore/QDebug>

TZ_NAMESPACE_BEGIN(TzSoft)

TzHandler::TzHandler(TzHandler* pSuccessor /* = nullptr */)
	: m_pSuccessor(pSuccessor)
{

}

TzHandler::~TzHandler()
{
	delete m_pSuccessor;
	m_pSuccessor = nullptr;
}

void TzConcreateHandler1::handleRequest()
{
	TZ_ASSERT(m_pSuccessor);
	if (nullptr != m_pSuccessor)
	{
		m_pSuccessor->handleRequest();
	}
	else
	{
		qDebug() << "HandleRequset by ConcreateHandler1";
	}
}

void TzConcreateHandler2::handleRequest()
{
	TZ_ASSERT(m_pSuccessor);
	if (nullptr != m_pSuccessor)
	{
		m_pSuccessor->handleRequest();
	}
	else
	{
		qDebug() << "HandleRequset by ConcreateHandler2";
	}
}

TZ_NAMESPACE_END(TzSoft)