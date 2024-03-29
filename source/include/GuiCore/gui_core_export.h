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
 * @brief This file provides a serious export macros about GuiTools.
 * codec.
 * @file main.cpp
 * @author Tom Zhao(18872770445@163.com)
 * @since 2022-07-23
 * @date Created: 2022-07-23
 * @date Last modified: 2022-07-23
 *
 * Github: @link https://github.com/zty950323/PersonalOpenCADTools @endlink
 * Homepage: @link https://blog.csdn.net/zhaotianyu950323 @endlink
 * Blog: @link https://www.zhihu.com/people/Tom_Zhao @endlink
 */

#ifndef _GUI_CORE_CORE_EXPORT_H_H_
#define _GUI_CORE_CORE_EXPORT_H_H_

#include "zsofts_compiler_specific.h"

#ifdef TZ_SOFT_GUI_CORE_MODULE
#define TZ_GUI_CORE_EXPORT TZ_EXPORT
#define TZ_GUI_CORE_STATIC_EXPORT TZ_EXPORT
#define TZ_GUI_CORE_EXPORT_STATIC
#define TZ_GUI_CORE_C_EXPORT TZ_C_EXPORT
#else
#define TZ_GUI_CORE_EXPORT TZ_IMPORT
#define TZ_GUI_CORE_STATIC_EXPORT
#define TZ_GUI_CORE_EXPORT_STATIC TZ_IMPORT
#define TZ_GUI_CORE_C_EXPORT TZ_C_IMPORT
#endif

#endif // _GUI_CORE_CORE_EXPORT_H_H_
