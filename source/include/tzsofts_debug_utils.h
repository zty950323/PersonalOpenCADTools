/**
 * Copyright (c) 2021, Tom Zhao personal. ("TZOpenTools")
 * This software is a personal tools project by Tom Zhao.
 * Description:
 */

#ifndef _TZSOFTS_DEBUG_UTILS_H_H_
#define _TZSOFTS_DEBUG_UTILS_H_H_

#include "zsofts_compiler_specific.h"
#include "zsofts_types.h"

// String maker macros
#define _TZ_MAKESTR(x) #x
#define TZ_MAKESTR(x) _TZ_MAKESTR(x)

#define _TZ_MAKESTRW(x) TZ_T(#x)
#define TZ_MAKESTRW(x) _TZ_MAKESTRW(x)

#if TZ_PHASE <= TZ_UNITT_PHASE

#include "tzsofts_assert.h"
#define TZ_FAIL() \
  TzSoft::Asserter(TZ_T("Invalid Execution."), TZ_T(__FILE__), __LINE__)
#define TZ_FAIL_ONCE()                    \
  {                                       \
    static bool s_bFailedAlready = false; \
    if (!s_bFailedAlready)                \
    {                                     \
      s_bFailedAlready = true;            \
      TZ_FAIL();                          \
    }                                     \
  }

#define TZ_ASSERT(exp) \
  ((exp) || (TzSoft::Asserter(TZ_T(#exp), TZ_T(__FILE__), __LINE__), 0))
#define TZ_ASSERT_ONCE(exp)                                   \
  {                                                           \
    static bool s_bAssertAlready = false;                     \
    if (!s_bAssertAlready && !(exp))                          \
    {                                                         \
      s_bAssertAlready = true;                                \
      TzSoft::Asserter(TZ_T(#exp), TZ_T(__FILE__), __LINE__); \
    }                                                         \
  }

#define TZ_VERIFY(exp) TZ_ASSERT(exp)

#include "tzsofts_trace_util.h"
#define TZ_TRACE TzSoft::Tracer
#define TZ_TRACE0(szFormat) TzSoft::Tracer(szFormat)
#define TZ_TRACE1(szFormat, param1) TzSoft::Tracer(szFormat, param1)
#define TZ_TRACE2(szFormat, param1, param2) \
  TzSoft::Tracer(szFormat, param1, param2)
#define TZ_TRACE3(szFormat, param1, param2, param3) \
  TzSoft::Tracer(szFormat, param1, param2, param3)

#elif TZ_PAHSE <= TZ_ALPHA_PHASE

#define TZ_FAIL()
#define TZ_FAIL_ONCE()
#define TZ_ASSERT(exp)
#define TZ_ASSERT_ONCE(exp)
#define TZ_VERIFY(exp) TZ_ASSERT(exp)
#define TZ_TRACE
#define TZ_TRACE0(szFormat)
#define TZ_TRACE1(szFormat, param1)
#define TZ_TRACE2(szFormat, param1, param2)
#define TZ_TRACE3(szFormat, param1, param2, param3)

#else

#define TZ_FAIL()
#define TZ_FAIL_ONCE()
#define TZ_ASSERT(exp)
#define TZ_ASSERT_ONCE(exp)
#define TZ_VERIFY(exp) (exp)
#define TZ_TRACE
#define TZ_TRACE0(szFormat)
#define TZ_TRACE1(szFormat, param1)
#define TZ_TRACE2(szFormat, param1, param2)
#define TZ_TRACE3(szFormat, param1, param2, param3)

#endif

#if (TZ_COMPILER == TZ_COMILER_MSVC) && (TZ_BUILD_MODE == TZ_BUILD_DEBUG)
#pragma warning(disable : 4081)
#define TZ_MAKEMESSAGE(desc) message(__FILE__ "(" TZ_MAKESTR ") :" #desc)
#elif defined(__sun) && TZ_COMPILER != TZ_COMPILER_GUNC
#define TZ_MAKEMESSAGE(desc) dummy_pragma
#else
#define TZ_MAKEMESSAGE(desc) message(#desc)
#endif

#endif // _TZSOFTS_DEBUG_UTILS_H_H
