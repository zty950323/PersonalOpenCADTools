///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#ifndef  BASIC_COMPONENT_H_H_
#define BASIC_COMPONENT_H_H_

#include "zsofts_compiler_specific.h"

#include <list>

TZ_NAMESPACE_BEGIN(TzSoft)

// 组合中的抽象基类
class TzComponent
{
public:
	TzComponent() {}
	virtual ~TzComponent() {}
	// 纯虚函数,只提供接口,没有默认的实现
	virtual void operation() = 0;
	// 虚函数,提供接口,有默认的实现就是什么都不做
	virtual void add(TzComponent* pChild);
	virtual void remove(TzComponent* pChild);
	virtual TzComponent* getChild(int nIndex);
};

// 派生自 Component,是其中的叶子组件的基类
class TzLeaf : public TzComponent
{
public:
	TzLeaf()
	{

	}

	virtual ~TzLeaf()
	{

	}

	virtual void operation() override;
};

// 派生自 Component,是其中的含有子件的组件的基类
class TzComposite : public TzComponent
{
public:
	TzComposite() {}
	virtual ~TzComposite();
	virtual void operation();
	virtual void add(TzComponent* pChild);
	virtual void remove(TzComponent* pChild);
	virtual TzComponent* getChild(int nIndex);
private:
	// 采用 list 容器去保存子组件
	std::list<TzComponent*> m_ListOfComponent;
};

TZ_NAMESPACE_END(TzSoft)

#endif