/**
 * Copyright (c) 2021, Tom Zhao personal. ("TZOpenTools")
 * This software is a personal tools project by Tom Zhao.
 * Description:
 */

#ifndef SOURCE_BASIC_INCLUDE_ROOT_MEM_HEAP_DBG_H_
#define SOURCE_BASIC_INCLUDE_ROOT_MEM_HEAP_DBG_H_

#include "zsofts_compiler_specific.h"

#ifdef TZ_MEM_DEBUG

#include "root_mem_malloc.h"

inline void* TZ_CDECL operator new(size_t size, const char* file, int line) {
  return _tzMallocDbg(size, file, line);
}

inline void* TZ_CDECL operator new[](size_t size, const char* file, int line) {
  return _tzMallocDbg(size, file, line);
}

inline void TZ_CDECL operator delete(void* p, const char* file, int line) {
  _tzFreeDbg(p, file, line);
}

inline void TZ_CDECL operator delete[](void* p, const char* file, int line) {
  _tzFreeDbg(p, file, line);
}

#define TZ_DEBUG_NEW new (__FILE__, __LINE__)
#define TZ_DEBUG_DELETE delete

#endif

#endif  // !SOURCE_BASIC_INCLUDE_ROOT_MEM_HEAP_DBG_H_
