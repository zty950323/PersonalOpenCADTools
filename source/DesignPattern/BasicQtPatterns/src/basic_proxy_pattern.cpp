///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include "basic_proxy_pattern.h"

#include <QtCore/QDebug>

TZ_NAMESPACE_BEGIN(TzSoft)

TzRealSubject::TzRealSubject()
{
	qDebug() << "Constructing a RealSubject";
}

TzRealSubject::~TzRealSubject()
{

}

void TzRealSubject::request()
{
	qDebug() << "Request By RealSubject";
}

TzProxy::TzProxy()
	: m_pRealSubject(nullptr)
{
	qDebug() << "Constructing a Proxy";
}

TzProxy::~TzProxy()
{
	delete m_pRealSubject;
	m_pRealSubject = nullptr;
}

void TzProxy::request()
{
	if (nullptr == m_pRealSubject)
	{
		qDebug() << "Request By Proxy";
		m_pRealSubject = new TzRealSubject();
	}
	m_pRealSubject->request();
}

TZ_NAMESPACE_END(TzSoft)