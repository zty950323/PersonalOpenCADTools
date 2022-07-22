///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#ifndef _BASIC_SINGLETON_PATTERN_H_H_
#define _BASIC_SINGLETON_PATTERN_H_H_

#include "zsofts_compiler_specific.h"

TZ_NAMESPACE_BEGIN(TzSoft)

class TzSingleton
{
public:
	TzSingleton()
	{

	};

	~TzSingleton() 
	{

	};

	// 静态成员函数,提供全局访问的接口
	static TzSingleton* GetInstancePtr();
	static TzSingleton GetInstance();
	void Test();

private:
	// 静态成员变量,提供全局惟一的一个实例
	static TzSingleton* m_pStatic;
};

TZ_NAMESPACE_END(TzSoft)

#endif