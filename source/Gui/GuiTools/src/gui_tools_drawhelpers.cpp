/**
 * Copyright (c) 2022, Tom Zhao personal. ("TZOpenTools")
 * This software is a personal tools project by Tom Zhao.
 * Description:
 */

#include "gui_tools_drawhelpers.h"

#include <QtGui/QGuiApplication>
#include <QtGui/QScreen>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDesktopWidget>
#include <QtWidgets/QMainWindow>

#include "gui_tools_dpi_helper_p.h"

TZ_NAMESPACE_BEGIN(TzSoft)

/*
\class TzSoft::TzDrawHelpers
\internal
*/

TzDrawHelpers::TzDrawHelpers() {}

TzDrawHelpers::~TzDrawHelpers() {}

#ifdef Q_OS_MAC
double TzDrawHelpers::m_logpixel = 72.0;
#else
double TzDrawHelpers::m_logPixel = 96.0;
#endif  // Q_OS_MAC

int TzDrawHelpers::defaultDpiX() {
#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
  if (const QScreen* screen = QGuiApplication::primaryScreen()) {
    return qRound(screen->logicalDotsPerInchX());
  }
#else  // (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
#ifdef Q_OS_WIN
  HDC displayDC = GetDC(0);
  int currentLogPixel = GetDeviceCaps(displayDC, LOGPIXELSX);
  ReleaseDC(0, displayDC);
  return currentLogPixel;
#endif  // Q_OS_WIN
#endif  // (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
  // PI has not been initialised, or is is being initialised. Give a default dpi
  return static_cast<int>(m_logPixel);
}

int TzDrawHelpers::defaultDpiY() {
#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
  if (const QScreen* screen = QGuiApplication::primaryScreen()) {
    return qRound(screen->logicalDotsPerInchY());
  }
#else  // (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
#ifdef Q_OS_WIN
  HDC displayDC = GetDC(0);
  int currentLogPixel = GetDeviceCaps(displayDC, LOGPIXELSY);
  ReleaseDC(0, displayDC);
  return currentLogPixel;
#endif  // Q_OS_WIN
#endif  // (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
  // PI has not been initialised, or is is being initialised. Give a default dpi
  return static_cast<int>(m_logPixel);
}

int TzDrawHelpers::defaultDpi() { return 0; }

double TzDrawHelpers::logicalPixel(void) { return m_logPixel; }

int TzDrawHelpers::dpiScaled(int value) {
  return static_cast<int>(value * dpiScaled(1.0) + 0.5);
}

double TzDrawHelpers::dpiScaled(double value) {
  static const qreal scale = static_cast<qreal>(defaultDpiX()) / m_logPixel;
  return value * scale;
}

int TzDrawHelpers::getDPI() { return defaultDpiX(); }

double TzDrawHelpers::getDPIToPercent() { return getDPI() * 100 / m_logPixel; }

void TzDrawHelpers::adaptHighDpi(QWidget* form) {}

QScreen* TzDrawHelpers::screenAtMainWindow() {
  QWidget* widget = nullptr;
  QWidgetList widgetList = QApplication::topLevelWidgets();
  for (QWidget* w : widgetList) {
    if (qobject_cast<QMainWindow*>(w)) {
      widget = w;
      break;
    }
  }

  if (widget == nullptr && widgetList.isEmpty() == false)
    widget = widgetList.at(0);
  if (widget) {
    QDesktopWidget* dtWidget = QApplication::desktop();
    const int& num = dtWidget->screenNumber(widget);
    if (num >= 0) {
      const QList<QScreen*>& allScreens = QGuiApplication::screens();
      return allScreens.at(num);
    }
  }

  return nullptr;
}

QScreen* TzDrawHelpers::screenAt(const QWidget* w) {
  if (nullptr == w) return nullptr;
  QDesktopWidget* dtWidget = QApplication::desktop();
  const int& num = dtWidget->screenNumber(w);
  if (num >= 0) {
    const QList<QScreen*>& allScreens = QGuiApplication::screens();
    return allScreens.at(num);
  }
  return nullptr;
}

QScreen* TzDrawHelpers::screenAt(int screenNumber) {
  const QList<QScreen*>& allScreens = QGuiApplication::screens();
  return allScreens.at(screenNumber);
}

int TzDrawHelpers::screenNumber(const QWidget* w) {
  if (nullptr == w) return -1;
  QDesktopWidget* dtWidget = QApplication::desktop();
  return dtWidget->screenNumber(w);
}

QString TzDrawHelpers::parseStyleSheet(const QString& styleSheet) {
  return QString();
}

TZ_NAMESPACE_END(TzSoft)
