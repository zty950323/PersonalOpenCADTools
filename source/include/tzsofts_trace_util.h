/**
 * Copyright (c) 2021, Tom Zhao personal. ("TZOpenTools")
 * This software is a personal tools project by Tom Zhao.
 * Description:
 */

#ifndef _TZSOFTS_TRACE_UTIL_H_H_
#define _TZSOFTS_TRACE_UTIL_H_H_

#include "platform_export.h"
#include "zsofts_types.h"

TZ_NAMESPACE_BEGIN(TzSoft)

typedef void (*TraceFuncA)(const TZCHAR* szDebugStr);
typedef void (*TraceFuncW)(const TZWCHAR* szDebugStr);

class TZ_PLATFORM_STATIC_EXPORT Tracer {
 public:
  Tracer(const TZCHAR* szFormat, ...);
  Tracer(const TZWCHAR* szFormat, ...);

  static TraceFuncA setTraceFuncitonA(TraceFuncA pfnTraceA);
  static TraceFuncW setTraceFuncitonW(TraceFuncW pfnTraceW);

 private:
  static void defaultTraceA(const TZCHAR* strDebug);
  static void defaultTraceW(const TZWCHAR* strDebug);

  static TraceFuncA sm_pfnTraceA;
  static TraceFuncW sm_pfnTraceW;
};

TZ_NAMESPACE_END(TzSoft)

#endif  // !_TZSOFTS_TRACE_UTIL_H_H_
