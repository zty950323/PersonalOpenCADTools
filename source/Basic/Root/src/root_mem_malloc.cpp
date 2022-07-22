/**
 * Copyright (c) 2021, Tom Zhao personal. ("TZOpenTools")
 * This software is a personal tools project by Tom Zhao.
 * Description:
 */

#include "root_mem_malloc.h"

#if (TZ_PLATFORM == TZ_PLATFORM_WINDOWS)
#if (TZ_ARCHITECURE_BIT == TZ_ARCHITECTURE_BIT32)
#include "root_win32_mem_pool.h"
#else
#include "root_win64_mem_pool.h"
#endif
#else
#error "Memory pool for other platform isn't implememnted yet!"
#endif

#if defined(TZ_MEM_DBG)

TZ_ROOT_EXPORT
TZPVOID _tzMallocDbg(size_t size, const TZCHAR* fn, TZINT32 ln) {
  // TZ_ASSERT(NULL == TZ_T("Memory debug is not implented yet!"));
  return (TZPVOID)NULL;
}

TZ_ROOT_EXPORT
void _tzFreeDbg(TZPVOID p, const TZCHAR* fn, TZINT32 ln) {
  // TZ_ASSERT(NULL == TZ_T("Memory debug is not implented yet!"));
}

TZ_ROOT_EXPORT
TZPVOID _tzReallocDbg(TZPVOID p, size_t size, const TZCHAR* fn, TZINT32 ln) {
  // TZ_ASSERT(NULL == TZ_T("Memory debug is not implented yet!"));
  return (TZPVOID)NULL;
}

#else  // #if defined(TZ_MEM_DBG)

TZPVOID _tzMalloc(size_t size) {
  if (size > 0x80000000) {
#ifdef _PNH_DEFINED
    _PNH pOldHandlerFn = ::_set_new_handler(NULL);
    ::_set_new_handler(pOldHandlerFn);
    if (pOldHandlerFn != NULL) {
      (*pOldHandlerFn)(size);
    }
#endif
    return NULL;
  }

  return g_tzGlobalHeap.allocHeap(size);
}

void _tzFree(TZPVOID p) {
  if (!p) {
    return;
  }

  g_tzGlobalHeap.freeHeap(p);
}

TZPVOID _tzRealloc(TZPVOID p, size_t size) {
  if (size <= 0) {
    return p;
  }

  return g_tzGlobalHeap.reallocHeap(p, size);
}

#endif  // #if defined(TZ_MEM_DBG)
