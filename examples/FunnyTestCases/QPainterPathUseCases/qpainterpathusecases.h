#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_qpainterpathusecases.h"

class QPainterPathUseCases : public QMainWindow
{
    Q_OBJECT

public:
    QPainterPathUseCases(QWidget *parent = Q_NULLPTR);

private:
    void paintEvent(QPaintEvent* event) override;
    void drawOutline(QPainter* painter, QPainterPath path);
    void drawPath(QPainter* painter, QPainterPath path);

private:
    Ui::QPainterPathUseCasesClass ui;
};
