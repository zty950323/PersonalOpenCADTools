/**
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 1. You can modify and use this program at will.
 * 2. But it is suggested that it is more suitable for learning and teaching
 * purposes.
 *
 * @version 1.0
 * @brief This file provides a serious predefined parameters about GuiCore.
 * codec.
 * @file gui_core_defines.h
 * @author Tom Zhao(18872770445@163.com)
 * @since 2023-01-30
 * @date Created: 2023-01-30
 * @date Last modified: 2023-01-30
 *
 * Github: @link https://github.com/zty950323/PersonalOpenCADTools @endlink
 * Homepage: @link https://blog.csdn.net/zhaotianyu950323 @endlink
 * Blog: @link https://www.zhihu.com/people/Tom_Zhao @endlink
 */

#ifndef _GUI_CORE_CORE_DEFINES_H_H_
#define _GUI_CORE_CORE_DEFINES_H_H_

#include "zsofts_compiler_specific.h"

TZ_NAMESPACE_BEGIN(TzSoft)

enum class CoreCommonFlag : unsigned short
{
  TZ_NEED_WIDGETS = 0,
};

TZ_NAMESPACE_END(TzSoft)

#define __builtin_expect(EXP, C) (EXP)

#endif // _GUI_CORE_CORE_DEFINES_H_H_
