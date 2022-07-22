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

    // ���� 300 * 200
    QRectF rect(100, 100, 300, 200);
    QPainterPath path;
    path.addRect(rect);

    // ����ԭʼ·��
    drawPath(&painter, path);

    // ��������
    drawOutline(&painter, path);
}

void QPainterPathUseCases::drawOutline(QPainter* painter, QPainterPath path)
{
    // ���ɿ���������
    QPainterPathStroker stroker;
    stroker.setCapStyle(Qt::RoundCap);  // �˵���
    stroker.setJoinStyle(Qt::RoundJoin);  // ������ʽ
    stroker.setDashPattern(Qt::DashLine);  // ����ͼ��
    stroker.setWidth(6);  // ���

    // ����һ����·������������򣩣���ʾԭʼ·�� path ������
    QPainterPath outlinePath = stroker.createStroke(path);

    // ��������ʱ���õĻ��ʣ�������߿��ɫ���֣�
    QPen pen = painter->pen();
    pen.setColor(QColor(0, 160, 230));
    pen.setWidth(6);

    // ��ָ���Ļ��� pen ���� outlinePath
    // painter->strokePath(outlinePath, pen);
    painter->setPen(pen);
    painter->drawPath(outlinePath);

    // ��ָ���Ļ�ˢ brush ���·�� outlinePath
    painter->fillPath(outlinePath, QBrush(Qt::yellow));
}

void QPainterPathUseCases::drawPath(QPainter* painter, QPainterPath path)
{
    QPen pen = painter->pen();
    pen.setWidth(1);

    // ���û��ʡ���ˢ
    painter->setPen(pen);
    painter->setBrush(QColor(35, 175, 75));

    // ����·��
    painter->drawPath(path);
}
