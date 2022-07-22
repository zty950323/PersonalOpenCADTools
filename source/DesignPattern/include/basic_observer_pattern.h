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

// Subject 抽象基类， 只需要知道 TzObserver 基类声明就可以了。
class TzObserverSubject 
{
public:
	TzObserverSubject()
		: m_nSubjectState(-1)
	{
		
	}

 	virtual ~TzObserverSubject();

	void notify();											// 通知对象改变状态
	void attach(TzObserver* pObserver);		// 新增对象
	void detach(TzObserver* pObserver);		// 删除对象

	// 虚函数， 提供默认的实现， 派生类可以自己实现来覆盖基类的实现。
	virtual void setState(OBSERVER_STATE nState);			// 设置状态
	virtual OBSERVER_STATE getState();							// 得到状态

protected:
	OBSERVER_STATE m_nSubjectState = { 0 };							// 模拟保存 Subject 状态的常量。
	std::list<TzObserver*> m_listObserver;	// 保存 Observer 指针的链表。
};

// TzObserver 抽象基类
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

	// 纯虚函数， 从各个派生类可能有不同的实现。
	// 通知 TzObserver 状态发生了变化。
	virtual void update(TzObserverSubject* pSubject) = 0;
protected:
	OBSERVER_STATE m_nObserverState = { -1 };						// 模拟保存 TzObserver 状态的变量。
};

// ConcreateSubject 类， 派生在Subject类中
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

	// 派生类自己实现来覆盖基类的实现
	virtual void setState(OBSERVER_STATE nState) override;			// 设置状态
	virtual OBSERVER_STATE getState() override;							// 得到状态
};

// TzConcreateObserver 类派生子 TzObserver
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

	// 虚函数， 实现基类提供的接口
	virtual void update(TzObserverSubject* pSubject);
};

TZ_NAMESPACE_END(TzSoft)

#endif