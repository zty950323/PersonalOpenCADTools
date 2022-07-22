/**
 * Copyright (c) 2021, Tom Zhao personal. ("TZOpenTools")
 * This software is a personal tools project by Tom Zhao.
 * Description:
 */

#include "tzsofts_mem_heap.h"

#include "root_mem_heap.h"

TZ_NAMESPACE_BEGIN(TzSoft)

TZ_ROOT_EXPORT_STATIC
TZPVOID
TZ_FASTCALL
TzcHeap::operator new(size_t size) { return _tzMalloc(size); }

TZ_ROOT_EXPORT_STATIC
void TZ_FASTCALL TzcHeap::operator delete(TZPVOID p) { _tzFree(p); }

TZ_NAMESPACE_END(TzSoft)
