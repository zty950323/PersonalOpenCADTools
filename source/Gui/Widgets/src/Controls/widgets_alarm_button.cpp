/**
 * Copyright (c) 2022, Tom Zhao personal. ("TZOpenTools")
 * This software is a personal tools project by Tom Zhao.
 * Description: This file records the implementation of an alarm button based on
 * QT.
 */

#include "Widgets/Controls/widgets_alarm_button.h"

#include <QtCore/QTimer>
#include <QtGui/QMouseEvent>
#include <QtGui/QPainter>
#include <QtGui/QPainterPath>

#include "Widgets/widgets_basic_color_enum_map.h"

using TzSoft::BasicColorDataTools;

namespace {
constexpr int16_t Interval = 250;
constexpr int16_t DefaultRect = 5;
constexpr int16_t PainterOffset = 2;
constexpr float PainterScale = 200.0f;
constexpr int16_t DefaultBorderRaidus = 99;
constexpr int16_t DefaultInnerRaidus = 90;
constexpr int16_t DefaultBGRaidus = 80;
constexpr int16_t DefaultTextRaidus = 100;
constexpr int16_t DefaultFontPixalSize = 85;
constexpr QColor WhiteColor = QColor(255, 255, 255);
}  // namespace

TzAlarmButton::TzAlarmButton(QWidget* parent) : QWidget(parent) {
  m_text = QStringLiteral("");
  auto colorMap = BasicColorDataTools::getPointer();
  m_textColor = colorMap->findColor(WidgetsBasicColor::White);
  m_alarmColor = colorMap->findColor(WidgetsBasicColor::LightRed);
  m_normalColor = colorMap->findColor(WidgetsBasicColor::DarkGray);
  m_borderOutColorStart = colorMap->findColor(WidgetsBasicColor::White);
  m_borderOutColorEnd = colorMap->findColor(WidgetsBasicColor::LightGray);
  m_borderInColorStart = colorMap->findColor(WidgetsBasicColor::LightGray);
  m_borderInColorEnd = colorMap->findColor(WidgetsBasicColor::White);
  m_bgColor = colorMap->findColor(WidgetsBasicColor::LightBlue);

  m_showRect = false;
  m_showOverlay = true;
  m_overlayColor = colorMap->findColor(WidgetsBasicColor::White);
  m_canMove = false;
  installEventFilter(this);
  m_isAlarm = false;
  m_isPressed = false;

  m_timerAlarm = new QTimer(this);
  connect(m_timerAlarm, SIGNAL(timeout()), this, SLOT(alarm()));
  m_timerAlarm->setInterval(Interval);
}

TzAlarmButton::~TzAlarmButton() {}

bool TzAlarmButton::eventFilter(QObject* watched, QEvent* event) {
  if (m_canMove) {
    QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
    if (mouseEvent->type() == QEvent::MouseButtonPress) {
      if (this->rect().contains(mouseEvent->pos()) &&
          (mouseEvent->button() == Qt::LeftButton)) {
        m_lastPoint = mouseEvent->pos();
        m_isPressed = true;
      }
    } else if (mouseEvent->type() == QEvent::MouseMove && m_isPressed) {
      int dx = mouseEvent->pos().x() - m_lastPoint.x();
      int dy = mouseEvent->pos().y() - m_lastPoint.y();
      this->move(this->x() + dx, this->y() + dy);
    } else if (mouseEvent->type() == QEvent::MouseButtonRelease &&
               m_isPressed) {
      m_isPressed = false;
    }
  }

  return QWidget::eventFilter(watched, event);
}

void TzAlarmButton::paintEvent(QPaintEvent* evt) {
  int width = this->width();
  int height = this->height();
  int side = qMin(width, height);

  // Preparation for painting,
  // enable anti aliasing, translate the axis center, and scale equally.
  QPainter painter(this);
  painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);

  if (m_showRect) {
    // Draw a rectangular area
    painter.setPen(Qt::NoPen);
    painter.setBrush(m_bgColor);
    painter.drawRoundedRect(this->rect(), DefaultRect, DefaultRect);

    // Draw a text.
    if (!m_text.isEmpty()) {
      QFont font;
      font.setPixelSize(side - 20);
      painter.setFont(font);
      painter.setPen(m_textColor);
      painter.drawText(this->rect(), Qt::AlignCenter, m_text);
    }
  } else {
    painter.translate(width / PainterOffset, height / PainterOffset);
    painter.scale(side / PainterScale, side / PainterScale);

    // Draw outer border
    drawBorderOut(&painter);
    // Draw inner border
    drawBorderIn(&painter);
    // Draw internal indicator color
    drawBg(&painter);
    // Draw centered text
    drawText(&painter);
    // Draw mask layer
    drawOverlay(&painter);
  }
}

void TzAlarmButton::drawBorderOut(QPainter* painter) {
  int radius = DefaultBorderRaidus;
  painter->save();
  painter->setPen(Qt::NoPen);
  QLinearGradient borderGradient(0, -radius, 0, radius);
  borderGradient.setColorAt(0, m_borderOutColorStart);
  borderGradient.setColorAt(1, m_borderOutColorEnd);
  painter->setBrush(borderGradient);
  painter->drawEllipse(-radius, -radius, radius * PainterOffset,
                       radius * PainterOffset);
  painter->restore();
}

void TzAlarmButton::drawBorderIn(QPainter* painter) {
  int radius = DefaultInnerRaidus;
  painter->save();
  painter->setPen(Qt::NoPen);
  QLinearGradient borderGradient(0, -radius, 0, radius);
  borderGradient.setColorAt(0, m_borderInColorStart);
  borderGradient.setColorAt(1, m_borderInColorEnd);
  painter->setBrush(borderGradient);
  painter->drawEllipse(-radius, -radius, radius * PainterOffset,
                       radius * PainterOffset);
  painter->restore();
}

void TzAlarmButton::drawBg(QPainter* painter) {
  int radius = DefaultBGRaidus;
  painter->save();
  painter->setPen(Qt::NoPen);
  painter->setBrush(m_bgColor);
  painter->drawEllipse(-radius, -radius, radius * PainterOffset,
                       radius * PainterOffset);
  painter->restore();
}

void TzAlarmButton::drawText(QPainter* painter) {
  if (m_text.isEmpty()) {
    return;
  }

  int radius = DefaultTextRaidus;
  painter->save();

  QFont font;
  font.setPixelSize(DefaultFontPixalSize);
  painter->setFont(font);
  painter->setPen(m_textColor);
  QRect rect(-radius, -radius, radius * PainterOffset, radius * PainterOffset);
  painter->drawText(rect, Qt::AlignCenter, m_text);
  painter->restore();
}

void TzAlarmButton::drawOverlay(QPainter* painter) {
  if (!m_showOverlay) {
    return;
  }

  int radius = DefaultBGRaidus;
  painter->save();
  painter->setPen(Qt::NoPen);

  QPainterPath smallCircle;
  QPainterPath bigCircle;
  radius -= 1;
  smallCircle.addEllipse(-radius, -radius, radius * PainterOffset,
                         radius * PainterOffset);
  radius *= PainterOffset;
  bigCircle.addEllipse(-radius, -radius + 140, radius * PainterOffset,
                       radius * PainterOffset);

  // The shape of the highlight is a small
  // circle with the part of the big circle deducted.
  QPainterPath highlight = smallCircle - bigCircle;

  QLinearGradient linearGradient(0, -radius / PainterOffset, 0, 0);
  m_overlayColor.setAlpha(100);
  linearGradient.setColorAt(0.0, m_overlayColor);
  m_overlayColor.setAlpha(30);
  linearGradient.setColorAt(1.0, m_overlayColor);
  painter->setBrush(linearGradient);
  painter->rotate(-20);
  painter->drawPath(highlight);

  painter->restore();
}

void TzAlarmButton::setText(const QString& text) {
  if (m_text != text) {
    m_text = text;
    update();
  }
}

void TzAlarmButton::setTextColor(const QColor& textColor) {
  if (m_textColor != textColor) {
    m_textColor = textColor;
    update();
  }
}

void TzAlarmButton::setAlarmColor(const QColor& alarmColor) {
  if (m_alarmColor != alarmColor) {
    m_alarmColor = alarmColor;
    update();
  }
}

void TzAlarmButton::setNormalColor(const QColor& normalColor) {
  if (m_normalColor != normalColor) {
    m_normalColor = normalColor;
    update();
  }
}

void TzAlarmButton::setBorderOutColorStart(const QColor& borderOutColorStart) {
  if (m_borderOutColorStart != borderOutColorStart) {
    m_borderOutColorStart = borderOutColorStart;
    update();
  }
}

void TzAlarmButton::setBorderOutColorEnd(const QColor& borderOutColorEnd) {
  if (m_borderOutColorEnd != borderOutColorEnd) {
    m_borderOutColorEnd = borderOutColorEnd;
    update();
  }
}

void TzAlarmButton::setBorderInColorStart(const QColor& borderInColorStart) {
  if (m_borderInColorStart != borderInColorStart) {
    m_borderInColorStart = borderInColorStart;
    update();
  }
}

void TzAlarmButton::setBorderInColorEnd(const QColor& borderInColorEnd) {
  if (m_borderInColorEnd != borderInColorEnd) {
    m_borderInColorEnd = borderInColorEnd;
    update();
  }
}

void TzAlarmButton::setBgColor(const QColor& bgColor) {
  if (m_bgColor != bgColor) {
    m_bgColor = bgColor;
    update();
  }
}

void TzAlarmButton::setBgColor(const WidgetsBasicColor& bgColor) {
  setBgColor(BasicColorDataTools::getInstance().findColor(bgColor));
}

void TzAlarmButton::setCanMove(bool canMove) {
  if (m_canMove != canMove) {
    m_canMove = canMove;
    update();
  }
}

void TzAlarmButton::setShowRect(bool showRect) {
  if (m_showRect != showRect) {
    m_showRect = showRect;
    update();
  }
}

void TzAlarmButton::setShowOverlay(bool showOverlay) {
  if (m_showOverlay != showOverlay) {
    m_showOverlay = showOverlay;
    update();
  }
}

void TzAlarmButton::setOverlayColor(const QColor& overlayColor) {
  if (m_overlayColor != overlayColor) {
    m_overlayColor = overlayColor;
    update();
  }
}

void TzAlarmButton::startAlarm() {
  if (!m_timerAlarm->isActive()) {
    m_timerAlarm->start();
  }
}

void TzAlarmButton::stopAlarm() {
  if (m_timerAlarm->isActive()) {
    m_timerAlarm->stop();
  }
}

void TzAlarmButton::alarm() {
  if (m_isAlarm) {
    m_textColor = WhiteColor;
    m_bgColor = m_normalColor;
  } else {
    m_textColor = WhiteColor;
    m_bgColor = m_alarmColor;
  }

  update();
  m_isAlarm = !m_isAlarm;
}

QString TzAlarmButton::getText() const { return m_text; }

QColor TzAlarmButton::getTextColor() const { return m_textColor; }

QColor TzAlarmButton::getAlarmColor() const { return m_alarmColor; }

QColor TzAlarmButton::getNormalColor() const { return m_normalColor; }

QColor TzAlarmButton::getBorderOutColorStart() const {
  return m_borderOutColorStart;
}

QColor TzAlarmButton::getBorderOutColorEnd() const {
  return m_borderOutColorEnd;
}

QColor TzAlarmButton::getBorderInColorStart() const {
  return m_borderInColorStart;
}

QColor TzAlarmButton::getBorderInColorEnd() const { return m_borderInColorEnd; }

QColor TzAlarmButton::getBgColor() const { return m_bgColor; }

bool TzAlarmButton::getCanMove() const { return m_canMove; }

bool TzAlarmButton::getShowRect() const { return m_showRect; }

bool TzAlarmButton::getShowOverlay() const { return m_showOverlay; }

QColor TzAlarmButton::getOverlayColor() const { return m_overlayColor; }

QSize TzAlarmButton::sizeHint() const { return QSize(100, 100); }

QSize TzAlarmButton::minimumSizeHint() const { return QSize(10, 10); }
