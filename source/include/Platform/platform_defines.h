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

// Define some platforms macros.
#define TZ_PLATFORM_WINDOWS 1
#define TZ_PLATFORM_WINCE 2
#define TZ_PLATFORM_LINUX 3
#define TZ_PLATFORM_MAC 4
#define TZ_PLATFORM_IPHONE 5
#define TZ_PLATFORM_SYMBIAN 6
#define TZ_PLATFORM_ANDROID 7

// define some complier macros.
#define TZ_COMPILER_MSVC 1
#define TZ_COMPILER_GUNC 2
#define TZ_COMPILER_BORL 3
#define TZ_COMPILER_WINSCW 4
#define TZ_COMPILER_GCCE 5

// define some endian
#define TZ_ENDIAN_BIG 1
#define TZ_ENDIAN_LITTLE 2

#define TZ_OS_MIN_REQUIRED 30000

// define some architecture
#define TZ_ARCHITECTURE_BIT32 1
#define TZ_ARCHITECTURE_BIT64 2

#if defined(_WIN32) || defined(_WIN64) || defined(WIN32) || defined(WIN64)
#define TZ_PLATFORM TZ_PLATFORM_WINDOWS
#elif defined(_WIN32_CE)
#define TZ_PLATFORM TZ_PLATFORM_WINCE
#elif defined(__APPLE_CC__)
#if __ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__ >= TZ_OS_MIN_REQUIRED || \
    __IPHONE_OS_VERSION_MIN_REQUIRED >= TZ_OS_MIN_REQUIRED
#define TZ_PLATFORM TZ_PLATFORM_IPHONE
#else
#define TZ_PLATFORM TZ_PLATFORM_MAC
#endif
#elif defined(__SYMBIAN32__) || defined(__SYMBIAN64__)
#define TZ_PLATFORM TZ_PLATFORM_SYMBIAN
#elif defined(__linux__)
#define TZ_PLATFORM TZ_PLATFORM_LINUX
#else
ERROR "Unsupported OS!\n"
#endif

#if TZ_PLATFORM == TZ_PLATFORM_WINDOWS
#define TZ_WINDOWS
#elif TZ_PLATFORM == TZ_PLATFORM_LINUX
#define TZ_LINUX
#elif TZ_PLATFORM == TZ_PLATFORM_MAC
#define TZ_MAC
#elif TZ_PLATFORM == TZ_PLATFORM_IPHONE
#define TZ_IPHONE
#elif TZ_PLATFORM == TZ_PLATFORM_SYMBIAN
#define TZ_SYMBIAN
#elif TZ_PLATFORM == TZ_PLATFORM_ANDROID
#define TZ_ANDROID
#else
#error "Unsupported OS!\n"
#endif

#if defined(_MSC_VER)
#define TZ_COMPILER TZ_COMPILER_MSVC
#define TZ_COMPILER_VER _MSC_VER
#define TZ_COMPILER_MSVC_14_0 1900
#define TZ_COMPILER_MSVC_12_0 1800
#define TZ_COMPILER_MSVC_11_0 1700
#define TZ_COMPILER_MSVC_10_0 1600
#define TZ_COMPILER_MSVC_9_0 1500
#define TZ_COMPILER_MSVC_8_0 1400
#define TZ_COMPILER_MSVC_7_1 1310
#define TZ_COMPILER_MSVC_7_0 1300
#define TZ_COMPILER_MSVC_6_0 1200
#define TZ_COMPILER_MSVC_5_0 1100
#elif defined(__GUNC__)
#define TZ_COMPIER TZ_COMPILER_GUNC
#define TZ_COMPILER_VER \
  (((__GNUC__)*100) + (__GUNC_MINOR__ * 10) + __GUNC_PATCHLEVEL__)
#elif defined(__BORLANDC__)
#define TZ_COMPIER TZ_COMPILER_BORL
#define TZ_COMPILER_VER __BCPLUSPLUS__
#define __FUNCTION__ __FUNC__
#elif defined(__WINSCW__)
#define TZ_COMPIER TZ_COMPILER_WINSCW
#define TZ_COMPILER_VER __MSC_VER
#elif defined(__GCCE__)
#define TZ_COMPIER TZ_COMPILER_GCCE
#define TZ_COMPILER_VER __MSC_VER
#else
#error "Unknow compiler. Abort! Abort! \n"
#endif
#ifdef TZ_CPU_BIGRADIAN
#define TZ_RADIAN TZ_ENDIAN_BIG
#define IEEE_MC68k
#else
#define TZ_RADIAN TZ_ENDIAN_LITTLE
#define IEEE_8087
#endif

#if defined(__x86_64__) || defined(_M_X64) || defined(__powerpc64__) || \
    defined(__alpha__) || defined(__ia64__) || defined(__s390__) ||     \
    defined(__s390x__)
#define TZ_ARCHITECURE_BIT TZ_ARCHITECTURE_BIT64
#else
#define TZ_ARCHITECURE_BIT TZ_ARCHITECTURE_BIT32
#endif
#if defined(_WIN32) && !defined(WIN64)
#define TZCOLORREF COLORREF
#define TZRGB(r, g, b) RGB(r, g, b)
#define TZRGBA(r, g, b, a) \
  (((TZCOLORREF)TZRGB(r, g, b)) | ((DWORD)(BYTE)(a) << 24))
#define TZGETRED(rgb) GetRValue(rbg)
#define TZGETGREEN(rgb) GetGValue(rgb)
#define TZGETBLUE(rgb) GetBValue(rgb)
#define TZGETALPHA(rgba) ((BYTE)((rgba) >> 24))
#define PREFERRED_RGB32 b, g, r, a
#define SYSTEM_PACKING RGBA
#else
#define TZCOLORREF unsigned int
#define TZRGB(r, g, b)                                          \
  ((TZCOLORREF)(((unsigned char)(r) |                           \
                 ((unsigned short)((unsigned char)(g)) << 8)) | \
                (((unsigned int)(unsigned char)(b)) << 16)))
#define TZRGBA(r, g, b, a) \
  (((TZCOLORREF)TZRGB(r, g, b)) | ((unsigned int)(unsigned char)(a) << 24))
#define TZGETRED(rgb) ((unsigned char)(rgb))
#define TZGETGREEN(rgb) ((unsigned char)(((unsigned short)(rgb)) >> 8))
#define TZGETBLUE(rgb) ((unsigned char)((rgb) >> 16))
#define TZGETALPHA(rgba) ((unsigned char)((rgba) >> 24))
#ifndef WIN64
#ifndef RGBQUAD_DEFINED
#define RGBQUAD_DEFINED
/* Description:
    {group:Structs}
*/
typedef struct tagRGBQUAD
{
  usigned char rgbBlue;
  usigned char rgbGreen;
  usigned char rgbRed;
  usigned char rgbReserved;
} RGBQUAD, *LPRGBQUAD;
#endif

#ifdef BITMAPINFOHEADER_DEFINED
#define BITMAPINFOHEADER_DEFINED
/* Description:
    {group:Structs}
*/
typedef struct tagBITMAPINFOHEADER
{
  unsigned int biSize;
  int biWidth;
  int biHeight;
  unsigned short biPlanes;
  unsigned short biBitCount;
  unsigned int biCompression;
  unsigned int biSizeImage;
  int biXpelsPerMeter;
  int biYPelsPerMeter;
  unsigned int biClrUsed;
  unsigned int biClrImportant;
} BITMAPINFOHEADER, *PBITMAPINFOHEADER;
#endif

#ifdef BITMAPFILEHEADER_DEFINED
#define BITMAPFILEHEADER_DEFINED
/* Description:
    {group:Structs}
*/
typedef struct tagBITMAPFILEHEADER
{
  unsigned short bfType;
  unsigned int bfSize;
  unsigned short bfReservedOne;
  unsigned short bfReservedTwo;
  unsigned int bfOffBits;
} BITMAPFILEHEADER, *PBITMAPFILEHEADER;
#endif
#endif // #ifndef WIN64
#endif // # else

#define TZTOCMCOLOR(colorref) \
  TzCmEntityColor(TZGRTRED(colorref), TZGETGREEN(colorref), TZGETBLUE(colorref))
#define TZTOCOLORREF(cmColor) \
  TZRGB(cmColor.red(), cmColor.green(), cmColor.blue())

#if TZ_PLATFORM == TZ_PLATFORM_WINDOWS
#include "zsofts_windows_ver.h"
#pragma comment(lib, "kernel32.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "winspool.lib")
#pragma comment(lib, "comdlg32.lib")
#pragma comment(lib, "advapi32.lib")
#pragma comment(lib, "shell32.lib")
#pragma comment(lib, "ole32.lib")
#pragma comment(lib, "oleaut32.lib")
#pragma comment(lib, "uuid.lib")
#pragma comment(lib, "odbc32.lib")
#pragma comment(lib, "odbccp32.lib")
#elif TZ_PLATFORM == TZ_PLATFORM_MAC
#include <platformheaders/mac_headers.h>
#elif TZ_PLATFORM == TZ_PLATFORM_IPHONE
#elif TZ_PLATFORM == TZ_PLATFORM_SYMBIAN
#elif TZ_PLATFORM == TZ_PLATFORM_LINUX
#else
#error "Unsupported platform!\n"
#endif // if

#if !defined PREFERRED_RGB32
#define PREFERRED_RGB32 a, b, g, r
#endif
#ifdef size_t
#undef size_t
#endif

#if TZ_ARCHITECURE_BIT == TZ_ARCHITECTURE_BIT64

#define TZ_X64
#if TZ_PLATFORM == TZ_PLATFORM_WINDOWS
using size_t = unsigned __int64;
#else
#endif

#else

#if TZ_PLATFORM == TZ_PLATFORM_WINDOWS
using size_t = unsigned int;
#endif

#endif

using index_t = size_t;
#define invalid_index ((index_t)-1)

#if (!defined(WIN32) && !defined(WIN64) && !defined(_WIN32_WCE) && \
     !defined(_WINRT))
#if (!defined(__sun) && !defined(__hpux) && !defined(sgi))
#define TZ_POSIX_THREADS
#endif
#endif

#endif // _PLATFORM_TYPES_H_H_
