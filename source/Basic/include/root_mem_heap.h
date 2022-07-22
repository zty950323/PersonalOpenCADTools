/**
 * Copyright (c) 2021, Tom Zhao personal. ("TZOpenTools")
 * This software is a personal tools project by Tom Zhao.
 * Description:
 */

#ifndef SOURCE_BASIC_INCLUDE_ROOT_MEM_HEAP_H_
#define SOURCE_BASIC_INCLUDE_ROOT_MEM_HEAP_H_

#include "root_export.h"
#include "root_mem_malloc.h"
#include "tzsofts_debug_utils.h"
#include "zsofts_types.h"

#pragma push_macro("new")
#pragma push_macro("delete")
#undef new
#undef delete

class TzcRootHeap {
 public:
#if defined(TZ_MEM_DBG)
  TZ_FORCEINLINE static TZPVOID operator new(
      size_t size, const TZCHAR* fn = MAKESTR(__FILE__),
      TZINT32 ln = __LINE__) {
    return _tzMallocDbg(size, fn, ln);
  }

  TZ_FORCEINLINE static void operator delete(
      TZPVOID p, const TZCHAR* fn = MAKESTR(__FILE__), TZINT32 ln = __LINE__) {
    _tzFreeDbg(p, fn, ln);
  }
#else
  static TZPVOID operator new(size_t size) { return _tzMalloc(size); }

  static void operator delete(TZPVOID p) { _tzFree(p); }
#endif
};

TZ_ROOT_C_EXPORT TZPVOID
tzAllocatePage(const TZUINT32 page_size /*used only for checking*/);
TZ_ROOT_C_EXPORT void tzFreePage(TZPVOID p);

#pragma pop_macro("delete")
#pragma pop_macro("new")

#if defined(TZ_MEM_DBG)
#include "root_mem_heap_dbg.h"
#endif

#endif  // SOURCE_BASIC_INCLUDE_ROOT_MEM_HEAP_H_
