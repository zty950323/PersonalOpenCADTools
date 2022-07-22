/**
 * Copyright (c) 2022, Tom Zhao personal. ("TZOpenTools")
 * This software is a personal tools project by Tom Zhao.
 * Description: This file records a class as a tool for create basic color map.
 */

#ifndef SOURCE_INCLUDE_WIDGETS_WIDGETS_BASIC_COLOR_ENUM_MAP_H_
#define SOURCE_INCLUDE_WIDGETS_WIDGETS_BASIC_COLOR_ENUM_MAP_H_

#include <QtCore/QMap>
#include <QtGui/QColor>

#include "DesignPatternTools/basic_open_singleTon.h"
#include "widgets_defines.h"

using Basic::TzSingleTon;

TZ_NAMESPACE_BEGIN(TzSoft)

class BasicColorDataTools : public TzSingleTon<BasicColorDataTools> {
 public:
  BasicColorDataTools();
  virtual ~BasicColorDataTools() = default;

  QColor findColor(const WidgetsBasicColor& color);

 private:
  QMap<WidgetsBasicColor, QColor> m_basicColorMap;
};

TZ_NAMESPACE_END(TzSoft)

#endif  // SOURCE_INCLUDE_WIDGETS_WIDGETS_BASIC_COLOR_ENUM_MAP_H_
