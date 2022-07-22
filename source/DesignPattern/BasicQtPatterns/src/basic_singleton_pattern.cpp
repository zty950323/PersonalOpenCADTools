///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include "basic_singleton_pattern.h"

#include <QtCore/QDebug>

TZ_NAMESPACE_BEGIN(TzSoft)

TzSingleton* TzSingleton::m_pStatic = nullptr;

TzSingleton* TzSingleton::GetInstancePtr()
{
	if (nullptr == m_pStatic)
	{
		m_pStatic = new TzSingleton();
	}

	return m_pStatic;
}

TzSingleton TzSingleton::GetInstance()
{
	return *GetInstancePtr();
}

void TzSingleton::Test()
{
	qDebug() << "Test singleton!";
}

TZ_NAMESPACE_END(TzSoft)