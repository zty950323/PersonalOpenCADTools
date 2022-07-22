/**
 * Copyright (c) 2022, Tom Zhao personal. ("TZOpenTools")
 * This software is a personal tools project by Tom Zhao.
 * Description:
 */

#ifndef _GUI_TOOLS_DRAWHELPERS_H_
#define _GUI_TOOLS_DRAWHELPERS_H_

#include <QtWidgets/QStyleOption>
#include <QtWidgets/QWidget>

#include "GuiTools/gui_tools_export.h"

TZ_NAMESPACE_BEGIN(TzSoft)

class TZ_GUI_TOOLS_EXPORT TzDrawHelpers {
 public:
  TzDrawHelpers();
  virtual ~TzDrawHelpers();

 public:
  static int defaultDpiX();
  static int defaultDpiY();
  static int defaultDpi();

  static double logicalPixel(void);

  static int dpiScaled(int value);
  static double dpiScaled(double value);
  static int getDPI();
  static double getDPIToPercent();

  // adjust the widget w and its children minimize size and maximize size,
  // especially for the pixmap type label.
  static void adaptHighDpi(QWidget* form);

  // tools functions
  // returns the screen that contains the main window.
  static QScreen* screenAtMainWindow();

  // returns the screen that contains the largest part of widget, or
  // -1 if the widget not on a screen.
  static QScreen* screenAt(const QWidget* w);
  static QScreen* screenAt(int screenNumber);

  // returns the index of the screen that contains the largest part of widget,
  // or -1 if the widget not on a screen.
  static int screenNumber(const QWidget* w);

  // We use dpi func to adapt the hight resolution, like "padding: dpi(2)px 3px
  // 4px 5px;" The function will parse the string and replace dpi(2) with 3.
  static QString parseStyleSheet(const QString& styleSheet);

 private:
  static double m_logPixel;
};

TZ_NAMESPACE_END(TzSoft)

#endif  // _GUI_TOOLS_DRAWHELPERS_H_
