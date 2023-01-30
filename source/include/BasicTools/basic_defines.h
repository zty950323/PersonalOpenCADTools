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
 * @brief Define some common structures in our platform.
 * @file basic_defines.h
 * @author Tom Zhao(18872770445@163.com)
 * @since 2023-01-19
 * @date Created: 2023-01-19
 * @date Last modified: 2023-01-19
 *
 * Github: @link https://github.com/zty950323/PersonalOpenCADTools @endlink
 * Homepage: @link https://blog.csdn.net/zhaotianyu950323 @endlink
 * Blog: @link https://www.zhihu.com/people/Tom_Zhao @endlink
 */

#ifndef _BASIC_DFEINS_H_H_
#define _BASIC_DFEINS_H_H_

#include "platform_types.h"

#pragma pack(push, 8)

namespace Basic
{
    struct Vector2d
    {
        TZDOUBLE x;
        TZDOUBLE y;
    };

    struct Vector3d
    {
        TZDOUBLE x;
        TZDOUBLE y;
        TZDOUBLE z;
    };

    struct Vector2i
    {
        TZUINT32 x;
        TZUINT32 y;
    };

    struct Vector3i
    {
        TZUINT32 x;
        TZUINT32 y;
        TZUINT32 z;
    };

    struct ScreenPoint
    {
        TZINT32 x;
        TZINT32 y;
    };
} // namespace Basic

#pragma pack(pop)

#endif // _BASIC_DFEINS_H_H_
