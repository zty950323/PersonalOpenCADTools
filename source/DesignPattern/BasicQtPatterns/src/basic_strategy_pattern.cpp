///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include "basic_strategy_pattern.h"

#include <QtCore/QDebug>

TZ_NAMESPACE_BEGIN(TzSoft)

TzContext::TzContext(TzStrategy* pStrategy)
	: m_pStrategy(pStrategy)
{

}

TzContext::~TzContext()
{
	delete m_pStrategy;
	m_pStrategy = nullptr;
}

void TzContext::contextInterface()
{
	if (nullptr != m_pStrategy)
	{
		m_pStrategy->algorithmInterface();
	}
}

void TzConcreateStrategyA::algorithmInterface()
{
	qDebug() << "AlgorithmInterface Implemented by TzConcreateStrategyA";
}

TZ_NAMESPACE_END(TzSoft)