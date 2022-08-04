/**
 * Copyright (c) 2021, Tom Zhao personal. ("TZOpenTools")
 * This software is a personal tools project by Tom Zhao.
 * Description:
 */

#ifndef __TZ_ROOT_EXPORT_H_INCLUDE__
#define __TZ_ROOT_EXPORT_H_INCLUDE__

#include "zsofts_compiler_specific.h"

#ifdef TZSOFT_ROOT_MODULE
#define TZ_ROOT_EXPORT TZ_EXPORT
#define TZ_ROOT_STATIC_EXPORT TZ_EXPORT
#define TZ_ROOT_EXPORT_STATIC
#define TZ_ROOT_C_EXPORT TZ_C_EXPORT
#else
#define TZ_ROOT_EXPORT TZ_IMPORT
#define TZ_ROOT_STATIC_EXPORT
#define TZ_ROOT_EXPORT_STATIC TZ_IMPORT
#define TZ_ROOT_C_EXPORT TZ_C_IMPORT
#endif

#endif // __TZ_ROOT_EXPORT_H_INCLUDE__
