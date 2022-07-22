/**
 * Copyright (c) 2022, Tom Zhao personal. ("TZOpenTools")
 * This software is a personal tools project by Tom Zhao.
 * Description:
 */

#ifndef SOURCE_GUI_WIDGETS_INC_WIDGETS_PRIVATE_H_
#define SOURCE_GUI_WIDGETS_INC_WIDGETS_PRIVATE_H_

#include "zsofts_compiler_specific.h"

TZ_NAMESPACE_BEGIN(TzSoft)

enum WidgetsPrivateFlags {
  kPrivateNone = 0,
};

class TzWidgetsPrivate {
 public:
  explicit TzWidgetsPrivate(const WidgetsPrivateFlags& flag);
  ~TzWidgetsPrivate();

 private:
  WidgetsPrivateFlags m_privateFlag;
};

TZ_NAMESPACE_END(TzSoft)

#endif  // SOURCE_GUI_WIDGETS_INC_WIDGETS_PRIVATE_H_
