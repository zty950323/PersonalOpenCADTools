#include "tzdocketbutton.h"
#include <QStylePainter>
#include <QStyleOptionTitleBar>

void TzDocketButton::paintEvent(QPaintEvent *)
{
    QStylePainter painter(this);
    QStyleOptionTitleBar option;
    option.init(this);
    option.activeSubControls = m_control;
    painter.drawPrimitive(QStyle::PE_PanelButtonTool, option);
}
