/**
 * Copyright (c) 2022, Tom Zhao personal. ("TZOpenTools")
 * This software is a personal tools project by Tom Zhao.
 * Description:
 */

#ifndef SOURCE_INCLUDE_GUI_CORE_CORE_DEFINES_H_
#define SOURCE_INCLUDE_GUI_CORE_CORE_DEFINES_H_

#include "zsofts_compiler_specific.h"

TZ_NAMESPACE_BEGIN(TzSoft)

enum class CoreCommonFlag : unsigned short
{
  TZ_NEED_WIDGETS = 0,
};

TZ_NAMESPACE_END(TzSoft)

#define __builtin_expect(EXP, C)  (EXP)

#endif // SOURCE_INCLUDE_GUI_CORE_CORE_DEFINES_H_
