///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include "basic_flyweight_pattern.h"

#include <QtCore/QDebug>

TZ_NAMESPACE_BEGIN(TzSoft)

STATE TzFlyweight::getIntrinsicState()
{
	return m_state;
}

TzFlyweightFacytory::~TzFlyweightFacytory()
{
	std::list<TzFlyweight*>::iterator iter1, iter2, temp;

	for (iter1 = m_listFlyweight.begin(), iter2 = m_listFlyweight.end();
		iter1 != iter2;)
	{
		temp = iter1;
		++iter1;
		delete (*temp);
	}

	m_listFlyweight.clear();
}

TzFlyweight* TzFlyweightFacytory::getFlyweight(const STATE& key)
{
	std::list<TzFlyweight*>::iterator iter1, iter2;

	for (iter1 = m_listFlyweight.begin(), iter2 = m_listFlyweight.end();
		iter1 != iter2;
		++iter1)
	{
		if ((*iter1)->getIntrinsicState() == key)
		{
			qDebug() << "The TzFlyweight: " << QString::fromStdString( key ) << " already exits";
			return (*iter1);
		}
	}

	qDebug() << "Creating a new TzFlyweight: " << QString::fromStdString(key);
	TzFlyweight* flyweight = new TzConcreateFlyweight(key);
	m_listFlyweight.push_back(flyweight);
	return flyweight;
}


void TzConcreateFlyweight::operation(STATE& extrinsicState)
{
	qDebug() << QString::fromStdString(extrinsicState);
}

TZ_NAMESPACE_END(TzSoft)