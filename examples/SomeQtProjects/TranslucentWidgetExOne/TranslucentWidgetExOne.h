#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TranslucentWidgetExOne.h"

class TranslucentWidgetExOne : public QMainWindow
{
    Q_OBJECT

public:
    TranslucentWidgetExOne(QWidget *parent = Q_NULLPTR);

private:
    Ui::TranslucentWidgetExOneClass ui;
};
