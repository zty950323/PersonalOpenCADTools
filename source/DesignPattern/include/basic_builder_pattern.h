///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#ifndef  BASIC_BUILDER_H_H_
#define BASIC_BUILDER_H_H_

#include "zsofts_compiler_specific.h"

TZ_NAMESPACE_BEGIN(TzSoft)

// �������,������ Builder �Ļ���,�ṩ��ͬ���ֵĹ����ӿں���
class TzBuilder
{
public:
	TzBuilder() {};
	virtual ~TzBuilder() {}
	// ���麯��,�ṩ������ͬ���ֵĹ����ӿں���
	virtual void builderPartA() = 0;
	virtual void builderPartB() = 0;
};

// ʹ�� Builder ������Ʒ,������Ʒ�Ĺ��̶�һ��,���ǲ�ͬ�� builder �в�ͬ��ʵ��
// �����ͬ��ʵ��ͨ����ͬ�� Builder ��������ʵ��,����һ�� Builder ��ָ��,ͨ�������
// ʵ�ֶ�̬���� 
class TzDirector
{
public:
	TzDirector(TzBuilder* pBuilder);
	~TzDirector();
	void Construct();
private:
	TzBuilder* m_pBuilder = { nullptr };
};

// Builder ��������,ʵ�� BuilderPartA �� BuilderPartB �ӿں���
class TzConcreateBuilder1 : public TzBuilder
{
public:
	TzConcreateBuilder1()
	{

	}

	virtual ~TzConcreateBuilder1()
	{

	}

	virtual void builderPartA() override;
	virtual void builderPartB() override;
};

// Builder ��������,ʵ�� BuilderPartA �� BuilderPartB �ӿں���
class TzConcreateBuilder2 : public TzBuilder
{
public:
	TzConcreateBuilder2()
	{

	}

	virtual ~TzConcreateBuilder2()
	{

	}

	virtual void builderPartA() override;
	virtual void builderPartB() override;
};

TZ_NAMESPACE_END(TzSoft)

#endif