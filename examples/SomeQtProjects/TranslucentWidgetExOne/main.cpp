#include "stdafx.h"
#include "TranslucentWidgetExOne.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TranslucentWidgetExOne w;
    w.show();
    return a.exec();
}
