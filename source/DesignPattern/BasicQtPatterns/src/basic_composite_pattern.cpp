///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include "basic_composite_pattern.h"

#include <QtCore/QDebug>
#include <algorithm>

TZ_NAMESPACE_BEGIN(TzSoft)

/*-------------------------------------------------------------------
 Component 成员函数的实现
-------------------------------------------------------------------*/

void TzComponent::add(TzComponent* pChild)
{

}

void TzComponent::remove(TzComponent* pChild)
{

}

TzComponent* TzComponent::getChild(int nIndex)
{
	return nullptr;
}

/*-------------------------------------------------------------------
 Leaf 成员函数的实现
-------------------------------------------------------------------*/

void TzLeaf::operation()
{
	qDebug() << "operation by leaf";
}

/*-------------------------------------------------------------------
 Composite 成员函数的实现
-------------------------------------------------------------------*/

TzComposite::~TzComposite()
{
	std::list<TzComponent*>::iterator iter1, iter2, temp;
	for (iter1 = m_ListOfComponent.begin(), iter2 = m_ListOfComponent.end();
		iter1 != iter2;
		)
	{
		temp = iter1;
		++iter1;
		delete (*temp);
	}
}

void TzComposite::add(TzComponent* pChild)
{
	m_ListOfComponent.push_back(pChild);
}

void TzComposite::remove(TzComponent* pChild)
{
	std::list<TzComponent*>::iterator iter;
	iter = find(m_ListOfComponent.begin(), m_ListOfComponent.end(), pChild);

	if (m_ListOfComponent.end() != iter)
	{
		m_ListOfComponent.erase(iter);
	}
}

TzComponent* TzComposite::getChild(int nIndex)
{
	if (nIndex <= 0 || nIndex > m_ListOfComponent.size())
	{
		return nullptr;
	}

	std::list<TzComponent*>::iterator iter1, iter2;
	int i;
	for (i = 1, iter1 = m_ListOfComponent.begin(), iter2 = m_ListOfComponent.end();
		iter1 != iter2;
		++iter1, ++i)
	{
		if (i == nIndex)
		{
			break;
		}
	}
	return *iter1;
}

void TzComposite::operation()
{
	qDebug() << "Operation by Composite";

	std::list<TzComponent*>::iterator iter1, iter2;

	for (iter1 = m_ListOfComponent.begin(), iter2 = m_ListOfComponent.end();
		iter1 != iter2;
		++iter1)
	{
		(*iter1)->operation();
	}
}

TZ_NAMESPACE_END(TzSoft)