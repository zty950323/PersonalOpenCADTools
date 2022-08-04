/**
 * Copyright (c) 2022, Tom Zhao personal. ("TZOpenTools")
 * This software is a personal tools project by Tom Zhao.
 * Description:
 */

#ifndef SOURCE_INCLUDE_WIDGETS_WIDGETS_DEFINES_H_
#define SOURCE_INCLUDE_WIDGETS_WIDGETS_DEFINES_H_

#include "zsofts_compiler_specific.h"

TZ_NAMESPACE_BEGIN(TzSoft)

enum class WidgetsCommonFlag : unsigned short
{
  TZ_NEED_WIDGETS = 0,
};

enum class WidgetsBasicColor : unsigned short
{
  Green = 0,
  Red,
  Yellow,
  Black,
  DarkGray,
  Gray,
  Blue,
  LightBlue,
  LightRed,
  LightGreen,
  LightGray,
  White,
};

TZ_NAMESPACE_END(TzSoft)

#endif // SOURCE_INCLUDE_WIDGETS_WIDGETS_DEFINES_H_
