/**
 * Copyright (c) 2022, Tom Zhao personal. ("TZOpenTools")
 * This software is a personal tools project by Tom Zhao.
 * Description: This file records the implementation of an alarm button based on
 * QT.
 */

#ifndef SOURCE_INCLUDE_WIDGETS_CONTROLS_WIDGETS_ALARM_BUTTON_H_
#define SOURCE_INCLUDE_WIDGETS_CONTROLS_WIDGETS_ALARM_BUTTON_H_

#include <QtWidgets/QWidget>

#include "Widgets/widgets_defines.h"
#include "Widgets/widgets_export.h"

using TzSoft::WidgetsBasicColor;

class TzAlarmButton : public QWidget {
  Q_OBJECT

 public:
  explicit TzAlarmButton(QWidget* parent = nullptr);
  ~TzAlarmButton();

 public:
  QString getText() const;
  QColor getTextColor() const;
  QColor getAlarmColor() const;
  QColor getNormalColor() const;

  QColor getBorderOutColorStart() const;
  QColor getBorderOutColorEnd() const;
  QColor getBorderInColorStart() const;
  QColor getBorderInColorEnd() const;
  QColor getBgColor() const;

  bool getCanMove() const;
  bool getShowRect() const;
  bool getShowOverlay() const;
  QColor getOverlayColor() const;

  QSize sizeHint() const;
  QSize minimumSizeHint() const;

  // set the button text.
  void setText(const QString& text);
  // set text color.
  void setTextColor(const QColor& textColor);

  // set alarm / normal color.
  void setAlarmColor(const QColor& alarmColor);
  void setNormalColor(const QColor& normalColor);

  // set the border out color during start to end.
  void setBorderOutColorStart(const QColor& borderOutColorStart);
  void setBorderOutColorEnd(const QColor& borderOutColorEnd);

  // set the border in color during start to end.
  void setBorderInColorStart(const QColor& borderInColorStart);
  void setBorderInColorEnd(const QColor& borderInColorEnd);

  // set background color.
  void setBgColor(const QColor& bgColor);
  void setBgColor(const WidgetsBasicColor& bgColor);

  // set this can be moved.
  void setCanMove(bool canMove);
  // set whether needs to show rect.
  void setShowRect(bool showRect);
  // set whether needs to show overlay.
  void setShowOverlay(bool showOverlay);
  // set the overlay color.
  void setOverlayColor(const QColor& overlayColor);

  // set to start the alarm.
  void startAlarm();
  void stopAlarm();
  void alarm();

 protected:
  bool eventFilter(QObject* watched, QEvent* event);
  void paintEvent(QPaintEvent*);
  void drawBorderOut(QPainter* painter);
  void drawBorderIn(QPainter* painter);
  void drawBg(QPainter* painter);
  void drawText(QPainter* painter);
  void drawOverlay(QPainter* painter);

 private:
  QString m_text;
  QColor m_textColor;
  QColor m_alarmColor;
  QColor m_normalColor;

  QColor m_borderOutColorStart;
  QColor m_borderOutColorEnd;
  QColor m_borderInColorStart;
  QColor m_borderInColorEnd;
  QColor m_bgColor;

  bool m_showRect;
  bool m_canMove;
  bool m_showOverlay;
  QColor m_overlayColor;

  bool m_isAlarm;
  QTimer* m_timerAlarm;
  QPoint m_lastPoint;
  bool m_isPressed;
};

#endif  // SOURCE_INCLUDE_WIDGETS_CONTROLS_WIDGETS_ALARM_BUTTON_H_
