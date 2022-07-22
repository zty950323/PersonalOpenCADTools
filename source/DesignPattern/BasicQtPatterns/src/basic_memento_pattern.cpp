///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include "basic_memento_pattern.h"

#include <QtCore/QDebug>

TZ_NAMESPACE_BEGIN(TzSoft)

TzOriginator::TzOriginator()
{

}

TzOriginator::TzOriginator(const State& rState)
	: m_state(rState)
{

}

TzOriginator::~TzOriginator()
{

}

State TzOriginator::getState() const
{
	return m_state;
}

void TzOriginator::setState(const State& rState)
{
	m_state = rState;
}

TzMemento* TzOriginator::createMemento()
{
	return new TzMemento(m_state);
}

void TzOriginator::restoreState(TzMemento* pMemento)
{
	if (nullptr != pMemento)
	{
		m_state = pMemento->getState();
	}
}

void TzOriginator::printState() const 
{
	qDebug() << "State =" << QString::fromStdString(m_state);
}

//////////////////////////////////////////////////////////////////////////
TzMemento::TzMemento(const State& rState)
	: m_state(rState)
{

}

State TzMemento::getState() const
{
	return m_state;
}

void TzMemento::setState(const State& rState)
{
	m_state = rState;
}

TZ_NAMESPACE_END(TzSoft)