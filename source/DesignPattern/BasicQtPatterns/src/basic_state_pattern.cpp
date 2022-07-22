///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include "basic_state_pattern.h"

#include <QtCore/QDebug>

TZ_NAMESPACE_BEGIN(TzSoft)

TzStateContext::TzStateContext(TzState* pState)
	: m_pState(pState)
{

}

TzStateContext::~TzStateContext()
{
	delete m_pState;
	m_pState = nullptr;
}

void TzStateContext::request()
{
	if (nullptr != m_pState)
	{
		m_pState->handle(this);
	}
}

void TzStateContext::changeState(TzState* pState)
{
	if (nullptr != m_pState)
	{
		delete m_pState;
		m_pState = nullptr;
	}

	m_pState = pState;
}

void TzConcreateStateA::handle(TzStateContext* pContext)
{
	qDebug() << "Handle by ConcreateStateA.";

	if (nullptr != pContext)
	{
		pContext->changeState(new TzConcreateStateB());
	}
}

void TzConcreateStateB::handle(TzStateContext* pContext)
{
	qDebug() << "Handle by ConcreateStateB.";

	if (nullptr != pContext)
	{
		pContext->changeState(new TzConcreateStateA());
	}
}

TZ_NAMESPACE_END(TzSoft)