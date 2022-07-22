#include "stdafx.h"
#include "TzArrowButton.h"

TzArrowButton::TzArrowButton(Direction dir, QWidget *parent)
    : QPushButton(parent)
{
}

TzArrowButton::~TzArrowButton()
{
}

QSize TzArrowButton::sizeHint(void) const
{
    return QSize();
}

TzArrowButton::Direction TzArrowButton::direction() const
{
    return Direction();
}

void TzArrowButton::setDirection(Direction dir)
{
}

void TzArrowButton::paintEvent(QPaintEvent * event)
{
}

QPainterPath TzArrowButton::arrowPath() const
{
    return QPainterPath();
}
