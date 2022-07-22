/**
 * Copyright (c) 2022, Tom Zhao personal. ("TZOpenTools")
 * This software is a personal tools project by Tom Zhao.
 * Description:
 */

#ifndef SOURCE_GUI_CORE_INC_CORE_PRIVATE_H_
#define SOURCE_GUI_CORE_INC_CORE_PRIVATE_H_

#include "zsofts_compiler_specific.h"

TZ_NAMESPACE_BEGIN(TzSoft)

enum CorePrivateFlags {
  kPrivateNone = 0,
};

class TzCorePrivate {
 public:
  explicit TzCorePrivate(const CorePrivateFlags& flag);
  ~TzCorePrivate();

 private:
  CorePrivateFlags m_privateFlag;
};

TZ_NAMESPACE_END(TzSoft)

#endif  // SOURCE_GUI_CORE_INC_CORE_PRIVATE_H_
