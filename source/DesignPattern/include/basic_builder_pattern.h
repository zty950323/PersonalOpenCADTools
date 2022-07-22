///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#ifndef  BASIC_BUILDER_H_H_
#define BASIC_BUILDER_H_H_

#include "zsofts_compiler_specific.h"

TZ_NAMESPACE_BEGIN(TzSoft)

// 虚拟基类,是所有 Builder 的基类,提供不同部分的构建接口函数
class TzBuilder
{
public:
	TzBuilder() {};
	virtual ~TzBuilder() {}
	// 纯虚函数,提供构建不同部分的构建接口函数
	virtual void builderPartA() = 0;
	virtual void builderPartB() = 0;
};

// 使用 Builder 构建产品,构建产品的过程都一致,但是不同的 builder 有不同的实现
// 这个不同的实现通过不同的 Builder 派生类来实现,存有一个 Builder 的指针,通过这个来
// 实现多态调用 
class TzDirector
{
public:
	TzDirector(TzBuilder* pBuilder);
	~TzDirector();
	void Construct();
private:
	TzBuilder* m_pBuilder = { nullptr };
};

// Builder 的派生类,实现 BuilderPartA 和 BuilderPartB 接口函数
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

// Builder 的派生类,实现 BuilderPartA 和 BuilderPartB 接口函数
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