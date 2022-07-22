/**
 * Copyright (c) 2022, Tom Zhao personal. ("TZOpenTools")
 * This software is a personal tools project by Tom Zhao.
 * Description:
 */

#ifndef SOURCE_GUI_TOOLS_INC_CORE_PRIVATE_H_
#define SOURCE_GUI_TOOLS_INC_CORE_PRIVATE_H_

#include "zsofts_compiler_specific.h"

TZ_NAMESPACE_BEGIN(TzSoft)

enum ToolsPrivateFlags {
  kPrivateNone = 0,
};

class TzToolsPrivate {
 public:
  explicit TzToolsPrivate(const ToolsPrivateFlags& flag);
  ~TzToolsPrivate();

 private:
  ToolsPrivateFlags m_privateFlag;
};

TZ_NAMESPACE_END(TzSoft)

#endif  // SOURCE_GUI_TOOLS_INC_CORE_PRIVATE_H_
