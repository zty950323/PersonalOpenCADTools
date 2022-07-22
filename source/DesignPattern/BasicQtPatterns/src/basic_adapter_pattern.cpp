///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include "basic_adapter_pattern_01.h"

#include <QtCore/QDebug>

TZ_NAMESPACE_BEGIN(TzSoft)

void TzAdaptee::specialRequest()
{
	qDebug() << "SpecialRequest of TzAdaptee.";
}

TzAdapter::TzAdapter(TzAdaptee* pAdaptee)
	: m_pAdptee(pAdaptee)
{

}

TzAdapter::~TzAdapter()
{
	delete m_pAdptee;
	m_pAdptee = nullptr;
}

void TzAdapter::request()
{
	qDebug() << "request of TzAdapter";

	m_pAdptee->specialRequest();
}

TZ_NAMESPACE_END(TzSoft)