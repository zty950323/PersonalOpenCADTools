///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2020, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include "tzsofts_assert.h"

TZ_NAMESPACE_BEGIN(TzSoft)

#if defined(TZ_WINDOWS)

#if defined(TZ_USE_DEBUGOUTPUT_FOR_ASSERTION_FAIL)
void debugOutputAssert(const TZTCHAR* expression, const TZTCHAR* fileName,
                       int lineNumber) {
  static const TZCHAR* _s_debug_assertion_fmt =
      TZ_T("\nASSERT FAIL!!!!\nExpression:\"%s\"\nOccur at:\"%s(line %d)\"\n");
  const size_t _debug_assertion_fmt_strlen =
      tz_strlen(_s_debug_assertion_fmt) +
      (NULL == expression ? 1 : tz_strlen(expression)) +
      (NULL == fileName ? 1 : tz_strlen(fileName)) + 20;
  TZCHAR* _assertInfoForStr = new TZCHAR[_debug_assertion_fmt_strlen];

  if (tz_stprintf(_assertInfoForStr, _s_debug_assertion_fmt, expression,
                  fileName, lineNumber) > 0) {
    ::OutputDebugString(_assertInfoForStr);
  }
  delete[] _assertInfoForStr;
}

TZ_PLATFORM_STATIC_EXPORT TzAssertFunc Asserter::sm_pfnAssert =
    debugOutputAssert;
#else

TZ_PLATFORM_STATIC_EXPORT TzAssertFunc Asserter::sm_pfnAssert =
    Asserter::defaultAssert;

#endif

#else

// TODO: Put assert method for platform that other than windows.

static void otherAssert(const TZCHAR* expression, const TZCHAR* fileName,
                        int lineNumber) {
  wprintf(TZ_T("\nTzAsserter failed -- %ls:%d "), fileName, lineNumber);
}

TZ_PLATFORM_STATIC_EXPORT TzAssertFunc Asserter::sm_pfnAssert = otherAssert;

#endif

TZ_NAMESPACE_END(TzSoft)