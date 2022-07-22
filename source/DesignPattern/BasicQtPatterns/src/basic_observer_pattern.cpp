///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include "basic_observer_pattern.h"

#include <QtCore/QDebug>
#include <algorithm>

TZ_NAMESPACE_BEGIN(TzSoft)

/* --------------------------------------------------------------------
| TzObserverSubject 类成员函数的实现
|
----------------------------------------------------------------------*/

TzObserverSubject::~TzObserverSubject()
{
	std::list<TzObserver*>::iterator iter1, iter2, temp;

	for (iter1 = m_listObserver.begin(), iter2 = m_listObserver.end();
		iter1 != iter2;)
	{
		temp = iter1;
		++iter1;
		delete(*temp);
	}

	m_listObserver.clear();
}

void TzObserverSubject::notify()
{
	qDebug() << "Notify TzObserver's State";

	std::list<TzObserver*>::iterator iter1, iter2;

	for (iter1 = m_listObserver.begin(), iter2 = m_listObserver.end();
		iter1 != iter2;
		++iter1)
	{
		(*iter1)->update(this);
	}
}

void TzObserverSubject::attach(TzObserver* pObserver)
{
	qDebug() << "Attach an TzObserver.";

	m_listObserver.push_back(pObserver);
}

void TzObserverSubject::detach(TzObserver* pObserver)
{
	std::list<TzObserver*>::iterator iter;
	iter = std::find(m_listObserver.begin(), m_listObserver.end(), pObserver);

	if (m_listObserver.end() != iter)
	{
		m_listObserver.erase(iter);
	}

	qDebug() << "Detach an Observer.";
}

void TzObserverSubject::setState(OBSERVER_STATE nState)
{
	qDebug() << "SetState By Subject.";
	m_nSubjectState = nState;
}

OBSERVER_STATE TzObserverSubject::getState()
{
	qDebug() << "GetState By Subject.";
	return m_nSubjectState;
}

/* --------------------------------------------------------------------
| TzConcreateSubject 类成员函数的实现
|
----------------------------------------------------------------------*/

void TzConcreateSubject::setState(OBSERVER_STATE nState)
{
	qDebug() << "SetState By ConcreateSubject.";
	m_nSubjectState = nState;
}

OBSERVER_STATE TzConcreateSubject::getState()
{
	qDebug() << "GetState By ConcreateSubject.";
	return m_nSubjectState;
}

/* --------------------------------------------------------------------
| TzConcreateObserver 类成员函数的实现
|
----------------------------------------------------------------------*/

void TzConcreateObserver::update(TzObserverSubject* pSubject)
{
	if (nullptr == pSubject)
	{
		return;
	}

	m_nObserverState = pSubject->getState();

	qDebug() << "The ObeserverState is " << m_nObserverState;
}

TZ_NAMESPACE_END(TzSoft)