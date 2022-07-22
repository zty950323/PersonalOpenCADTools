///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#ifndef  BASIC_PROTOTYPE_H_H_ 
#define BASIC_PROTOTYPE_H_H_

#include "zsofts_compiler_specific.h"

TZ_NAMESPACE_BEGIN(TzSoft)

// 虚拟基类,所有原型的基类,提供 Clone 接口函数
class TzPrototype
{
public:
	TzPrototype() {}
	virtual ~TzPrototype() {}
	virtual TzPrototype* Clone() = 0;
};

// 派生自 Prototype,实现 Clone 方法
class TzConcreatePrototype1 : public TzPrototype
{
public:
	TzConcreatePrototype1();
	TzConcreatePrototype1(const TzConcreatePrototype1&);
	virtual ~TzConcreatePrototype1();
	virtual TzPrototype* Clone();
};

// 派生自 Prototype,实现 Clone 方法
class TzConcreatePrototype2 : public TzPrototype
{
public:
	TzConcreatePrototype2();
	TzConcreatePrototype2(const TzConcreatePrototype2&);
	virtual ~TzConcreatePrototype2();
	virtual TzPrototype* Clone();
};

TZ_NAMESPACE_END(TzSoft)

#endif