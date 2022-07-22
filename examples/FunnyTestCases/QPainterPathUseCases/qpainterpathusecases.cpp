#include "qpainterpathusecases.h"
#include <QPainter>

QPainterPathUseCases::QPainterPathUseCases(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

void QPainterPathUseCases::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    // 矩形 300 * 200
    QRectF rect(100, 100, 300, 200);
    QPainterPath path;
    path.addRect(rect);

    // 绘制原始路径
    drawPath(&painter, path);

    // 绘制轮廓
    drawOutline(&painter, path);
}

void QPainterPathUseCases::drawOutline(QPainter* painter, QPainterPath path)
{
    // 生成可填充的轮廓
    QPainterPathStroker stroker;
    stroker.setCapStyle(Qt::RoundCap);  // 端点风格
    stroker.setJoinStyle(Qt::RoundJoin);  // 连接样式
    stroker.setDashPattern(Qt::DashLine);  // 虚线图案
    stroker.setWidth(6);  // 宽度

    // 生成一个新路径（可填充区域），表示原始路径 path 的轮廓
    QPainterPath outlinePath = stroker.createStroke(path);

    // 绘制轮廓时所用的画笔（轮廓外边框灰色部分）
    QPen pen = painter->pen();
    pen.setColor(QColor(0, 160, 230));
    pen.setWidth(6);

    // 用指定的画笔 pen 绘制 outlinePath
    // painter->strokePath(outlinePath, pen);
    painter->setPen(pen);
    painter->drawPath(outlinePath);

    // 用指定的画刷 brush 填充路径 outlinePath
    painter->fillPath(outlinePath, QBrush(Qt::yellow));
}

void QPainterPathUseCases::drawPath(QPainter* painter, QPainterPath path)
{
    QPen pen = painter->pen();
    pen.setWidth(1);

    // 设置画笔、画刷
    painter->setPen(pen);
    painter->setBrush(QColor(35, 175, 75));

    // 绘制路径
    painter->drawPath(path);
}
