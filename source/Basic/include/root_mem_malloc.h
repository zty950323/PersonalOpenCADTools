/**
 * Copyright (c) 2021, Tom Zhao personal. ("TZOpenTools")
 * This software is a personal tools project by Tom Zhao.
 * Description:
 */

#ifndef SOURCE_BASIC_INCLUDE_ROOT_MEM_MALLOC_H_
#define SOURCE_BASIC_INCLUDE_ROOT_MEM_MALLOC_H_

#include "root_export.h"
#include "zsofts_types.h"

// Define heap funcitons:

#if defined(TZ_MEM_DBG)

TZ_ROOT_EXPORT
TZPVOID _tzMallocDbg(size_t size, const TZCHAR* fn, TZINT32 ln);

TZ_ROOT_EXPORT
void _tzFreeDbg(TZPVOID p, const TZCHAR* fn, TZINT32 ln);

TZ_ROOT_EXPORT
TZPVOID _tzReallocDbg(TZPVOID p, size_t size, const TZCHAR* fn, TZINT32 ln);

#define tzMalloc(s) _tzMallocDbg(s, __FILE__, __LINE__)
#define tzFree(p) _tzFreeDbg(p, __FILE__, __LINE__)
#define tzRealloc(p, s) _tzReallocDbg(p, s, __FILE__, __LINE__)

#else  // #if defined(TZ_MEM_DBG)

TZPVOID _tzMalloc(size_t size);

void _tzFree(TZPVOID p);

TZPVOID _tzRealloc(TZPVOID p, size_t size);

#define tzMalloc(s) _tzMalloc(s)
#define tzFree(p) _tzFree(p)
#define tzRealloc(p, s) _tzRealloc(p, s)

#endif  // #if defined(TZ_MEM_DBG)

#endif  // SOURCE_BASIC_INCLUDE_ROOT_MEM_MALLOC_H_
