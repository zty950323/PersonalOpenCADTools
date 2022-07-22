/**
 * Copyright (c) 2022, Tom Zhao personal. ("TZOpenTools")
 * This software is a personal tools project by Tom Zhao.
 * Description:
 */

#ifndef SOURCE_INCLUDE_GUI_CORE_CORE_EXPORT_H_
#define SOURCE_INCLUDE_GUI_CORE_CORE_EXPORT_H_

#include "zsofts_compiler_specific.h"

#ifdef TZ_SOFT_GUI_CORE_MODULE
#define TZ_GUI_CORE_EXPORT TZ_EXPORT
#define TZ_GUI_CORE_STATIC_EXPORT TZ_EXPORT
#define TZ_GUI_CORE_EXPORT_STATIC
#define TZ_GUI_CORE_C_EXPORT TZ_C_EXPORT
#else
#define TZ_GUI_CORE_EXPORT TZ_IMPORT
#define TZ_GUI_CORE_STATIC_EXPORT
#define TZ_GUI_CORE_EXPORT_STATIC TZ_EXPORT
#define TZ_GUI_CORE_C_EXPORT TZ_C_EXPORT
#endif

#endif  // SOURCE_INCLUDE_GUI_CORE_CORE_EXPORT_H_
