/**
 * Copyright (c) 2021, Tom Zhao personal. ("TZOpenTools")
 * This software is a personal tools project by Tom Zhao.
 * Description:
 */

#ifndef _TZSOFTS_ASSERT_H_H
#define _TZSOFTS_ASSERT_H_H

#include "platform_export.h"
#include "zsofts_types.h"

#ifdef TZ_WINDOWS
#include <crtdbg.h>
#else
#include <stdio.h>
#include <wchar.h>
#endif // TZ_WINDOWS

#include <assert.h>

#pragma pack(push, 8)

TZ_NAMESPACE_BEGIN(TzSoft)

typedef void (*TzAssertFunc)(const TZTCHAR *expression, const TZTCHAR *fileName,
                             int lineNumber);

class TZ_PLATFORM_STATIC_EXPORT Asserter
{
public:
  Asserter(const TZTCHAR *expression, const TZTCHAR *fileName, int lineNumber)
  {
    // (*sm_pfnAssert)(expression, fileName, lineNumber);
    defaultAssert(expression, fileName, lineNumber);
  }

  ~Asserter() {}

  static TzAssertFunc setAssertFunction(TzAssertFunc pfnAssert)
  {
    TzAssertFunc pfnOldFunc = sm_pfnAssert;
    sm_pfnAssert = pfnAssert;
    return pfnOldFunc;
  }

private:
  static void defaultAssert(const TZTCHAR *expression, const TZTCHAR *fileName,
                            int lineNumber)
  {
#if TZ_BUILD_MODE == TZ_BUILD_DEBUG && TZ_COMPILER == TZ_COMPILER_MSVC && \
    TZ_PLATFORM != TZ_PLATFORM_WINCE
#if TZ_COMPILER_VER >= TZ_COMPILER_MSVC_8_0
    if (1 ==
        _CrtDbgReportW(_CRT_ASSERT, fileName, lineNumber, NULL, expression))
      _CrtDbgBreak();
#elif TZ_COMPILER_VER >= TZ_COMPILER_MSVC_7_0
    _assert(expression, fileName, lineNumber);
#else
    _assert((void *)expression, (void *)fileName, lineNumber);
#endif
#endif
  }
  TZ_PLATFORM_EXPORT_STATIC static TzAssertFunc sm_pfnAssert;
};

TZ_NAMESPACE_END(TzSoft)

#endif // !_TZSOFT_ASSERT_H_H
