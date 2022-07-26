/**
 * Copyright (c) 2022, Tom Zhao personal. ("TZOpenTools")
 * This software is a personal tools project by Tom Zhao.
 * Description:
 */

#ifndef SOURCE_INCLUDE_WIDGETS_WIDGETS_EXPORT_H_
#define SOURCE_INCLUDE_WIDGETS_WIDGETS_EXPORT_H_

#include "zsofts_compiler_specific.h"

#ifdef TZ_SOFT_WIDGETS_MODULE
#define TZ_WIDGETS_EXPORT TZ_EXPORT
#define TZ_WIDGETS_STATIC_EXPORT TZ_EXPORT
#define TZ_WIDGETS_EXPORT_STATIC
#define TZ_WIDGETS_C_EXPORT TZ_C_EXPORT
#else
#define TZ_WIDGETS_EXPORT TZ_IMPORT
#define TZ_WIDGETS_STATIC_EXPORT
#define TZ_WIDGETS_EXPORT_STATIC TZ_IMPORT
#define TZ_WIDGETS_C_EXPORT TZ_C_IMPORT
#endif

#endif // SOURCE_INCLUDE_WIDGETS_WIDGETS_EXPORT_H_
