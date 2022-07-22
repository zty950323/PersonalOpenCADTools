///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#ifndef _MIDR_GL_UTIL_H_H_
#define _MIDR_GL_UTIL_H_H_

#include <type_traits>

#define TZ_MIDR_GL_D()	\
	using __d_type = std::remove_pointer<decltype(this->m_pImpl)>::type;		\
	using __d_ctype = std::add_const<__d_type>::type;		\
	using __d_pointer = std::add_pointer<__d_type>::type;			\
	using __d_cpointer = std::add_pointer<__d_ctype>::type;		\
	using __type = std::conditional<std::is_const<std::remove_pointer<decltype(this)>::type>::value, __d_cpointer, __d_pointer>::type;		\
	__type d = reinterpret_cast<__type>(this->m_pImpl)

#define TZ_MIDR_GL_DOWN_D(DownType)		\
	using __d_type = DownType;		\
	using __d_ctype = std::add_const<__d_type>::type;		\
	using __d_pointer = std::add_pointer<__d_type>::type;		\
	using __d_cpointer = std::add_pointer<__d_ctype>::type;		\
	using __type = std::conditional<std::is_const<std::remove_pointer<decltype(this)>::type>::value, __d_cpointer, __d_pointer>::type;		\

#define TZ_MIDR_GL_Q()		\
	using __d_type = std::remove_pointer<decltype(this->m_pFacade)>::type;		\
	using __d_ctype = std::add_const<__d_type>::type;		\
	using __d_pointer = std::add_pointer<__d_type>::type;		\
	using __d_cpointer = std::add_pointer<__d_ctype>::type;		\
	using __type = std::conditional<std::is_const<std::remove_pointer<decltype(this)>::type>::value, __d_cpointer, __d_pointer>::type;		\
	__type q = reinterpret_cast<__type>(this->m_pFacade)

#endif // _MIDR_GL_UTIL_H_H_