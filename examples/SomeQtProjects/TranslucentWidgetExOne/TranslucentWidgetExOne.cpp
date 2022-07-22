#include "stdafx.h"
#include "TranslucentWidgetExOne.h"

TranslucentWidgetExOne::TranslucentWidgetExOne(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground, true);
    setWindowOpacity(0.5);
    ui.widget->setWindowOpacity(0.5);
}
