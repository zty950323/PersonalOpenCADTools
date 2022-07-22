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

// ����еĳ������
class TzComponent
{
public:
	TzComponent() {}
	virtual ~TzComponent() {}
	// ���麯��,ֻ�ṩ�ӿ�,û��Ĭ�ϵ�ʵ��
	virtual void operation() = 0;
	// �麯��,�ṩ�ӿ�,��Ĭ�ϵ�ʵ�־���ʲô������
	virtual void add(TzComponent* pChild);
	virtual void remove(TzComponent* pChild);
	virtual TzComponent* getChild(int nIndex);
};

// ������ Component,�����е�Ҷ������Ļ���
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

// ������ Component,�����еĺ����Ӽ�������Ļ���
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
	// ���� list ����ȥ���������
	std::list<TzComponent*> m_ListOfComponent;
};

TZ_NAMESPACE_END(TzSoft)

#endif