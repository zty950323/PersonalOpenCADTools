///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include "tzsofts_trace_util.h"

#include <malloc.h>

#include "tzsofts_str_operations.h"

TZ_NAMESPACE_BEGIN(TzSoft)

TraceFuncA Tracer::sm_pfnTraceA = Tracer::defaultTraceA;
TraceFuncW Tracer::sm_pfnTraceW = Tracer::defaultTraceW;

#if defined(TZ_WINDOWS)

Tracer::Tracer(const TZCHAR* szFormat, ...) {
  va_list argList;
  va_start(argList, szFormat);

  int sizeReq = _vscprintf(szFormat, argList);
  TZCHAR* pOutput = (TZCHAR*)::malloc((sizeReq + 1) * sizeof(TZCHAR));
  if (nullptr != pOutput) {
    vsprintf_s(pOutput, (sizeReq + 1) * sizeof(TZCHAR), szFormat, argList);
    (*sm_pfnTraceA)(pOutput);
    va_end(argList);
  }

  ::free(pOutput);
}

Tracer::Tracer(const TZWCHAR* szFormat, ...) {
  va_list argList;
  va_start(argList, szFormat);

  int sizeReq = _vscwprintf(szFormat, argList);
  TZWCHAR* pOutput = (TZWCHAR*)::malloc((sizeReq + 1) * sizeof(TZWCHAR));
  if (nullptr != pOutput) {
    vswprintf_s(pOutput, (sizeReq + 1) * sizeof(TZWCHAR), szFormat, argList);
    (*sm_pfnTraceW)(pOutput);
    va_end(argList);
  }

  ::free(pOutput);
}

#else  // #if defined(TZ_WINDOWS)

#include <stdio.h>

Tracer::Tracer(const TZCHAR* szFormat, ...) {
#warning "check this!!!"
  va_list argList;
  va_start(argList, szFormat);
  _vscprintf(szFormat, argList);

  va_end(argList);
}

Tracer::Tracer(const TZWCHAR* szFormat, ...) {
#warning "check this!!!"
  va_list argList;
  va_start(argList, szFormat);
  _vscwprintf(szFormat, argList);

  va_end(argList);
}

#endif  // if defined(TZ_WINDOWS)

TraceFuncA Tracer::setTraceFuncitonA(TraceFuncA pfnTraceA) {
  TraceFuncA pfnOldFunc = pfnTraceA;
  sm_pfnTraceA = pfnTraceA;
  return pfnOldFunc;
}

TraceFuncW Tracer::setTraceFuncitonW(TraceFuncW pfnTraceW) {
  TraceFuncW pfnOldFunc = pfnTraceW;
  sm_pfnTraceW = pfnTraceW;
  return pfnOldFunc;
}

void Tracer::defaultTraceA(const TZCHAR* strDebug) {
#ifdef TZ_WINDOWS
  ::OutputDebugStringA(strDebug);
#else
  tz_printf(strDebug);
#endif  // TZ_WINDOWS
}

void Tracer::defaultTraceW(const TZWCHAR* strDebug) {
#ifdef TZ_WINDOWS
  ::OutputDebugStringW(strDebug);
#else
  tz_printf(strDebug);
#endif  // TZ_WINDOWS
}

TZ_NAMESPACE_END(TzSoft)