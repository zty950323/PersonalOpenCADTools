/**
 * Copyright (c) 2022, Tom Zhao personal. ("TZOpenTools")
 * This software is a personal tools project by Tom Zhao.
 * Description:
 */

#ifndef _GUI_TOOLS_DRAWHELPERS_PRIVATE_H_
#define _GUI_TOOLS_DRAWHELPERS_PRIVATE_H_

#include "gui_tools_drawhelpers.h"

TZ_NAMESPACE_BEGIN(TzSoft)

class TZ_GUI_TOOLS_EXPORT TzDrawHelpersPrivate {
 public:
  static void adaptHighDpi(QWidget* w);

  static QString parseStyleSheet(const QString& styleSheet);

  static int screenNumber(const QWidget* w);

  static QScreen* screenAt(const QWidget* w);
  static QScreen* screenAt(int screenNumber);

  static QScreen* screenAtMainWindow();
};

TZ_NAMESPACE_END(TzSoft)

#endif  // _GUI_TOOLS_DRAWHELPERS_H_
