///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#ifndef  _MIDR_GL_EXPORT_H_H_
#define _MIDR_GL_EXPORT_H_H_

#include "zsofts_compiler_specific.h"

#ifdef TZSOFT_MIDR_GL_MOUDLE

#	define TZ_MIDR_GL_EXPORT					TZ_EXPORT
#	define TZ_MIDR_GL_STATIC_EXPORT		TZ_EXPORT
#	define TZ_MIDR_GL_EXPORT_STATIC
#	define TZ_MIDR_GL_C_EXPORT				TZ_C_EXPORT

#	ifndef ZCRX_EXPIMP
#		define ZCRX_EXPIMP
#		define ZCRX_STATIC_EXPIMP
#endif

#else

#	define TZ_MIDR_GL_EXPORT					TZ_IMPORT
#	define TZ_MIDR_GL_STATIC_EXPORT		
#	define TZ_MIDR_GL_EXPORT_STATIC		TZ_IMPORT
#	define TZ_MIDR_GL_C_EXPORT				TZ_C_IMPORT

#	ifndef ZCRX_EXPIMP
#		define ZCRX_EXPIMP
#		define ZCRX_STATIC_EXPIMP
#endif

#endif // TZSFOT_MIDR_GL_MOUDLE

#endif