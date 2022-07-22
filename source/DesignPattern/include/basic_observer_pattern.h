///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#ifndef _BASIC_OBSERVER_PATTERN_H_H_
#define _BASIC_OBSERVER_PATTERN_H_H_

#include "zsofts_compiler_specific.h"

#include <list>

TZ_NAMESPACE_BEGIN(TzSoft)

using OBSERVER_STATE = int;

class TzObserver;

// Subject ������࣬ ֻ��Ҫ֪�� TzObserver ���������Ϳ����ˡ�
class TzObserverSubject 
{
public:
	TzObserverSubject()
		: m_nSubjectState(-1)
	{
		
	}

 	virtual ~TzObserverSubject();

	void notify();											// ֪ͨ����ı�״̬
	void attach(TzObserver* pObserver);		// ��������
	void detach(TzObserver* pObserver);		// ɾ������

	// �麯���� �ṩĬ�ϵ�ʵ�֣� ����������Լ�ʵ�������ǻ����ʵ�֡�
	virtual void setState(OBSERVER_STATE nState);			// ����״̬
	virtual OBSERVER_STATE getState();							// �õ�״̬

protected:
	OBSERVER_STATE m_nSubjectState = { 0 };							// ģ�Ᵽ�� Subject ״̬�ĳ�����
	std::list<TzObserver*> m_listObserver;	// ���� Observer ָ�������
};

// TzObserver �������
class TzObserver
{
public:
	TzObserver()
		: m_nObserverState(-1)
	{

	}

	virtual ~TzObserver()
	{

	}

	// ���麯���� �Ӹ�������������в�ͬ��ʵ�֡�
	// ֪ͨ TzObserver ״̬�����˱仯��
	virtual void update(TzObserverSubject* pSubject) = 0;
protected:
	OBSERVER_STATE m_nObserverState = { -1 };						// ģ�Ᵽ�� TzObserver ״̬�ı�����
};

// ConcreateSubject �࣬ ������Subject����
class TzConcreateSubject : public TzObserverSubject
{
public:
	TzConcreateSubject() 
		: TzObserverSubject()
	{

	}

	virtual ~TzConcreateSubject()
	{

	}

	// �������Լ�ʵ�������ǻ����ʵ��
	virtual void setState(OBSERVER_STATE nState) override;			// ����״̬
	virtual OBSERVER_STATE getState() override;							// �õ�״̬
};

// TzConcreateObserver �������� TzObserver
class TzConcreateObserver : public TzObserver
{
public:
	TzConcreateObserver()
		: TzObserver()
	{

	}

	virtual ~TzConcreateObserver()
	{

	}

	// �麯���� ʵ�ֻ����ṩ�Ľӿ�
	virtual void update(TzObserverSubject* pSubject);
};

TZ_NAMESPACE_END(TzSoft)

#endif