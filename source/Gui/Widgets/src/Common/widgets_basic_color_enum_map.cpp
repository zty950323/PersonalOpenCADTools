/**
 * Copyright (c) 2022, Tom Zhao personal. ("TZOpenTools")
 * This software is a personal tools project by Tom Zhao.
 * Description: This file records a class as a tool for create basic color map.
 */

#include "Widgets/widgets_basic_color_enum_map.h"

TZ_NAMESPACE_BEGIN(TzSoft)

BasicColorDataTools::BasicColorDataTools() {
    m_basicColorMap[WidgetsBasicColor::Green] = QColor(0, 166, 0);
    m_basicColorMap[WidgetsBasicColor::Red] = QColor(255, 0, 0);
    m_basicColorMap[WidgetsBasicColor::Yellow] = QColor(238, 238, 0);
    m_basicColorMap[WidgetsBasicColor::Black] = QColor(0, 0, 0);
    m_basicColorMap[WidgetsBasicColor::DarkGray] = QColor(10, 10, 10);
    m_basicColorMap[WidgetsBasicColor::Gray] = QColor(129, 129, 129);
    m_basicColorMap[WidgetsBasicColor::Blue] = QColor(0, 0, 166);
    m_basicColorMap[WidgetsBasicColor::LightBlue] = QColor(100, 184, 255);
    m_basicColorMap[WidgetsBasicColor::LightRed] = QColor(255, 107, 107);
    m_basicColorMap[WidgetsBasicColor::LightGreen] = QColor(24, 189, 155);
    m_basicColorMap[WidgetsBasicColor::LightGray] = QColor(166, 166, 166);
    m_basicColorMap[WidgetsBasicColor::White] = QColor(255, 255, 255);
}

QColor BasicColorDataTools::findColor(const WidgetsBasicColor& color) {
    return m_basicColorMap[color];
}

TZ_NAMESPACE_END(TzSoft)
