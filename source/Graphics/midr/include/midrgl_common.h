///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
// This is a common file for some macros are defined for the smallest 
// graphics rendering engine.
///////////////////////////////////////////////////////////////////////////////////////////

#ifndef _MIDR_GL_COMMON_H_H_
#define _MIDR_GL_COMMON_H_H_

#define TZ_MIDR_GL_DECLARE_IMP(Class)	\
	friend class Class##Impl;	\
	Class##Impl* m_pImpl

#define TZ_MIDR_GL_DECLARE_FACADE(Class)		\
	Class* m_pFacade

#define TZ_MIDR_GL_DISABLE_COPY_MOVE(Class)	\
	Class(const Class&) = delete;			\
	Class& operator = (const Class&) = delete;	\
	Class(Class&&) = delete;		\
	Class& operator = (Class&&) = delete	\

/*
	Avoid "unused parameter" warnings.
*/
#define TZRGL_UNUSED(x) (void)x;
#define TZRGL_SAFE_DELETE(p) if (p) { delete p; p = nullptr; }

#endif