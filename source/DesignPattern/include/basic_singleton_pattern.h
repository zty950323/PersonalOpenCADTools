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

	// ��̬��Ա����,�ṩȫ�ַ��ʵĽӿ�
	static TzSingleton* GetInstancePtr();
	static TzSingleton GetInstance();
	void Test();

private:
	// ��̬��Ա����,�ṩȫ��Ωһ��һ��ʵ��
	static TzSingleton* m_pStatic;
};

TZ_NAMESPACE_END(TzSoft)

#endif