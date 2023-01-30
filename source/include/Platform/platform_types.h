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
 * @brief
 * @file basic_array.h
 * @author Tom Zhao(18872770445@163.com)
 * @since 2023-01-19
 * @date Created: 2023-01-19
 * @date Last modified: 2023-01-19
 *
 * Github: @link https://github.com/zty950323/PersonalOpenCADTools @endlink
 * Homepage: @link https://blog.csdn.net/zhaotianyu950323 @endlink
 * Blog: @link https://www.zhihu.com/people/Tom_Zhao @endlink
 */

#ifndef _PLATFORM_TYPES_H_H_
#define _PLATFORM_TYPES_H_H_

#include "platform_defines.h"
#include "platform_compiler_specific.h"

#include <limits.h>
#include <stddef.h>
#include <tchar.h>
#include <stdint.h>

#if USHRT_MAX == 0xFFFFU
#define TZ_SIZEOF_SHORT 2
#else
#error "Unsupported short size!"
#endif // USHRT_MAX == 0xFFFFU

#if UINT_MAX == 0xFFFFFFFFUL
#define TZ_SIZEOF_INT 4
#else
#error "Unsupported int size!"
#endif // UINT_MAX == 0xFFFFFFFFUL

#ifdef __LP64__
#define TZ_SIZEOF_LONG 8
#else
#define TZ_SIZEOF_LONG 4
#endif

#if TZ_ARCHITECURE_BIT == TZ_ARCHITECTURE_BIT64
#define TZ_SIZEOF_POINTER 8
#elif TZ_ARCHITECURE_BIT == TZ_ARCHITECTURE_BIT32
#define TZ_SIZOF_POINTER 4
#else
#error "Unsupported architecture bit!\n"
#endif // TZ_ARCHITECURE_BIT == TZ_ARCHITECTURE_BIT32

#if (defined(WIN32) || defined(WIN64))
#define TZCHAR_IS_INT16LE 1
#else
#define TZCHAR_IS_INT16LE 0
#endif

// Define some int value type name.
using RTContext = void *; // Running time context, refers to fiber or coroutine.
using TZINT8 = int8_t;
using TZUINT8 = uint8_t;
using TZINT16 = int16_t;
using TZUINT16 = uint16_t;

// Long is not recommended when crossing platforms.
// But we define TZINT32 as long in Win32 for compatibility.
#if TZ_SIZEOF_LONG == 8
using TZINT32 = int32_t;
using TZUINT32 = uint32_t;
#else
using TZINT32 = long;
using TZUINT32 = unsigned long;
#endif

#ifdef TZ_WINDOWS
using TZINT64 = int64_t;
using TZUINT64 = uint64_t;
#else
using TZINT64 = __int64;
using TZUINT64 = unsigned __int64;
#endif // TZ_WINDOWS

// Define some float value type name.
using TZFLOAT32 = float;
using TZFLOAT64 = double;

// Define some char value type name.
using TZCHAR = char;
using TZWCHAR = wchar_t;
using TZUCHAR = unsigned char;

// Define some characters macros for different codec.
#if TZ_BUILD_CHARACTERS == TZ_CHARACTERS_MBCS
using TZTCHAR = TZCHAR;
#define TZ__T(X) X
#elif TZ_BUILD_CHARACTERS == TZ_CHARACTERS_UNICODE
using TZTCHAR = TZWCHAR;
#define TZ__T(X) L##X
#else
using TZTCHAR = TZCHAR;
#define TZ__T(X) X
#endif
#define TZ_T(X) TZ__T(X)

// Define some char pointer types name.
using TZPSTR = TZCHAR *;
using TZPCSTR = const TZCHAR *;
using TZCHARP = TZCHAR *;
using TZCHARCP = const TZCHAR *;

// Define some wchar pointer types name.
using TZPWSTR = TZWCHAR *;
using TZPCWSTR = const TZWCHAR *;
using TZWCHARP = TZWCHAR *;
using TZWCHARCP = const TZWCHAR *;
using TZPMBSTR = TZUCHAR *;
using TZCMBSTR = const TZUCHAR *;
using TZUCHARP = TZUCHAR *;
using TZUCHARCP = const TZUCHAR *;
using TZPTSTR = TZTCHAR *;
using TZPCTSTR = const TZTCHAR *;
using TZTCHARP = TZTCHAR *;
using TZTCHARCP = const TZTCHAR *;

using TZPVOID = void *;
using TZPCVOID = const void *;

#ifndef TZ_X64
using TZLONGPTR = __w64 long;
using TZULONGPTR = __w64 unsigned long;
using TZINTPTR = __w64 int;
using TZUINGPTR = __w64 unsigned int;
#else // TZ_X64
#ifndef TZ_WINDOWS
using TZLONGPTR = int64_t;
using TZULONGPTR = uint64_t;
using TZ_INTPTR = int64_t;
using TZUINTPTR = uint64_t;
#else
using TZLONGPTR = __int64;
using TZULONGPTR = unsigned __int64;
using TZ_INTPTR = __int64;
using TZUINTPTR = unsigned __int64;
#endif // TZ_WINDOWS
#endif // TZ_X64

using TZADDRESS = TZULONGPTR;

using TZBYTE = unsigned char;

#ifndef __LP64__
using TZBOOL = int;
#else
using TZBOOL = bool;
#endif // __LP64__

using TZSHORT = short;
using TZINT = int;
using TZLONG = long;
using TZLLONG = long long;
using TZUSHORT = unsigned short;
using TZUINT = unsigned int;
using TZULONG = unsigned long;
using TZULLONG = unsigned long long;

using TZWORD = TZUINT16;
using TZDWORD = TZUINT32;
using TZQWORD = TZUINT64;

using TZFLOAT = float;
using TZDOUBLE = double;
using TZLDOUBLE = long double;
using TZSIZET = size_t;
using TZLENGHT = TZUINT32;
using TZINDEX = TZUINT32;
using WindowId = TZLONGPTR;

using UndoMarkId = TZUINT64;

#define invalid_index ((TZINDEX)-1)

// Path
#define TZ_MAX_DRIVE 3
#define TZ_MAX_PATH 260
#define TZ_MAX_FNAME 256
#define TZ_MAX_DIR 256
#define TZ_MAX_EXT 256
#define TZ_BIG_MAX_FNAME 1024
#define TZ_MAX_FULL_PATH 4096

#define TZMIN(a, b) (((a) < (b)) ? (a) : (b))
#define TZMAX(a, b) (((a) > (b)) ? (a) : (b))

#define TZBYTE_BIT CHAR_BIT
#define TZWORD_BIT (CHAR_BIT * sizeof(TZWORD))
#define TZDWORD_BIT (CHAR_BIT * sizeof(TZDWORD))
#define TZQWORD_BIT (CHAR_BIT * sizeof(TZQWORD))

#define TZBYTE_MAX ((TZBYTE)(-1))
#define TZWORD_MAX ((TZWORD)(-1))
#define TZDWORD_MAX ((TZDWORD)(-1))
#define TZQWORD_MAX ((TZQWORD)(-1))

#define TZMAKEWORD(a, b)                               \
    ((TZWORD)(((TZBYTE)(((TZWORD)(a)) & TZBYTE_MAX)) | \
              ((TZWORD)((TZBYTE)(((TZWORD)(b)) & TZBYTE_MAX))) << TZBYTE_BIT))
#define TZLOBYTE(w) ((TZBYTE)(((TZWORD)(w)) & TZBYTE_MAX))
#define TZHIBYTE(w) ((TZBYTE)((((TZWORD)(w)) >> TZBYTE_BIT) & TZBYTE_MAX))

#define TZMAKEDWORD(a, b)                                         \
    ((TZDWORD)(((TZWORD)(((TZDWORD)(a)) & TZWORD_MAX)) |          \
               ((TZDWORD)((TZWORD)(((TZDWORD)(b)) & TZWORD_MAX))) \
                   << TZWORD_BIT))
#define TZLOWORD(dw) ((TZWORD)(((TZDWORD)(dw)) & TZWORD_MAX))
#define TZHIWORD(dw) ((TZWORD)((((TZDWORD)(dw)) >> TZWORD_BIT) & TZWORD_MAX))

#define TZMAKEQWORD(a, b)                                          \
    ((TZQWORD)(((TZWORD)(((TZQWORD)(a)) & TZDWORD_MAX)) |          \
               ((TZQWORD)((TZWORD)(((TZQWORD)(b)) & TZDWORD_MAX))) \
                   << TZDWORD_BIT))
#define TZLODWORD(qw) ((TZDWORD)(((TZQWORD)(qw)) & TZDWORD_MAX))
#define TZHIDWORD(qw) \
    ((TZDWORD)((((TZQWORD)(qw)) >> TZDWORD_BIT) & TZDWORD_MAX))

#define TZGETBIT(f, b) (((f) & (b)) ? true : false)
#define TZGETBITS(f, b) ((((f) & (b)) ^ (b)) ? false : true)
#define TZSETBIT(f, b, v) ((v) ? ((f) |= (b)) : ((f) &= ~(b)))
#define TZ_NUM_ARRAYE(x) (sizeof(x) / sizeof(x[0]))

#ifndef NULL
#ifdef __cplusplus
#define NULL 0
#else
#define NULL ((void *)0)
#endif
#endif // __cplusplus

// Constant
#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TZEOS
#define TZEOS TZ_T('\0')
#endif

#ifndef TZEOSA
#define TZEOSA '\0'
#endif

#ifndef TZEOSW
#define TZEOSW L'\0'
#endif

#if defined(_IA64_) ||                                               \
    (TZ_COMPILER == TZ_COMPILER_MSVC && (TZ_COMPILER_VER >= 1020) || \
     (TZ_COMPILER == TZ_COMPILER_BORL) || (TZ_COMPILER_VER == __BCPLUSPLUS__))
#define BUILTIN_INT64 __int64
#define PERCENT18LONG "%18I64d\r\n"
#elif TZ_SIZEOF_POINTER == 8
#define BUILTIN_INT64 long
#define PERCENT18LONG "%18Id\r\n"
#elif defined(__MWERKS__) || defined(__GNUC__) || defined(sgi) || \
    defined(_AIX) || defined(__sun) || defined(__hpux)
#define BUILTIN_INT64 long long
#define PERCENT18LONG "%18lld\r\n"
#endif

#ifndef BUILTIN_INT64
#define PERCENT18LONG "%18d\r\n"
#endif

#endif // _PLATFORM_TYPES_H_H_
