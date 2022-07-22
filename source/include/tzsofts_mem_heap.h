/**
 * Copyright (c) 2021, Tom Zhao personal. ("TZOpenTools")
 * This software is a personal tools project by Tom Zhao.
 * Description:
 */

#ifndef SOURCE_INCLUDE_TZSOFTS_MEM_HEAP_H_
#define SOURCE_INCLUDE_TZSOFTS_MEM_HEAP_H_

#include "root_export.h"
#include "zsofts_types.h"

#pragma push_macro("new")
#pragma push_macro("delete")
#undef new
#undef delete

TZ_NAMESPACE_BEGIN(TzSoft)

class TZ_ROOT_STATIC_EXPORT TzcHeap {
 public:
  static TZ_ROOT_EXPORT_STATIC TZPVOID TZ_FASTCALL operator new(size_t size);
  static TZ_ROOT_EXPORT_STATIC void TZ_FASTCALL operator delete(TZPVOID p);
};

#pragma pop_macro("delete")
#pragma pop_macro("new")

TZ_NAMESPACE_END(TzSoft)

#endif  // SOURCE_INCLUDE_TZSOFTS_MEM_HEAP_H_
