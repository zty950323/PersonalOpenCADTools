/**
 * Copyright (c) 2022, Tom Zhao personal. ("TZOpenTools")
 * This software is a personal tools project by Tom Zhao.
 * Description:
 */

#ifndef __TZ_BASIC_EXPORT_H_INCLUDE__
#define __TZ_BASIC_EXPORT_H_INCLUDE__

#include "zsofts_compiler_specific.h"

#ifdef TZ_SOFT_BASIC_TOOL_MODULE
#define TZ_BASIC_EXPORT TZ_EXPORT
#define TZ_BASIC_STATIC_EXPORT TZ_EXPORT
#define TZ_BASIC_EXPORT_STATIC
#define TZ_BASIC_C_EXPORT TZ_C_EXPORT
#else
#define TZ_BASIC_EXPORT TZ_EXPORT
#define TZ_BASIC_STATIC_EXPORT TZ_EXPORT
#define TZ_BASIC_EXPORT_STATIC
#define TZ_BASIC_C_EXPORT TZ_C_EXPORT
#endif

#endif  // __TZ_BASIC_EXPORT_H_INCLUDE__
